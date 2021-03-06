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


#define pii pair<int,int>

vector<pii> input,save;

bool done[1005];

vector< vector<int> > tp,ans;
int sum,ts;




int dist( int x, int y , int a ,int b)
{
    int s=(x-a)*(x-a) + (y-b)*(y-b);

    double ret=sqrt( (double)s);

    return ceil(ret);
}

vector<pii> rem;

vector<int> solve( vector<pii> in)
{
    int n=in.sz;

    int x=(in[0].X+in[n-1].X)/2;
    int y=(in[0].Y+in[n-1].Y)/2;
    int r=max( dist(in[0].X , in[0].Y , x , y) , dist( in[n-1].X , in[n-1].Y , x , y) );

        if(r<1)
             r=1;

        ts+=r;

    for(int i=0;i<n;i++)
         done[i]=false;

    for(int i=0;i<n;i++)
         if( (x-in[i].X)*(x-in[i].X) + (y-in[i].Y)*(y-in[i].Y) <= r*r )
           done[i]=true;

      rem.clear();

    for(int i=0;i<n;i++)
         if( !done[i] )
            rem.pb( in[i] );


    vector<int> ans;
            ans.pb(x);
            ans.pb(y);
            ans.pb(r);

            return ans;



}


void process( vector<pii> curr)
{
       while(curr.sz)
       {
            tp.pb( solve(curr) );
            curr=rem;
       }
}

void init( int n , int k)//n ko k part me k >=1
{

     int st=n/k;

     for(int i=1;i<=k-1;i++)
     {
          vector<pii> tp;
          for(int j=st*(i-1);j<st*i;j++)
             {
                tp.pb( input[j] );
             }

            process(tp);
     }

     vector<pii> tp;
     for(int j=st*(k-1);j<n;j++)
         {
            tp.pb( input[j]);
         }

      process(tp);

}

bool comp( pii a, pii b)
{
    return (a.X*a.X+a.Y*a.Y<b.X*b.X+b.Y*b.Y);
}

bool comp2( pii a, pii b)
{
    return (a.X*a.X+a.Y*a.Y > b.X*b.X+b.Y*b.Y);
}

bool comp3( pii a, pii b)
{
    return (a.X*b.Y < b.Y*a.X);
}

int main()
{
 ios_base::sync_with_stdio(0);

 int n;

 cin>>n;

 int x,y;

 for(int i=0;i<n;i++)
 {
     cin>>x>>y;
     input.pb( mp(x,y) );
 }


  sum=(1<<25);

  /*************************First Compare**//////////////////////

 sort( input.bg,input.en);

    for(int part=1;part<=n;part++)
    {

         tp.clear();
         ts=0;

         init(n,part);

         if(sum > ts )
         {
             ans=tp;
             sum=ts;
         }
    }

      /*************************Second Compare**//////////////////////

       sort( input.bg,input.en,comp);

    for(int part=1;part<=n;part++)
    {

         tp.clear();
         ts=0;

         init(n,part);

         if(sum > ts )
         {
             ans=tp;
             sum=ts;
         }
    }

           /*************************3Compare**//////////////////////

       sort( input.bg,input.en,comp2);

    for(int part=1;part<=n;part++)
    {

         tp.clear();
         ts=0;

         init(n,part);

         if(sum > ts )
         {
             ans=tp;
             sum=ts;
         }
    }

          /*************************4 Compare**//////////////////////

       sort( input.bg,input.en,comp3);

    for(int part=1;part<=n;part++)
    {

         tp.clear();
         ts=0;

         init(n,part);

         if(sum > ts )
         {
             ans=tp;
             sum=ts;
         }
    }

     cout<<ans.sz<<endl;

 for( int i=0;i<ans.sz;i++,cout<<endl)
     for(int j=0;j<3;j++)
      cout<<ans[i][j]<<" ";

 return 0;

}
