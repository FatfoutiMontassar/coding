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
    int t,a,b,c ;
    cin >> t ;
    while(t--){
        cin >> a >> b >> c ;
        cout << max(a,max(b,c)) << endl;
    }


    return 0;
}
