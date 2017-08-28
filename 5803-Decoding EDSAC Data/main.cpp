#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
#define ld long double
int t,tc,k ;
char ch,len ;
const string alpha = "PQWERTYUIOJ#SZK*?F@D!HNM&LXGABCV" ;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> t ;
    while(t--){
        cin >> tc >> ws >> ch >> ws >> k >> ws >> len ;
        cout << tc << ' ' ;
        int id = 0 ;
        int ans = (len == 'F' ? 0 : 1 ) ;
        for(int i = 0 ; i < alpha.size() ; i++){
            if(alpha[i] == ch){id = i ; break; }
        }
        ans += (id<<12) ;
        ans += (k<<1) ;

        ld ret = 0 ;
        for(int i = 15 ; i >= 0 ; i--){
            ret += ( (ans&(1<<i)) != 0 ? 1.0/((ld)((int)1<<(16-i))) : 0 ) ;
        }
        if( (ans&(1<<16)) != 0)ret -= 1.0 ;


        string out = "" ;
        if(ret<0)cout << '-' ;
        ret = abs(ret) ;
        cout << (int)(ret) << '.' ;
        ret -= (int)(ret) ;

        for(int i = 0 ; i < 16 ; i++){
            ret -= (int)(ret) ;
            ret *= 10 ;
            out += (char)((int)(ret) + '0')  ;
        }
        int idx = -1 ;
        for(int i = 15 ; i >= 0 ; i--){
            if(out[i] != '0'){
                idx = i ;
                break;
            }
        }
        if(idx<0)cout << '0' << endl;
        else{
            for(int i = 0 ; i <= idx ; i++)cout << out[i] ;
            cout << endl;
        }
    }
    return 0;
}
