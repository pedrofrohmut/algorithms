const generateArray = (size) =>
{
    const arr = []
    for (let i = 1; i <= size; i++) {
        const index = Math.floor(Math.random() * i)
        arr.splice(index, 0, i)
    }
    return arr
}

const getLeftAndRight = (arr) =>
{
    const extra = arr % 2 == 0 ? 0 : 1 // extra when arr.length is odd
    const mid = Math.floor(arr.length / 2) - 1
    const left = arr.slice(0, mid + extra)
    const right = arr.slice(mid + extra)
    return { left, right }
}

const sortArray = (arr) =>
{
    for (let i = 1; i < arr.length; i++) {
        const key = arr[i];
        let j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return arr
}

const mergeLeftAndRight = (left, right) =>
{
    const resultLength = left.length + right.length
    let result = []
    let leftIndex = 0
    let rightIndex = 0
    for (let k = 0; k < resultLength; k++) {
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

const compareArrays = (subject, expected) =>
{
    for (let i = 0; i < subject.length; i++) {
        if (subject[i] != expected[i]) return false
    }
    return true
}

const main = () =>
{
    const size = 30_000

    // Generate array
    const genStart = new Date().getTime()
    const arr = generateArray(size)
    const genEnd = new Date().getTime()

    const sortStart = new Date().getTime()

    // Get Left and Right halves of the array
    const { left, right } = getLeftAndRight(arr)

    // Sort Left and Right (with insertionSort)
    sortArray(left)
    sortArray(right)

    // Merge Left and Right
    const merged = mergeLeftAndRight(left, right)

    const sortEnd = new Date().getTime()

    // Eval sorted array with an expected result
    const expected = []
    for (let i = 1; i <= size; i++) expected.push(i)
    const areEqual = compareArrays(merged, expected)

    // Output the results
    console.log("1. Time to generate array: ", genEnd - genStart, "ms")
    if (! areEqual) {
        console.log("2. Result array is NOT sorted as expected")
    } else {
        console.log("2. Result array is sorted as expected")
        console.log("3. Time to merge sort the array: ", sortEnd - sortStart, "ms")
    }
}

main()
