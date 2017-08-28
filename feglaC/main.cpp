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
    int t,n ;
    cin >> t ;
    while(t--){
        cin >> n ;
        for(int i = 1 ; i <= n ; i++){
            int x = min(i,n-i+1) ;
            if(i == (n+1)/2){
                for(int j = 1 ; j <= n ; j++)cout << '*' ;
                cout << endl;
            }else{
                for(int j = 1 ; j <= x ; j++)cout << '*' ;
                for(int j = 0 ; j < (n-2*x)  ; j++)cout << ' ' ;
                for(int j = 1 ; j <= x ; j++)cout << '*' ;
                cout << endl;
            }
        }
    }

    return 0;
}
