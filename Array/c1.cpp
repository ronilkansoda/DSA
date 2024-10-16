#include <iostream>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;

void ChangeArr(int arr[], int size)
{
    printf("in funciton\n");
    for (int i = 0; i < size; i++)
    {
        arr[i] = arr[i] * 2;
    }
}
typedef struct
{
    int index1;
    int index2;
} Indices;

Indices linearSearch(int arr[], int target)
{
    Indices result = {-1, -1};
    int sz = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                result.index1 = i;
                result.index2 = j;
                return result;
            }
        }

        // if (arr[i] == target)
        // {
        //     return i;
        // }
    }
    return result;
}

int main()
{
    // int marks[] = {100, 24, 3, 44, 5};
    // int smallest = INT_MAX;
    // int biggest = INT_MIN;

    // for (int i = 0; i < sizeof(marks) / sizeof(marks[0]); i++)
    // {
    //     if (marks[i] < smallest)
    //     {
    //         smallest = marks[i];
    //     }
    //     if (marks[i] > biggest)
    //     {
    //         biggest = marks[i];
    //     }
    // }
    // printf("The Minimun is : %d \n", smallest);
    // printf("The Maximum is : %d \n", biggest);

    int arr[] = {3, 2, 4};

    int target = 6;

    // ChangeArr(arr, 4);

    // printf("in main\n");
    // for (int i = 0; i < 4; i++)
    // {
    //     printf("%d ", arr[i]);
    // }

    Indices val = linearSearch(arr, target);
    printf("[%d,%d]", val.index2, val.index1);
    return 0;
}
