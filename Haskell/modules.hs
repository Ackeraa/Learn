import Data.List
import Data.Function
--import Data.List hiding (nub)
import qualified Data.Map as Map

numUniques :: (Eq a) => [a] -> Int
numUniques = length . nub

x1 = intersperse '.' "asds"

x2 = intercalate " " ["hey", "there", "guys"]

x3 = group [1, 1, 1, 2, 1, 2, 3, 2, 1, 3]

x4 = [[1, 2, 3], [1, 2], [1, 2, 3, 4]]

x5 = sortBy (compare `on` length) x4

phoneBook = 
  [("asd", "123")
  ,("das", "312")
  ]

findKey :: (Eq k) => k -> [(k, v)] -> Maybe v
findKey key [] = Nothing
findKey key ((k, v):xs) = if key == k
  then Just v
  else findKey key xs

findKey' :: (Eq k) => k -> [(k, v)] -> Maybe v
findKey' key = foldr (\(k, v) acc -> if key == k then Just v else acc) Nothing

x6 = Map.fromList phoneBook

main = putStrLn (show(x6))
