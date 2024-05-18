#include <stdio.h>
int countpairswithdiff(int arr[], int n, int key)
{
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] - arr[i] == key || arr[i] - arr[j] == key)
            {
                count++;
            }
        }
    }
    return count;
}
int main()
{
    int T;
    printf("enter no.of test cases");
    scanf("%d", &T);
    while (T--)
    {
        int n, key;
        printf("enter no. of values to input");
        scanf("%d", &n);
        int arr[n];
        printf("enter values ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        printf("enter key");
        scanf("%d", &key);
        int result = countpairswithdiff(arr, n, key);
        printf("%d\n", result);
    }
    return 0;
}
