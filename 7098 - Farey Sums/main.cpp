#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
#define mp make_pair
#define pb push_back
vector<int > fractions[10007] ;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    for(int i = 2 ; i <= 10000 ; i++){
        for(int j = 1 ; j <= i ; j++){
            if(__gcd(i,j) == 1){
                fractions[i].pb(j) ;
            }
        }
    }


    return 0;
}
