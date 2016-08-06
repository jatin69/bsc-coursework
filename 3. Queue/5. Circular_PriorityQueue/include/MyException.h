#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H


class MyException
{
    private:
        char* msg;
    public:
        MyException(const char*);
        MyException(const MyException&);
        ~MyException();
        void printerror();

};

#endif // MYEXCEPTION_H
