#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF 10000000000007
#define PI acos(-1)
#define F first
#define S second
#define pii pair<ll,ll >
#define mp make_pair
int n,t,m,u,v,q ;
ll a[222] ;
ll dist[222] ;
vector<vector<int > > g ;
vector<pii > E ;

ll fun(int x,int y){
//    return max(0LL,(a[y]-a[x]))*max(0LL,(a[y]-a[x]))*max(0LL,(a[y]-a[x])) ;
    return (a[y]-a[x])*(a[y]-a[x])*(a[y]-a[x]) ;
}

void run(){
    for(int i = 0 ; i < n ; i++){
        dist[i] = INF ;
    }
    dist[0] = 0LL ;
    /// F : dist , S : node
    priority_queue< pii , vector<pii> , greater<pii> > Q ;
    Q.push(mp(0,0)) ;
    while(!Q.empty()){
        pii p = Q.top() ;
        Q.pop() ;
        ll u = p.S ;
        ll d = p.F ;
        for(int i = 0 ; i < g[u].size() ; i++){
            int v = g[u][i] ;
            if( d + fun(u,v) < dist[v] ){
                dist[v] = d + fun(u,v) ;
                Q.push(mp(dist[v],v)) ;
            }
        }
    }
return ;
}
void go(){
    for(int i = 0 ; i < n ; i++){
        dist[i] = INF ;
    }
    dist[0] = 0 ;
    for(int i = 0 ; i < n-1 : i++){
        for(int j = 0 ; j < m ; j++){
            u = E[j].F ;
            v = E[j].S ;
            if(dist[u]+fun(u,v)<dist[v]){
                dist[v] = dist[u]+fun(u,v) ;
            }
        }
    }

}

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    int tc = 1 ;
    while(cin >> n ){
        if(tc!=1)cout << endl;
        for(int i = 0 ; i < n ; i++){
            cin >> a[i] ;
        }
        g.clear() ;
        g.resize(n) ;
        E.clear() ;
        cin >> m ;
        for(int i = 0 ; i < m ; i++){
            cin >> u >> v ;
            g[u-1].push_back(v-1) ;
            E.push_back(mp(u-1,v-1)) ;
        }
        go() ;
        cin >> q ;
        cout << "Set #" << tc++ << endl;
        while(q--){
            cin >> t ;
            if(dist[t-1] < 3LL)cout << '?';
            else cout << dist[t-1] ;
            if(q!=0)cout << endl;
        }
    }
    return 0;
}
