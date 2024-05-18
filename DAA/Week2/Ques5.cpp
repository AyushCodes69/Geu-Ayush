#include <stdio.h>
void findindices(int arr[], int n)
{
    int found = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = arr[i] + arr[j];
            int low = 0, high = n - 1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (arr[mid] == sum)
                {
                    printf("%d %d %d", i, j, mid);
                    found = 1;
                    break;
                }
                else if (arr[mid] < sum)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            if (found)
            {
                break;
            }
        }
        if (found)
        {
            break;
        }
    }

    if (!found)
    {
        printf("No sequence found\n");
    }
}

int main()
{
    int T;
    printf("enter no. of test cases");
    scanf("%d", &T);
    while (T--)
    {
        int n;
        printf("enter no.of values to input");
        scanf("%d", &n);
        int arr[n];
        printf("enter values");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        findindices(arr, n);
    }
    return 0;
}
