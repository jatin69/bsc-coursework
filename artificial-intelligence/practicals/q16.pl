go:-  nl,write('Enter a list               : '), read(L),
	 write('Enter element to be deleted: '), read(E),
	 delete_first(E,L,X),
	 write('Updated list               : '), write(X),nl.

delete_first(H,[H|T],T):-!.
delete_first(X,[H|T],[H|T1]) :- delete_first(X,T,T1).

