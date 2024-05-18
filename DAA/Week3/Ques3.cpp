#include<iostream>
using namespace std;
int par(int arr[],int l,int h)
{
    int key=arr[h];
    int i=l-1;
    for(int j=l;j<=h;j++)
    {
        if(arr[j]<key)
        {
            i++;
            int t=arr[i];
            arr[i]=arr[j];
            arr[j]=t;
        }
    }
    int t=arr[i+1];
    arr[i+1]=arr[h];
    arr[h]=t;
    return(i+1);
}
void quicksort(int arr[],int l,int h)

{
  if(l<h)
  {
      int p=par(arr,l,h);
      quicksort(arr,l,p-1);
      quicksort(arr,p+1,h);
  }
}
int main()
{
    int i,j,n,x,k,f=0;
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
    quicksort(arr,0,n-1);
    quicksort(arr,0,n-1);
    for(k=0;k<n;k++)
    {
         if(arr[k]==arr[k+1])
        {
            f=1;
            cout<<"YES"<<endl;
            break;
        }
        else
           f=0;
    }
    if(f==0)
    {
        cout<<"NO"<<endl;
    }
    }

    }
