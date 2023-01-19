const arr = [5, 30, 34, 19, 20, 31, 33, 2, 15, 32, 25, 17, 38, 4, 6, 23, 29, 40, 14, 7, 36, 21, 1, 16, 39, 26, 35, 9, 12, 13, 24, 3, 37, 18, 27, 10, 8, 28, 11, 22]
let result = []

if (arr[0] < arr[1]) {
    result[0] = arr[0]
    result[1] = arr[1]
} else {
    result[0] = arr[1]
    result[1] = arr[0]
}

let i = 2
while (i < arr.length) {
    let j = 0
    while(j < result.length && result[j] < arr[i]) {
        j++
    }
    if (j == result.length) {
        result.push(arr[i])
    } else {
        const leftSlice = result.slice(0, j)
        const rightSlice = result.slice(j)
        result = [ ...leftSlice, arr[i], ...rightSlice ]
    }
    i++
}

// console.log("Arr")
// arr.forEach(x => console.log(x))
// console.log("\nResult")
// result.forEach(x => console.log(x))
