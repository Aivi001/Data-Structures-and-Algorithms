#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[],int lo,int hi,int x)
{

while(lo<=hi)
	{
int mid=lo+(hi-lo)/2;

if(arr[mid]>=x)
	hi=mid-1;
else
	lo=mid+1;
}
	return arr[lo];
}

int main()
{
  // Let us search 3 in below array
  int arr1[] = {1,3,5,7,21,45};
  int n = sizeof(arr1)/sizeof(arr1[0]);
  int key = 19;
   
  // Function calling
  cout << "Closest element to "<<key<<" is :" << 
           binarySearch(arr1,0,n-1, key);
            
  return 0;
}
