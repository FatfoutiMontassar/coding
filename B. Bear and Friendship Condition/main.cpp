#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
#define mp make_pair
int n,m,u,v ;
vector<vector<int > > g ;
bool vis[155000] ;
ll x ;

void dfs(int pos){
    vis[pos] = true ;
    x++;
    for(int i = 0 ; i < g[pos].size() ; i++){
        if(!vis[g[pos][i]]){
            dfs(g[pos][i]) ;
        }
    }
return ;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> n >> m ;
    g.clear() ;
    g.resize(n) ;
    memset(vis,false,sizeof vis) ;
    ll cnt = 0LL;
    for(int i = 0 ; i < m ; i++){
        cin >> u >> v ;
        u--;
        v--;
        g[u].push_back(v) ;
        g[v].push_back(u) ;
    }
    for(int i = 0 ; i < n ; i++){
        if(!vis[i]){
            x = 0 ;
            dfs(i) ;
            cnt += x*(x-1)/2 ;
        }
    }

    cout << (cnt == m ? "YES" : "NO" ) << endl;
    return 0;
}
