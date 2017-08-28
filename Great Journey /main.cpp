#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second

const int N = 5 * 100005;
int n,t;
int a[N], b[N];
int vis[N];

int bfs()
{
    queue<int> q;
    q.push(0);
    memset(vis,-1,sizeof vis);
    vis[0] = 0;

    return -1;
}

int main()
{

//#ifndef ONLINE_JUDGE
//    freopen("/home/montaf/Documents/in.in", "r",stdin  ) ;
////    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
//#endif

    freopen("great.in","r",stdin);


    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++) scanf("%d",a+i);
        for(int i=0; i<n; i++) scanf("%d",b+i);
        int ans = bfs();
        printf("%d\n",ans);
    }
    return 0;
}
