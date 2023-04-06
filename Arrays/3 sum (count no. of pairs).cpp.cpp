// link: https://classroom.codingninjas.com/app/classroom/me/14169/content/260022/offering/3548853/problem/28
///////// O(n^3)
/*
int tripletSum(int *arr, int n, int num)
{
	//Write your code here
    int count=0;
    for(int i=0;i<n-2;i++)
    {
       for(int j=i+1;j<n-1;j++)
       {
           for(int k=j+1;k<n;k++)
           {
               if(arr[i]+arr[j]+arr[k]==num)
                   count++;
           }
       }
    }
    return count;
}
*/
/////// O(n^2)
int tripletSum(int *arr, int n, int num)
{
    sort(arr,arr+n);
     int c=0,c1=0,c2=0;
for(int p=0;p<n-2;p++)
{
    int i=p+1,j=n-1;
   
    //int i=0,j=n-1;
while(i<j)
{
    c1=0;
    c2=0;
    if(arr[p]+arr[i]+arr[j]==num)
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
        ///////// for case like 2 2 2 2
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
 
    else if(arr[p]+arr[i]+arr[j]<num)
        i++;
    else
        j--;
}
}
    return c;
}
