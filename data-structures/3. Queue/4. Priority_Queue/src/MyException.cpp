#include<iostream>
#include<cstring>
#include "MyException.h"

MyException::MyException(const char* str)
{
    msg = new char[strlen(str)];
    strcpy(msg,str);
}

MyException::~MyException()
{
    delete []msg;
}

MyException:: MyException(const MyException& ex)
{
    msg = new char[strlen(ex.msg)];
    strcpy(msg,ex.msg);
}

void MyException:: printerror()
{
    std::cout.write(msg,strlen(msg));
}
