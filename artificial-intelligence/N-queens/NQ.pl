/*
N-queens problem solved in GNU Prolog
Usage as: nqueen(X,4).

Assumed that each queen comes in a separate row, we calculate columns for N-queen
*/

nqueen(Solution,N) :-	length(Solution, N),
			/* create a list of N dummy variabiles */
			queen(Solution, N). 		
			/*search for a configuration of N queens */

/* returns a list of integer from K to N included es up2N(1,4,X) X = [1,2,3,4] */
listN(N,N,[N]):-!.
listN(I,N,[I|T]):- I<N, I1 is I+1, listN(I1, N, T).

/* No queens is a solution for any N queens problem. All queens are in a safe position.*/
queen([],_). 

queen([Q|OTHERQ],N) :-	
			/*first, solve the subproblem	*/
			queen(OTHERQ, N), 
			/* we then generate all possible positions for queen Q  */
 			listN(1,N,Candidate_positions_for_queenQ),
			/* we pick one of such position */
			member(Q, Candidate_positions_for_queenQ),	
			/* we check whether the queen Q does not attack other queens*/
			noattack(Q,OTHERQ, 1).


/*if  no queen remains, there is no one left to attack, so we are safe. */
noattack(_,[],_).
noattack(Q,[Q1|OTHERQ],Xdist):-
				/*not on the same column */
				Q =\= Q1, 	
				/* column diff is not equal to diagonal */
				abs(Q1-Q) =\= Xdist,
				/* Check the safety for other queens as well */	
				Xdist1 is Xdist + 1,
				noattack(Q,OTHERQ,Xdist1).
