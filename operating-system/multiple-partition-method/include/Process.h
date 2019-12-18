#ifndef PROCESS_H
#define PROCESS_H


class Process
{
    int size;
    bool allocated;

public:
    Process();
    void enterProcess();
    void setAllocated();
    void resetAllocated();
    int retSize();
    bool isAllocated();
};

#endif // PROCESS_H
