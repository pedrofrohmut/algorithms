using System;
using System.Diagnostics;

public class InsertionSortClass
{
    static int GenerateIndex(int num, Random rand) => rand.Next(num);

    static void InsertIntoArray(int[] arr, int pos, int elem)
    {
        for (var i = arr.Length - 1; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = elem;
    }

    static int[] GenerateArray(int size)
    {
        var rand = new Random();
        var arr = new int[size];
        for (var i = 1; i <= size; i++) {
            var index = GenerateIndex(i, rand);
            InsertIntoArray(arr, index, i);
        }
        return arr;
    }

    static void InsertionSort(int[] arr)
    {
        for (var i = 1; i < arr.Length; i++) {
            var key = arr[i];
            var j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    static int[] GetExpectedArray(int size)
    {
        var arr = new int[size];
        for (var i = 0; i < size; i++) arr[i] = i + 1;
        return arr;
    }

    static bool CompareArrays(int[] arr, int[] expected)
    {
        for (var i = 0; i < arr.Length; i++) {
            if (arr[i] != expected[i]) return false;
        }
        return true;
    }

    public static void Main(string[] args)
    {
        var size = 30000;

        // Generate array
        var sw1 = new Stopwatch();
        sw1.Start();
        var arr = GenerateArray(size);
        sw1.Stop();

        Console.WriteLine("1. Time to generate array: " + sw1.Elapsed.Milliseconds);

        // Sort array
        var sw2 = new Stopwatch();
        sw2.Start();
        InsertionSort(arr);
        sw2.Stop();

        // Eval sorted array with an expected result
        var expected = GetExpectedArray(size);
        bool are_equal = CompareArrays(arr, expected);
        if (! are_equal) {
            Console.WriteLine("2. The array is NOT sorted as expected");
        } else {
            Console.WriteLine("2. Result array is sorted as expected");
            Console.WriteLine("3. Time to sort the array: " + sw2.Elapsed.Milliseconds);
        }
    }
}
