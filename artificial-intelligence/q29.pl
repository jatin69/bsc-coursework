utter(X):-sentence(X,[]).

sentence(Start,End):- nounphase(Start, Rest), verbphase(Rest,End).

nounphase([Noun|End],End):-noun(Noun),!.
nounphase([Article,Noun|End],End):- article(Article),noun(Noun).

verbphase([Verb|End],End):-verb(Verb),!.
verbphase([Verb|Rest],End):-verb(Verb), nounphase(Rest,End).

article(a).
article(the).
noun(man).
noun(dog).
verb(likes).
verb(bites).
