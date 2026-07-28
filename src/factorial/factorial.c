#include <stdio.h>

int factorial(int n)
{
    if (n == 1) {
        return 1;
    }
    return factorial(n - 1) * n;
}

int main()
{
    int n = 5;
    printf("Factorial of %d is %d\n", n, factorial(n));
}
