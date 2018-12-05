#include<bits/stdc++.h>
using namespace std;

  int rodCut(int price[],int n)
  {
    vector<int>T(n+1,0);  // intialise max profit to 0


    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=i;j++)   //not j<=n
      {
        T[i]=max(T[i],price[j-1]+T[i-j]);  //type the exact reverse cond. be conscious of what u type!!

      }
        //return doesn't come here

    }

return T[n];
  }


int main()
{
  int price[]={1,5,8,9,10,17,17,20};
  int rodLen=4;

  cout<<"Profit is "<<rodCut(price,rodLen)<<"\n";

  return 0;

}
