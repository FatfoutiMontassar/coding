#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
int t,n,m;
string s ;
int dist[200][200] ;
int di[4] = {0,0,1,-1} ;
int dj[4] = {1,-1,0,0} ;

bool ok(int x,int y){
    return ( x >= 0 && x < n && y >= 0 && y < m ) ;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    cin >> t ;
    while(t--){
        cin >> n >> m ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                dist[i][j] = INF ;
            }
        }
        queue<pair<pair<int,int > ,int > > Q ;
        for(int i = 0 ; i < n ; i++){
            cin >> s ;
            for(int j = 0  ; j < m ; j++){
                if(s[j] == '1'){
                    dist[i][j] = 0 ;
                    Q.push(mp(mp(i,j),0)) ;
                }
            }
        }
        while(!Q.empty()){
            pair<pair<int,int > ,int > p = Q.front() ;
            Q.pop() ;
            int x = p.F.F ;
            int y = p.F.S ;
            int d = p.S ;
            if(dist[x][y]<d)continue ;
            for(int i = 0 ; i < 4 ; i++){
                if(ok(x+di[i],y+dj[i])){
                    if(d+1<dist[x+di[i]][y+dj[i]]){
                        dist[x+di[i]][y+dj[i]] = d+1 ;
                        Q.push(mp(mp(x+di[i],y+dj[i]),d+1)) ;
                    }
                }
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                cout << dist[i][j] << ' ' ;
            }
            cout << endl;
        }
    }
    return 0;
}
