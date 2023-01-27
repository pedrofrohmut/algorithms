const generateArray = (size) => {
    let arr = []
    for (let i = 1; i <= size; i++) {
        const index = Math.floor(Math.random() * i)
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

const insertionSort2 = (arr) => {
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

const main = () => {
    const size = 30_000

    const genStart = new Date().getTime()
    const arr = generateArray(size)
    const genEnd = new Date().getTime()

    const sortStart = new Date().getTime()
    const res = insertionSort(arr)
    const sortEnd = new Date().getTime()

    const sort2Start = new Date().getTime()
    const res2 = insertionSort2(arr)
    const sort2End = new Date().getTime()

    const expected = []
    for (let i = 1; i <= arr.length; i++) expected.push(i)

    console.log(`Time to generate ${genEnd - genStart} ms`)

    if (expected.toString() != res.toString()) {
        console.error("Result1: They are not equal")
    } else {
        console.log("Result1: array sorted is as expected")
        console.log(`Result1: Time to sort ${sortEnd - sortStart} ms`)
    }

    if (expected.toString() != res2.toString()) {
        console.error("Result2: They are not equal")
    } else {
        console.log("Result2: array is sorted as expected")
        console.log(`Result2: Time to sort2 ${sort2End - sort2Start} ms`)
    }
}

main()
