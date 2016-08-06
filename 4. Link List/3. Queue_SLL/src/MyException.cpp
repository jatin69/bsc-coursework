#include "MyException.h"

 #include<iostream>
 using namespace std ;
  MyException::MyException()
  {
  }
  MyException::MyException( const char* pmsg)
  {
    msg=pmsg;
  }

  void MyException::printerror()
  {
    cout<<msg;
  }
