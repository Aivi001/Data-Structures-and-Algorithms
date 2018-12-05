#include <bits/stdc++.h>
using namespace std;
 
 int kthLargest(int arr[],int n,int k)
 {
 	int i;
 	priority_queue<int ,vector<int>, greater<int> > pq;

 	for(i=0;i<k;i++)
 	{
 		pq.push(arr[i]);
 	}

 	for(i=k;i<n;i++)
 	{
 		//if(i<n-1)
 		//cout<<pq.top();
 		if(arr[i]>pq.top())
 		{
 			pq.pop();
 			pq.push(arr[i]);
 		}
 	}

 	cout<<"kth largest is "<<pq.top()<<"\n";
 }



int main()
{
   int arr[] = {10, 20, 11, 70, 50, 40, 100, 55};
   int k = 3;
   int n = sizeof(arr)/sizeof(arr[0]);
   kthLargest(arr, n, k);
   return 0;
}