#include<iostream>
using namespace std;
void insertion(int arr[], int n) {
    int i, comp = 0, shift = 0, j = 0, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comp++;
            arr[j + 1] = arr[j];
            shift++;
            j = j - 1;
        }
        arr[j + 1] = key;
        shift++;
    }
    cout << "number of comparison " << comp << endl;
    cout << "number of shift " << shift << endl;
    cout << "sorted array" << endl;
    for (i = 0; i < n; i++)
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
    insertion(arr,n);

    }
}
