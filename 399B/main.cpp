#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second

ll n,l,r,pos;

ll fun(ll x){
    ll a = pos;
    ll b = n;
    while(b>3){
        if(x==a+1){
            return (b&1LL);
        }
        x %= (a+1);
        b /= 2 ;
        a /= 2 ;
    }
    if(x&1LL)return b >> 1LL;
    else return b&1LL;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> n >> l >> r ;
    pos = (pow(2,floor(log(n)/log(2))+1)-1)/2;
    ll ans = 0;

    for(ll i = l ; i <= r ; i++){
        ans += ( 1LL * fun(i) ) ;
    }
    cout << ans << endl ;
    return 0;
}
