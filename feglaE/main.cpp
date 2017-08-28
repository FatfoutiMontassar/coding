#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
#define sqrt_ (int)sqrt

bool fun(int x){
    if(sqrt_(x)*sqrt_(x) == x)return true ;
    return false ;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    int t,n,x ;
    cin >> t ;
    while(t--){
        cin >> n ;
        int sum = 0 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                cin >> x ;
                if(fun(x))sum += x ;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
