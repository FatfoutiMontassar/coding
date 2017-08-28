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
    int ans(0) ;
    for(int i = 0 ; i < INF ; i++){
        for(int j = 0 ; j < INF ; j++){
            ans -= 2 ;
            ans += 5 ;
            ans -= 3 ;
        }
    }
    cout << ":p" << endl;

    return 0;
}
