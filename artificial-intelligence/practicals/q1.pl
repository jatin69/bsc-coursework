father(edward,albert).
father(albert,john).
father(albert,bob).
father(albert,mary).
father(albert,jasmine).
father(albert,mahsa).
father(bob,harry).
father(john,arun).
mother(asha,victoria).
mother(victoria,john).
mother(victoria,bob).
mother(victoria,jasmine).
mother(victoria,mary).
mother(victoria,mahsa).
mother(jasmine,pooja).
mother(mary,simi).
female(asha).
female(victoria).
female(mary).
female(mahsa).
female(jasmine).
female(pooja).
female(simi).
male(edward).
male(albert).
male(john).
male(bob).
male(arun).
male(harry).

is_father(X):-male(X),
		father(X,_),!.

is_mother(X):-female(X),
		mother(X,_),!.

is_son(X):-male(X), 
		father(_,X),!.

is_son(X):-male(X),
		mother(_,X),!.

sibling(X,Y):-father(X1,X),
		father(X1,Y),
		mother(X2,X),
		mother(X2,Y).

brother_of(X,Y):-male(X),
		sibling(X,Y).

sister_of(X,Y):-female(X),
		sibling(X,Y).

grandpa_of(X,Y):-father(X1,X),
		father(X1,Y).

grandson(X,Y):-male(X),
		father(X1,X),
		father(Y,X1),!.

grandson(X,Y):-male(X),
		mother(X1,X),
		mother(Y,X1).

first_cousin(X,Y):-father(X1,X),
		father(X2,Y),
		brother_of(X1,X2),X\=Y,!.

first_cousin(X,Y):-mother(X1,X),
		mother(X2,Y),
		sister_of(X1,X2),X\=Y,!.

first_cousin(X,Y):-father(X1,X),
		mother(X2,Y),
		sibling(X1,X2),X\=Y,!.

first_cousin(X,Y):-mother(X1,X),
		father(X2,Y),
		sibling(X1,X2),X\=Y.

descendent(X,Y):-father(Y,X),!.
descendent(X,Y):-father(Y1,X),
		descendent(Y1,Y).

/*
Goal: is_father(edward).
Yes
Goal: is_father(arun).
No
Goal: is_mother(victoria).
Yes
Goal: is_mother(simi).
No
Goal: is_son(john).
Yes
*/


