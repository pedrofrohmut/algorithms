module Main (main) where

import System.Random

genArr :: Float -> Int -> StdGen -> [Int]
genArr _size 0   _gen = []
genArr size  len gen  =
    let (rnd_value, newGen) = random gen :: (Float, StdGen)
        value = floor $ (rnd_value * size) + 1
    in  value : genArr size (len - 1) newGen

getSmaller :: [Int] -> Int
getSmaller mainArr =
        getIt (head mainArr) mainArr
    where
        getIt minv [] = minv
        getIt minv arr =
            if head arr < minv
                then getIt (head arr) (tail arr)
                else getIt minv (tail arr)

removeFromArr :: Int -> [Int] -> [Int]
removeFromArr _val [] = []
removeFromArr val (x:xs) =
    if x == val
        then removeFromArr val xs
        else x : removeFromArr val xs

selectSort :: [Int] -> [Int]
selectSort =
    go []
    where
        go result [] = result
        go result arr =
            let minv = getSmaller arr in
            let newArr = removeFromArr minv arr in
            go (result ++ [minv]) newArr

main :: IO ()
main = do
    let size = 1000000 :: Float
    let len = 10 :: Int
    let initialGen = mkStdGen 2
    let arr = genArr size len initialGen

    putStrLn $ show arr ++ "\n"

    let smaller = getSmaller arr
    putStrLn $ "Min: " ++ show smaller ++ "\n"

    putStrLn $ "Without Min: " ++ show (removeFromArr smaller arr) ++ "\n"

    putStrLn $ "Result: " ++ show (selectSort arr)
