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
  // insertion sort
  for(int i=1;i<n;i++) // i=1  bcoz single element is always sorted
  {
    for(int j=i;j>0;j--) // j=i => bcoz  we have to compare each element with all elements on its left one by one . swap if element is smaller than ele. on its left
        if(arr[j]<arr[j-1])
        {
            int temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
        }
        else
         break; // added break statement as we do not need to check for further elements as 
        //  ele. to left will already be > than curr ele. as left part is already sorted
        //  & adding this break statement also reduces best case complexity to O(n)
    }
  for(int i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
  } 