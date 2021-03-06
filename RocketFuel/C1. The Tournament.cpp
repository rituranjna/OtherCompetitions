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
typedef long long ll;
#define pii pair<ll,ll>

ll n;
ll k;
ll pt[200];
ll est[200];



int main()
{
	 ios_base::sync_with_stdio(0);

	 cin>>n>>k;

	 for(int i=0;i<n;i++)
         cin>>pt[i]>>est[i];



     ll ans=-1;

    for(int mask=0;mask<(1<<n);mask++)
    {
         ll req=0;
         ll curr=0;

         int val[22];

          for(int i=0;i<n;i++)
              if( mask&(1<<i) )
                {
                 req+=est[i];
                 curr++;

                 val[i]=pt[i];
                }
               else
               {
                   val[i]=pt[i]+1;
               }

           int lost=0;

            for(int i=0;i<n;i++)
                   if( val[i] > curr )
                      lost++;
                    else if( val[i] == curr )
                    {
                           if( (mask&(1<<i))==0)
                               lost++;
                    }

             if( lost <=k-1)
             {
                   if( ans==-1)
                      ans=req;
                   else
                       ans=min( ans , req);
             }
    }

    cout<<ans<<endl;
 return 0;

}

