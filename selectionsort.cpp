#include <iostream>

using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};

    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    cout << "Sorted Array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

/*
============================================================================
                                THEORY
============================================================================

AIM:
To implement Selection Sort algorithm using C++.

----------------------------------------------------------------------------

WHAT IS SORTING?
Sorting means arranging data in:
1. Ascending order
OR
2. Descending order

Example:

Before Sorting:
64 25 12 22 11

After Sorting:
11 12 22 25 64

----------------------------------------------------------------------------

WHAT IS SELECTION SORT?
Selection Sort repeatedly:
1. Finds smallest element
2. Places it at correct position

It divides array into:
- Sorted part
- Unsorted part

----------------------------------------------------------------------------

WORKING OF SELECTION SORT

PASS 1:
Find minimum element from entire array.
Swap with first position.

11 25 12 22 64

PASS 2:
Find minimum from remaining array.
Swap with second position.

11 12 25 22 64

PASS 3:
11 12 22 25 64

Final Sorted Array:
11 12 22 25 64

----------------------------------------------------------------------------

ALGORITHM:
1. Start from first index
2. Find minimum element
3. Swap minimum with current position
4. Repeat for all elements

----------------------------------------------------------------------------

TIME COMPLEXITY:

Best Case:
:contentReference[oaicite:0]{index=0}

Average Case:
:contentReference[oaicite:1]{index=1}

Worst Case:
:contentReference[oaicite:2]{index=2}

----------------------------------------------------------------------------

SPACE COMPLEXITY:
:contentReference[oaicite:3]{index=3}

Selection Sort is an in-place sorting algorithm.

----------------------------------------------------------------------------

ADVANTAGES:
1. Simple to understand
2. Less memory usage
3. Performs fewer swaps

----------------------------------------------------------------------------

DISADVANTAGES:
1. Slow for large data
2. Not efficient
3. Not stable

----------------------------------------------------------------------------

APPLICATIONS:
1. Small datasets
2. Educational purposes
3. Memory constrained systems

----------------------------------------------------------------------------

OUTPUT:

Sorted Array:
11 12 22 25 64

============================================================================
*/