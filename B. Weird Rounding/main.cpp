#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
string s;
int k ;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> s >> k ;
    int cnt(0) ;
    int ans(0) ;
    for(int i = 0 ; i < s.size() ; i++){
        int j = s.size() - 1 - i ;
        if(s[j] == '0')cnt++;
        else ans++;
        if(cnt==k){
            cout << ans << endl;
            return 0 ;
        }
    }
    cout << s.size() -1 << endl;
    return 0;
}
