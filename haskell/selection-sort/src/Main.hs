module Main (main) where

import System.Random

{-
  -- Function from LearYouAHaskell for reference

  finiteRandoms :: (RandomGen g, Random a, Num n) => n -> g -> ([a], g)
  finiteRandoms 0 gen = ([], gen)
  finiteRandoms n gen =
      let (value, newGen) = random gen
          (restOfList, finalGen) = finiteRandoms (n-1) newGen
      in  (value:restOfList, finalGen)
-}

genArr :: Float -> Int -> StdGen -> [Int]
genArr _size 0   _gen = []
genArr size  len gen  =
    let (rnd_value, newGen) = random gen :: (Float, StdGen)
        value = floor $ (rnd_value * size) + 1
    in  value : genArr size (len - 1) newGen

main :: IO ()
main = do
    let size = 1000000 :: Float
    let len = 1000 :: Int
    let initialGen = (mkStdGen 1)
    let arr = genArr size len initialGen
    -- putStrLn $ show arr
    putStrLn "Arr generated"
