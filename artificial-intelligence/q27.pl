go:- nl, write('*** DFS ***'), nl, nl, write('The Tree : '), 
	T=
	t(t(t(nil,48,t(nil,49,nil)),50,nil),68,t(t(nil,75,nil),77,t(nil,79,nil))),
	write(T), nl,nl, write('enter ele   : '), read(R1), dfs(T,R1),write('Element not found !'),!.	
go:- write('Element found !').

dfs(nil,_):-!.
dfs(t(_,Ele,_),Ele):- !,fail.
dfs(t(LEFT,R,RIGHT),Ele):- R\=Ele, dfs(LEFT,Ele), dfs(RIGHT,Ele).


