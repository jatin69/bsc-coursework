#ifndef PARTITION_H
#define PARTITION_H


class Partition
{
    int id;
    int size;
    int allocatedMemory;

public:
    Partition();
    void createPartition(int);
    void allocateMemory(int);
    void deallocateMemory();
    int retSize();
    int retId();
    int retFreeMemory();
};

#endif // PARTITION_H
