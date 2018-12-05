#include <bits/stdc++.h>
using namespace std;

int* sortK(int*arr,int n,int k)
{
	priority_queue<int , vector<int> , greater<int> >pq;
	int i;
	int* a=new int [3];


	for(i=0;i<=k;i++)
		pq.push(arr[i]);

	int t;
	for(i=k+1,t=0;t<n;i++,t++)  //no need i<n condition
	{
		if(i<n)
		{	
			a[t]=pq.top();
			pq.pop();
			pq.push(arr[i]);
		}
		else{
			a[t]=pq.top();
			pq.pop();
		}

	}
	return a;
}

int main()
{
    int k = 3;
    int arr[] = {2, 6, 3, 12, 56, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int* ans=sortK(arr, n, k);
 
    cout << "Following is sorted array: ";
    for(k=0;k<n;k++)
    	cout<<ans[k]<<" ";
    cout<<"\n";
 
    return 0;
}