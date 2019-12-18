go:-	write('Enter number of disks : '), read(N), nl,
	toh(N).

/* standard algorithm-	move(No_of_disks,src,dest,aux).  */

toh(N):- move(N,left,right,middle).

move(0,_,_,_):-!.

move(1,A,C,_):- inform(A,C),!.

move(N,A,C,B):- M is N-1,
		move(M,A,B,C),
		move(1,A,C,B),
		move(M,B,C,A).

inform(A,C):-	nl,write('Move -> from tower '),write(A),write(' to tower '),write(C),nl.

