#include<iostream>
using namespace std;
void merge(int arr[],int si,int ei)
{
    int i=si,mid=si+(ei-si)/2,j=mid+1,k=0,l=0;
    int arr2[ei-si+1];
    while(i<=mid&&j<=ei)
    {
        if(arr[i]<=arr[j])
        {
            arr2[k]=arr[i];
            i++;
            k++;
        }
        else
        {
            arr2[k]=arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        arr2[k]=arr[i];
            i++;
            k++;
    }
    while (j<=ei)
    {
        arr2[k]=arr[j];
            j++;
            k++;
    }
    for(int i=si;i<=ei;i++)
    {
        arr[i]=arr2[l];
        l++;
    }
    
}
 void mergeSort(int arr[],int si,int ei)
 {
    if(si<ei)
    {
        int mid=si+(ei-si)/2;
        mergeSort(arr,0,mid);
        mergeSort(arr,mid+1,ei);
        merge(arr,si,ei);
    }
 }
int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  // merge sort
  mergeSort(arr,0,n-1);
  for(int i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
} 