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


int main()
{
 ios_base::sync_with_stdio(0);

 fi;fo;

 string in="";

 for(int i=0;i<2500;i++)
    in+=('a' + (rand()%25) );

  for(int i=0;i<in.sz;i++)
  {
       if( ('a'<=in[i])&& (in[i]<='z') )
        continue;

        cout<<"error\n";
  }

 cout<<in<<endl;

 return 0;

}
