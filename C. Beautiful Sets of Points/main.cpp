#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
int n,m ;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> n >> m ;
    cout << min(n,m)+1 << endl;
    for(int i = 0 ; i <= min(n,m) ; ++i){
        cout << i << ' ' << min(n,m)-i << endl;
    }
    return 0;
}
