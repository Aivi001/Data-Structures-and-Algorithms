#include<bits/stdc++.h>
using namespace std;

int ceilIndex(int arr[],vector<int>&t,int l,int r,int k) //&t important
    {
        while(r-l>1)
        {
            int m=l+(r-l)/2;
            if(arr[t[m]]>=k)
                r=m;
            else
                l=m;
        }
        return r;
    }

    void LIS(int arr[],int n)
    {
        vector<int>tail(n,0);
        vector<int>prev(n,-1);

        int len=1;

        for(int i=1;i<n;i++)   //i=1 not =0;
        {
            if(arr[i]<arr[tail[0]])
                tail[0]=i;  //not arr[i];
            else if(arr[i]>arr[tail[len-1]])
                {
                    prev[i]=tail[len-1];
                    tail[len++]=i;
                }
            else
                {
                    int pos=ceilIndex(arr,tail,-1,len-1,arr[i]);
                    prev[i]=tail[pos-1];
                    tail[pos]=i;

                }
        }

                  for(int j=tail[len-1];j>=0;j=prev[j])
                {
                    cout<<arr[j]<<"\t";
                }
                cout<<"\n";
                cout<<"Length of LIS: "<<len<<"\n";  //not sizeof(prev); its 24 here

    }


int main()
{
  int arr[]={2,3,7,11,8,10,13,6};
  int n=sizeof(arr)/sizeof(arr[0]);
  LIS(arr,n);

}
