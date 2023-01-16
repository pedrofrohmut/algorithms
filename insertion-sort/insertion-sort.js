const arr = [5, 2, 4, 6, 1, 3]
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

console.log("Arr")
arr.forEach(x => console.log(x))

console.log("\nResult")
result.forEach(x => console.log(x))
