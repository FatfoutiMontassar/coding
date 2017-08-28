#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second

int tab[100007] ;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    int n ;
    cin >> n ;
    for(int i = 0 ; i < n ; i++)cin >> tab[i] ;
    priority_queue<int > Q ;
    int printed(0) ;
    for(int i = 1 ; i <= n ; i++){
        Q.push(tab[i-1]) ;
        while(1){
            if(Q.top() != (n-printed) ){
                break;
            }
            cout << Q.top() << ' ' ;
            printed++;
            Q.pop() ;
        }
        cout << endl;
    }
    return 0;
}
