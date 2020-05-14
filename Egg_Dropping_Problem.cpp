#include <iostream>
using namespace std;
#include <limits.h>

// To get Maximum of two numbers...............
int max(int a, int b) { return (a > b) ? a : b; }

// To get minimum number of trials needed with "n" eggs and "k" floors......
int eggDrop(int n, int k)
{
    //A 2D Array where entry eggFloor[i][j] will store minimum number of trials with "i" eggs and "j" floors.
    int eggFloor[n + 1][k + 1];
    int res;
    int i, j, x;

    // We need minimum one trial for one floor and 0 trials for 0 floors
    for (i = 1; i <= n; i++)
    {
        eggFloor[i][1] = 1;
        eggFloor[i][0] = 0;
    }

    // j trials for one egg and j floors.
    for (j = 1; j <= k; j++)
        eggFloor[1][j] = j;

    // Rest of the entries in Array is filled using optimal substructure property
    for (i = 2; i <= n; i++)
    {
        for (j = 2; j <= k; j++)
        {
            eggFloor[i][j] = INT_MAX;
            for (x = 1; x <= j; x++)
            {
                res = 1 + max(eggFloor[i - 1][x - 1], eggFloor[i][j - x]);
                if (res < eggFloor[i][j])
                    eggFloor[i][j] = res;
            }
        }
    }

    // result is stored in -->> eggFloor[n][k]
    return eggFloor[n][k];
}

// Driver to test to print Minimum egg to be Dropped.....
int main()
{
    // declaring variables for eggs and floors respectively......!!!
    int n = 2;
    printf("Number of Floors in Building: ");
    int k;
    scanf("%d", &k);
    /*  printf("Number of available Eggs: ");
		
    	scanf("%d", &n);
         */
    printf("\nMinimum number of trials with %d eggs and "
           "%d floors is: %d \n",
           n, k, eggDrop(n, k));
    return 0;
}