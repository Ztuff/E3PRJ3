// Libraries
 #include <linux/gpio.h> 
 #include <linux/fs.h>
 #include <linux/cdev.h>
 #include <linux/device.h>
 #include <asm/uaccess.h>
 #include <linux/module.h>
 
 //Hvad skal med?
 // Den skal også kunne styre jumper 3 til at sørge for auto-connect 
 // https://gitorious.org/devkit8000/linux-omap-devkit8000/source/7972b6f3acb6889833a5c41901507a79b47bd1d0:drivers/bluetooth/btuart_cs.c#L282
 
 // Skal rettes til
#define BT_TX_PIN 142
#define BT_RX_PIN 143
#define BT_AUTOCONNECT_PINT 140 //Vil det virke?
#define BT_MINOR 0
#define BT_NBR_MINOR 1
#define MAXLENGTH 32

MODULE_LICENSE( "Dual BSD/GPL");

// **************** Function implementation ****************

int BT_open(struct inode *inode, struct file *filep)
{
  int major, minor;
  major = MAJOR(inode->i_rdev);
  minor = MINOR(inode->i_rdev);
  printk("Opening BT Device [major], [minor]: %i, %i\n", major, minor);
  return 0;
}

int BT_release(struct inode *inode, struct file *filep)
{
  int minor, major;

  major = MAJOR(inode->i_rdev);
  minor = MINOR(inode->i_rdev);
  printk("Closing/Releasing BT Device [major], [minor]: %i, %i\n", major, minor);

  return 0;
}

static struct cdev BT_cdev;
static int devno;

ssize_t BT_read(struct file *filep, char __user *buf, size_t count, loff_t *f_pos)
{
  char readBuf[ MAXLENGTH ];
  int length, value;
  unsigned long err; // long, da størrelsen på int er systemafhængig
  
  value = gpio_get_value( BT_PIN );
  
  length = sprintf( readBuf, "%d", value );
  
  if( length > count )
  {
    printk( "Length (%i) is bigger than count (%i)\n", length, count );
    return -1;
  }
  
  // copy_to_user kopierer en blok af data fra kernel space til user space
  // buf = to:		Destination address, in user space
  // readBuf =		from: Source address, in kernel space
  // length = n:	Number of bytes to copy
  err = copy_to_user( buf, readBuf, length );
  if( err != 0 )
  {
    printk( "Error with copy_to_user(), bytes not copied: %lu\n", err );
    return -1;
  }

  // Øg offset med længden på værdien fra GPIO'en
  *f_pos += length;
  
  return length;
}

ssize_t BT_write(struct file *filep, const char __user *ubuf, size_t count, loff_t *f_pos)
{
  char writeBuf[ MAXLENGTH ];
  int value;
  unsigned long err; // long, da størrelsen på int er systemafhængig
  
// Hvilke trin er det der skal udføres?
// Hint konvertering fra string til int kan gøres via sscanf() - antagelsen er at det er strenge der sendes til og fra user space. Det debugging lettere.

  // copy_to_user kopierer en blok af data fra kernel space til user space
  // writeBuf =	 to:	Destination address, in kernel space
  // buf = from:	Source address, in user space
  // length = n:	Number of bytes to copy
  err = copy_from_user( writeBuf, ubuf, count );
  
  if( err != 0 )
  {
    printk( "Error with copy_from_user(), bytes not copied: %lu\n", err );
    return -1;
  }
  
  sscanf( writeBuf, "%d", &value );
  
  gpio_set_value( BT_PIN, value );

  // Øg offset med længden på værdien fra GPIO'en
  *f_pos += count;
  
  return count;
}

// ************ End of function implementation ************

// BT_fops, af typen file_operations som allerede er typedef'et,
// sættes, linje for linje, til hver af de fire .* i struct'en
struct file_operations BT_fops =
{
  .owner = THIS_MODULE,
  .read = BT_read,
  .write = BT_write,
  .open = BT_open,
  .release = BT_release
};

static int __init BT_init(void)
{
  // Request GPIO
  if( gpio_request( BT_PIN, "BT" ) != NULL)
  {
    printk ( KERN_ALERT "Access to BT pin has failed\n" );
    goto err1;
  }
  
  // Set GPIO direction (in or out)
  if( gpio_direction_output( BT_PIN, 1 ) != NULL)
  {
    printk ( KERN_ALERT "BT direction set has failed\n" );
    goto err2;
  }
  
  // Make device no
  if( alloc_chrdev_region( &devno, BT_MINOR, BT_NBR_MINOR, "BT_Driver") != NULL )
  {
    printk ( KERN_ALERT "Couldn't make BT device number\n" );
    goto err3;
  }
  
  // Init cdev
  cdev_init(&BT_cdev, &BT_fops);
  
  // Register Device
  if( cdev_add(&BT_cdev, devno, BT_NBR_MINOR ) != NULL )
  {
    printk ( KERN_ALERT "Device registration check for BT has failed\n" );
    goto err4;
  }
 
 printk( KERN_ALERT "BT driver inserted\n" );
 
  return 0;
  
  err4:
    unregister_chrdev_region( devno, BT_NBR_MINOR );
  
  err3:
  // Do nothing
  
  err2:
    gpio_free( BT_PIN );
    
  err1:
    return -1;
}

static void BT_exit(void)
{
  // Delete Cdev
  cdev_del( &BT_cdev );
  
  // Unregister Device
  unregister_chrdev_region( devno, BT_NBR_MINOR );
  
  // Free GPIO
  gpio_free( BT_PIN );

  // Afsluttende besked
  printk( KERN_ALERT "Modulet BT termineret\n");
}

module_init(BT_init);
module_exit(BT_exit);
