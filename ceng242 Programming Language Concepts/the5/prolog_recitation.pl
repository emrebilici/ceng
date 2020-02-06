% METU Department of Computer Engineering
% Spring 2018-19 CENG242 Recitation 2 - Prolog


% === TERMS ===
% Atoms : mary, food, likes etc.
% Numbers : 0, 1, etc.
% Variables : X, Y, etc.
% Structures : hates(mary,food)
hates(mary,food).
father(charles, james).
add_3_and_double(X,Y) :- Y is (X+3)*2.


% === FACTS ===
apple.
car(bmw).
female(mary).
eats(mary, icecream).


% === RULES ===
toy(doll).
toy(train).
plays(ann,train).
likes(ann, X) :- toy(X), plays(ann, X). % ann likes X if X is a toy and ann plays with X.
likes(john, Y) :- likes(ann, Y).	% john likes Y if ann likes Y.


% === ARITHMETIC OPERATORS ===
p1(X, Y) :- X = Y - 1.	% run p1(X, 3).
p2(X, Y) :- X is Y - 1.	% run p2(X, 3).
p3(X, Y) :- X =< Y.		% run p3(2, 3).
p4(X, Y) :- X == Y.		% run p4(4-1, 3).
p5(X, Y) :- X =:= Y.	% run p5(4-1, 3).

% === LOGICAL OPERATORS ===
% a :- b.  			% a if b
% a :- b,c. 		% a if b and c.
% a :- b;c. 		% a if b or c.
% a :- not(b). 		% a if b fails
% a :- b -> c;d. 	% a if (if b then c else d)

student(marry).
person(X) :- student(X).

animal(monkey).
animal(hawk).
flies(hawk).
bird(X) :- animal(X), flies(X).

dead(michaeljackson).
alive(X) :- not(dead(X)).

min(A, B, Min) :- A < B -> Min = A ; Min = B.


% === LISTS ===
size([],0). 									% Acts as the base case in the recursion.
size([_|T],N) :- size(T,N1), N is N1+1.
% size([H|T], X) :- N is N1+1, size(T,N1).		% comment the first and uncomment this one to see the problem
% Note that replacing the first predicate with the second causes instantiation error 
% while evaluating 'is' operator. 'is' expects the right hand side to be instantiated 
% at the time of evaluation (i.e. value of N1 must be known).


% === BACKTRACKING EXAMPLE ===
parent(pam, bob).
parent(tom, bob).
parent(tom, liz).
parent(bob, ann).
parent(bob, pat).
parent(pat, jim).
predecessor(X, Y) :- parent(X, Y).
predecessor(X, Z) :- parent(X, Y), predecessor(Y, Z).
% Order of clauses and goals is important. The following predicate definition results in infinite recursion. (local stack overflow)
% predecessor(X, Z) :- predecessor(Y, Z), parent(X, Y).
% predecessor(X, Y) :- parent(X, Y).

% Running the goal; predecessor(tom, pat).
% - The rule that appears first, is applied first. Unifying: {tom/X} , {pat/Z}.
% - The goal is replaced by parent(tom, pat).
% - No fact is present for parent(tom, pat).
% - Next rule is applied. Unifying: {tom/X} , {pat/Z}.
% - New goal : parent(tom, Y), predecessor(Y, pat).
% - The first one matches one of the facts {bob/Y}.
% - Second sub-goal: predecessor(bob, pat).
% - Applying the first rule. Unifying: {bob/X} , {pat/Z}.
% - The goal is replaced by parent(bob, pat).
% - The fact parent(bob, pat) is present.
% - Prolog returns.


% === CUTS ===
% if p holds then r implies g, and if ¬p holds then t implies g.
g :- p,!,r.
g :- t.

% In the presence of backtracking, incorrect answers can result.
% max(A, B, B) :- A < B.
% max(A, B, A).

% To prevent backtracking to the second rule the cut symbol is inserted into the first rule.
max(A, B, B) :- A < B, !.
max(A, B, A).

% Don’t try other choices of red and color if X satisfies red
red(car).
red(bird).
red(pen).
color(X, red) :- red(X), !.