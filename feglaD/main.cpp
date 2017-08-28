#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
string s ;
int tab[30];

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    int t,n ;
    cin >> t ;
    while(t--){
        cin >> n >> s ;
        memset(tab,0,sizeof tab);
        for(int i = 0 ; i < n ; i++)tab[int(s[i]-'a')]++;
        char ans = '_' ;
        int x = 0 ;
        for(int i = 0 ; i < 26 ; i++){
            if(tab[i]>x){
                x = tab[i] ;
                ans = char(i+'a') ;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
