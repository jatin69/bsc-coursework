go:-  nl,write('Enter a list  : '), read(L),
	 write('Enter position: '), read(P),
	 length(L,Len), P =< Len,
	 delete_nth(P,L,Res),nl,
	 write('List after deletion: '), write(Res),nl.

delete_nth(1,[_|T],T):-!.
delete_nth(N,[H|T1],[H|T2]):- N1 is N-1, delete_nth(N1,T1,T2).
