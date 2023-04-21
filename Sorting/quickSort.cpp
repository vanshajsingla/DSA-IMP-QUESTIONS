#include<iostream>
using namespace std;
int partition(int arr[],int si,int ei)
{
   int pivot=arr[si],c=0;
   // count no. of elements <= pivot 
   //bring pivot to correct pos.
   for(int i=si+1;i<=ei;i++)
   {
    if(arr[i]<=pivot)
    {
        c++;
    }
   } 
   int pi=si+c;
   swap(arr[si],arr[pi]);
    // bring all elements smaller than pivot to left & all elements greater than pivot to right
    int i=si,j=ei;
    while(i<pi&&j>pi)
    {
        while(arr[i]<=pivot)
        i++;
        while(arr[j]>pivot)
        j--;
        if(i<pi&&j>pi)
        {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    return pi;
}
 void quickSort(int arr[],int si,int ei)
 {
    if(si<ei)
    {
        int pi=partition(arr,si,ei);
        quickSort(arr,si,pi-1);
        quickSort(arr,pi+1,ei);
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
  // quick sort
  quickSort(arr,0,n-1);
  for(int i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
} 