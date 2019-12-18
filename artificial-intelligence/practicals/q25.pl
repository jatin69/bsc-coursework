go:-  nl,write('Enter a list               : '), read(L),
	 write('Enter element to be deleted: '), read(E),
	 delete_all(E,L,X),
 	 write('Updated list               : '), write(X),nl.

delete_all(_,[],[]).
delete_all(X,[X|T],L) :- delete_all(X,T,L),!.
delete_all(X,[H1|T1],[H1|T2]) :- delete_all(X,T1,T2).









