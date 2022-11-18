import Data.Monoid
import Control.Applicative

a = fmap (*) [1, 2, 3, 4]
b = fmap (\f -> f 9) a

class (Functor f) => Applicative f where
  pure :: a -> f a
  (<*>) :: f (a -> b) -> f a -> f b

instance Applicative Maybe where
  pure = Just
  Nothing <*> _ = Nothing
  (Just f) <*> something = fmap f something
  
{-
class Monoid m where
  mempty :: m
  mappend :: m -> m -> m
  mconcat :: [m] -> m
  mconcat = foldr mappend mempty

instance Monoid [a] where
  mempty = []
  mappend = (++)

newtype Product a = Product { getProduct :: a }
  deriving (Eq, Ord, Read, Show, Bounded)

instance Num a => Monoid (Product a) where
  mempty = Product 1
  Product x `mappend` Product y = Pruduct (x * y)
-}

main = do
    print b
