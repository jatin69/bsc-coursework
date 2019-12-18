% Figure 2.14   A program for the monkey and banana problem.

% move( State1, Move, State2): making Move in State1 results in State2;
%    a state is represented by a term:
%    state( MonkeyHorizontal, MonkeyVertical, BoxPosition, HasBanana)

move( state( middle, onbox, middle, hasnot),   % Before move
      grasp,                                   % Grasp banana
      state( middle, onbox, middle, has) ).    % After move 

move( state( P, onfloor, P, H),
      climb,                                   % Climb box
      state( P, onbox, P, H) ). 

move( state( P1, onfloor, P1, H),
      push( P1, P2),                           % Push box from P1 to P2
      state( P2, onfloor, P2, H) ). 

move( state( P1, onfloor, B, H),
      walk( P1, P2),                           % Walk from P1 to P2
      state( P2, onfloor, B, H) ).                   

% canget( State): monkey can get banana in State

canget( state( _, _, _, has) ).       % can 1: Monkey already has it 

canget( State1)  :-                   % can 2: Do some work to get it
  move( State1, Move, State2),        % Do something
  canget( State2).                    % Get it now
 

