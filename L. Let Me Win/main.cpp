#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
#define buli(x)  __builtin_popcount(x)
ll t,n ;
pair<int,int > tab[18] ;
int dp[70000][18][2] ;

ll solve(ll mask,ll last,bool pos){
    if(buli(mask) == n)return 1 ;
    if(dp[mask][last][pos] != -1)return dp[mask][last][pos] ;
    ll ret(0) ;
    for(int i = 0 ; i < n ; i++){
        if((int)(mask&(1<<i)) == 0){
            if(tab[i].F == tab[i].S){
                if(pos){
                    if(tab[last].S == tab[i].F)ret += solve(mask|(1<<i),i,true) ;
                }else{
                    if(tab[last].F == tab[i].F)ret += solve(mask|(1<<i),i,true) ;
                }
            }else{
                if(pos){
                    if(tab[last].S == tab[i].F)ret += solve(mask|(1<<i),i,true) ;
                    else if(tab[last].S == tab[i].S)ret += solve(mask|(1<<i),i,false) ;
                }else{
                    if(tab[last].F == tab[i].F)ret += solve(mask|(1<<i),i,true) ;
                    else if(tab[last].F == tab[i].S)ret += solve(mask|(1<<i),i,false) ;
                }
            }
        }
        ret %= INF ;
    }
return dp[mask][last][pos] = ret ;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    freopen("let.in"   , "r" ,stdin  ) ;
    cin >> t ;
    while(t--){
        memset(dp,-1,sizeof dp) ;
        cin >> n ;
        for(int i = 0 ; i < n ; i++){
            cin >> tab[i].F >> tab[i].S ;
        }
        ll ans = 0 ;
            for(int i = 0 ; i < n ; i++){
                ans += solve(1<<i,i,true) ;
                if(tab[i].F != tab[i].S){
                    ans += solve(1<<i,i,false) ;
                }
                ans %= INF ;
            }
        cout << ans << endl;
    }
    return 0;
}
