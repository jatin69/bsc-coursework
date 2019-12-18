go:-  nl,write('Enter a list : '), read(L),
      last_ele(L,X),
      write('Last element : '), write(X),nl.

last_ele([X],X):-!.
last_ele([H|T],X):- last_ele(T,X).
