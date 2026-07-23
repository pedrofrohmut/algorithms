uint Factorial(uint n) {
    if (n < 2) {
        return 1;
    }
    return n * Factorial(n - 1);
}

uint n = 5;
uint result = Factorial(n);
Console.WriteLine($"Factorial of {n} is {result}");
