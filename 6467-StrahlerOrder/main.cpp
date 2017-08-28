#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
#define pb push_back
int t ;
vector<vector<int > > g ;
vector<vector<int > > grev ;
bool ok[1111] ;
vector<int > temp[2] ;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> t ;
    while(t--){
        cin >> tc >> n >> m ;
        memset(ok,true,sizeof ok) ;
        memset(ans,-1,sizeof ans) ;
        g.clear() ; grev.clear() ;
        g.resize(n) ; grev.resize(n) ;
        for(int i = 0 ; i < m ; i++){
            cin >> u >> v ;
            u--; v--;
            g[u].pb(v) ;
            grev[v].pb(u) ;
            ok[v] = false ;
        }
        temp[0].clear() ;
        temp[1].clear() ;
        for(int i = 0 ; i < n ; i++){
            if(ok[i] == true){
                temp[0].pb(i) ;
                ans[i] = 1 ;
            }
        }
        while(1){
            int cnt(0) ;
            for(int i = 0 ; i < temp[0].size() ; i++)cnt += g[temp[0][i]].size() ;
            if(cnt == 0)break;


        }
        cout << tc << ans[n-1] << endl;
    }

    return 0;
}
