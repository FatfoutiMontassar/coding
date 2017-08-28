#include <bits/stdc++.h>
/// not solved
using namespace std;
#define ll long long int
struct node{
    ll sum;
    ll sums;
    node(){}
    node(ll sum_,ll sums_):sum(sum_),sums(sums_){}
};
const int N = 100007 ;
ll a[N] ;
node st[4*N] ;
ll o,l,r,val;

void propagate(int cur,int lval){

}

void set(int cur,int ns,int ne,int qs,int qe,int val){
    if(ns > qe || ne < qs)return ;
    propagate(cur,lazy[cur]) ;
    if(ns>=qs && ne <= qe){
        st[]
        return ;
    }
}

void build(int cur,int ns,int ne){
    if(ns == ne){
        st[cur] = node(a[ns],a[ns]*a[ns]) ;
        return ;
    }
    int mid = ns + (ne-ns)/2 ;
    build(2*cur,ns,mid) ;
    build(2*cur+1,mid+1,ne) ;
    st[cur] = node(st[2*cur].sum+st[2*cur+1].sum,st[2*cur].sums+st[2*cur+1].sums) ;
return ;
}

void add(int cur,int ns,int ne,int qs,int qe,int val){
    if(ns > qe || ne < qs)return ;
    propagate(cur,lazy[cur]);
    if(ns >= qs && ne <= qe){
        st[cur] = node(st[cur].sum+(ne-ns+1)*val,st[cur].sums+val*val*(ne-ns+1)+2*val*st[cur].sum) ;
        propagate(cur,val) ;
        return ;
    }
    int mid = ns + (ne-ns)/2 ;
    build(2*cur,ns,mid) ;
    build(2*cur+1,mid+1,ne) ;
    st[cur] = node(st[2*cur].sum+st[2*cur+1].sum,st[2*cur].sums+st[2*cur+1].sums) ;
return ;
}

ll query(int cur,int ns,int ne,int qs,int qe){
    if( ns > qe || ne < qs)return 0LL ;
    propagate(cur,lazy[cur]) ;
    if( ns >= qs && ne <= qe )return st[cur].sums ;
    int mid = ns + (ne-ns)/2 ;
    return query(2*cur,ns,mid,qs,qe) + query(2*cur+1,mid+1,ne,qs,qe) ;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;

    int t,tc(1) ;
    cin >> t ;
    while(t--){
        cout << "Case "<<tc++<<":"<<endl;
        cin >> n >> m ;
        for(int i = 0 ; i < n ; i++)
            cin >> a[i] ;
        build(1,0,n-1) ;
        for(int i = 0 ; i < m ; i++){
            cin >> o >> l >> r ;
            if(o != 2){
                cin >> val ;
                if(o == 1)add(1,0,n-1,l,r,val) ;
                else set(1,0,n-1,l,r,val) ;
            }else{
                cout << query(1,0,n-1,l-1,r-1) << endl;
            }
        }
    }
    return 0;
}
