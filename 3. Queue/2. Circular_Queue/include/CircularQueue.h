#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

template <class T>
class CircularQueue
{
    public:
        /** Default constructor */
        CircularQueue();
        /** Parametrized constructor */
        CircularQueue(T);
        /** Default destructor */
        ~CircularQueue();
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
#endif // CIRCULARQUEUE_H
