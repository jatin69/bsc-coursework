#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H


class priority_queue
{
private:


    int* arr;
    int length;
    int heapsize;

    public:
    priority_queue();
    priority_queue(int);

    void Swap(int&,int&);
    void max_heapify(int);
    void max_heap_insert(int);
    void heap_increase_key(int , int);
    int heap_maximum();
    int heap_extract_max();
    void display();

};

#endif // PRIORITY_QUEUE_H
