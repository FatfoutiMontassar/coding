#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
string s1,s2 ;


int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> s1 >> s2 ;
    int b(0) ;

    for(int i = 0 ; i < s1.size() ; i++){
        b = max(b,(int)(s1[i]-'0')) ;
    }

    for(int i = 0 ; i < s2.size() ; i++){
        b = max(b,(int)(s2[i]-'0')) ;
    }
    b++ ;

    int sum(0),ret(0) ;

    reverse(s1.begin(),s1.end()) ;
    reverse(s2.begin(),s2.end()) ;

    for(int i = 0 ; i < max(s1.size(),s2.size()) ; i++){
        int perm(0) ;
        if(i<s1.size())perm += (int)(s1[i]-'0') ;
        if(i<s2.size())perm += (int)(s2[i]-'0') ;
        sum *= 10 ;
        sum += (perm+ret)%b ;
        ret = (perm+ret)/b ;
    }
    if(ret != 0)cout << max(s1.size(),s2.size() ) + 1 << endl;
    else cout << max(s1.size(),s2.size() ) << endl;
    return 0;
}
