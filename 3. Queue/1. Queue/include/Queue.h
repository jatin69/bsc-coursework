#ifndef QUEUE_H
#define QUEUE_H


template <class T>
class Queue
{
    public:
        /** Default constructor */
        Queue();
        /** parameterized constructor */
        Queue(T);
        /** Default destructor */
        ~Queue();
        void EnQueue(T);
        T DeQueue();
        void Display();
        void ClearQueue();
        bool isFull();
        bool isEmpty();

    protected:
    private:
        T *arr;
        int Front;
        int Rear;
        int Length;
        T temp;

};

#endif // QUEUE_H
