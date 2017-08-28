#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
int na,ma,nb,mb ;
string a[55] ;
string b[55] ;

bool ok(int x,int y){
    return ( x >= 0 && x < nb && y >= 0 && y < mb ) ;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> na >> ma ;
    for(int i = 0 ; i < na ; i++){
        cin >> a[i] ;
    }
    cin >> nb >> mb ;
    for(int i = 0 ; i < nb ; i++){
        cin >> b[i] ;
    }
    int ans(-1),ansx(-1),ansy(-1) ;
    for(int x = -50 ; x <= 50 ; x++){
        for(int y = -50 ; y <= 50 ; y++){
            int aux = 0 ;
            for(int i = 0 ; i < na ; i++){
                for(int j = 0 ; j < ma ; j++){
                    aux += (ok(i+x,j+y) ? ( a[i][j] == '1' &&  b[i+x][j+y] == '1'  ? 1 : 0 ) : 0 ) ;
                }
            }
            if(aux>ans){
                ans = aux ;
                ansx = x ;
                ansy = y ;
            }
        }
    }
    cout << ansx << ' ' << ansy << endl;
    return 0;
}
