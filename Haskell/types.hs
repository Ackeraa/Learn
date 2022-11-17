-- Language: haskell
-- Path: types.hs
import qualified Data.Map as Map

data Point = Point Float Float deriving (Show)
data Shape = Circle Point Float | Rectangle Point Point deriving (Show)

surface :: Shape -> Float
surface (Circle _ r) = pi * r ^ 2
surface (Rectangle (Point x1 y1) (Point x2 y2)) = (abs $ x2 - x1) * (abs $ y2 - y1)

data Person = Person {
  firstName :: String,
  lastName :: String,
  age :: Int,
  height :: Float
} deriving (Show, Eq, Read)

p = Person "John" "Doe" 30 1.90
p1 = Person { firstName = "John", lastName = "Doe", age = 30, height = 1.90 }
p2 = read "Person { firstName = \"John\", lastName = \"Doe\", age = 30, height = 1.90 }" :: Person

data Car a b c = Car { 
  company :: a,
  model :: b,
  year :: c
} deriving (Show)

--data Maybe a = Nothing | Just a
--data Either a b = Left  a | Right b deriving (Eq, Ord, Read, Show)

--type IntMap v = Map Int v
--type IntMap = Map Int

data LockerState = Taken | Free deriving (Show, Eq)
type Code = String
type LockerMap = Map.Map Int (LockerState, Code)

lockerLookup :: Int -> LockerMap -> Either String Code
lockerLookup lockerNumber map =
  case Map.lookup lockerNumber map of 
    Nothing -> Left $ "Locker number " ++ show lockerNumber ++ " doesn't exist!"
    Just (state, code) -> if state /= Taken
                            then Right code
                            else Left $ "Locker " ++ show lockerNumber ++ " is already taken!"

--data List a = Empty | Cons a (List a) deriving (Show, Read, Eq, Ord)
--data List a = Empty | Cons { listHead :: a, listTail :: List a } deriving (Show, Read, Eq, Ord)
infixr 5 :-:
data List' a = Empty' | a :-: (List' a) deriving (Show, Read, Eq, Ord)

--3 :-: 4 :-: 5 :-: Empty' is equivalent to 3 `Cons` (4 `Cons` (5 `Cons` Empty'))

{-
infixr 5 .++
(.++) :: List a -> List a -> List a
[] .++ ys = ys
(x:xs) .++ ys = x :-: (xs .++ ys)
-}

{-
class Eq' a where
  (==) :: a -> a -> Bool
  (/=) :: a -> a -> Bool
  x == y = not (x /= y)
  x != y = not (x == y)

data TrafficLight = Red | Yellow | Green

instance Eq TrafficLight where
  Red == Red = True
  Green == Green = True
  Yellow == Yellow = True
  _ == _ = False

instance Show TrafficLight where 
  show Red = "Red light"
  show Yellow = "Yellow light"
  show Green = "Green light"

instance (Eq m) => (Maybe m) where
  Just x == Just y = x == y
  Nothing == Nothing = True
  _ == _ = False

instance Functor Maybe where
  fmap f (Just x) = Just (f x)
  fmap f Nothing = Nothing

instance Functor (Either a) where
  fmap f (Right x) = Right (f x)
  fmap f (Left x) = Left x

-}
class YesNo a where
  yesno :: a -> Bool

instance YesNo Int where
  yesno 0 = False
  yesno _ = True

instance YesNo [a] where
  yesno [] = False
  yesno _ = True

instance YesNo Bool where
  yesno = id

instance YesNo (Maybe a) where
  yesno (Just _) = True
  yesno Nothing = False

yesnoIf :: (YesNo y) => y -> a -> a -> a
yesnoIf yesnoVal yesResult noResult = if yesno yesnoVal then yesResult else noResult

main = putStrLn (show(yesnoIf [] "sadasd" "asds"))
