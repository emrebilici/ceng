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
 | check (ASTNode b c d) == "" && (child (ASTNode b c d)=="plus" || child (ASTNode b c d)== "times" || child (ASTNode b c d) == "negate" || child (ASTNode b c d) =="num" || simpleorlet b == "let")= ASTJust (first(helper((ASTNode b c d), 0)), "num", second(helper((ASTNode b c d), 0)))
 | check (ASTNode b c d) == "" && (child (ASTNode b c d)=="cat" || child (ASTNode b c d)== "len" || child (ASTNode b c d) == "str" ||   simpleorlet b == "let")= ASTJust (first(helper((ASTNode b c d), 0)), "str", second(helper((ASTNode b c d), 0)))
 | otherwise = ASTError (check (ASTNode b c d))

normalEvaluation EmptyAST = ASTJust ("", "", 0) 
normalEvaluation (ASTNode b c d)
 | check (ASTNode b c d) == "" && (child (ASTNode b c d)=="plus" || child (ASTNode b c d)== "times" || child (ASTNode b c d) == "negate" || child (ASTNode b c d) =="num" || simpleorlet b == "let")= ASTJust (first(helper((ASTNode b c d), 0)), "num", second(helper((ASTNode b c d), 0)))
 | check (ASTNode b c d) == "" && (child (ASTNode b c d)=="cat" || child (ASTNode b c d)== "len" || child (ASTNode b c d) == "str" ||   simpleorlet b == "let")= ASTJust (first(helper((ASTNode b c d), 0)), "str", second(helper((ASTNode b c d), 0)))
 | otherwise = ASTError (check (ASTNode b c d))

{-
normalEvaluation EmptyAST = ASTJust ("", "", 0) 
normalEvaluation (ASTNode (ASTSimpleDatum b) c d)
 | check (ASTNode (ASTSimpleDatum b) c d) == "" = ASTJust (helper(ASTNode (ASTSimpleDatum b) c d), b, 0)
 | otherwise = ASTError (check (ASTNode (ASTSimpleDatum b) c d))
-}

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
  

helper :: (AST, Int) -> (String, Int) 
helper (EmptyAST, z) = ("", z)
helper ((ASTNode b c d),z)
 | letorsimple (ASTNode b c d) == "let" = helper(first(iflet((ASTNode b c d),z)), second(iflet((ASTNode b c d),z)))
 | child (ASTNode b c d) == "plus"  = (show(first(ifPlus(c, inc z )) + first(ifPlus (d, inc z))), second(ifPlus(c, inc z )) + second(ifPlus (d, inc z))) 
 | child (ASTNode b c d) == "cat"   =  (first(ifLength (c, inc z )) ++ first(ifLength (d, inc z )) , second(ifLength(c, inc z )) + second(ifLength (d, inc z)))
 | child (ASTNode b c d) == "times" = (show(first(ifPlus(c, inc z )) * first(ifPlus (d, inc z))), second(ifPlus(c, inc z )) + second(ifPlus (d, inc z))) 
 | child (ASTNode b c d) == "len" = (first(ifLength (c, inc z )) ++ first(ifLength (d, inc z )) , second(ifLength(c, inc z )) + second(ifLength (d, inc z)))
 | child (ASTNode b c d) == "negate" = (show(first(ifPlus(c, inc z )) + first(ifPlus (d, inc z))), second(ifPlus(c, inc z )) + second(ifPlus (d, inc z))) 
 | child (ASTNode b c d) == "num" = (numControl1 (c) , z)
 | child (ASTNode b c d) == "str" = (first(ifLength (c, z)), z)
 | (show c == show EmptyAST) && (show d == show EmptyAST) = (child (ASTNode b c d), z )  --gereksiz



