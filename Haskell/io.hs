import Data.Char
import Control.Monad
import System.IO

{-
main = do
  putStrLn "Hello, what's your first name?"
  firstName <- getLine
  putStrLn "Hello, what's your last name?"
  lastName <- getLine
  let bigFirstName = map toUpper firstName
      bigLastName = map toUpper lastName
  putStrLn $ "hey " ++ bigFirstName ++ " " ++ bigLastName ++ ", how are you?"
  
-}

{-
main = do
  c <- getChar
  if c /= ' '
    then do
      putChar c
      main
    else return ()
-}

{-
main = do
  c <- getChar
  when (c /= ' ') $ do
    putChar c
    main
-}

{-
main = do
  sequence (map print [1,2,3,4,5])
  mapM print [1,2,3,4,5]
  contents <- getContents
  putStr (map toUpper contents)
-}

{-
main = do
  handle <- openFile "girlfriend.txt" ReadMode
  contents <- hGetContents handle
  putStr contents
  hClose handle
-}

main = do
  withFile "girlfriend.txt" ReadMode (\handle -> do
    contents <- hGetContents handle
    putStr contents)
