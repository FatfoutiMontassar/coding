#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
map<string ,int > M ;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
string s ;
M["Tetrahedron"] = 4 ;
M["Cube"] = 6 ;
M["Octahedron"] = 8 ;
M["Dodecahedron"] = 12 ;
M["Icosahedron"] = 20 ;
    int n ;
    cin >> n  ;
    int ans(0) ;
    for(int i = 0 ; i < n ; i++){
        cin >> s ;
        ans += M[s] ;
    }
    cout << ans << endl;


    return 0;
}
