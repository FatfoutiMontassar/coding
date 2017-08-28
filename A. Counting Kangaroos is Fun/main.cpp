#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
int tab[500007] ;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    int n ;
    cin >> n ;
    for(int i = 0 ; i < n ; i++)cin >> tab[i] ;
    sort(tab,tab+n) ;
    int p1 = n-1 ;
    int p2 = n/2 - 1 ;
    int cnt = 0 ;
    while(p1>=0 && p2>=0){
        if(tab[p1]>=2*tab[p2]){
            --p1;
            --p2;
            cnt++;
        }else{
            --p2;
        }
    }
    cout << n-cnt << endl;
    return 0;
}
