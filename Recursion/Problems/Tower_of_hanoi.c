#include <stdio.h>

// Function to move disks
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);                      // Move n-1 disks from 'from_rod' to 'aux_rod'
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod); // Move nth disk from 'from_rod' to 'to_rod'
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);                      // Move n-1 disks from 'aux_rod' to 'to_rod'
}

int main()
{
    int n = 3; // Number of disks
    printf("The sequence of moves involved in solving the Tower of Hanoi puzzle are:\n");
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B, and C are names of rods
    return 0;
}