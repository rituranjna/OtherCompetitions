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

const int mod=1000000007LL;

#define maxn 200005

int  dp[2][maxn];

int  memo[2][maxn];
int req[1005];

int R,G;

int height(int h , int gd)//h th height pe rakhne ja rah ahai
{
    int x=(h&1);

    if( memo[x][gd]!=-1)
         return memo[x][gd];

    int rd=req[h-1]-gd;

    int r_rem=R-rd;
    int g_rem=G-gd;

    int ans=0;

    //keep r
    if( h <=r_rem)
    {
        ans=max(ans, height(h+1,gd)+1 );
    }

    if( h <= g_rem)
    {
        ans=max( ans, height( h+1, gd + h )+1 );
    }

    return memo[x][gd]=ans;
}


//int cont[2][200005];

int sheight(int h , int gd)//h th height pe rakhne ja rah ahai
{
    int x=(h&1);

    if( memo[x][gd]!=-1)
         return memo[x][gd];

    int rd=req[h-1]-gd;

    int r_rem=R-rd;
    int g_rem=G-gd;

    int ans=0;

    //keep r
    if( h <=r_rem)
    {
        ans=max(ans, height(h+1,gd)+1 );
    }

    if( h <= g_rem)
    {
        ans=max( ans, height( h+1, gd + h )+1 );
    }

    return memo[x][gd]=ans;
}

int main()
{
 ios_base::sync_with_stdio(0);

 for(int i=0;i<=1000;i++)
 {
     req[i]=i*(i+1)/2;
 }

 fill(memo,-1);

 cin>>R>>G;

 fill(dp,0);

 for(int h=900;h>=1;h--)
 {
       int curr=(h&1);
       int prev=((h+1)&1);

       for(int gd=0;gd<=G;gd++)
          {
                   dp[curr][gd]=0;

                    int rd=req[h-1]-gd;
                    int r_rem=R-rd;
                    int g_rem=G-gd;


                if( h <=r_rem)
                {
                    dp[curr][gd]=max(dp[curr][gd], dp[prev][gd]+1 );
                }

                if( h <= g_rem)
                {
                    dp[curr][gd]=max(dp[curr][gd], dp[prev][gd+h]+1 );
                }
          }

    }

    int ht=dp[1][0];

    cout<<" Height  is "<<dp[1][0]<<endl;


     for(int h=900;h>=1;h--)
     {
       int curr=(h&1);
       int prev=((h+1)&1);

       for(int gd=0;gd<=G;gd++)
          {
                   dp[curr][gd]=0;

                    int rd=req[h-1]-gd;
                    int r_rem=R-rd;
                    int g_rem=G-gd;


                if( h <=r_rem)
                {
                    dp[curr][gd]=max(dp[curr][gd], dp[prev][gd]+1 );
                }

                if( h <= g_rem)
                {
                    dp[curr][gd]=max(dp[curr][gd], dp[prev][gd+h]+1 );
                }
          }
     }

     int x=
     for(int i=0;i<maxn;i++)




 int a=2*mod;

 cout<<a<<endl;

 return 0;

}
