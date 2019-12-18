go:- 	nl, write('Enter the Tree : '), read(T), nl, 
	write('The Pre-order DFS traversal is  : '),
	preorder(T,R2), write(R2),nl.
	
preorder(nil,[]):-!.
preorder(tr(nil,X,nil),[X]):-!.
preorder(tr(LEFT,R,RIGHT),Res):- preorder(LEFT,LT), preorder(RIGHT,RT),
				 append([R],LT,Temp),
				 append(Temp,RT,Res),!.

/* sample tree : 
   tr(tr(tr(nil,48,tr(nil,49,nil)),50,nil),68,tr(tr(nil,75,nil),77,tr(nil,79,nil))) 
*/
	
