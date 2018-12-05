#include<bits/stdc++.h>
using namespace std;

bool find3Numbers(int A[],int n,int sum)
{
int i=0,j=0,curr;
unordered_set<int>s;  //time complexity of unorderd set is O(1) whereas for set it's O(n) 

for(i=0;i<n;i++)
{
s.insert(A[i]);
}

for(i=0;i<n;i++)
{
curr=sum+A[i];
if(s.find(curr)!=s.end())
	return true;
else
	s.insert(A[i]);


}
	return false;   //forgot

}


int main()
{
    int A[] = { 1, 4, 45, 6, 10, 8 };
    int sum =2;
    int arr_size = sizeof(A) / sizeof(A[0]);
 
    if (find3Numbers(A, arr_size, sum))
        cout << "Yes";
    else
        cout << "No";
 
    return 0;
}
