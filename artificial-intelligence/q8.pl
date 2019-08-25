go:-  nl,write('Enter first list : '), read(L1),
         write('Enter second list: '), read(L2),
         conc(L1,L2,L),
         write('Appended list    : '), write(L).

conc([],L,L).
conc([X|L1],L2,[X|L3]):- conc(L1,L2,L3).
