#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
int t,n;
bool ok(ll x){
    ll last = 9 ;
    ll aux = x ;
    while(aux){
        if(aux%10<=last){
            last = aux%10 ;
            aux /= 10 ;
        }else{
            return false ;
        }
    }
    return true ;
}
int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> t ;
    int tc(1) ;
    while(t--){
        cin >> n ;
        for(int i = n ; i >= 0 ; i--){
            if(ok(i)){
                cout << "Case #"<<tc++<<": "<<i<<endl;
                break;
            }
        }
    }

    return 0;
}
