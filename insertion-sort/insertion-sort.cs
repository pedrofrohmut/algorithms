using System;

public class InsertionSort
{
    public static void Main(string[] args)
    {
        int[] arr = new int[] { 5, 19, 20, 2, 15, 17, 4, 6, 14, 7, 21, 1, 16, 9, 12, 13, 3, 18, 10, 8, 11 };
        int[] res = new int[arr.Length];

        if (arr[0] < arr[1]) {
            res[0] = arr[0];
            res[1] = arr[1];
        } else {
            res[0] = arr[0];
            res[1] = arr[1];
        }

        for (int i = 2; i < arr.Length; i++) {
            int j = 0;
            while (j < i && res[j] < arr[i]) j++;
            for (int k = arr.Length - 1; k > j; k--) res[k] = res[k - 1];
            res[j] = arr[i];
        }
    }
}
