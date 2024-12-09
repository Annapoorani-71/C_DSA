// If a recursive function calling itself and that recursive call is the last statement in the function then it’s known as Tail Recursion.

// Code Showing Tail Recursion

#include <stdio.h>

void fun(int n)
{
    if (n > 0)
    {
        printf("%d ", n);

        fun(n - 1);
    }
}

int main()
{
    int x = 3;
    fun(x);
    return 0;
}
