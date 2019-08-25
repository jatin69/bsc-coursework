speaks(bob,russian).
speaks(mary,russian).
speaks(mary,english).
speaks(john,english).

understands(P1,P2):- speaks(P1,X), speaks(P2,X), P1\=P2.
