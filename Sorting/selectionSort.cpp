#include<iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  // selection sort
  int mini,mini_idx;
  for(int i=0;i<n-1;i++) // n-1 passes bcoz we have to find smallest element n-1 times 
  {
     mini=arr[i],mini_idx=i;
    for(int j=i+1;j<n;j++) // j=i+1 => bcoz  i elements are already sorted we have to find min. from rest n-i elements
    {
        if(arr[j]<mini)
        {
            mini=arr[j];
            mini_idx=j;
        }
    }
    // Now, swap curr element with min element
    int temp=arr[i];
    arr[i]=mini;
    arr[mini_idx]=temp;
  }
  for(int i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }

} 