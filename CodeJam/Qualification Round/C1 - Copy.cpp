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

int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};

int val[5][5];
int in[5][5];//0 if empty ,1 if mines

bool done[5][5];

int row,col,mines;

bool cool;

void dfs( int x, int y)
{
     if( done[x][y])
         return ;

     done[x][y]=true;

     for(int i=0;i<8;i++)
     {
          int nx=x+dx[i];
          int ny=y+dy[i];

          if( nx < 0 || nx >=row || ny <0 || ny >=col)
           continue;

          if( val[nx][ny]==0)
             dfs(nx,ny);
     }

}

void process()
{
     fill(val,0);

     for(int i=0;i<row;i++)
         for(int j=0;j<col;j++)
           if( in[i][j]==1)
        {
             val[i][j]=20;

             for(int k=0;k<8;k++)
             {
                  int tx=i+dx[k];
                  int ty=j+dy[k];

                  if( tx <0 || tx>=row || ty<0 || ty >=col)
                    continue;

                  val[tx][ty]++;
             }
     }

     cout<<"\n\n\nin\n";
     for(int i=0;i<row;i++,cout<<endl)
         for(int j=0;j<col;j++)
            cout<<in[i][j]<<" ";

     cout<<"\nVal is\n";

          for(int i=0;i<row;i++,cout<<endl)
         for(int j=0;j<col;j++)
          cout<<val[i][j]<<" ";


     //start dfs , all '0' must be in compnent



     int x=-1,y=-1;

    //find a zero
       for(int i=0;i<row;i++)
          for(int j=0;j<col;j++)
            if( val[i][j]==0)
       {
           x=i;
           y=j;
           break;
       }

       if(x==-1)//kow zero wala nahi mila
       {
           cool=false;
            return ;
       }

       fill(done,0);

       dfs(x,y);

       //all zero must be connexted
       for(int i=0;i<row;i++)
         for(int j=0;j<col;j++)
           if( val[i][j]==0)
              if( done[i][j]==false)
           {
             cool=false;
             return;
           }

       //checking for all non-mines coverd by ZEROs

       for(int i=0;i<row;i++)
         for(int j=0;j<col;j++)
           if( val[i][j]==0)
           {

              for(int k=0;k<8;k++)
               {
                  int tx=i+dx[k];
                  int ty=j+dy[k];

                  if( tx <0 || tx>=row || ty<0 || ty >=col)
                    continue;

                   if( val[tx][ty] <=8)
                     done[tx][ty]=true;
              }
        }


        //checking if all non-mones are coverd

        for(int i=0;i<row;i++)
             for(int j=0;j<col;j++)
               if( val[i][j]<=8)
                  if( !done[i][j])
        {
            cool=false;
            return;
        }

}

void solve( int t)
{
    cin>>row>>col>>mines;

    cout<<row<<"  "<<col<<"  "<<mines<<endl;

    bool mila=false;

    for(int mask=0;mask<(1<<(row*col) ) ;mask++)
      if( __builtin_popcount(mask)==mines)
    {

          cool=true;//abhi tak sahi hai

          for(int i=0;i<row;i++)
             for(int j=0;j<col;j++)
            {
                 int id=i*col+j;

                 if( mask&(1<<id) )
                     in[i][j]=1;
                 else
                     in[i][j]=0;


                  cout<<id<<"  "<<(mask&(1<<id))<<"  "<<i<<" "<<j<<endl;
            }

            cout<<"\nHere maks is "<<mask<<endl;;

            process();

            if(cool)
            {
                mila=true;
                break;
            }
    }

   printf("Case #%d:\n",t);

    if( !mila)
    {
       printf("Impossible\n");
       return;
    }

    bool zd=0;

    for(int i=0;i<row;i++,cout<<endl)
         for(int j=0;j<col;j++)
            if( val[i][j]<=8)
              {
                    if( val[i][j]==0)
                    {
                        if(zd==true)
                         cout<<".";
                        else
                        {
                            cout<<"c";
                            zd=true;
                        }
                    }
                   else
                      cout<<".";
              }
              else
              {
                  cout<<"*";
              }
}


int main()
{
 ios_base::sync_with_stdio(0);

  int test;

  cin>>test;

  for(int i=1;i<=test;i++)
  {
        solve(i);
  }

 return 0;

}
