#include <stdio.h>

int excessiveFactorial(int n)
{
    if (n == 0)
    {
        return 1; // Base case
    }

    // Excessive recursion: calling the same function multiple times unnecessarily
    return n * excessiveFactorial(n - 1) + (n == 1 ? 0 : excessiveFactorial(n - 1));
}

int main()
{
    int num = 5;
    printf("Excessive Factorial of %d is %d\n", num, excessiveFactorial(num));
    return 0;
}
