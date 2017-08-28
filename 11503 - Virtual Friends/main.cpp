#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
int t,n ;
int parent[300007] ;
int sz[300007] ;
map<string,int > M ;
string s1,s2 ;

int findSet(int x){
    return parent[x] =
        (parent[x] == x ? x : findSet(parent[x] ) ) ;
}


void unionSet(int x,int y){
    int sz1 = sz[findSet(x)] ;
    int sz2 = sz[findSet(y)] ;
    int mini = min(findSet(x),findSet(y)) ;
    int maxi = max(findSet(x),findSet(y)) ;
    parent[maxi] = mini ;
    sz[mini] = sz1+sz2 ;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif

    cin >> t ;
    for(int test = 1 ; test <= t ; test++){
        int cnt(0) ;
        cin >> n ;
        for(int i = 0 ; i <= 2*n ; i++){parent[i] = i ; sz[i] = 1 ; }

        for(int i = 0 ; i < n ; ++i){
            cin >> s1 >> s2 ;
            if(M.count(s1) == 0){
                M[s1] = cnt++ ;
            }
            if(M.count(s2) == 0){
                M[s2] = cnt++ ;
            }
            if(findSet(M[s1]) != findSet(M[s2])){
                unionSet(M[s1],M[s2]) ;
            }
            cout << sz[min(findSet(M[s1]),findSet(M[s2]))] << endl;
        }
    }


    return 0;
}
