// arr is the full array with 40 elements
const arr = [5, 30, 34, 19, 20, 31, 33, 2, 15, 41, 32, 25, 17, 38, 4, 6, 23, 29, 40, 14, 7, 36, 21, 1, 16, 39, 26, 35, 9, 12, 13, 24, 3, 37, 18, 27, 10, 8, 28, 11, 22]

const start = new Date().getTime()

const { Left, Right } = getLeftAndRight(arr)

const res = mergeLeftAndRight(Left, Right)

const end = new Date().getTime()

console.log("Start:", start)
console.log("End:", end)
console.log("Total:", end - start, "in milliseconds")

// res.forEach((x, i) => console.log(`res[${i}]: ${x}`))

function orderArray(arr) {
    let res = []
    res[0] = arr[0]
    for (let i = 1; i < arr.length; i++) {
        let j = 0
        // iterate through res array to find insert position
        while (j < i && res[j] < arr[i]) j++
        // Insert elem into res array into j position
        res.splice(j, 0, arr[i])
    }
    return res
}

function getLeftAndRight(arr) {
    const mid = Math.floor(arr.length / 2)

    // Separate the A into 2 slices of same size
    let Left = arr.slice(0, mid)
    let Right = arr.slice(mid)

    // Order both slices
    Left = orderArray(Left)
    Right = orderArray(Right)

    return { Left, Right }
}

function mergeLeftAndRight(Left, Right) {
    const resultLength = Left.length + Right.length
    let result = []
    let leftIndex = 0
    let rightIndex = 0
    for (let k = 0; k < resultLength; k++) {
        if (rightIndex >= Right.length) {
            result[k] = Left.slice(leftIndex)
            break
        }
        if (leftIndex >= Left.length) {
            result[k] = Right.slice(rightIndex)
            break
        }
        if (Left[leftIndex] < Right[rightIndex]) {
            result[k] = Left[leftIndex]
            leftIndex++
        } else {
            result[k] = Right[rightIndex]
            rightIndex++
        }
    }
    return result
}
