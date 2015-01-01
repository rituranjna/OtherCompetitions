#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(s) ((int)(s.size()))
#define bg begin()
#define en end()
#define Y second
#define X first
typedef long long ll;
#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)
const double pi     =   acos(-1.0);
const double eps    =   1e-8;
#define print(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );
/*Solution code starts here */

#define maxn 10000

int  order[maxn];
ll val[maxn];

int N;
int day;

ll solve( int  up , int down)
{
    vector<int> tp;

    for(int i=1;i<=day;i++)
         if( (order[i] == up) ||  ( order[i] == down ) )
             tp.pb( i );

    ll ans=0;

    int a=up,b=down;


    for(int i=0;i<sz(tp);i++)
         if( order[tp[i]] == up)
           continue;
         else
           {
               ans+=val[up];
               swap(up,down);
           }

    // cout<<a<<"  "<<b<<"  "<<ans<<endl;

     return ans;
}

int main()
{
 ios_base::sync_with_stdio(0);

 cin>>N>>day;

 for(int i=1;i<=N;i++)
     cin>>val[i];

 for(int i=1;i<=day;i++)
     cin>>order[i];


 ll ans=0;


 for(int i=1;i<=N;i++)
     for(int j=i+1;j<=N;j++)
     {
        ans+=min( solve(i,j)  , solve(j,i) );
     }

 cout<<ans<<endl;

 return 0;

}
