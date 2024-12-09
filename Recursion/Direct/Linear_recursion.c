#include <stdio.h>

int factorial(int n)
{
    if (n == 0)
    {
        return 1; // Base case
    }
    return n * factorial(n - 1); // Recursive call (linear)
}

int main()
{
    int num = 5;
    printf("Factorial of %d is %d\n", num, factorial(num));
    return 0;
}
