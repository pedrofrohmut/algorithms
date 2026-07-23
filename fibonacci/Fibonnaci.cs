using System;

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
    Console.Write($"Fibonnaci of {n} is ");
    string[] strSeq = seq.Select(x => x.ToString()).ToArray();
    Console.Write("[ ");
    Console.Write(String.Join(", ", strSeq));
    Console.WriteLine(" ]");
}

uint n = 100;
List<uint> result = Fibonacci(n);
PrintFibonacci(result, n);
