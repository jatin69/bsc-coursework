go:-
 nl,write('Enter a list    : '),
 read(L),
 write('Enter a subsequence : '),
 read(S),
 is_subsequence(S,L).

is_subsequence([],[_|_]) 	:-!.
is_subsequence([H|T],[H|T1]) 	:- is_subsequence(T,T1),!.
is_subsequence([H|T],[H1|T1]) :- is_subsequence([H|T],T1),!.


/*
Return true for contiguous and non-contiguous match.
*/