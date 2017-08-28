#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
#define ll long long int
#define INF 100000000007
#define PI acos(-1)
#define F first
#define S second
int nFl , nElev , u , v ;
vector<int > up[1007] ;
vector<int > down[1007] ;

int fun1(ll a,ll b){
    /// return the smallest time t greater then a and that could be written t = (2n)*b
    /// we could find n using binary search ...
    ll l = 0 ;
    ll r = INF ;
    while(r-l>0){
        ll mid = (l+r)/2LL ;
        if(2LL*mid*b >= a)r = mid ;
        else l = mid+1 ;
    }
    return 2*r*b ;
}

int fun2(ll a,ll b){
    /// return the smallest time t greater then a and that could be written t = (2n+1)*b
    ll l = 0 ;
    ll r = INF ;
    while(r-l>0){
        ll mid = (l+r)/2LL ;
        if((2LL*mid+1)*b >= a)r = mid ;
        else l = mid+1 ;
    }
    return (2LL*r+1)*b ;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    cin >> nFl >> nElev ;
    for(int i = 0 ; i < nElev ; i++){
        cin >> u >> v ;
        u-- ;
        v-- ;
        up[u].push_back(v) ;
        down[v].push_back(u) ;
    }
    vector<int > dist(nFl,INF) ;
    dist[0] = 0 ;
    priority_queue<pair<int,int > , vector<pair<int,int > > , greater<pair<int,int > > > Q ;
    /// F : dist , S : floor
    Q.push(mp(0,0)) ;
    while(!Q.empty()){
        pair<int,int > p = Q.top() ;
        Q.pop() ;
        int pos = p.S ;
        int d = p.F ;
        if(dist[pos]<d)continue ;
        for(int i = 0 ; i < up[pos].size() ; i++){
            int t = fun1(d,( up[pos][i] - pos )*5) ;
            if(t+5*(up[pos][i]-pos) < dist[up[pos][i]] ){
                dist[up[pos][i]] = t+5*(up[pos][i]-pos) ;
                Q.push(mp(dist[up[pos][i]],up[pos][i])) ;
            }
        }
        for(int i = 0 ; i < down[pos].size() ; i++){
            int t = fun2(d,( pos - down[pos][i] )*5) ;
            if(t+5*(pos-down[pos][i]) < dist[down[pos][i]] ){
                dist[down[pos][i]] = t+5*(pos-down[pos][i]) ;
                Q.push(mp(dist[down[pos][i]],down[pos][i])) ;
            }
        }
    }
    cout << dist[nFl-1] << endl;
    return 0;
}
