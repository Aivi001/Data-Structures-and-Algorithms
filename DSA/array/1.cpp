#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr1[],int lo,int hi,int key)
{
if(hi<lo)
	return -1;
int mid=lo+(hi-lo)/2;
if(key==arr1[mid])
return mid;

else if(key>arr1[mid])
	return binarySearch(arr1,mid+1,hi,key);
else
	return binarySearch(arr1,lo,mid-1,key);
}


int findPivot(int arr1[],int lo,int hi)
{
if(hi<lo)
	return -1;
if(hi==lo)
	return lo;

int mid=lo+(hi-lo)/2;

if(mid<hi&&arr1[mid]>arr1[mid+1])
	return mid;
else if(mid>lo && arr1[mid]<arr1[mid-1])
	return mid-1;

if(arr1[lo]>=arr1[mid])
	return findPivot(arr1,lo,mid-1);
else 
	return findPivot(arr1,mid+1,hi);
}


int pivotedBinarySearch(int arr1[],int n,int key)
{

int pivot=findPivot(arr1,0,n-1);
if(pivot==-1)
return binarySearch(arr1,0,n-1,key);

if(arr1[pivot]==key)
	return pivot;
else if(key>=arr1[0])
	return binarySearch(arr1,0,pivot-1,key);
else
	return binarySearch(arr1,pivot+1,n-1,key);
}


int main()
{
  // Let us search 3 in below array
  int arr1[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
  int n = sizeof(arr1)/sizeof(arr1[0]);
  int key = 3;
   
  // Function calling
  cout << "Index of the element is : " << 
           pivotedBinarySearch(arr1, n, key);
            
  return 0;
}
