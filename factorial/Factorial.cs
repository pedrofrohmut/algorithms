// Classic with recursion
uint Factorial(uint n)
{
    if (n < 2) {
        return 1;
    }
    return n * Factorial(n - 1);
}

// Normal csharp way with mutatios and loops
uint Factorial2(uint n)
{
    uint res = 1;
    for (uint i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

// Prints all factorials from 1 to n
void Factorial3(uint n)
{
    uint x = 1;
    for (uint i = 1; i <= n; i++) {
        x = x * i;
        Console.WriteLine("Factorial3 => Factorial of {0} is {1}", i, x);
    }
}

void Main()
{
    uint n = 10;
    uint result = Factorial(n);
    Console.WriteLine($"Factorial1 => Factorial of {n} is {result}");

    Console.WriteLine("Factorial2 => Factorial of {0} is {1}", n, Factorial2(n));

    Factorial3(10);
}

Main()
