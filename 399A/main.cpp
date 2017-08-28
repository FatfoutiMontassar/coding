#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
int n ;
int tab[100007] ;


int main(){

#ifndef ONLINE_JUDGE
//    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    int n ;
    cin >> n ;
    for(int i = 0 ; i < n ; i++){
        cin >> tab[i] ;
    }
    sort(tab,tab+n) ;
    int mini = tab[0] ;
    int maxi = tab[n-1] ;
    int ans(0) ;
    for(int i = 0 ; i < n ; i++){
        if(tab[i]>mini && tab[i]<maxi)ans++ ;
    }
    cout << ans << endl;


    return 0;
}
