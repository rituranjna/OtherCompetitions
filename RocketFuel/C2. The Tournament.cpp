#include<algorithm>
#include<iostream>
#include<sstream>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<fstream>
#include<cctype>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<map>
#include<set>
using namespace std;

#define pb push_back
#define mp make_pair
#define Y second
#define X first

#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)

const double pi     =   acos(-1.0);
const double eps    =   1e-8;



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

int n;
int pt[105];
int ef[105];
int k;
int win;

int memo[105][105][105];

int solve( int curr , int bet , int done)//curr th pos , bet are better than manao , done jjit chuka hai
{
      if(curr==n)
      {
            if( bet < k)
                  if( done==win)
                     return 0;

            return (1<<30);
      }

      int &ans=memo[curr][bet][done];

      if(ans!=-1)
         return ans;

      ans=(1<<30);

      //Win with this curr
       if( pt[curr] <=win )
         ans=min( ans , solve(curr+1,bet , done+1 ) + ef[curr] );
       else
          ans=min( ans , solve(curr+1,bet+1,done+1) + ef[curr] );

       //lose this match

       if( pt[curr]+1 < win)
          ans=min( ans , solve(curr+1,bet,done) );
       else
          ans=min( ans , solve(curr+1,bet+1,done) );

       return ans;
}

int main()
{
	 ios_base::sync_with_stdio(0);

	 cin>>n>>k;

	 for(int i=0;i<n;i++)
         cin>>pt[i]>>ef[i];


     int ans=(1<<30);

     for(int i=0;i<=n;i++)
     {
          win=i;
         memset(memo,-1,sizeof(memo));
          ans=min( ans , solve(0,0,0) );
     }

     if( ans==(1<<30))
         cout<<"-1\n";
     else
         cout<<ans<<endl;



 return 0;

}
