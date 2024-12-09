#include <stdio.h>

// Function declarations
void functionA(int n);
void functionB(int n);

// Function A definition
void functionA(int n)
{
    if (n <= 0)
    {
        return; // Base condition to stop recursion
    }
    printf("In functionA: %d\n", n);
    functionB(n - 1); // Call functionB
}

// Function B definition
void functionB(int n)
{
    if (n <= 0)
    {
        return; // Base condition to stop recursion
    }
    printf("In functionB: %d\n", n);
    functionA(n - 1); // Call functionA
}

int main()
{
    int n = 5;
    functionA(n); // Start the recursion with functionA
    return 0;
}
