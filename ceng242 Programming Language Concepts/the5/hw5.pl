:- module(hw5 , [catomic_number/2, ion/2, molecule/2]).
:- [catoms].


% helper(NAME,[], 0).
% helper(NAME,[_|T], N) :- catom(NAME,_ ,_, [_|T]).
% helper(NAME,[_|T], N)

size([],0).
size([_|T],N) :- size(T,N1), N is N1+1.


helper1(X,Y):- X > 4 -> Y is X-8; Y is X.

my_last(X,[X]):- !.
% my_last(X,[X]):- my_last(X,[X]),helper1(X,Y) !.
my_last(X,[_|L]):-my_last(X,L).

sum_list([], 0).
sum_list([H|R], S) :-
   sum_list(R, Rest),
   S is H + Rest.

% catomic_number(NAME,CATOMIC_NUMBER)
% catomic_number(NAME,0).
 catomic_number(NAME,CATOMIC_NUMBER) :- catom(NAME,_,_, [H|L]), sum_list([H|L], CATOMIC_NUMBER). 


ion(NAME,CHARGE):- catom(NAME,_,_,[_|L]), my_last(Y,[_|L]), helper1(Y,CHARGE).

add(A,B,[A|B]).
add_list([],L,L).
add_list([H|T],L1,L):- add(H,L2,L),add_list(T,L1,L2).

% molecule(CATOM_LIST, TOTAL_CATOMIC_NUMBER).
% molecule([], T).



sum_catom(0,[]).
sum_catom(Total,[H|R]) :-  
	catomic_number(H,C1), 
	sum_catom(Rest,R), 
	Total is Rest + C1.

% all catoms in list
% allcatom([]).
allcatom(L) :- findall(H,catom(H,_,_,_),L).

mysubset([], []).
mysubset([E|T], [E|T1]):- mysubset(T, T1).
mysubset([_|T], L):- mysubset(T, L).

subsetofcatoms(S):- allcatom(L),mysubset(L,S).

molecule(Result, TotalCat) :- allcatom(L),getsub(L,Result,TotalCat) .

% burasi baska kod

        getsub([],[], _).
        getsub(L,X, TotalSum):- 
                mysubset(L,N),
                check(N, X, TotalSum).


	getsub2([],[],_).
	getsub2(L,Rez,Total):- 
checksum([],_).
checksum(H,S):- sum_catom(S,H).
  
	%findall(LR,mysubset(L,LR,X)),
	%check(X,Rez,TotalSum).
             %   findall(LR, subsetofcatoms(LR), N),
	%	catomic_number(N,X),
         %       check(X, Rez, S).

% checks if each sublist of a given list of lists, has the sum of elements S
check([], [], _).
% the LR variable here gives a warning after entering the goal
check([H|T], LR, S):- 
    sum_catom(S, [H]),
    !, check(T, LR, S).
%check([_|T], LR, S):-
 %   check(T, LR, S).









