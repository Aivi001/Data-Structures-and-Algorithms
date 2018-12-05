/*
#include<bits/stdc++.h>
using namespace std;

bool subSum(int arr[],int n,int sum)
{
    if(sum==0)
      return true;
    if(n<0||sum==0)
      return false;

    bool include=subSum(arr,n-1,sum-arr[n]);
    bool exclude=subSum(arr,n-1,sum);

    return include||exclude;
}

bool partition(int arr[],int n)
{
  int sum=0;
  for(int j=0;j<n;j++)
    sum+=arr[j];

  return !(sum&1)&& subSum(arr,n-1,sum/2);
}

int main()
{
  int arr[]={7,3,1,5,4,8};

  int n=sizeof(arr)/sizeof(arr[0]);

  partition(arr,n)?cout<<"Yes\n":cout<<"No\n";

  return 0;

}
*/

#include<bits/stdc++.h>
using namespace std;

bool subSum(int arr[],int n,int sum)
{
    if(sum==0)
      return true;
    if(n<0||sum==0)
      return false;

    bool include=subSum(arr,n-1,sum-arr[n]);
    bool exclude=subSum(arr,n-1,sum);

    return include||exclude;
}

bool partition(int arr[],int n)
{
  int sum=0;
  for(int j=0;j<n;j++)
    sum+=arr[j];

  return !(sum%3)&&subSum(arr,n-1,sum/3);
}

int main()
{
  int arr[]={1,1,1,1,1,1,3};

  int n=sizeof(arr)/sizeof(arr[0]);

  partition(arr,n)?cout<<"Yes\n":cout<<"No\n";

  return 0;

}
