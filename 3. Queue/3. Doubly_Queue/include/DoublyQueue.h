#ifndef DOUBLYQUEUE_H
#define DOUBLYQUEUE_H


template <class T>
class DoublyQueue
{
    public:
        /** Default constructor */
        DoublyQueue();
        /** parameterized constructor */
        DoublyQueue(T);
        /** Default destructor */
        ~DoublyQueue();
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

#endif // DOUBLYQUEUE_H
