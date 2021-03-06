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

ll dp[1<<10];
int p[1<<10];

#define mod 1000000007

int main()
{
 ios_base::sync_with_stdio(0);

 int n;

 cin>>n;

 for(int i=1;i<=n;i++)
     cin>>p[i];

  dp[1]=1;

  for(int i=2;i<=n;i++)
  {
         ll sm=1;

          for(int j=p[i];j<i;j++)
             sm=(sm+ dp[j] +1 )%mod;

          dp[i]=sm;
  }

   ll ans=0;

   for(int i=1;i<=n;i++)
       ans=(ans+dp[i]+1)%mod;

  cout<<ans<<endl;



 return 0;

}
