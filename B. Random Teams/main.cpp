#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
ll n,m ;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> n >> m ;
    cout << ( (n/m+1LL)*(n/m)/2LL )*(n%m) + ( (n/m)*(n/m-1LL)/2LL )*(m-n%m) << ' ' << (n-(m-1LL))*(n-(m-1LL)-1LL)/2LL << endl;
    return 0;
}
