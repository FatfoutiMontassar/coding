#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
int t,n;
ll v1[1000] ;
ll v2[1000] ;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> t ;
    for(int tc = 1 ; tc <= t ; tc++){
        cin >> n ;
        for(int i = 0 ; i < n ; i++){
            cin >> v1[i] ;
        }
        for(int i = 0 ; i < n ; i++){
            cin >> v2[i] ;
        }
        sort(v1,v1+n) ;
        sort(v2,v2+n) ;
        ll ans(0) ;
        for(int i = 0 ; i < n ; i++){
            ans += v1[i]*v2[n-1-i] ;
        }
        cout << "Case #" << tc << ": " << ans << endl;
    }
    return 0;
}
