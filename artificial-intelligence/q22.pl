go:-  nl,write('Enter first number : '), read(N1),
	 write('Enter second number: '), read(N2),
 	 multiply(N1,N2,R),
 	 write('Product            : '), write(R).

multiply(X,0,0):-!.
multiply(X,1,X):-!.
multiply(X,Y,Res):- N is Y-1, multiply(X,N,R), Res is R+X.
