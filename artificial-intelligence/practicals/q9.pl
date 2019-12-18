go:-  nl,write('Enter a list : '), read(L),
      rev(L,R),
      write('Reversed list: '), write(R).

rev([X],[X]):-!.
rev([X|T],L) :- rev(T,R), append(R,[X],L).
