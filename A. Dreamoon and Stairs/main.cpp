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
//    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif

    cin >> n >> m ;
    int ans = INF ;
    for(int i = 0 ; i <= n ; i+=2){
        if( (i/2+(n-i))%m == 0 ){
            if((i/2+(n-i))<ans){
                ans = (i/2+(n-i)) ;
                cout << i/2 << ' ' << n-i << endl;
            }
        }
    }
    cout << ( ans != INF ? ans : -1 ) << endl;


    return 0;
}
