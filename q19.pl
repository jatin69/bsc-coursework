go:-  nl,write('Enter list : '), read(L),
      sumlist(L,Sum),
      write('Sum        : '), write(Sum).

sumlist([],0).
sumlist([X|T], Res) :- sumlist(T,R1), Res is X + R1.
