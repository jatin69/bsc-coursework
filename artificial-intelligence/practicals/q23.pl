go:-	nl,write('Enter first list : '), read(L1),
       	   write('Enter second list: '), read(L2),
	   mergeList(L1,L2,M),
	   write('Merged list      : '),write(M), nl.

mergeList([],A,A):-!.
mergeList(A,[],A):-!.

mergeList([H1|T1],[H2|T2],X) :- H1=<H2, mergeList(T1,[H2|T2],Y), append([H1],Y,X),!.

mergeList([H1|T1],[H2|T2],X) :- mergeList([H1|T1],T2,Y), append([H2],Y,X),!.
