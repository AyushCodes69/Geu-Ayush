#include<iostream>
using namespace std;
void selection(int arr[],int n)
{
    int comp=0,s=0;
    for (int i = 0; i < n - 1; i++)
        {
        int m = i;
        for (int j = i + 1; j < n; j++)
         {
            if (arr[j] < arr[m])
            {
                m= j;
            }
        comp++;
        }
        int temp = arr[i];
        arr[i] = arr[m];
        arr[m] = temp;
        s++;
    }
    cout << "number of comparison " << comp << endl;
    cout << "number of swap" << s << endl;
    cout << "sorted array" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int i,j,n,x;
    cout<<"ENTER NUMBER OF ITERATION"<<endl;
    cin>>x;
    for(i=1;i<=x;i++)
    {
    cout<<"ENTER SIZE"<<endl;
    cin>>n;
    int arr[n];
    cout<<"ENTER ELEMENTS IN ARRAY"<<endl;
    for(j=0;j<n;j++)
    {
        cin>>arr[j];
    }
    selection(arr,n);

    }
}
