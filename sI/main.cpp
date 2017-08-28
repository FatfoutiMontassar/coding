#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define f first
#define s second
#define mp make_pair
#define pii pair<int,int>

int grid[505][505];
int dist[505][505];
int n,m,tc;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool check(int i,int j)
{
    return (i<n && i>-1 && j<m && j>-1);
}

int dij()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            dist[i][j] = -1;
        }
    }
    priority_queue<pair<int,pair<pii,int>>> q;
    q.push(mp(grid[0][0],mp(mp(0,0),0)));
    dist[0][0] = grid[0][0];
    while(!q.empty())
    {
        pair<int,pair<pii,int>> to = q.top();
        q.pop();
        int x = to.s.f.f;
        int y = to.s.f.s;
        int t = to.s.s;
        int maxi = to.f;

        if((x==(n-1)) && (y==(m-1))) return min(maxi,grid[x][y] - t);
        if(grid[x][y]-t <= 0) continue;
        t++;
        for(int i=0;i<4;i++)
        {
            int xx = x+dx[i];
            int yy = y+dy[i];
            if(check(xx,yy))
            {
                if(dist[xx][yy] < min(dist[x][y],grid[xx][yy]-t))
                {
                    dist[xx][yy] = min(dist[x][y],grid[xx][yy]-t);
                    q.push(mp(dist[xx][yy],mp(mp(xx,yy),t)));
                }

            }
        }

    }
    return -1;
}

int main(){

//#ifndef ONLINE_JUDGE
//    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
////    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
//#endif

fstream cin("ilove.in");

cin>>tc;
while(tc--)
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }
    int ans = dij();
    if(ans > -1) cout<<ans;
    else cout<<"impossible";
    cout<<endl;
}




    return 0;
}
