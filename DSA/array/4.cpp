#include<bits/stdc++.h>
using namespace std;

int ascendingBinarySearch(int arr[], int low,
                           int high, int key)
{
   while (low <= high)
   {
       int mid = low + (high - low) / 2;
       if (arr[mid] == key)
           return mid;
       if (arr[mid] > key)
           high = mid - 1;
       else
           low = mid + 1;
   }
    return -1;
}
 
int descendingBinarySearch(int arr[], int low, 
                            int high, int key)
{
   while (low <= high)
   {
       int mid = low + (high - low) / 2;
       if (arr[mid] == key)
           return mid;
       if (arr[mid] < key)
           high = mid - 1;
       else
           low = mid + 1;
   }
    return -1;
}


int searchBitonic(int arr[],int n,int k,int x)
{
if(k>arr[x])
	return -1;
int temp=ascendingBinarySearch(arr,0,x,k);
	if(temp!=-1)
	return temp;
temp=descendingBinarySearch(arr,x+1,n-1,k);
}


int findBitonicPoint(int arr[],int n,int l,int r)
{
 int mid=l+(r-l)/2;

if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1])
	return mid;

else if(arr[mid]>arr[mid-1]&&arr[mid]<arr[mid+1])
	return findBitonicPoint(arr,n,mid,r);

else if(arr[mid]<arr[mid-1]&&arr[mid]>arr[mid+1])
	return findBitonicPoint(arr,n,l,mid);
}

int main() {
    int arr[] = {-8, 1, 2, 3, 4, 5, -2, -3};
    int key = 5;
    int n ,l, r;
    n = sizeof(arr)/sizeof(arr[0]);
    l = 0;
    r = n - 1;
    int index;
    index = findBitonicPoint(arr, n, l, r);
      
    int x = searchBitonic(arr, n, key, index);
     
    if (x == -1)
       cout << "Element Not Found"<<endl;
    else
       cout << "Element Found at index " << x<<endl;
     
  return 0;
}
