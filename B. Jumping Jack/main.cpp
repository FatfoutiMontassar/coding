#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
ll x ;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> x ;
    x = abs(x) ;
    ll pos(0) ;
    ll cnt(0) ;
    while(pos<x || (pos-x)&1 ){
        pos += (++cnt) ;
    }
    cout << cnt << endl;
    return 0;
}
