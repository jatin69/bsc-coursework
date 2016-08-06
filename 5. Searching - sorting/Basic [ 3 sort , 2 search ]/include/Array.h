#ifndef ARRAY_H
#define ARRAY_H


class Array
{
    public:

    int* arr;
    int Size;

    /// default cons.
    Array(int);

    /// default destructor
    ~Array();

    /// copy cons.
    Array(const Array&);

    /// enter & display functions
    void fillarray();
    void display();

    /// searching functions
    int lsearch( int );
    int bsearch( int );

    /// common sorting techniques
    Array& bubble_sort();
    Array& sel_sort();
    Array& ins_sort();

};

#endif //
