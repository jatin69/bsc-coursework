go:- 	nl, write('*** TREE TRAVERSALS - IN-Order, PRE-Order, POST-Order ***'), nl, nl, 	
	write('Enter the Tree : '), read(T), 
	/* T=tr(tr(tr(nil,48,tr(nil,49,nil)),50,nil),68,tr(tr(nil,75,nil),77,tr(nil,79,nil))), */
	nl, nl,	write('For the Tree   : '), write(T), nl,nl,
	inorder(T,R1),   write('The Inorder traversal is    : '), write(R1),nl,
	preorder(T,R2),  write('The Pre-order traversal is  : '), write(R2),nl,
	postorder(T,R3), write('The Post-order traversal is : '), write(R3),nl.
	
inorder(nil,[]):-!.
inorder(tr(nil,X,nil),[X]):-!.
inorder(tr(LEFT,R,RIGHT),Res):-	inorder(LEFT,LT), inorder(RIGHT,RT),
				append(LT,[R],Temp),
				append(Temp,RT,Res),!.
preorder(nil,[]):-!.
preorder(tr(nil,X,nil),[X]):-!.
preorder(tr(LEFT,R,RIGHT),Res):- preorder(LEFT,LT), preorder(RIGHT,RT),
				 append([R],LT,Temp),
				 append(Temp,RT,Res),!.
postorder(nil,[]):-!.
postorder(tr(nil,X,nil),[X]):-!.
postorder(tr(LEFT,R,RIGHT),Res):- postorder(LEFT,LT), postorder(RIGHT,RT),
				 append(LT,RT,Temp),
				 append(Temp,[R],Res),!.



