#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second

map<string ,ll > M1;
map<string ,ll > M2;
string winner,s ;
pair<string,ll> state[1007] ;
ll x ;


int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    int n ;
    cin >> n ;
    ll ans = -1 * (1e9+7) ;
    for(int i = 0 ; i < n ; i++){
        cin >> s >> x ;
        state[i] = {s,x} ;
        M1[s] += x ;
    }
    for(map<string ,ll > :: iterator it = M1.begin() ; it != M1.end() ; it++){
        ans = max(ans,it->second) ;
    }
    for(int i = 0 ; i < n ; i++){
        M2[state[i].F] += state[i].S ;
        if(M2[state[i].F] >= ans && M1[state[i].F] == ans){
            cout << state[i].F << endl;
            return 0 ;
        }
    }
}
