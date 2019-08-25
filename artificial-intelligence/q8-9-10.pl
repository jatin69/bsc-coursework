go:-
 nl,nl,write('   Menu'),nl,
 write('1. Append two lists.'),nl,
 write('2. Reverse a list.'),nl,
 write('3. Check whether a list is a palindrome'),nl,
 nl,write('Enter choice : '), read(C),
 choice(C).
 
 choice(1) :-	!,  	nl,write('Enter first list : '),
				read(L1),
				write('Enter second list: '),
				read(L2),
				conc(L1,L2,L),
				write('Appended list    : '),
				write(L).
 
 choice(2) :- !, 		nl,write('Enter a list : '),
				read(L),
				rev(L,R),
				write('Reversed list: '),
				write(R).
 
 choice(3) :- nl,write('Enter a list : '),
		  read(L),
		  palindrome(L),nl,!.
 choice(3) :- !,	write('Not a palindrome.'),nl.
 
 choice(X) :- nl,write('Invalid choice!'), go.
  
conc([],L,L).
conc([X|L1],L2,[X|L3]):- conc(L1,L2,L3).

rev([],[])   :- !.
rev([X],[X]) :- !.
rev([X|T],L) :- rev(T,R), append(R,[X],L).

palindrome(L) :- reverse(L,L),write('Palindrome.').
