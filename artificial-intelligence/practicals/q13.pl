go:- nl,write('Enter list: '), read(L),nl,
    write('List with duplicates removed:'),nl,
    removeDup(L,R),write(R),nl.

removeDup([],[]):-!.
/* If Head exists in Tail as well, its a duplicate, 
   leave it and continue with rest of the list.
*/
removeDup([H|T],L):- member(H,T),
		     removeDup(T,L),!.
/* Else, If Head does not exists in Tail, its not a duplicate, 
   it should be present in Resultant list.
*/removeDup([H|T1],[H|T2]):-  removeDup(T1,T2).
