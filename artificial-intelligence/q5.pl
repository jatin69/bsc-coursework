go:-
 nl,write('Enter number : '),
 read(N),nl,
 forLoop(1,N),nl.


forLoop(I,N) :- I=<N,
		fibo(I,Res),
		write(Res),
		write(' '),
		I1 is I+1,
		forLoop(I1,N).

fibo(1,0) :- !.
fibo(2,1) :- !.
fibo(N,T) :- N1 is N-1, N2 is N-2, fibo(N1,R1), fibo(N2,R2), T is R1 + R2.
