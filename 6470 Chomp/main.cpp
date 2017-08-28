#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
#define mp make_pair
int t,tc,p,q,r ;
int ans[111][111][111] ;
pair<int,pair<int,int > > Next[111][111][111] ;

void run(){
    /// 0 : not asigned
    /// 1 : losing state
    /// 2 : winning state
    memset(ans,0,sizeof ans) ;
    ans[1][0][0]  = 1 ;
    ans[0][0][0]  = 1 ;
    while(1){
        bool test(false) ;
        int sum(0) ;
        for(int i = 1 ; i <= 100 ; i++){
            for(int j = 0 ; j <= i ; j++){
                for(int k = 0 ; k <= j ; k++){
                    if(ans[i][j][k] == 0){
                        test = true ;
                        sum++;
                    }
                }
            }
        }
        if(!test)break;
        for(int i = 1 ; i <= 100 ; i++){
            for(int j = 0 ; j <= i ; j++){
                for(int k = 0 ; k <= j ; k++){
                    bool isW = false ; /// becomes true if exist Losing neighbor
                    bool isL = true  ; /// becomes false if exist neighbor not winning

                    for(int it = 1 ; it <= (k) ; it++){
                        if( (i == 0) && (j == 0) && (k-it == 0 ) )continue ;
                        if(ans[i][j][k-it] == 1){
                            Next[i][j][k] = mp(i,mp(j,k-it)) ;
                            isW = true , isL = false ;
                        }
                        else if(ans[i][j][k-it] == 0)isL = false ;
                    }

                    for(int it = 1 ; it <= (j) ; it++){
                        if((i == 0) && (j-it == 0) && (k-max(0,k-j+it) == 0) )continue ;
                        if(ans[i][j-it][k-max(0,k-j+it)] == 1){
                            Next[i][j][k] = mp(i,mp(j-it,k-max(0,k-j+it))) ;
                            isW = true , isL = false ;
                        }
                        else if(ans[i][j-it][k-max(0,k-j+it)] == 0)isL = false ;
                    }

                    for(int it = 1 ; it <= (i) ; it++){
                        if((i-it == 0)&&(j-max(0,j-i+it) == 0)&&(k-max(0,k-i+it) == 0))continue ;
                        if(ans[i-it][j-max(0,j-i+it)][k-max(0,k-i+it)] == 1){
                            Next[i][j][k] = mp(i-it,mp(j-max(0,j-i+it),k-max(0,k-i+it))) ;
                            isW = true , isL = false ;
                        }
                        else if(ans[i-it][j-max(0,j-i+it)][k-max(0,k-i+it)] == 0)isL = false ;
                    }

                    if(isW)ans[i][j][k] = 2 ;
                    else if(isL)ans[i][j][k] = 1 ;
                }
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
    run() ;
    cin >> t ;
    while(t--){
        cin >> tc >> p >> q >> r ;
        cout << tc << ' ' ;
        if(ans[p][q][r] == 2){
            cout << "W " ;
            pair<int,pair<int,int> > next = Next[p][q][r] ;
            if(next.S.F == q && next.S.S == r){
                cout << next.F+1 << ' ' << 1 << endl;
            }else if(next.S.S == r && next.S.F < q && next.F < p){
                cout << next.S.F+1 << ' ' << 1 << endl;
            }else if(next.F<p && next.S.F<q && next.S.S<r){
                cout << next.S.S+1 << ' ' << 1 << endl;
            }else if(next.F == p && next.S.S == r){
                cout << next.S.F+1 << ' ' << 2 << endl;
            }else if(next.F == p && next.S.F<q && next.S.S<r){
                cout << next.S.S+1 << ' ' << 2 << endl;
            }else{
                cout << next.S.S+1 << ' ' << 3 << endl;
            }
        }else{
            cout << "L" << endl;
        }
    }
    return 0;
}
