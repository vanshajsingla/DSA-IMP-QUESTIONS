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
  // bubble sort
  for(int i=0;i<n-1;i++) // n-1 passes => bcoz 1st element will automatically come at its correct place. So, no need to run a pass for it. 
  {
    for(int j=0;j<n-i-1;j++) //n-i-1  --> n-1 => bcoz for n elements we have to do n-1 comparisons
    {                                   //n-i => bcoz i elements are already at there correct position
        if(arr[j]>arr[j+1])
        {
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
  }
  for(int i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }

} 