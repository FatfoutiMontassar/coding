#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
int n ;
int  len[100007] ;
int cost[100007] ;
int  cnt[100007] ;
int  BIT[100007] ;

set<int > St ;
vector<int> poss ;

void add(int pos,int val){
    int x = pos ;
    while(x<=1e5){
        BIT[x] += val ;
        x += (x&(-x)) ;
    }
return ;
}

int get(int pos){
    int ret(0) ;
    int x(pos) ;
    while(x){
        ret += BIT[x] ;
        x -= (x&(-x)) ;
    }
return ret ;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> n ;
    memset(BIT,0,sizeof BIT) ;
    for(int i = 0 ; i < n ; i++){
        cin >> len[i] ;
        cnt[len[i]]++;
        if(St.insert(len[i]).second){
            poss.push_back(len[i]) ;
        }
    }
    sort(poss.rbegin(),poss.rend()) ;
    int sum(0) ;
    for(int i = 0 ; i < n ; i++){
        cin >> cost[i] ;
        sum += cost[i] ;
        add(len[i],cost[i]);
    }
    for(int i = 1 ; i <= 7 ; i++){
        cout << i << ' ' << get(i) << endl;
    }
    int ans = INF ;
    for(int i = 0 ; i < poss.size() ; i++){
        if(cnt[poss[i]]>=n/2){
            ans = min(ans,sum-get(poss[i])) ;
            cout << poss[i] << ' ' << get(poss[i]) << endl;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
