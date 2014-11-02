#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <fstream>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz size()
#define bg begin()
#define en end()
#define Y second
#define X first
typedef long long ll;

#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

#define print(a) cout<<(#a)<<" = "<<a<<"  ";
#define println(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );

vector <string> parse(string s, string c)
{
  int len = c.length(), p = -len, np;
  vector <string> ans;

  do
    {
      np = s.find(c, p+len);
      ans.push_back(s.substr(p+len, np - p - len));
      p = np;
    }
  while (p != string::npos);

  return ans;
}


/*Solution code starts here */


double dp[2005][2005];
bool row[2005],col[2005];


int main()
{
 ios_base::sync_with_stdio(0);

 fill(row,0);
 fill(col,0);

 int N;
 int m;



 cin>>N>>m;

  int a=N,b=N;

 int x,y;

 for(int i=1;i<=m;i++)
 {
    cin>>x>>y;

    if(!row[x])
    {
        a--;
        row[x]=true;
    }

    if(!col[y])
    {
        b--;
        col[y]=true;
    }
 }

 dp[0][0]=0;

 for(int i=0;i<=a;i++)
     for(int j=0;j<=b;j++)
 {
      if(i==0 && j==0)
         continue;

      double r=i,c=j,nr=N-i,nc=N-j ,n=N;;

      dp[i][j]=1;

      if(i)
         dp[i][j]+=dp[i-1][j]*( r/n)*(nc/n);

      if(j)
         dp[i][j]+=dp[i][j-1]*(nr/n)*(c/n);

      if(i&&j)
         dp[i][j]+=dp[i-1][j-1]*(r/n)*(c/n);

        double pr=(nr/n)*(nc/n);

        dp[i][j]/=(1-pr);
 }

 cout<<dp[a][b]<<endl;

 return 0;

}
