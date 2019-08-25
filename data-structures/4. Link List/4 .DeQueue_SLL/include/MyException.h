#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

class MyException
{
    public:
        MyException();
        MyException(const char*);
        void printerror();
    protected:
    private:
    const char* msg;
};

#endif // MYEXCEPTION_H
