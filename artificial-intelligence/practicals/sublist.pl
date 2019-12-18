go:- 
nl,write('Enter a list : '), read(L1),
nl,write('Enter the sublist to be searched : '), read(L2),
sub_list(L2,L1). 

sub_list(S,L):- append(L1,L2,L) ,
		append(S,L3,L2).
		
/*
checking sub-list of a list. 
(in exact order) check presence & continuity.
returns true if sublist is present in continuous order.
returns false if sublist is present without-order.
*/