#ifndef CIRCULARPRIORITY_H
#define CIRCULARPRIORITY_H
#include <Queue.h>

template <class T>
class CircularPriority : public Queue<T>
{
    public:
        /** Default constructor */
        CircularPriority();
         /** parameterized constructor */
        CircularPriority(T);
        /** Default destructor */
        ~CircularPriority();
         void EnQueue(T);
        bool CheckPriority(T,T);
};

#endif // CIRCULARPRIORITY_H

