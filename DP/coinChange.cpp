#include<bits/stdc++.h>
using namespace std;

int minCoins(int stock[],int n,int money)
{
  vector<int>T(money+1);
  T[0]=0; //base case , 0 coins for tot=0

  for(int i=1;i<=money;i++)   // important note : =0 to <=money 
  {
      T[i]=9999;
  int res=9999;

  for(int c=0;c<n;c++)   //for each coin
  {
    if(i-stock[c]>=0)
      res=T[i-stock[c]];

      if(res!=9999)
        T[i]=min(T[i],res+1);


  }
}
return T[money];
}

int main()
{
int stock[]={1,2,3,4};

int n=sizeof(stock)/sizeof(stock[0]);

int money=15;

cout<<"Minimum number of coins req is "<<minCoins(stock,n,money)<<"\n";

return 0;

}
