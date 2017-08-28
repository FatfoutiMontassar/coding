#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
int n,x ;
int tab[200007] ;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> n ;
    int cnt(0),ans(0) ;
    for(int i = 0 ; i < 2*n ; i++){
        cin >> x ;
        if(tab[x] == 1)cnt-- ;
        else{
            tab[x] = 1 ;
            cnt++ ;
        }
        ans = max(ans,cnt) ;
    }
    cout << ans << endl;

    return 0;
}
