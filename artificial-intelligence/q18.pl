go:-  nl,write('Enter a list    : '), read(L),
      write('Largest element : '),
      maxlist(L,X), write(X),nl.

max(X,Y,M):- X>Y,M=X,!.
max(_,Y,Y).

maxlist([H],H) :- !.
maxlist([H|T],MaxE) :- maxlist(T,M1), max(H,M1,MaxE).


