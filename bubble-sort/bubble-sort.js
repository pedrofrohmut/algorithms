const generateArray = (size) => {
    const arr = []
    for (let i = 1; i <= size; i++) {
        const index = Math.floor(Math.random() * i)
        arr.splice(index, 0, i)
    }
    return arr
}

const bubbleSort = (arr) => {
    const res = arr.slice(0)
    for (let i = 0; i < res.length; i++) {
        for (let j = res.length - 1; j > i; j--) {
            if (res[j] < res[j - 1]) {
                const tmp = res[j]
                res[j] = res[j - 1]
                res[j - 1] = tmp
            }
        }
    }
    return res
}

const main = () =>
{
    const size = 30000

    // Generate Array
    const genStart = new Date().getTime()
    const arr = generateArray(size)
    const genEnd = new Date().getTime()

    // Sort array
    const sortStart = new Date().getTime()
    const res = bubbleSort(arr)
    const sortEnd = new Date().getTime()

    // Eval sorted array with an expected result
    const expected = []
    for (let i = 1; i <= size; i++) expected.push(i)
    areEqual = expected.toString() == res.toString()

    // Output the results
    console.log(`1. Time to generate array: ${genEnd - genStart} ms`)
    if (! areEqual) {
        console.log("2. The result array is NOT sorted as expected")
    } else {
        console.log("2. The result array is sorted as expected")
        console.log(`3. Time to bubble sort the array: ${sortEnd - sortStart} ms`)
    }
}

main()
