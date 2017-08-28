#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
const int n = 12 ;
int t,tc;
int tab[15] ;

int fun(){
    int ans(0) ;
    for(int i = 1 ; i < n-1 ; i++){
        for(int j = i ; j < n-1 ; j++){
            int mini = tab[i] ;
            for(int k = i ; k <= j ; k++)mini = min(mini,tab[k]) ;
            if(mini > tab[i-1] && mini > tab[j+1] )ans++ ;
        }
    }
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
        for(int i = 0 ; i < 12 ; i++)cin >> tab[i] ;
        cout << tc << ' ' << fun() << endl;
    }
    return 0;
}
