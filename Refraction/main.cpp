#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
#define ld long double
int t ;
ld W,H,x,xe,ye,mu ;

bool check(ld h){

}

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif

    cin >> t ;
    while(t--){
        cin >> W >> H >> x >> xe >> ye >> mu ;
        ld l = 0 , r = H ;
        if(check(1.0*H) == false)cout << "Impossible" << endl;
        else{
            while(abs(l-r)<0.000000001){
                ld mid = (l+r)/2 ;
                if(check(mid))r = mid ;
                else l = mid ;
            }
            cout << r << endl;
        }
    }

    return 0;
}
