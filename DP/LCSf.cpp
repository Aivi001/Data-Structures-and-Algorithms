#include<bits/stdc++.h>
using namespace std;

int lookup[20][20];


        void LCSlen(string x,string y,int m,int n)
    {
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(x[i-1]==y[j-1])
                    lookup[i][j]=lookup[i-1][j-1]+1;
                else
                    lookup[i][j]=max(lookup[i-1][j],lookup[i][j-1]);

            }
        }

    }

 vector<string> LCS(string x,string y,int m,int n)
 {
     if(m==0||n==0)
     {
         vector<string>v(1);
         return v;
     }

     if(x[m-1]==y[n-1])
     {
         vector<string>lcs=LCS(x,y,m-1,n-1);

         for(string &str:lcs)
            str.push_back(x[m-1]);

        return lcs;   //this!!
     }

     if(lookup[m-1][n]>lookup[m][n-1])
        return LCS(x,y,m-1,n);
     if(lookup[m][n-1]>lookup[m-1][n])
        return LCS(x,y,m,n-1);

    vector<string>top=LCS(x,y,m-1,n);
    vector<string>left=LCS(x,y,m,n-1);

    top.insert(top.end(),left.begin(),left.end());

    return top;
}


 set<string> LCS(string x,string y)
{
    int m=x.length(),n=y.length();
    LCSlen(x,y,m,n);
    vector<string> v=LCS(x,y,m,n);
    set<string> lcs(make_move_iterator(v.begin()),make_move_iterator(v.end()));
    return lcs;

}

int main()
{
  string x="ABCBDAB",y="BDCABA";
    set<string>lcs=LCS(x,y);
    for(string str:lcs)
        cout<<str<<endl;
    return 0;
}
