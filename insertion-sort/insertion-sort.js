const getIndex = i => Math.floor(Math.random() * i)

const generateArray = (size) => {
    let arr = []
    for (let i = 1; i <= size; i++) {
        const index = getIndex(i)
        arr.splice(index, 0, i)
    }
    return arr
}

const insertionSort = (arr) => {
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

const main = () => {
    const size = 30_000

    const genStart = new Date().getTime()
    const arr = generateArray(size)
    const genEnd = new Date().getTime()

    console.log(`1. Time to generate ${genEnd - genStart} ms`)

    const sortStart = new Date().getTime()
    const res = insertionSort(arr)
    const sortEnd = new Date().getTime()

    const expected = []
    for (let i = 1; i <= arr.length; i++) expected.push(i)

    if (expected.toString() != res.toString()) {
        console.error("2. They are not equal")
    } else {
        console.log("2. Result array is as expected")
        console.log(`3. Sorted in ${sortEnd - sortStart} milliseconds`)
    }
}

main()
