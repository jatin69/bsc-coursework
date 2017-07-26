go:- nl,write('Enter a list : '), read(L),
	 write('Enter element: '),  read(E),
	 myMember(E,L),!.

go:- nl,write('Element not found.').

/* 
 * or,
 *
 * myMember(E,L);
 * nl,write('Element not found.').
 *
 */

myMember(X,[X|_]) :- nl,write('Element found.').
/* 
 * if the element to be found is same as the head.
 * myMember(X,[X|T]), T occurs once, singleton variable,
 * use anonymous variable.
 * myMember(X,[X|_]). for one occurence. 
 */

myMember(X,[_|T]) :- myMember(X,T).	
/* 
 * if the element exists in the tail.
 * myMember(X,[H|T]) :- myMember(X,T).
 * H occurs once, use anonymous variable.
 */
