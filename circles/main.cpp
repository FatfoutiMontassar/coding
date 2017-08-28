#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
int X[22] ;
int Y[22] ;
double R[22] ;
int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    int n ;
    cin >> n ;
    for(int i = 0 ; i < n ; i++){
        cin >> X[i] >> Y[i] >> R[i] ;
    }
    int mask = (1<<n)-1 ;
    for(int i = 0 ; i <= mask ; i++){
        double area = 0 ;
        area = calc(i) ;
        ans += ( buli(mask)&1 !=0 ? area : -1*area ) ;
    }


    return 0;
}
