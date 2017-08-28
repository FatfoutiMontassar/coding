#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
int n,m,u,v,ni,k ;
string s ;
int ans[111][111][2] ;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif

    while(cin >> n && n != 0 ){
        cin >> m ;
        for(int i = 1 ; i <= n ; i++){
            for(int j = i ; j <= n ; j++){
                ans[i][j][0] = -1*INF ;
                ans[i][j][1] = INF ;
            }
        }
        bool flag = false ;
        for(int i = 0 ; i < m ; i++){
            cin >> u >> ni >> s >> k ;
            v = u + ni ;
            if(s == "gt"){
                ans[u][v][0] = max(ans[u][v][0],k) ;
            }else{
                ans[u][v][1] = min(ans[u][v][1],k) ;
            }
            if(ans[u][v][1] <= ans[u][v][0])flag = true ;
        }
        if(flag == true )cout << "successful conspiracy" << endl;
        else cout << "lamentable kingdom" << endl;
    }
    return 0;
}
