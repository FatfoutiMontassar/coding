#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
ll t,n,x;
ll tab[111] ;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> t ;
    while(t--){
        cin >> n ;
        for(int i = 0 ; i < n ; i++){
            cin >> tab[i] ;
        }
        bool ok(false) ;
        for(int i = 0 ; i < n ; i++){
            ll ans(0) ;
            for(int j = 0 ; j < n ; j++){
                ans ^= (i == j ? (tab[j]-1) : tab[j] ) ;
            }
            if(ans != 0){
                ok = true ;
                break;
            }
        }
        cout << (ok ? "First" : "Second" ) << endl;
    }
    return 0;
}
