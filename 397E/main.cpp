#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define ll long long int
#define INF (ll)(1000000000000000007)
#define PI acos(-1)
#define F first
#define S second

struct state {
    ll val  ;
    ll mini ;
    ll maxi ;
    state(){}
    state(ll val_,ll mini_ ,ll maxi_):val(val_),mini(mini_),maxi(maxi_){}
};

const ll MAXN = 100007 ;
ll n,m,l,r ;
ll tab[MAXN] ;

state ST[4*MAXN] ;

state merge(state a,state b){
    ll ret = INF ;
    ret = min(ret,a.val) ;
    ret = min(ret,b.val) ;
    ret = min(ret,abs(a.maxi-b.mini)) ;
    ret = min(ret,abs(a.mini-b.maxi)) ;
    ret = min(ret,abs(a.mini-b.mini)) ;
    ret = min(ret,abs(a.maxi-b.maxi)) ;
    return state(ret,min(a.mini,b.mini),max(a.maxi,b.maxi)) ;
}

void build(ll node,ll s,ll e){
    if(s == e){
            ST[node] = state(2LL*(ll)INF,tab[s],tab[s]) ;
    }else{
        ll mid = (s+e)/2 ;
        build(2*node,s,mid) ;
        build(2*node+1,mid+1,e) ;

        ST[node] = merge(ST[2*node],ST[2*node+1]) ;
    }
//    cout << s << ' ' << e << ' ' << ST[node].val << ' ' << ST[node].mini << ' ' << ST[node].maxi << endl;
return ;
}

state query(ll node,ll s,ll e,ll l,ll r){
//    cout << s << ' ' << e << endl;
    if( ( s > r || e < l ) || s > e ){
        return state(INF,INF,-1LL*INF) ;
    }
    else if(s>=l && e <=r){
//        cout << s << ' ' << e << ' ' << ST[node].val << ' ' << ST[node].mini << ' ' << ST[node].maxi << endl;
        return ST[node] ;
    }
    else{
        ll mid = (s+e)/2 ;
        state ret = merge(query(2*node,s,mid,l,r),query(2*node+1,mid+1,e,l,r)) ;
//        cout << ret.val << endl;
        return ret ;
    }
}

ll stupid(int l,int r){
    vector<ll > temp ;
    for(int i = l ; i <= r ; i++)temp.pb(tab[i]) ;
    sort(temp.begin(),temp.end()) ;
    ll ans(INF) ;
    for(int i = 1 ; i < temp.size() ; i++){
        ans = min(ans,abs(temp[i]-temp[i-1])) ;
    }
    return ans ;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> n ;
    for(int i = 0 ; i < n ; i++)cin >> tab[i] ;
    build(1,0,n-1) ;
    cin >> m ;
    for(int i = 0 ; i < m ; i++){
        cin >> l >> r ;
        cout << stupid(l-1,r-1) << endl;
    }

    return 0;
}
