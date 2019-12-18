go:-
    nl,write('Enter a list: '), read(L), nl,
    write('1. Check even length.'),nl,
    write('2. Check odd length.'),nl,
    write('Enter choice: '), read(C), nl,
    choice(C,L),nl.

choice(1,L) :- evenlength(L).
choice(2,L) :- oddlength(L).

evenlength(L) :-  length(L,X), R is X mod 2, R==0, write('Length is even'),!.
evenlength(_) :-   write('Length is not even').

oddlength(L) :-  length(L,X), R is X mod 2, R==1, write('Length is odd'),!.
oddlength(_) :-   write('Length is not odd').