ifPlus :: (AST, Int) -> (Int, Int)
ifPlus (EmptyAST, z) = (0,z)
ifPlus ((ASTNode b c d), z)
 | letorsimple (ASTNode b c d) == "let" = (first(ifPlus(first(iflet((ASTNode b c d), z)),second(iflet((ASTNode b c d), z)))),second(iflet((ASTNode b c d),z)))
 | child (ASTNode b c d) == "num" && isNumber(numControl1 (c))= (ifNum (c),z)
 | child (ASTNode b c d) == "negate" = (negate (first(ifPlus (c , inc z))),second(ifPlus (c , inc z)) )
 | child (ASTNode b c d) == "len" = (length (first(ifLength (c, inc z))),second(ifLength (c , inc z)) )
 | child (ASTNode b c d) == "plus" = (first(ifPlus(c, inc z )) + first(ifPlus (d, inc z)), second(ifPlus(c, inc z )) + second(ifPlus (d, inc z)))
 | child (ASTNode b c d) == "times" = (first(ifPlus(c, inc z )) * first(ifPlus (d, inc z)), second(ifPlus(c, inc z )) + second(ifPlus (d, inc z)))
 | (show c == show EmptyAST) && (show d == show EmptyAST) = (read(child (ASTNode b c d))::Int, z ) -- bu gereksiz sil bunu


ifNum :: (AST) -> Int
ifNum (ASTNode (ASTSimpleDatum b) c d) = read (b):: Int

ifLength :: (AST, Int) -> (String, Int)
ifLength (EmptyAST, z) = ("",z)
ifLength ((ASTNode b c d) ,z)
 | letorsimple (ASTNode b c d) == "let" = (first(ifLength(first(iflet((ASTNode b c d),z)),z)) ,z)
 | child (ASTNode b c d) == "str" = (first(ifLength (c, z)),z)
 | child (ASTNode b c d) == "cat" = (first(ifLength (c , inc z)) ++ first(ifLength (d, inc z)), second(ifLength(c, inc z )) + second(ifLength (d, inc z)))
 | (show c == show EmptyAST) && (show d == show EmptyAST) = (child (ASTNode b c d),z )



iflet:: (AST, Int) -> (AST,Int)
iflet (EmptyAST,z)  = (EmptyAST,z)
iflet ((ASTNode (ASTLetDatum b) c d),z)
 | child c == "plus"  || child c == "times" || child c == "len"|| child c == "negate" || child c =="num" = (first(printB(d,b,first(helper(c, z)),"num",z)),second(printB(d,b,first(helper(c, z)),"num",z)))
 | child c == "cat"  || child c == "str"  = (first(printB(d,b,first(helper(c, z)),"str",z)),second(printB(d,b,first(helper(c, z)),"str",z)))
 | otherwise = (EmptyAST,z)

--printB için bir parametre daha tanımla 


printB :: (AST, String,String,String,Int)-> (AST,Int)
printB (EmptyAST,_,_,_,z) = (EmptyAST,z)
printB ((ASTNode b c d), x, y,h,z) 
 | simpleorlet(b) == "let" && child (ASTNode b c d) ==  x = (first(iflet ((ASTNode b c d),z)), z)
 | simpleorlet(b) == "let"  = ((ASTNode b (first(printB(c,x,y,h, z))) (first(printB(d,x,y,h,  z)))),z) --iflet (ASTNode b c d)
 | child (ASTNode b c d) ==  x  = ((ASTNode (ASTSimpleDatum h) (ASTNode (ASTSimpleDatum y) EmptyAST EmptyAST) EmptyAST),z)
 | child (ASTNode b c d) == "plus" = ((ASTNode b (first(printB(c,x,y,h,inc z))) (first(printB(d,x,y,h, inc z)))),inc z)
 | child (ASTNode b c d) == "times" = ((ASTNode b (first(printB(c,x,y,h , inc z))) (first(printB(d,x,y,h,inc z )))),inc z)
 | child (ASTNode b c d) == "negate" = ((ASTNode b (first(printB(c,x,y,h, inc z ))) EmptyAST),inc z)
 | child (ASTNode b c d) == "cat" = ((ASTNode b (first(printB(c, x,y,h, inc z))) (first(printB(d, x,y,h, inc z)))),inc z)
 | child (ASTNode b c d) == "len" = ((ASTNode b (first(printB(c, x,y,h, inc z))) EmptyAST),inc z)
 | child (ASTNode b c d) == "num" = ((ASTNode b c d),z)
 | child (ASTNode b c d) == "str" = ((ASTNode b c d),z)
 | otherwise = ((ASTNode b (first(printB(c, x,y,h, z))) (first(printB(d, x,y,h, z)))),z)



simpleorlet:: ASTDatum -> String
simpleorlet (ASTSimpleDatum b) = "simple"
simpleorlet (ASTLetDatum b)  = "let"


inc :: Int -> Int
inc 0 = 1
inc x = (x + 1)