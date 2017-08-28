#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
ll t,n,h,w ;
ll tab[10007] ;
ll ans[10007] ;

void solve(){
    for(int i = 1 ; i <= w ;i++){
       for(int j = 0 ; j < n ; j++){
            if(tab[j] < i){
                ans[i] += ans[i-(tab[j]+1)] ;
                ans[i] %= INF ;
            }
       }
    }
    ll ret = ans[w] ;
    for(int i = 1 ; i < h ; i++){
        ans[w] *= ret ;
        ans[w] %= INF ;
    }
cout << ans[w] << endl;
}


int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> t ;
    while(t--){
        cin >> n >> h >> w ;
        memset(ans,0,sizeof ans) ;
        for(int i = 0 ; i < n ; i++){
            cin >> tab[i] ;
            ans[tab[i]]++ ;
        }
        solve() ;
    }
    return 0;
}
