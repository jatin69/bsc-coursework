#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <Queue.h>

template <class T>
class PriorityQueue : public Queue<T>
{
    public:
        /** Default constructor */
       PriorityQueue();
         /** parameterized constructor */
        PriorityQueue(T);
        /** Default destructor */
        ~PriorityQueue();
        void EnQueue(T);
        bool CheckPriority(T,T);
    protected:
    private:
};

#endif // PRIORITYQUEUE_H
