#include<bits/stdc++.h>
using namespace std;

  unordered_map<string,int>lookup;

  int knapsack(int v[],int w[],int n,int W)
  {
    if(W<0)
      return INT_MIN;
    if(n<0 || W<0)
      return 0;

    string key= to_string(n)+"|"+to_string(W);
    if(lookup.find(key)==lookup.end())
    {
        int include=v[n]+knapsack(v,w,n-1,W-w[n]);

        int exclude=knapsack(v,w,n-1,W);

        lookup[key]=max(include,exclude);

    }
    return lookup[key];

  }



int main()
{
  int v[]={20,5,10,40,15,25};
  int w[]={1,2,3,8,7,4};

  int W=10;

  int n=sizeof(v)/sizeof(v[0]);

  cout<<"Knapsack value is "<<knapsack(v,w,n-1,W)<<"\n";

}
