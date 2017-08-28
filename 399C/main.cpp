#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
ll n,k,x ;
int  tab[100007] ;
int tab1[100007] ;
int tab2[100007] ;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> n >> k >> x ;
    for(int i = 0 ; i < n ; i ++)cin >> tab[i] ;

    /// stupid :
    k %= 4 ;
    for(int i = 0 ; i < k ; i ++){
        sort(tab,tab+n) ;

//        for(int j = 0 ; j < n ; j++){
//            cout << tab[j] << ' ' ;
//        }
//        cout << endl;

        for(int j = 0 ; j < n ; j += 2){
            tab[j] ^= x ;
        }
    }

    int mini(INF)    ;
    int maxi(-1*INF) ;

    for(int i = 0 ; i < n ; i++){
        mini = min(mini,tab[i]) ;
        maxi = max(maxi,tab[i]) ;
    }
    cout << maxi << ' ' << mini << endl;

    /// end stupid .

    /*
    int mini = INF ;
    int maxi = -1 * INF ;

    for(int i = 0 ; i < n ; i++){
        tab1[i] = tab[i] ;

        if(k>1)tab2[i] = tab[i] ^ x ;
        else tab2[i] = tab[i] ;

        mini = min(mini,min(tab1[i],tab2[i])) ;
        maxi = max(maxi,max(tab1[i],tab2[i])) ;
    }
    cout << maxi << ' ' << mini << endl;
    */

    return 0;
}
