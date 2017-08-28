#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
int n,u,v,dst,idx ;
vector<vector<int > > g ;
bool vis[10007] ;

void dfs(int pos,int d){
    vis[pos] = true ;
    if(d>dst){
        dst = d ;
        idx = pos ;
    }
    for(int i = 0 ; i < g[pos].size() ; i++){
        if(!vis[g[pos][i]]){
            dfs(g[pos][i],d+1) ;
        }
    }
return ;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    cin >> n ;
    g.resize(n) ;
    for(int i = 0 ; i < n-1 ; i++){
        cin >> u >> v ;
        u-- ; v-- ;
        g[u].push_back(v) ;
        g[v].push_back(u) ;
    }
    for(int i = 0 ; i < n ; i++)vis[i] = false ;
    dst = 0 ;
    dfs(0,0) ;
    for(int i = 0 ; i < n ; i++)vis[i] = false ;
    dst = 0 ;
    dfs(idx,0) ;
    cout << dst << endl;
    return 0;
}
