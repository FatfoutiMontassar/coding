#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
int t ;
ll a,b ;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> t ;
    while(t--){
        cin >> a >> b ;
        ll base = 1LL ;
        ll ansAnd = 0LL ;
        ll  ansOr = 0LL ;
        for(int i = 0 ; i < 64 ; i++){
            ll aux = (b/(1LL<<i)) - ((a-1)/(1LL<<i)) ;
            ansAnd += base * (aux == (b-a+1)) ;
            ansOr  += base * (aux!=0) ;
            base *= 2LL ;
        }
        cout << ansOr << ' ' << ansAnd << endl;
    }
    return 0;
}
