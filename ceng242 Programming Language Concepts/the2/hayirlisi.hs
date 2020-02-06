module Hw2 where

data ASTResult = ASTError String | ASTJust (String, String, Int) deriving (Show, Read)
data ASTDatum = ASTSimpleDatum String | ASTLetDatum String deriving (Show, Read)
data AST = EmptyAST | ASTNode ASTDatum AST AST deriving (Show, Read)

isNumber :: String -> Bool

eagerEvaluation :: AST -> ASTResult

normalEvaluation :: AST -> ASTResult

-- DO NOT MODIFY OR DELETE THE LINES ABOVE -- 
-- IMPLEMENT isNumber, eagerEvaluation and normalEvaluation FUNCTIONS ACCORDING TO GIVEN SIGNATURES -- 

-- sayi iceriyorsa false donuyor --
-- bos olunca donemedim--
-- bir helper yap bunları. boslugu o an kontrol etsin.
isNumber [] = False
isNumber (x:xs)
 | x == '-' && xs== [] = False 
 | x =='-' = isNumber1 (xs)
 | otherwise = isNumber1 (x:xs)

isNumber1 :: String -> Bool
isNumber1 [] = True
isNumber1 (x:xs)
 | x /= '0' && x /= '1' &&  x /= '2' && x /= '3' && x /= '4' && x /= '5' && x /= '6' && x /= '7' && x /= '8' && x /= '9' = False
 | otherwise = isNumber1 xs


numControl1 :: AST -> String
numControl1 EmptyAST =  "boyle bir sey olamaz"
numControl1 (ASTNode (ASTSimpleDatum b) c d)
	| show(c) == show(EmptyAST) && show(d) == show(EmptyAST) && not(isNumber(b)) =("the value \'" ++ b ++ "\' is not a number!")
	| otherwise = b

numControl2 :: AST -> String
numControl2 EmptyAST =  ""
numControl2 (ASTNode (ASTSimpleDatum b) c d)
	| not(isNumber(b)) = ("the value \'" ++ b ++ "\' is not a number!")
	| otherwise = ""


child:: AST -> String
child EmptyAST = ""
child (ASTNode (ASTSimpleDatum b) c d) = b
child (ASTNode (ASTLetDatum b) c d) = b

eagerEvaluation EmptyAST = ASTJust ("", "", 0) 
eagerEvaluation (ASTNode b c d)
 | check (ASTNode b c d) == "" && (child (ASTNode b c d)=="plus" || child (ASTNode b c d)== "times" || child (ASTNode b c d) == "negate" || child (ASTNode b c d) =="num" || simpleorlet b == "let")= ASTJust (helper(ASTNode b c d))
 | check (ASTNode b c d) == "" && (child (ASTNode b c d)=="cat" || child (ASTNode b c d)== "len" || child (ASTNode b c d) == "str" ||   simpleorlet b == "let")= ASTJust (helper(ASTNode b c d))
 | otherwise = ASTError (check (ASTNode b c d))


normalEvaluation EmptyAST = ASTJust ("", "", 0) 
normalEvaluation (ASTNode (ASTSimpleDatum b) c d)
 | check (ASTNode (ASTSimpleDatum b) c d) == "" = ASTJust (helper(ASTNode (ASTSimpleDatum b) c d), b, 0)
 | otherwise = ASTError (check (ASTNode (ASTSimpleDatum b) c d))

check :: AST -> String
check EmptyAST = ""
check (ASTNode b c d)
 | child (ASTNode b c d) == "num" = numControl2 c
 | child (ASTNode b c d) == "plus" && (check c == "" && check d == "")  && (child c == "cat" || child d == "cat" || child c == "str" || child d == "str") = ("plus operation is not defined between " ++ child c ++ " and " ++ child d++ "!")
 | child (ASTNode b c d) == "times" && (check c == "" && check d == "") && (child c == "cat" || child d == "cat" || child c == "str" || child d == "str") = ("times operation is not defined between " ++ child c ++ " and " ++ child d++ "!")
 | child (ASTNode b c d) == "negate" && (check c == "") && (child c == "cat" || child c == "str" ) = ("negate operation is not defined on " ++ child c++ "!" )
 | child (ASTNode b c d) == "cat" && (check c == "" && check d == "") && (child c == "len" || child c == "num" || child c == "negate" ||  child c == "times" || child c == "plus" || child d == "len" || child d == "num" || child d == "times" || child d == "plus" || child d == "negate" ) = ("cat operation is not defined between " ++ child c ++ " and " ++ child d ++ "!")
 | child (ASTNode b c d) == "len" && (check c == "") && (child c == "len" || child c == "num" || child c == "negate" ||  child c == "times" || child c == "plus" || child d == "len" || child d == "num" || child d == "times" || child d == "plus" || child d == "negate" || child c == "len" || child d == "len" ) = ("len operation is not defined on " ++ child c ++ "!")
 | otherwise = check c ++ check d  

