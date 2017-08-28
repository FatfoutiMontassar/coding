#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
int t , n , m , q , x , cost ;
vector<vector<pair<int,int> > > g ;
string s1,s2,name ;
map<string,int > M ;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    cin >> t ;
    while(t--){
        cin >> n ;
        g.clear();
        g.resize(n) ;
        for(int i = 0 ; i < n ; i++){
            cin >> name ;
            M[name] = i ;
            cin >> m ;
            for(int j = 0 ; j < m ; j++){
                cin >> x >> cost ;
                x--;
                g[i].push_back({x,cost}) ;
                g[x].push_back({i,cost}) ;
            }
        }
        cin >> q ;
        while(q--){
            cin >> s1 >> s2 ;
            int s = M[s1] ;
            int t = M[s2] ;
            vector<int > dist(n,INF) ;
            priority_queue<pair<int,int > , vector<pair<int,int> > , greater<pair<int,int> > > Q ;
            /// F : distance , S : node
            Q.push(mp(0,s)) ;
            dist[s] = 0 ;
            while(!Q.empty()){
                pair<int,int > p = Q.top() ;
                Q.pop() ;
                int pos = p.S ;
                int d = p.F ;
                if(pos == t)break;
                for(int i = 0 ; i < g[pos].size() ; i++){
                    int v = g[pos][i].F ;
                    int w = g[pos][i].S ;
                    if( d + w < dist[v] ){
                        dist[v] = d + w ;
                        Q.push(mp(dist[v],v)) ;
                    }
                }
            }
            cout << dist[t] << endl;
        }
    }

    return 0;
}
