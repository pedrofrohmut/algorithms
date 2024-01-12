console.log("Hello, World!")

// Example of a factorial call where you just use a while loop. This way only
// having a single call in the stack. Best efficency
const factorialWhile = (x) => {
    let n = 1
    let result = 1;
    while (n <= x) {
        result = result * n
        n++
    }
    console.log(`factorialWhile of ${x} is ${result}`)
    return result
}

factorialWhile(1)
factorialWhile(2)
factorialWhile(3)
factorialWhile(4)
factorialWhile(5)

// Factorial using recursion with zero optimization, just works. The stack goes up
// until the base case is reached and them the calculations begin.
const factorialRecursion = x => {
    const _factorialRecursion = (n) => {
        if (n <= 1)
            return 1
        return n * _factorialRecursion(n - 1)
    }
    const result = _factorialRecursion(x)
    console.log(`factorialRecursion of ${x} is ${result}`)
}

factorialRecursion(1)
factorialRecursion(2)
factorialRecursion(3)
factorialRecursion(4)
factorialRecursion(5)

// Factorial with recursion but with the optimization of tail recursion. The
// result is calculated on every step when the base case is reached it can just
// return the result. On compiled languages this can be compiled to a while loop
// that makes it a lot faster them simple recursion. Always prefer tail or head
// recursion over normal recursion when possible
const factorialTailRecursion = x => {
    const _fact = (n, result) => {
        if (n <= 1) return result
        return _fact(n - 1, result * n)
    }
    const result = _fact(x, 1)
    console.log(`factorialTailRecursion of ${x} is ${result}`)
}

factorialTailRecursion(1)
factorialTailRecursion(2)
factorialTailRecursion(3)
factorialTailRecursion(4)
factorialTailRecursion(5)