letorsimple:: AST -> String
letorsimple EmptyAST = ""
letorsimple (ASTNode (ASTSimpleDatum b) c d) = "simple"
letorsimple (ASTNode (ASTLetDatum b) c d)  = "let"


first :: (a, b) -> a  
first (x, _) = x  
  
second :: (a, b) -> b  
second (_, y) = y  
  

helper :: (AST, [Int]) -> (String, Int) 
helper (EmptyAST) = ("", "", 0)
helper ((ASTNode b c d),(ys))
 | letorsimple (ASTNode b c d) == "let" = helper(iflet(ASTNode b c d), ys)
 | child (ASTNode b c d) == "plus"  = (show(first (ifPlus (c, length(1:ys))) + first (ifPlus (d, length(1:ys)))), length(ys) )
 | child (ASTNode b c d) == "cat"   =  (first(ifLength (c, length(1:ys))) ++ first(ifLength (d, length(1:ys))) , length(ys))
 | child (ASTNode b c d) == "times" = (show(first(ifPlus (c, length(1:ys))) * first(ifPlus (d, length(1:ys)))), length(ys))
 | child (ASTNode b c d) == "len" = (show(length (first(ifLength (c, length(1:ys))))), length(ys))
 | child (ASTNode b c d) == "negate" = (show(negate(first(ifPlus (c, length(1:ys))))), length(ys))
 | child (ASTNode b c d) == "num" = (numControl1 (c) , length(ys))
 | child (ASTNode b c d) == "str" = (first(ifLength (c, length(ys))), length(ys))
 | (show c == show EmptyAST) && (show d == show EmptyAST) = (child (ASTNode b c d), length ys )  --gereksiz



ifPlus :: (AST, [Int]) -> (Int, Int)
ifPlus (EmptyAST) = 0
ifPlus (ASTNode b c d)
 | letorsimple (ASTNode b c d) == "let" = ifPlus (iflet(ASTNode b c d))
 | child (ASTNode b c d) == "num" && isNumber(numControl1 (c))= ifNum (c)
 | child (ASTNode b c d) == "negate" = negate (ifPlus c)
 | child (ASTNode b c d) == "len" = length (ifLength c)
 | child (ASTNode b c d) == "plus" = ifPlus c + ifPlus d
 | child (ASTNode b c d) == "times" = ifPlus c * ifPlus d
 | (show c == show EmptyAST) && (show d == show EmptyAST) = read(child (ASTNode b c d))::Int -- bu gereksiz sil bunu


ifNum :: (AST) -> Int
ifNum (ASTNode (ASTSimpleDatum b) c d) = read (b):: Int

ifLength :: (AST) -> String
ifLength (EmptyAST) = ""
ifLength (ASTNode b c d) 
 | letorsimple (ASTNode b c d) == "let" = ifLength(iflet(ASTNode b c d)) 
 | child (ASTNode b c d) == "str" = ifLength (c)
 | child (ASTNode b c d) == "cat" = ifLength (c) ++ ifLength (d)
 | (show c == show EmptyAST) && (show d == show EmptyAST) = child (ASTNode b c d) 



iflet:: AST -> AST
iflet EmptyAST = EmptyAST
iflet (ASTNode (ASTLetDatum b) c d)
 | child c == "plus"  || child c == "times" || child c == "len"|| child c == "negate" || child c =="num" = printB(d,b,helper(c),"num")
 | child c == "cat"  || child c == "str"  = printB(d,b,helper(c),"str")
 | otherwise = EmptyAST




printB :: (AST, String,String,String)-> AST
printB (EmptyAST,_,_,_) = EmptyAST
printB ((ASTNode b c d), x, y,h) 
 | simpleorlet(b) == "let" && child (ASTNode b c d) ==  x = iflet (ASTNode b c d)
 | simpleorlet(b) == "let"  = ASTNode b (printB(c,x,y,h)) (printB(d,x,y,h)) --iflet (ASTNode b c d)
 | child (ASTNode b c d) ==  x  = ASTNode (ASTSimpleDatum h) (ASTNode (ASTSimpleDatum y) EmptyAST EmptyAST) EmptyAST
 | child (ASTNode b c d) == "plus" = ASTNode b (printB(c,x,y,h)) (printB(d,x,y,h))
 | child (ASTNode b c d) == "times" = ASTNode b (printB(c,x,y,h )) (printB(d,x,y,h ))
 | child (ASTNode b c d) == "negate" = ASTNode b (printB(c,x,y,h )) EmptyAST
 | child (ASTNode b c d) == "cat" = ASTNode b (printB(c, x,y,h)) (printB(d, x,y,h))
 | child (ASTNode b c d) == "len" = ASTNode b (printB(c, x,y,h)) EmptyAST
 | child (ASTNode b c d) == "num" = ASTNode b c d
 | child (ASTNode b c d) == "str" = ASTNode b c d
 | otherwise = ASTNode b (printB(c, x,y,h)) (printB(d, x,y,h))



simpleorlet:: ASTDatum -> String
simpleorlet (ASTSimpleDatum b) = "simple"
simpleorlet (ASTLetDatum b)  = "let"

