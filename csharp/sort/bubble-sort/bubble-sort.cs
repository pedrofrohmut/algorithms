using System;
using System.Diagnostics;

public class BubbleSortClass
{
    static int[] GenerateArray(int size)
    {
        var rand = new Random();
        var arr = new int[size];
        for (var i = 0; i < size; i++) {
            arr[i] = rand.Next(int.MaxValue);
        }
        return arr;
    }


    static void BubbleSort(int[] arr)
    {
        for (var i = 0; i < arr.Length; i++) {
            for (var j = arr.Length - 1; j > i; j--) {
                if (arr[j] < arr[j - 1]) {
                    //swap
                    var tmp = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = tmp;
                }
            }
        }
    }

    static TimeSpan BenchBubbleSort(int[] arr)
    {
        var stopWatch = new Stopwatch();
        stopWatch.Start();
        BubbleSort(arr);
        stopWatch.Stop();
        return stopWatch.Elapsed;
    }

    static bool IsSorted(int[] arr)
    {
        for (var i = 0; i < arr.Length - 1; i++) {
            if (arr[i] > arr[i + 1]) return false;
        }
        return true;
    }

    public static void Main(string[] args)
    {
        var size = 40000;
        var arr = GenerateArray(size);

        var elapsed = BenchBubbleSort(arr);

        if (! IsSorted(arr)) {
            Console.WriteLine("The array is NOT sorted as expected");
        } else {
            Console.WriteLine("Time to bubble sort the array: " + elapsed.Milliseconds + " ms");
        }
    }
}
