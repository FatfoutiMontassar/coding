#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
int n,m,k,v ;
int occ[1000007] ;
int tab[1000007] ;
map<pair<int,int > , int > M ;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif

    while(cin >> n >> m){
        M.clear() ;
        memset(occ,0,sizeof occ) ;
        for(int i = 0 ; i < n ; i++){
            cin >> tab[i] ;
            occ[tab[i]]++;
            M[make_pair(tab[i],occ[tab[i]])] = i+1 ;
        }
        for(int i = 0 ; i < m ; i++){
            cin >> k >> v ;
            if(M.count(make_pair(v,k)) > 0 )cout << M[make_pair(v,k)] << endl;
            else cout << 0 << endl;
        }
    }


    return 0;
}
