#ifndef SYNCPRINT_HPP
#define SYNCPRINT_HPP

#include <osapi/Mutex.hpp>
#include <iostream>
#include <string>

class SyncPrint{
public:
  SyncPrint(){
  }
		
  ~SyncPrint(){
  }
		
  void print(std::string str){
    mut_.lock();
    std::cout << str;
    mut_.unlock();
  }
		
  void print(int i){
    mut_.lock();
    std::cout << i;
    mut_.unlock();
  }
		
  void println(std::string str){
    mut_.lock();
    std::cout << str << std::endl;
    mut_.unlock();
  }
		
  void println(int i){
    mut_.lock();
    std::cout << i << std::endl;
    mut_.unlock();
  }
		
  void carPrint(int id, std::string str){
    mut_.lock();
    std::cout << "Car# " << id << ": " << str;
    mut_.unlock();
  }
		
  void carPrintln(int id, std::string str){
    mut_.lock();
    std::cout << "Car# " << id << ": " << str << std::endl;
    mut_.unlock();
  }
		
	
private:
  osapi::Mutex mut_;
};

#endif
