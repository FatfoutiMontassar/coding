#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
int t,tc ;
const int n = 20 ;
pair<int,bool> tab[22] ;

bool cmp(pii a,pii b){
    return a.F < b.F ;
}

int fun(){
    int ans(0) ;

return ans ;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> t ;
    while(t--){
        cin >> tc ;
        for(int i = 0 ; i < n ; i++){
            cin >> tab[i].F;
            tab[i].S = false ;
        }
        cout << tc << ' ' << fun() << endl;
    }
    return 0;
}
