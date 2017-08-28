#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second

string home ;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    int n ;
    cin >>  n ;
    cin >> home  ;
    for(int i = 0 ; i < n ; i++){
        cin >> home ;
    }
    if(n&1)cout << "contest" << endl;
    else cout << "home" << endl;

    return 0;
}
