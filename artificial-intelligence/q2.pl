go:-
    nl,write('Enter first number : '),read(A),
    write('Enter second number: '),   read(B),
    sum(A,B,Sum),
    write('Sum : '),write(Sum),nl.

sum(A,B,Sum):- Sum is A+B.
