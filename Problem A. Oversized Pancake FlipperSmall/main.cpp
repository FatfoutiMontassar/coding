#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
int t,k,msk,n ;
string s ;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> t ;
    int tc(1) ;
    while(t--){
        cin >> s >> k ;
        n = s.size() ;
        msk = (1<<(n-k+1))-1 ;
        int ans = INF ;

        for(int i = 0 ; i <= msk ; i++){
            vector<bool > tmp(n) ;
            for(int j = 0 ; j < n ; j++)tmp[j] = ( s[j] == '-' ? false : true ) ;
            for(int j = 0 ; j < n ; j++){
                if((i&(1<<j))!=0){
                    for(int p = j ; p < j+k ; p++)tmp[p] = !tmp[p] ;
                }
            }
            bool ok(true) ;
            for(int j = 0 ; j < n ; j++){
                if(tmp[j] == false){
                    ok = false ;
                    break;
                }
            }
            if(ok){
                ans = min(ans,(int)(__builtin_popcount(i) )) ;
            }
        }
        cout << "Case #"<<tc++<<": " ;
        if(ans != INF)cout << ans << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
