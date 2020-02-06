-- Use GHCi for testing and debuging your programs

-- GHCi commands
-- :load 
-- :reload
-- :? (see list of available commands)
-- :t (examine types of functions and variables)

-- Resources you may refer while learning Haskelll
-- http://learnyouahaskell.com/chapters
-- haskell.org
-- Check Haskell tutorials pointed in http://www.ceng.metu.edu.tr/ceng242


-- Variable declarations
a = 5
b = [1, 2, 3]


-- Functions
-- Syntax:
-- <function name> [<param1> <param2> …] = <result>
square :: Int -> Int
square x = x * x

add :: Int -> Int -> Int
add x y = x + y

addThree :: Int -> Int -> Int -> Int
addThree x y z = x + y + z


--Pattern Matching
lucky :: (Integral a) => a -> String
lucky 7 = "LUCKY NUMBER SEVEN!"
lucky x = "Sorry, you're out of luck, pal!"

sayMe :: (Integral a) => a -> String
sayMe 1 = "One!"
sayMe 2 = "Two!"
sayMe 3 = "Three!"
sayMe 4 = "Four!"
sayMe 5 = "Five!"
sayMe x = "Not between 1 and 5"

unitImpulse :: Integer -> Integer
unitImpulse 0 = 1
unitImpulse _ = 0
{-
unitImpulse :: Integer -> Integer
unitImpulse _ = 0
unitImpulse 0 = 1
-}

len :: [Integer] -> Integer
len [] = 0
len (x:xs) = len(xs) + 1

-- Need to be careful with empty list.
head1 :: [a] -> a
head1 [] = error "Can't call head on an empty list!"
head1 (x:_) = x

capital :: String -> String
capital "" = "Empty string, whoops!"
capital all@(x:xs) = "The first letter of " ++ all ++ " is " ++ [x]


-- If Else
-- Syntax:
-- if e1 then e2 else e3
signum x = if x < 0 then -1
		else if x > 0 then 1
		else 0



-- Case Expression
-- Syntax:
-- case expression of pattern -> result
--		pattern -> result
--		pattern -> result
--		...

head2 :: [a] -> a
head2 xs = case xs of 	[] -> error "No head for empty lists!"
			(x:_) -> x

			

-- Guards
bmiTell :: (RealFloat a) => a -> String
bmiTell bmi
	| bmi <= 18.5 = "You're underweight!"
	| bmi <= 25.0 = "You're normal."
	| bmi <= 30.0 = "You're overweight!"
	| otherwise = "You're obese!!!"

bmiTell2 :: (RealFloat a) => a -> a -> String
bmiTell2 weight height
	| weight / height ^ 2 <= 18.5 = "You're underweight!"
	| weight / height ^ 2 <= 25.0 = "You're normal."
	| weight / height ^ 2 <= 30.0 = "You're overweight!"
	| otherwise = "You're obese!!!"

max' :: (Ord a) => a -> a -> a
max' a b
	| a > b = a
	| otherwise = b

  
-- Where
-- Syntax:
-- <function body>
-- 	where 	<line1>
-- 		<line2>
-- 		<line3>
-- 		...

bmiTell3 :: (RealFloat a) => a -> a -> String
bmiTell3 weight height
		| bmi <= 18.5 = "You're underweight!"
		| bmi <= 25.0 = "You're normal."
		| bmi <= 30.0 = "You're overweight!"
		| otherwise = "You're obese!!!"
		where bmi = weight / height ^ 2

initials :: String -> String -> String
initials firstname lastname = [f] ++ ". " ++ [l] ++ "."
				where 	(f:_) = firstname
					(l:_) = lastname


-- Let Example
cylinder :: (RealFloat a) => a -> a -> a
cylinder r h =
	let 	sideArea = 2 * pi * r * h
		topArea = pi * r ^2
	in sideArea + 2 * topArea


-- Recursion
-- Function for finding the maximum value inside the list.
maximum' :: (Ord a) => [a] -> a
maximum' [] = error "maximum of empty list"
maximum' [x] = x
maximum' (x:xs)
		| x > maxTail = x
		| otherwise = maxTail
		where maxTail = maximum' xs

-- Function for getting the reverse of a list.
reverse' :: [a] -> [a]
reverse' [] = []
reverse' (x:xs) = reverse' xs ++ [x]



-- Defining our Own Data Types
-- Syntax:
-- data <type name> = <value constructor1> | <value constructor1> | ...

data Shape = Circle Float Float Float | Rectangle Float Float Float Float deriving (Show)


surface :: Shape -> Float
surface (Circle _ _ r) = pi * r ^ 2
surface (Rectangle x1 y1 x2 y2) = (abs (x2 - x1)) * (abs (y2 - y1))


data Tree a = EmptyTree | Node a (Tree a) (Tree a) deriving (Show, Read, Eq)

-- Type Constructors
data Maybe a = Nothing | Just a deriving (Show)

-- Polymorphic functions
data Vector a = Vector a a a deriving (Show)

vplus :: (Num t) => Vector t -> Vector t -> Vector t
(Vector i j k) `vplus` (Vector l m n) = Vector (i+l) (j+m) (k+n)

vectMult :: (Num t) => Vector t -> t -> Vector t
(Vector i j k) `vectMult` m = Vector (i*m) (j*m) (k*m)

scalarMult :: (Num t) => Vector t -> Vector t -> t
(Vector i j k) `scalarMult` (Vector l m n) = i*l + j*m + k*n

-- Recursive Data Types
data List a = Empty | Cons a (List a) deriving Show

list_length Empty = 0
list_length (Cons x xs) = 1 + list_length xs

treeElem x EmptyTree = False
treeElem x (Node a left right)
		| x == a = True
		| otherwise = treeElem x right || treeElem x left

-- Type synonyms
type AssocList a b = [(a,b)] -- (Polymorphism)
type PhoneBook = [(String,String)]

-- Record Syntax
data Person = Person { firstName :: String  
                     , lastName :: String  
                     , age :: Int  
                     , height :: Float  
                     , phoneNumber :: String  
                     , flavor :: String  
                     } deriving (Show)

-- Modules
-- Syntax for importing modules: import <module name>



-- Take Home Exercises
-- 1. Implement reverse function which reverses a list of floats. Your function should work for only floats.
-- 2. Implement len function with case expressions.
-- 3. Implement bmiTell function using let-in construct.
-- 4. Examine result of the command ":info Shape" in the interpreter. 
-- 6. Examine result of the command ":info Tree" in the interpreter. 
