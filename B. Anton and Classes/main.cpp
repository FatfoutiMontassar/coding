#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
int n , m , a , b ;
int maxStart , minEnd ;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> n ;
    maxStart = 0 ;
    minEnd = INF ;
    for(int i = 0 ; i < n ; i++){
        cin >> a >> b ;
        maxStart = max(maxStart,a) ;
        minEnd   = min(minEnd  ,b) ;
    }
    int ans(0) ;
    cin >> m ;
    for(int i = 0 ; i < m ; i++){
        cin >> a >> b ;
        ans = max(ans,max(maxStart-b,0) ) ;
        ans = max(ans,max(a-minEnd,0) ) ;
    }
    cout << ans << endl;
    return 0;
}
