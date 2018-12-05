#include<bits/stdc++.h>
using namespace std;

    int leven(string x,int m,string y,int n)
    {
        int t[m+1][n+1]={0};

        for(int i=1;i<=m;i++)
            t[i][0]=i;
        for(int j=1;j<=n;j++)
            t[0][j]=j;
        int subCost;

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(x[i-1]==y[j-1])
                    subCost=0;
                else
                    subCost=1;
                t[i][j]=min(min(t[i-1][j]+1,t[i][j-1]+1),t[i-1][j-1]+subCost);

            }
        }
        return t[m][n];
    }


int main()
{
    string x="kitten",y="sitting";
    cout<<"Edit distance is "<<leven(x,x.length(),y,y.length())<<"\n";
    return 0;


}
