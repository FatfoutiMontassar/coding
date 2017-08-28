#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
#define pii pair<int,pair<pair<int,int >,int > >
int h,w,sx,sy,tx,ty ;
string a[111] ;
int dist[111][111][5] ;
int di[4] = {0,0,-1,1} ;
int dj[4] = {1,-1,0,0} ;

bool ok(int x,int y){
    if( x >= 0 && x < h && y >= 0 && y < w ){
        return a[x][y] != '*' ;
    }else{
        return false ;
    }
}

int fun(int x,int y){
    return (x == y || x*y == 0 ? 0 : 1 ) ;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    cin >> w >> h ;
    for(int i = 0 ; i < h ; i++){
        cin >> a[i] ;
    }
    bool flag = false ;
    for(int i = 0 ; i < h ; i++){
        for(int j = 0 ; j < w ; j++){
            for(int p = 0 ; p < 5 ; p++){
                dist[i][j][p] = INF ;
            }
            if(a[i][j] == 'C'){
                if(flag == false){
                    sx = i ;
                    sy = j ;
                    flag = true ;
                }else{
                    tx = i ;
                    ty = j ;
                }
            }
        }
    }

    /// F : cost , S.F.F ; x , S.F.S : y , S.S ; way
    /// 0 : default way for source
    /// 1 : up
    /// 2 : down
    /// 3 : left
    /// 4 : right

    priority_queue< pii , vector<pii> , greater<pii> > Q ;

    dist[sx][sy][0] = 0 ;

    Q.push(mp(0,mp(mp(sx,sy),0))) ;

    while(!Q.empty()){
        pii p = Q.top() ;
        Q.pop() ;
        int d = p.F ;
        int x = p.S.F.F ;
        int y = p.S.F.S ;
        int way = p.S.S ;
        for(int i = 0 ; i < 4 ; i++){
            if( ok(x+di[i],y+dj[i]) ){
                if(d+fun(way,i+1)<dist[x+di[i]][y+dj[i]][i+1]){
                    dist[x+di[i]][y+dj[i]][i+1] = d+fun(way,i+1) ;
                    Q.push(mp(dist[x+di[i]][y+dj[i]][i+1],mp(mp(x+di[i],y+dj[i]),i+1))) ;
                }
            }
        }
    }

    int ans = INF ;
    for(int i = 0 ; i < 5 ; i++){
        ans = min(ans,dist[tx][ty][i]) ;
    }
    cout << ans << endl;
    return 0;
}
