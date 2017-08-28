#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
#define ld long double
int n ;
ld X[60007] ;
ld V[60007] ;

ld fun(ld x){
    /// time = dist / speed
    ld ret = 0 ;
    for(int i = 0 ; i < n ; i++){
        ret = max(ret,(ld)(abs(x-X[i]))/((ld)(V[i])) ) ;
    }
return ret ;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    cin >> n ;
    ld l = INF * 1.0 ;
    ld r = -1.0 * INF ;
    for(int i = 0 ; i < n ;i++){
        cin >> X[i] ;
        l = min(l,1.0*X[i]) ;
        r = max(r,1.0*X[i]) ;
    }
    for(int i = 0 ; i < n ; i++){
        cin >> V[i] ;
    }
    while(abs(l-r)>0.0000001){
        ld mid1 = (2*l+r)/3.0 ;
        ld mid2 = (2*r+l)/3.0 ;

        ld ans1 = fun(l) ;
        ld ans2 = fun(mid1) ;
        ld ans3 = fun(mid2) ;
        ld ans4 = fun(r) ;

        if(ans1 >= ans2 && ans2 >= ans3 && ans3 >= ans4 ){
            l = mid2 ;
        }else if(ans1 >= ans2 && ans2 <= ans3 && ans3 <= ans4){
            r = mid2 ;
        }else if(ans1 >=ans2 && ans2 >= ans3 && ans3 <= ans4){
            l = mid1 ;
        }else{
            r = mid1 ;
        }
    }
    cout << fixed << setprecision(20) << fun(r) << endl;
    return 0;
}
