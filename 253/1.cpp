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

 int cont[255]; fill( cont,0);

 char in[1005];

 cin.getline(in,1005);

int n=strlen(in);

 for(int i=0;i<n;i++)
     cont[ in[i] ]++;

 int ans=0;

 for(int i='a';i<='z';i++)
      if( cont[i]>0)
      ans++;

 cout<<ans<<endl;

 return 0;

}
