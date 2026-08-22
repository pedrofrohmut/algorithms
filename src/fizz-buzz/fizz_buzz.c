#include <stdio.h>

void fizz_buzz(int limit)
{
    printf("FizzBuzz -> [ ");

    for (int i = 1; i <= limit; i++) {
        if (i % 15 == 0) {
            printf("FizzBuzz");
        } else if (i % 5 == 0) {
            printf("Buzz");
        } else if (i % 3 == 0) {
            printf("Fizz");
        } else {
            printf("%d", i);
        }

        if (i < limit) {
            printf(", ");
        }
    }

    printf(" ]\n");
}

int main(void)
{
    fizz_buzz(100);
    return 0;
}
