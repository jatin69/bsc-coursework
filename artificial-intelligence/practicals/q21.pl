go:-  nl,write('Enter Number  : '), read(Num),
 	 write('Enter Power   : '), read(Pow),
 	 power(Num,Pow,Ans),nl,
         write(Num),write(' raised to power '),write(Pow),write(' is : '),
         write(Ans).

power(_,0,1):-!.
power(X,1,X):-!.
power(X,Y,Res):- N is Y-1, power(X,N,R), Res is R*X.



