const { generateShuffledArray, generateExpectedArray } =  require("./arrays")

const _selectionSort = (arr) =>
{
    const src = arr.slice(0)
    const res = []
    for (let i = 0; i < arr.length; i++) {
        let min = src[0]
        let pos = 0
        let j = 0
        while (j < src.length) {
            if (src[j] < min) {
                min = src[j]
                pos = j
            }
            j++
        }
        res.push(min) // Add min to result array
        src.splice(pos, 1) // Remove min from src
    }
    return res
}

const selectionSort = (arr) =>
{
    const start = new Date().getTime()
    const resultArray = _selectionSort(arr)
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
    const { res, sortTime } = selectionSort(arr)

    // Eval result array with an expected result
    const expected = generateExpectedArray(size)
    const isSortedAsExpected = res.toString() == expected.toString()

    // Output the results
    console.log(`Time to generate shuffled array of size ${size}: ${genTime} ms`)
    if (! isSortedAsExpected) {
        console.log("2. The result arrays is NOT sorted as expected")
    } else {
        console.log("2. The result arrays is sorted as expected")
        console.log(`3. Time to selection sort the shuffled array: ${sortTime} ms`)
    }
}

main()
