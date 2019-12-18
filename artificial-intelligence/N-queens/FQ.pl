solution([]).

solution([X/Y | Others]) :-	solution(Others),
				member(Y, [1, 2, 3,4]),
				noattack(X/Y, Others).


noattack(X/Y, []).

noattack( X/Y,[X1/Y1 | Others]) :-	Y 	=\= 	Y1,
					/* shouldn't be in same column */
					/* shouldn't be in same row - ensured by our solve functor */
					Y1 - Y 	=\= 	X1 - X,
					Y1 - Y 	=\= 	X - X1,
					/* shouldnt be in +ve and -ve diagonal */
					/* a diagonal exists when row and column difference is same */
					noattack(X/Y, Others).




nqueen([1/Y1, 2/Y2, 3/Y3, 4/Y4]):- solution([1/Y1, 2/Y2, 3/Y3, 4/Y4]).



/*
run by using

solve(S).
*/

