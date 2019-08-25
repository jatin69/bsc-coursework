go:- 
	write('Enter a number : '), read(N),
	factorial(N,Res), nl,
	write('Factorial is : '),
	write(Res).

factorial(0,1):-!.
factorial(N,Fact):-	N>0, N1 is N-1, factorial(N1,F1), Fact is N*F1.

