const _getIndex = (i) => Math.floor(Math.random() * i)

const _generateShuffledArray = (size) => {
    const arr = []
    for (let i = 1; i <= size; i++) {
        const index = _getIndex(i)
        arr.splice(index, 0, i)
    }
    return arr
}

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

const _splitArray = (arr) => {
    const mid = Math.ceil(arr.length / 2)
    const left = arr.slice(0, mid)
    const right = arr.slice(mid)
    return [left, right]
}

const _mergeSort = (arr) =>
{
    if (arr.length == 1) return arr
    const [left, right] = _splitArray(arr)
    const leftResult = _mergeSort(left)
    const rightResult = _mergeSort(right)
    return _merge(leftResult, rightResult)
}

const generateShuffledArray = (size) =>
{
    const start = new Date().getTime()
    const generatedArray = _generateShuffledArray(size)
    const end = new Date().getTime()
    return {
        arr: generatedArray,
        genTime: end - start
    }
}

const mergeSort = (arr) =>
{
    const start = new Date().getTime()
    const result = _mergeSort(arr)
    const end = new Date().getTime()
    return {
        res: result,
        sortTime: end - start
    }
}

const generateExpectedArray = (size) =>
{
    const arr = []
    for (let i = 1; i <= size; i++) arr.push(i)
    return arr
}

const printArray = (arr, name) =>
{
    for (let i = 0; i < arr.length; i++) console.log(`${name}[${i}] = ${arr[i]}`)
}

const main = () => {
    const size = 30000

    // Generate shuffled array
    const {arr, genTime} = generateShuffledArray(size)

    // Sort shuffled array
    const {res, sortTime} = mergeSort(arr)

    // Eval sorted array with an expected result
    const expected = generateExpectedArray(size)

    // Output the results
    console.log(`1. Time to generate the array: ${genTime} ms`)
    if (res.toString() != expected.toString()) {
        console.log("2. Result array is NOT sorted as expected")
    } else {
        console.log("2. Result array is sorted as expected")
        console.log(`3. Time to merge sort the array: ${sortTime} ms`)
    }
}

main()
