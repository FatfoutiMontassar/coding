#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    ll a,b ;
    cin >> a >> b ;
    for(ll i = 0 ; ; i++){
        if(a>b){
            cout << i << endl;
            break;
        }
        a*=3LL;
        b*=2LL;
    }
    return 0;
}
