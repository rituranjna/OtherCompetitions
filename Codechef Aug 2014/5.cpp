#include <bits/stdc++.h>
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
#define print(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );
/*Solution code starts here */

#define mod 1000000007

vector <int> parse(string s, string c)
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

  vector<int> ret;

  for(int i=0;i<ans.size();i++)
     ret.pb( atoi(ans[i].c_str()) );

  return ret;
}

char tp[1000];

int n;
int can[105];
ll memo[105][1100];

ll solve( int id, int mask)
{
    if(id==101)
    {
        if(mask==((1<<n)-1) )
             return 1;
        return 0;
    }

    if( memo[id][mask]!=-1)
         return memo[id][mask];

    ll ans=0;

   //taking atleat one
    for(int i=0;i<n;i++)
         if( can[id]&(1<<i) )
            if( (mask&(1<<i))==0)
            {
                int new_mask=(mask|(1<<i));
                ans=ans+solve(id+1,new_mask);
                ans=ans%mod;
            }

     ans=ans+solve(id+1,mask);
     ans=ans%mod;

    return memo[id][mask]=ans;
}

void solve()
{
   fill(can,0);


   string input;

   getline(cin,input);

    n=atoi( input.c_str() );

   for(int i=0;i<n;i++)
   {
       getline(cin,input);

        vector<int> all=parse(input , " ");

        for(int j=0;j<all.sz;j++)
        {
            can[ all[j] ]=can[ all[j] ]|(1<<i);
        }
   }

   fill( memo , -1);

   printf("%lld\n",solve(1,0) );
}

int main()
{
 int test;

 string input;

 getline(cin,input);

 test=atoi( input.c_str() );

 while(test--)
 {
     solve();
 }

 return 0;

}
