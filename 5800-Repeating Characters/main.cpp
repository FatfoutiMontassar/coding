#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
int t,tc,r ;
string s ;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> t ;
    while(t--){
        cin >> tc >> r >> s ;
        cout << tc << ' ' ;
        for(int i = 0 ; i < s.size() ; i++){
            for(int j = 0 ; j < r ; j++)cout << s[i] ;
        }
        cout << endl;
    }
    return 0;
}
