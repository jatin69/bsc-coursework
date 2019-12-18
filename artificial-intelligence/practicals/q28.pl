go:- nl,write('Enter starting node : '), read(A),
	write('Enter finishing node: '), read(B),
        route(A,B),nl,
        write('Path exists.'),nl,!.
go:-
    nl,write('No path exists.'),nl.

route(A,B) :- edge(A,B),!.
route(A,B) :- edge(A,X), route(X,B).

edge(p,q).
edge(q,r).
edge(q,s).
edge(s,t).

/*
adjacency matrix will be -


nodes	p	q	r	s	t	
p	1	1	0	0	0
q	0	1	1	1	0
r	0	0	1	0	0
s	0	0	0	1	1
t	0	0	0	0	1

*/
