#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
int n ;
int tab[111] ;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> n ;

    for(int i = 0 ; i < n ; i++)cin >> tab[i] ;
    sort(tab,tab+n) ;
    int cnt(0) ;
    int sum = 0 ;
    int ans = 0 ;
    for(int i = 0 ; i < n ; i++){
        sum += tab[i] ;
        if(sum>710)break;
        cnt++;
        if(sum>350)ans += (sum-350) ;
    }
    cout << cnt << ' ' << ans << endl;
    return 0;
}
