#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
{
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

/*
   tail_factorial(n - 1, result * n)

   0 - n = 5, result = 1   => tail_factorial(5 - 1, 1  * 5)
   1 - n = 4, result = 5   => tail_factorial(4 - 1, 5  * 4)
   2 - n = 3, result = 20  => tail_factorial(3 - 1, 9  * 3)
   3 - n = 2, result = 60  => tail_factorial(2 - 1, 60 * 2)
   4 - n = 1, result = 120 => result

    PS: => means return
   */
int tail_factorial(int n, int result)
{
    if (n <= 1) return result;
    return tail_factorial(n - 1, result * n);
}

// Works the same way as tail recursion but with escape condition at the bottom
int head_factorial(int n, int result)
{
    if (n > 1) return head_factorial(n - 1, result * n);
    return result;
}

int main()
{
    int n1 = factorial(5);
    printf("Simple Recursion => Factorial of 5: %d\n", n1);

    // You can use a public function that accepts only N and let the 2 args call private
    int head_result = head_factorial(5, 1);
    printf("Head Recursion => Factorial of 5: %d\n", head_result);

    // Prefer tail recursion because the compiler can otimize it to a loop
    int tail_result = tail_factorial(5, 1);
    printf("Tail Recursion => Factorial of 5: %d\n", tail_result);

    return 0;
}
