// With recursion, Auxiliar function and accumulator (no callstack unwinding
// when base case is reached)
List<uint> Fibonacci(uint limit)
{
    List<uint> Aux(List<uint> acc, uint a, uint b)
    {
        uint nextNumber = a + b;

        if (nextNumber > limit) {
            return acc;
        }

        List<uint> newAcc = acc.Append(nextNumber).ToList();
        return Aux(newAcc, b, nextNumber);
    }

    return Aux(new List<uint>{}, 0, 1);
}

void PrintFibonacci(List<uint> seq, uint n)
{
    Console.Write($"Fibo1 => Fibonnaci of {n} is ");
    string[] strSeq = seq.Select(x => x.ToString()).ToArray();
    Console.Write("[ ");
    Console.Write(String.Join(", ", strSeq));
    Console.WriteLine(" ]");
}

// Calculates and print fibonacci. While loop and mutation
void Fibonacci2(uint limit)
{
    Console.Write($"Fibo2 => Fibonacci of {limit} is [ ");

    uint a = 0;
    uint b = 1;
    while (b < limit) {
        uint temp = a;
        a = b;
        b = temp + b;
        Console.Write($"{b} ");
    }

    Console.WriteLine("]");
}

void Main()
{
    uint n = 100;
    List<uint> result = Fibonacci(n);
    PrintFibonacci(result, n);

    Fibonacci2(500);
}

Main();
