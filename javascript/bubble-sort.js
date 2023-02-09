const { generateShuffledArray, generateExpectedArray } =  require("./arrays")

const _bubbleSort = (arr) =>
{
    const res = arr.slice(0)
    for (let i = 0; i < res.length; i++) {
        let swapCount = 0
        for (let j = res.length - 1; j > i; j--) {
            if (res[j] < res[j - 1]) {
                // Swap
                const tmp = res[j]
                res[j] = res[j - 1]
                res[j - 1] = tmp
                swapCount++
            }
        }
        // Optimization: Stop looping after array already sorted
        // *Only logical: actually keeping the extra variable makes it a little slower
        if (swapCount == 0) break
    }
    return res
}

const bubbleSort = (arr) =>
{
    const start = new Date().getTime()
    const resultArray = _bubbleSort(arr)
    const end = new Date().getTime()
    return {
        res: resultArray,
        sortTime: end - start
    }
}

const main = () =>
{
    const size = 40000

    // Generate array
    const { arr, genTime } = generateShuffledArray(size)

    // Sort shuffled array
    const { res, sortTime } = bubbleSort(arr)

    // Eval result array with an expected result
    const expected = generateExpectedArray(size)
    const isSortedAsExpected = res.toString() == expected.toString()

    // Output the results
    console.log(`Time to generate shuffled array of size ${size}: ${genTime} ms`)
    if (! isSortedAsExpected) {
        console.log("2. The result arrays is NOT sorted as expected")
    } else {
        console.log("2. The result arrays is sorted as expected")
        console.log(`3. Time to bubble sort the shuffled array: ${sortTime} ms`)
    }
}

main()
