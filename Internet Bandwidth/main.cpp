#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define inf (int)(1e9+7)
ll n,s,t,m,u,v,w ;
ll f,mf;
int p[1111] ;
int res[1111][1111] ;
vector<vector<int > > g ;

void aug(int v,int minedg){
    if(v==s){
        f = minedg;
        return;
    }
    if(p[v]!=-1){
        aug(p[v],min(minedg,res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}

void maxf(){
    mf = 0;
    while(1){
        f = 0;
        vector<int> dist(n+1,inf);
        memset(p,-1,sizeof p);
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(t==u)break;
            for(int i=0;i<g[u].size();++i){
                int v = g[u][i];
                if(res[u][v]>0 && dist[v]==inf){
                    q.push(v);
                    dist[v] = dist[u] + 1;
                    p[v] = u;
                }
            }
        }
        aug(t,inf);
        if(!f)break;
        mf += f;
    }
}


/*
vector<vector<pair<int,ll > > > g ;
vector<map<int,int> > idx ;

ll GetMaxFlow(){
    vector<int > parent(n,-1) ;
    vector<bool > vis(n,false) ;
    queue<int > Q ;
    Q.push(s) ;
    vis[s] = true ;
    while(!Q.empty()){
        int from = Q.front() ;
        Q.pop() ;
        for(int i = 0 ; i < g[from].size() ; i++){
            int to = g[from][i].F ;
            if(vis[to] == false && g[from][i].S > 0 ){
                vis[to] = true ;
                Q.push(to) ;
                parent[to] = from ;
            }
        }
    }
    if(vis[t] == false)return 0 ;
    else{
        ll flow(INF) ;
        for(int i = t ; i != s ; i = parent[i]){
            int id = idx[parent[i]][i] ;
//            cout << id << ' ';
            flow = min(flow,g[parent[i]][id].S) ;
        }
//        cout << endl;
        for(int i = t ; i != s ; i = parent[i]){
            int id = idx[parent[i]][i] ;
//            cout << id << ' ';
            g[parent[i]][id].S -= flow ;
            g[id][parent[i]].S += flow ;
        }
//        cout << endl;
        return flow ;
    }
}


ll maxFlow(){
    ll totalFlow(0) ;
    while(true){
        ll flow = GetMaxFlow() ;
        if(flow<=0)break ;
        totalFlow += flow ;
    }
return totalFlow ;
}*/


int main(){
#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    int tc(1) ;
    while(cin >> n && n != 0 ){
        cin >> s >> t >> m ;
        s-- ;
        t-- ;
        g.clear() ;
        g.resize(n) ;
        for(int i = 0 ; i < m ; i++){
            cin >> u >> v >> w ;
            u-- ;
            v-- ;
            g[u].pb(v) ;
            res[u][v] = w ;
            g[v].pb(u) ;
            res[v][u] = w ;
        }
        cout << "Network " << tc++ << endl;
        maxf() ;
        cout << "The bandwidth is " << mf << endl ;
    }
return 0 ;
}
