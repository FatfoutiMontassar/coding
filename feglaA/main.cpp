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
    int t ;
    ll a,b;
    cin >> t ;
    while(t--){
        cin >> a >> b ;
        cout << abs(a+b) << endl;
    }
    return 0;
}
