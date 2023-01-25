const SIZE = 100_000
const arr = populate_array(SIZE)
writeToFile(arr)

function getIndex(i)
{
    return Math.floor(Math.random() * i)
}

function populate_array(size)
{
    let arr = []
    for (let i = 1; i <= SIZE; i++) {
        const index = getIndex(i)
        arr.splice(index, 0, i)
    }
    return arr
}

function writeToFile(arr)
{
    const fs = require("fs")
    const writeStream = fs.createWriteStream("arr.txt")

    arr.forEach(x => writeStream.write(x + "\n"))

    writeStream.on("error", err => console.log("ERROR:", err))

    writeStream.on("finish", () => console.log("Array Successfuly Written"))

    writeStream.end()
}
