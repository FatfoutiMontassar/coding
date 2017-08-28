#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
#define mp make_pair
int t,x,y ;

int ans[17][17] ;
int di[4] = {-2,-2,1,-1} ;
int dj[4] = {1,-1,-2,-2} ;


bool ok(int x,int y){
    return ( x >= 0 && x < 15 && y >= 0 && y < 15 ) ;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    for(int i = 0 ; i < 15 ; i++){
        for(int j = 0 ; j < 15 ; j++){
            ans[i][j] = 0 ;
        }
    }
    while(1){
        bool test(true) ;
        int sum(0) ;
        for(int i = 0 ; i < 15 ; i++){
            for(int j = 0 ; j < 15 ; j++){
                if(ans[i][j] == 0){
                    sum++;
                    test = false ;
                }
            }
        }
        if(test)break;
        for(int i = 0 ; i < 15 ; i++){
            for(int j = 0 ; j < 15 ; j++){
                if(ans[i][j] == 0){
                    bool isL = true ;
                    bool isW = false ;
                    for(int k = 0 ; k < 4 ; k++){
                        int u = i+di[k] ;
                        int v = j+dj[k] ;
                        if(ok(u,v)){
                            if(ans[u][v] == 2)isL = false , isW = true ;
                            else if(ans[u][v] == 1){}
                            else{
                                isL = false ;
                            }
                        }
                    }
                    if(isW)ans[i][j] = 1 ;
                    else if(isL) ans[i][j] = 2 ;
                }
            }
        }
    }
//    for(int i = 0 ; i < 15 ; i++){
//        for(int j = 0 ; j < 15 ; j++){
//            cout << ans[i][j] << ' ' ;
//        }
//        cout << endl;
//    }
    cin >> t ;
    while(t--){
        cin >> x >> y ;
        cout << (ans[x-1][y-1] == 1 ? "First" : "Second" ) << endl;
    }
    return 0;
}
///s: TTT, TTH, THT, THH, HTT, HTH, HHT and HHH.
