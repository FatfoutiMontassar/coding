#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
int n ;
string s ;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> n >> s ;
    int cnt(0) ;
    for(int i = 0 ; i < n ; i++){
        if(s[i] != 'I')cnt++;
    }
    int ans(0) ;
    for(int i = 0 ; i < n ; i++){
        if(s[i] != 'F'){
            if(cnt-(s[i] == 'A') == (n-1))ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
