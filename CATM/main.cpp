#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
int n,m,k,mx,my,c1x,c1y,c2x,c2y,tc;
int dist[111][111] ;
int  vis[111][111] ;
int di[4] = {0,0,1,-1} ;
int dj[4] = {1,-1,0,0} ;
bool escape ;

bool ok(int x,int y){
    return ( x >= 0 && x < n && y >= 0 && y < m ) ;
}

void run(int x,int y){
    if(x == 0 || x == (n-1) || y == 0 || y == (m-1) ){
        escape = true ;
        return ;
    }
    vis[x][y] = tc ;
    for(int i = 0 ; i < 4 ; i++){
        if(ok(x+di[i],y+dj[i])){
            if(vis[x+di[i]][y+dj[i]] != tc && (abs(x+di[i]-mx)+abs(y+dj[i]-my)) < dist[x+di[i]][y+dj[i]] ){
                run(x+di[i],y+dj[i]) ;
            }
        }
    }
}


int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    cin >> n >> m ;
    cin >> k ;
    for(tc = 1 ; tc <= k ; tc++){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                dist[i][j] = INF ;
            }
        }
        cin >> mx >> my >> c1x >> c1y >> c2x >> c2y ;
        mx-- ; my-- ; c1x-- ; c1y-- ; c2x-- ; c2y-- ;
        queue<pair<pair<int,int > , int > > Q ;
        Q.push(mp(mp(c1x,c1y),0));
        Q.push(mp(mp(c2x,c2y),0));
        dist[c1x][c1y] = 0 ;
        dist[c2x][c2y] = 0 ;
        while(!Q.empty()){
            pair<pair<int,int>,int > p = Q.front() ;
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
        escape = false ;
        run(mx,my) ;
        if(escape)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
