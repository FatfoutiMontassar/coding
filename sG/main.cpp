#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
pair<ll,ll > state[500007] ;
map<ll,vector<int > > M1 ; /// -
map<ll,vector<int > > M2 ; /// +
ll n,x ;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
//    freopen("great.in"   , "r" ,stdin  ) ;
    int t ;
    scanf("%d",&t) ;
    while(t--){
        scanf("%d",&n) ;
        for(int i = 0 ; i < n ; i++){
            scanf("%lld",&x) ;
            state[i].F = x ;
        }
        for(int i = 0 ; i < n ; i++){
            scanf("%lld",&x) ;
            state[i].S = x ;
            M1[abs(state[i].F-state[i].S)].push_back(i) ;
            M2[state[i].F+state[i].S].push_back(i) ;
        }
        priority_queue<pair<int,int > ,vector<pair<int,int > > , greater<pair<int,int >  > > Q ;
        vector<int > dist(n,INF) ;
        dist[0] = 0 ;
        /// f : distance , s : node
        Q.push(make_pair(0,0)) ;
        while(!Q.empty()){
            pair<int,int >  here = Q.top() ;
            Q.pop() ;
            if(here.S == n-1)break ;
            for(auto i : M1[abs(state[here.S].F-state[here.S].S)] ){
                    if(here.F+1<dist[i]){
                        dist[i] = here.F+1 ;
                        Q.push(make_pair(dist[i],i)) ;
                    }
            }
            for(auto i : M2[state[here.S].F+state[here.S].S] ){
                    if(here.F+1<dist[i]){
                        dist[i] = here.F+1 ;
                        Q.push(make_pair(dist[i],i)) ;
                    }
            }
        }
        if(dist[n-1] == INF)printf("-1\n") ;
        else printf("%d\n",dist[n-1]) ;
    }


    return 0;
}
