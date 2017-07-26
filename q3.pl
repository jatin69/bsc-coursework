go:-
    nl,write('Enter first number : '),read(A),
    write('Enter second number: '),read(B),
    max(A,B,Res),
    write('Maximum : '),write(Res),nl.

max(X,Y,M):- X>Y,M=X,!.
max(_,Y,Y).
