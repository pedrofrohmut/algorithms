const { generateShuffledArray, generateExpectedArray } =  require("./arrays")

const _insertionSort = (arr) =>
{
    const res = arr.slice(0)
    for (let i = 1; i < res.length; i++) {
        const key = res[i];
        let j = i - 1;
        while (j >= 0 && res[j] > key) {
            res[j + 1] = res[j];
            j--;
        }
        res[j + 1] = key;
    }
    return res
}

const insertionSort = (arr) =>
{
    const start = new Date().getTime()
    const resultArray = _insertionSort(arr)
    const end = new Date().getTime()
    return {
        res: resultArray,
        sortTime: end - start
    }
}

const main = () => {
    const size = 40000

    // Generate array
    const { arr, genTime } = generateShuffledArray(size)

    // Sort shuffled array
    const { res, sortTime } = insertionSort(arr)

    // Eval result array with an expected result
    const expected = generateExpectedArray(size)
    const isSortedAsExpected = res.toString() == expected.toString()

    // Output the results
    console.log(`Time to generate shuffled array of size ${size}: ${genTime} ms`)
    if (! isSortedAsExpected) {
        console.log("2. The result arrays is NOT sorted as expected")
    } else {
        console.log("2. The result arrays is sorted as expected")
        console.log(`3. Time to insertion sort the shuffled array: ${sortTime} ms`)
    }
}

main()
