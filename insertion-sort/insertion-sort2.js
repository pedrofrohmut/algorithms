const arr = [5, 30, 34, 19, 20, 31, 33, 2, 15, 32, 25, 17, 38, 4, 6, 23, 29, 40, 14, 7, 36, 21, 1, 16, 39, 26, 35, 9, 12, 13, 24, 3, 37, 18, 27, 10, 8, 28, 11, 22]

const res = orderArray(arr)

// arr.forEach((x, i) => console.log(`arr[${i}]: ${x}`))
// res.forEach((x, i) => console.log(`res[${i}]: ${x}`))

function orderArray(arr) {
    let res = []
    res[0] = arr[0]
    for (let i = 1; i < arr.length; i++) {
        let j = 0
        while (j < i && res[j] < arr[i]) j++
        if (j == res.length) {
            res.push(arr[i])
        } else {
            res.splice(j, 0, arr[i])
        }
    }
    return res
}
