// link: https://classroom.codingninjas.com/app/classroom/me/14169/content/260022/offering/3548853/problem/20
#include<iostream>
#include<algorithm>
using namespace std;
////////////// time complexity : O(n^2)
/*
int pairSum(int *arr, int n, int num)
{
    int count=0;
	for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]+arr[j]==num)
                count++;
        }
    }
   return count; 
}
*/
/////////////// time complexity : O(nlogn)
int pairSum(int *arr, int n, int num)
{
    int c=0,c1=0,c2=0;
    sort(arr,arr+n);
    int i=0,j=n-1;
    while(i<j)
    {
        c1=0;
        c2=0;
        if(arr[i]+arr[j]==num)
        {
        ///// for repeating elements
            while(i<j&&arr[i]==arr[i+1])
            {
                c1++;
                i++;
            }
            while(j>i&&arr[j]==arr[j-1])
            {
                c2++;
                j--;
            }
            ///////// if all elements which sum to target are same (E.g. 2 2 2 2)
            if(i==j)
            {
            c=c+c1*(c1+1)/2;   
            }
            
            else if(c1!=0 || c2!=0)
            {
                c=c+(c1+1)*(c2+1);
                i++;
                j--;
                
            }
            else
            {
                c++;
                i++;
                j--;
            }
        
        }
 
        else if(arr[i]+arr[j]<num)
            i++;
        else
            j--;
    }
    return c;
}
