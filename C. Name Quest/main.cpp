#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
string text,pattern ;
bool fromRight[1000007] ;
bool  fromLeft[1000007] ;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> pattern >> text ;
    int n = text.size() ;
    int m = pattern.size() ;
    memset(fromLeft,false ,sizeof fromLeft) ;
    memset(fromRight,false , sizeof fromRight) ;

    int ptr(0) ;
    for(int i = 0 ; i < text.size() ; i++){
        if(ptr == m){
            fromLeft[i] = true ;
            continue ;
        }
        if(text[i] == pattern[ptr]){
            ptr++ ;
        }
        if(ptr == m){
            fromLeft[i] = true ;
        }
    }
    ptr = 0 ;
    for(int i = text.size() ; i >= 0 ; i--){
        if(ptr == m){
            fromRight[i] = true ;
            continue ;
        }
        if(text[i] == pattern[pattern.size()-1-ptr]){
            ptr++ ;
        }
        if(ptr == m){
            fromRight[i] = true ;
        }
    }
    int ans(0) ;
    for(int i = 0 ; i < text.size() -1 ; i++){
        if(fromLeft[i] == true && fromRight[i+1] == true)ans++;
    }
    cout << ans << endl;

    return 0;
}
