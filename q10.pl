go:-  nl,write('Enter a list : '),  read(L),
      palindrome(L),nl,!.

go:- write('Not a palindrome.'),nl.

/*rev([X],[X]):-!.
rev([X|T],L) :- rev(T,R), append(R,[X],L).*/

palindrome(L) :- reverse(L,L), write('Palindrome.').
