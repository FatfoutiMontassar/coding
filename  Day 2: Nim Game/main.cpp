#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
int t,n,x;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> t ;
    while(t--){
        cin >> n ;
        int ans(0) ;
        for(int i = 0 ; i < n ; i++){
            cin >> x ;
            ans ^= x ;
        }
        cout << (ans != 0 ? "First" : "Second" ) << endl;
    }
    return 0;
}
