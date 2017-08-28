#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
ll n,p,cost,root,sum ;
bool solved ;
ll    val[1000007] ;
ll parent[1000007] ;
ll    cum[1000007] ;
vector<vector<int > > g ;

ll dfsCalc(int pos){
    ll ret = 0LL ;
    for(int i = 0 ; i < g[pos].size() ; i++){
        ret += dfsCalc(g[pos][i]) ;
    }
return cum[pos] = ret + val[pos] ;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> n ;
    g.clear() ;
    g.resize(n) ;
    for(int i = 0 ; i < n ; i++){
        cin >> p >> cost ;
        if(p){
            g[p-1].push_back(i) ;
            val[i] = cost ;
            parent[i] = p-1 ;
        }else{
            root = i ;
            parent[i] = -1 ;
            val[i] = cost ;
        }
    }

    sum = dfsCalc(root) ;

    if(sum%3 != 0){
        cout << -1 << endl;
        return 0 ;
    }

    vector<int > poss1,poss2 ;

    for(int i = 0 ; i < n ; i++){
        if(cum[i] == sum/3 )     poss1.push_back(i) ;
        if(cum[i] == 2*(sum/3) ) poss2.push_back(i) ;
    }

    for(int i = 0 ; i < poss1.size() ; i++){
        int curr = i ;
        map<int ,bool > block ;
        while(curr != -1){
            block[i] = true ;
            if(cum[curr] == 2*(sum/3) && ( parent[curr] != -1 ) && ( parent[i] != -1 ) ){
//                cout << "*" << endl;
                cout << i+1 << ' ' << curr+1 << endl;
                return 0 ;
            }
            curr = parent[curr] ;
        }
        for(int j = 0 ; j < poss1.size() ; j++){
            if(block[poss1[j]] == false && (i!=poss1[j]) && ( parent[i] != -1 ) && ( parent[poss1[j]] != -1 ) ){
                cout << i+1 << ' ' << poss1[j]+1 << endl;
                return 0 ;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
