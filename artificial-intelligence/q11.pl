go:-	 nl,write('Enter a list  : '), read(L),
	 write('Enter element : '), read(E),
	 write('Enter position: '), read(P),
	 length(L,Len), Length is Len+1, P =< Length,
	 insert_nth(E,P,L,Res),
	 write('List after insertion: '),
	 write(Res),nl.

insert_nth(I,1,L,[I|L]):-!.
insert_nth(I,N,[H|T1],[H|T2]):- N1 is N-1,insert_nth(I,N1,T1,T2).
