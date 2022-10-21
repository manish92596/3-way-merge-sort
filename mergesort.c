#include <stdio.h>
#include <limits.h>

void merge(int arr[], int lb, int mid1, int mid2, int up)
{
    int n1 = mid1 - lb + 1;
    int n2 = mid2 - mid1;
    int n3 = up - mid2;
    int arr1[n1 + 1], arr2[n2 + 1], arr3[n3 + 1];
    arr1[n1] = INT_MAX;
    arr2[n2] = INT_MAX;
    arr3[n3] = INT_MAX;

    for (int i = 0; i < n1; i++)
    {
        arr1[i] = arr[lb + i];
    }
    for (int i = 0; i < n2; i++)
    {
        arr2[i] = arr[mid1 + i + 1];
    }
    for (int i = 0; i < n3; i++)
    {
        arr3[i] = arr[mid2 + i + 1];
    }

    int i = 0, j = 0, k = 0, z = lb;

    while (i <= n1 && j <= n2 && k <= n3 && z <= up)
    {
        if (arr1[i] < arr2[j] && arr1[i] < arr3[k])
        {
            arr[z++] = arr1[i++];
        }
        else if (arr2[j] < arr3[k])
        {
            arr[z++] = arr2[j++];
        }
        else
        {
            arr[z++] = arr3[k++];
        }
    }
}

void mergesort(int arr[], int lb, int up)
{
    if (lb < up)
    {
        int mid1 = lb + ((up - lb) / 3);
        int mid2 = lb + 2 * ((up - lb) / 3) + 1;
        mergesort(arr, lb, mid1);
        mergesort(arr, mid1 + 1, mid2);
        mergesort(arr, mid2 + 1, up);
        merge(arr, lb, mid1, mid2, up);
    }
}

void main()
{
    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    mergesort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
