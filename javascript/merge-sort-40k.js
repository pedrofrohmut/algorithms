const { generateShuffledArray, generateExpectedArray } =  require("./arrays")

const _merge = (left, right) =>
{
    const combinedLength = left.length + right.length
    let result = []
    let leftIndex = 0
    let rightIndex = 0
    for (let k = 0; k < combinedLength; k++) {
        if (rightIndex >= right.length) {
            result = result.concat(left.slice(leftIndex))
            break
        }
        if (leftIndex >= left.length) {
            result = result.concat(right.slice(rightIndex))
            break
        }
        if (left[leftIndex] < right[rightIndex]) {
            result[k] = left[leftIndex]
            leftIndex++
        } else {
            result[k] = right[rightIndex]
            rightIndex++
        }
    }
    return result
}

const _splitArray = (arr) =>
{
    const mid = Math.ceil(arr.length / 2)
    const left = arr.slice(0, mid)
    const right = arr.slice(mid)
    return [left, right]
}

const _mergeSort = (arr) =>
{
    if (arr.length == 1) return arr
    if (arr.length == 2) {
        if (arr[0] < arr[1]) {
            return [arr[0], arr[1]]
        } else {
            return [arr[1], arr[0]]
        }
    }
    const [left, right] = _splitArray(arr)
    const leftResult = _mergeSort(left)
    const rightResult = _mergeSort(right)
    return _merge(leftResult, rightResult)
}

const mergeSort = (arr) =>
{
    const start = new Date().getTime()
    const resultArray = _mergeSort(arr)
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
    const { res, sortTime } = mergeSort(arr)

    // Eval result array with an expected result
    const expected = generateExpectedArray(size)
    const isSortedAsExpected = res.toString() == expected.toString()

    // Output the results
    console.log(`Time to generate shuffled array of size ${size}: ${genTime} ms`)
    if (! isSortedAsExpected) {
        console.log("2. The result arrays is NOT sorted as expected")
    } else {
        console.log("2. The result arrays is sorted as expected")
        console.log(`3. Time to merge sort the shuffled array: ${sortTime} ms`)
    }
}

main()
