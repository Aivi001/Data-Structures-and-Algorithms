#include<bits/stdc++.h>
using namespace std;

bool find3Numbers(int A[],int n,int sum)
{
int i=0,j=0,curr;
unordered_set<int>s;  //time complexity of unorderd set is O(1) whereas for set it's O(n) 

for(i=0;i<n-2;i++)
{
curr=sum-A[i];

for(j=i+1;j<n;j++)
{
if(s.find(curr-A[j])!=s.end())
	return true;
else
	s.insert(A[j]);

}

}
	return false;   //forgot

}


int main()
{
    int A[] = { 1, 4, 45, 6, 10, 8 };
    int sum = 22;
    int arr_size = sizeof(A) / sizeof(A[0]);
 
    if (find3Numbers(A, arr_size, sum))
        cout << "Yes";
    else
        cout << "No";
 
    return 0;
}
