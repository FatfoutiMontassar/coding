#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
#define ld long double
int t,tc ;
ld D,v1,v2,v ;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> t ;
    while(t--){
        cin >> tc >> D >> v1 >> v2 >> v;
        ld ans(0.0) ;
        while(1){
            ld dist = D*(1/((v1+v2)/v+1)) ;
            if(dist<0.000000001)break;
            ans += dist ;
            D = dist ;
        }
        cout << tc << ' ' << fixed << setprecision(2) << ans << endl;
    }
    return 0;
}
