const _generateShuffledArray = (size) =>
{
    const arr = []
    for (let i = 1; i <= size; i++) {
        const index = Math.floor(Math.random() * i)
        arr.splice(index, 0, i)
    }
    return arr
}

const generateShuffledArray = (size) =>
{
    const start = new Date().getTime()
    const resultArray = _generateShuffledArray(size)
    const end = new Date().getTime()
    return {
        arr: resultArray,
        genTime: end - start
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
    console.log(" ------------------------------------------------------------ ")
    for (let i = 0; i < arr.length; i++) console.log(`${name}[${i}] = ${arr[i]}`)
}

module.exports = {
    generateShuffledArray,
    generateExpectedArray,
    printArray,
}
