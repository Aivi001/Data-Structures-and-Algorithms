#include<bits/stdc++.h>
using namespace std;

void wordBreak(vector<string> & dict,string str,string o)
{
  if(str.size()==0)
  {
    cout<<o<<"\n";
    return;
  }

  for(int i=1;i<=str.size();i++)
  {
    string prefix=str.substr(0,i);

    if(find(dict.begin(),dict.end(),prefix)!=dict.end())  //dict.find(prefix) is possible only in string,not in vector
        wordBreak(dict,str.substr(i),o+" "+prefix);

  }
}



int main()
{
  vector<string> dict = { "this","th","is","famous","Word","b","r","e","a","k","br","bre","brea","ak","break","problem"};

  string str="Wordbreakproblem";

  wordBreak(dict,str,"");

  return 0;
}
