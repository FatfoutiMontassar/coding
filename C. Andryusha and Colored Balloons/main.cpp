#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
int n ;
vector<vector<int > > g ;
bool vis[200007] ;
int color[200007] ;

void dfs(int pos){
    vis[pos] = true ;

    for(int i = 0 < g[])
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> n ;
    g.resize(n) ;
    for(int i = 0 ; i < n-1 ; i++){
        cin >> u >> v ;
        --u;
        --v;
        g[u].push_back(v) ;
        g[v].push_back(u) ;
    }
    memset(vis,false,sizeof vis) ;
    ans = 1 ;
    color[0] = 1 ;
    dfs(0) ;
    cout << ans << endl;
    return 0;
}
