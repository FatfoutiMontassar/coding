#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
ll t,tc,d ;
ll ans[70][11] ;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    for(int i = 0 ; i < 10 ; i++){
        ans[1][i] = 1 ;
    }
    for(int i = 2 ; i <= 64 ; i++){
        for(int d = 0 ; d < 10 ; d++){
            ll sum(0) ;
            for(int ld = d ; ld < 10 ; ld++){
                sum += ans[i-1][ld] ;
            }
            ans[i][d] = sum ;
        }
    }
    cin >> t ;
    while(t--){
        cin >> tc >> d ;
        ll ret(0) ;
        for(int i = 0 ; i < 10 ; i++){
            ret += ans[d][i] ;
        }
        cout << tc << ' ' << ret << endl;
    }

    return 0;
}
