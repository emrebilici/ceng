module Hw1 where

type Mapping = [(String, String, String)]
data AST = EmptyAST | ASTNode String AST AST deriving (Show, Read)

writeExpression :: (AST, Mapping) -> String
evaluateAST :: (AST, Mapping) -> (AST, String)
-- DO NOT MODIFY OR DELETE THE LINES ABOVE -- 
-- IMPLEMENT writeExpression and evaluateAST FUNCTION ACCORDING TO GIVEN SIGNATURES --
forLet [] = ""
forLet (x:xs)
 | xs == [] && second x == "num" = first x ++ "="   ++ third x  
 | xs == [] && second x == "str" = first x ++ "=" ++ "\"" ++ third x ++  "\"" 
 | second x == "str" =  first x  ++ "=" ++ "\"" ++ third x ++  "\"" ++ ";"++ forLet (xs)
 | second x == "num" =  first x ++ "=" ++third x ++ ";"++ forLet (xs)
 | otherwise =   first x ++ "=" ++   "\"" ++ third x ++  "\"" 


writeExpression ( ASTNode b c d , e ) 
            | e == [] = printA (ASTNode b c d) 
            | otherwise = "let "  ++ forLet e ++ " in " ++ printA (ASTNode b c d)

{-
--junk--
writeExpression1 ( ASTNode b c d , e ) 
            | show c == show EmptyAST && show d == show EmptyAST =  "(" ++  b 
            | show c /= show EmptyAST = "       bu   c     " ++ b ++ writeExpression (c,e) ++ ")"   
            | show d /= show EmptyAST =  "       bu   d      "  ++ b ++writeExpression (d,e) ++ ")"
-- --
-}
printA :: (AST)-> String
printA (EmptyAST) = ""
printA (ASTNode b c d) 
 | b == "plus" 	 = "(" ++ printA c ++ "+" ++ printA d  ++ ")"
 | b == "times"  = "(" ++ printA c ++ "*"  ++ printA d ++ ")"
 | b == "cat"  	 = "(" ++ printA c ++  "++" ++ printA d ++ ")"
 | b == "len"  	 = "(" ++ "length "  ++ printA c  ++ ")"
 | b == "negate" = "(" ++ "-"  ++ printA c ++ ")"
 | b == "num" = printA c  ++ printA d
 | b == "str" = "\"" ++  printA c  ++ "\"" ++  printA d
 | show c == show EmptyAST && show d == show EmptyAST =  b 
 | otherwise = printA c ++ b ++ printA d


first :: (a, b, c) -> a  
first (x, _, _) = x  
  
second :: (a, b, c) -> b  
second (_, y, _) = y  
  
third :: (a, b, c) -> c  
third (_, _, z) = z 



{-
evA :: (AST)-> String 
evA (EmptyAST) = ""
evA (ASTNode b c d) 
 | b == "plus" 	 = evA c ++ evA d 
 | b == "times"  = evA c ++ evA d 
 | b == "cat"  	 = evA c ++ evA d 
 | b == "len"  	 = evA c
 | b == "negate" = evA c
 | b == "num"	 = evA c  ++ evA d
 | b == "str" 	 =  evA c  ++  evA d
 | show c == show EmptyAST && show d == show EmptyAST =   b 
 | otherwise	 = evA c ++ show b ++ evA d


evB :: (AST) -> String
evB (EmptyAST) = ""
evB (ASTNode b c d) 
 | b == "plus" = helper c ++ helper d
 | b == "num"	 = evB c  ++ evB d
 | show c == show EmptyAST && show d == show EmptyAST =   b 
 | otherwise	 = b
-}


--- olay burada basliyor--- sadece sonuc basiyor

evaluateAST (a, b) 
 | b == [] = (a, helper(a)) 
 | otherwise = (a, helper(a)) -- helperi cagıracaksın ama icine farklı bir ast gondereceksin cunku islem yapiliyo

helper :: (AST) -> String
helper (EmptyAST) = []
helper (ASTNode b c d)
 |  b == "plus"	 = show(ifPlus c + ifPlus d )
 |  b == "cat" =  ifLength c ++ ifLength d 
 |  b == "times" = show(ifPlus c * ifPlus d)
 |  b == "len" = show(length (ifLength c))
 |  b == "negate" = show(ifPlus c)
 |  b == "num" = show (ifNum c)
 |  b == "str" = ifLength c
 |  show c == show EmptyAST && show d == show EmptyAST = b   --gereksiz

ifPlus :: (AST) -> Int
ifPlus (EmptyAST) = 0
ifPlus (ASTNode b c d) 
 | b == "num" = ifNum c
 | b == "negate" = negate (ifPlus c)
 | b == "len" = length (ifLength c)
 | b == "plus" = ifPlus c + ifPlus d
 | b == "times" = ifPlus c * ifPlus d
 | show c == show EmptyAST && show d == show EmptyAST = read(b)::Int -- bu gereksiz sil bunu


ifNum :: (AST) -> Int
ifNum (ASTNode b c d) = read (b):: Int

ifLength :: (AST) -> String
ifLength (EmptyAST) = ""
ifLength (ASTNode b c d) 
 | b == "str" = ifLength (c)
 | b == "cat" = ifLength (c) ++ ifLength (d)
 | show c == show EmptyAST && show d == show EmptyAST = b


checkL [] = ""
checkL (x:xs)
 | xs == [] = first x  
 | otherwise = checkL xs

change [] = ""
change (x:xs)
 | xs == [] = third x
 | otherwise = change xs

printB :: (AST, Mapping)-> AST
printB (EmptyAST,[]) = EmptyAST
printB (ASTNode b c d, (x:xs)) 
 | b == (first x) = ASTNode (second x) (ASTNode (third x) EmptyAST EmptyAST) EmptyAST
 | show c ==  show EmptyAST && show d == show EmptyAST = ASTNode b c d
 | otherwise = printB (c,(x:xs))

