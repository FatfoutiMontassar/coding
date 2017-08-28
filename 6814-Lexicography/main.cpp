#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
#define mp make_pair
#define pb push_back
ll fact[17] ;
string text ;
map<char,int > M ;
vector<pair<char,ll> > v ;
ll k ;

ll f(ll x){
    return fact[x] ;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    fact[0] = 1 ;
    for(ll i = 1 ; i < 17 ; i++)fact[i] = i*fact[i-1] ;
    while(cin >> text >> k){
        if(text == "#")break;
        k--;
        M.clear() ;
        for(int i = 0 ; i < text.size() ; i++)M[text[i]]++;
        v.clear() ;
        for(auto it : M){
            v.pb(mp(it.F,it.S)) ;
        }
        string output = "" ;
        for(int i = 0 ; i < text.size() ; i++){
            ll cnt(0) ;
            for(int j = 0 ; j < v.size() ; j++){
                cnt += v[j].S ;
            }
            ll range = f(cnt) ;
            for(int j = 0 ; j < v.size() ; j++){
                range /= f(v[j].S) ;
            }
            ll pointer = 0 ;
            int id = 0 ;
            for(int i = 0 ; i < v.size() ; i++){
                if( k < (pointer + ( (range * v[i].S) / cnt )) ){
                    id = i ;
                    break;
                }
                pointer +=  ( (range * v[i].S) / cnt ) ;
            }
            output += v[id].F ;
            v[id].S--;
            if(v[id].S == 0){
                v.erase(v.begin()+id) ;
            }
            k -= pointer ;
        }
        cout << output << endl;
    }
    return 0;
}
