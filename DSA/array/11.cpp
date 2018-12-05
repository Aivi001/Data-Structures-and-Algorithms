#include<bits/stdc++.h>
using namespace std;

void swa(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort012(int a[],int n)
{

int lo=0,hi=n-1,mid=0;

while(mid<=hi)
{

	switch(a[mid])
	{
	case 0: 
		swa(&a[lo++],&a[mid++]);
		break;
	case 1:
		mid++;
		break;
	case 2:
		swa(&a[mid],&a[hi--]);
		break;

	}


	}

}


int main()
{
    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int i;
 
    sort012(arr, arr_size);
 
    printf("array after segregation ");
   	for(i=0;i<arr_size;i++)
	cout<<arr[i]<<" ";
	cout<<"\n";
 
    //getchar();
    return 0;
}


