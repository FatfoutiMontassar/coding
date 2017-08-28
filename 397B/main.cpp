#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second

string s ;
bool ok[555] ;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> s ;
    memset(ok,false,sizeof ok) ;
    int cnt(0) ;
    for(int i = 0 ; i < s.size() ; i++){
        if(ok[i] == false){
            if(cnt>=26){
                cout << "NO" << endl;
                return 0 ;
            }
            if(s[i] != (char)(cnt+'a') ){
                cout << "NO" << endl;
                return 0 ;
            }
            cnt++;
            for(int j = i ; j < s.size() ; j++){
                if(s[j] == s[i]){
                    ok[j] = true ;
                }
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}
