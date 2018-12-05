#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[],int lo,int hi)
{
int mid;
while(lo<=hi)
{
 mid=lo+(hi-lo)/2;
if(arr[mid]==1&&arr[mid-1]==0)
	break;
else if(arr[mid]==1)
	hi=mid-1;
else
	lo=mid+1;
}
return mid;

}

void posOfFirstOne(int arr[])
{

int l=0,h=1;

while(arr[h]==0)
{
l=h;
h=2*l;
}

cout<<binarySearch(arr,l,h);
}


int main()
{
    int arr[] = { 0, 0, 1, 1, 1, 1 };
    posOfFirstOne(arr);
    return 0;
}
