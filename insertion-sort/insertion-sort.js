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
    const arr = generateArray(30_000)

    const start = new Date().getTime()

    const res = insertionSort(arr)

    const end = new Date().getTime()

    const expected = []
    for (let i = 1; i <= arr.length; i++) expected.push(i)

    if (expected.toString() != res.toString()) {
        console.error("They are not equal")
    } else {
        console.log("Result array is as expected")
        console.log(`Sorted in ${end - start} milliseconds`)
    }
}

main()
