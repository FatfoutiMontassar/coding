#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second

ll memo[1<<17][7];
pair<int,int> dom[17];
int all,n;

int comp(int last,int idx){
    if(last==dom[idx].first)return -1;
    else if(last==dom[idx].second)return 1;
    return 0;
}

ll dp(int mask,int last){
    if(mask==all){
//        cout<<"here";
        return 1;
    }

    ll& ret = memo[mask][last];
    if(ret!=-1)return ret;
    ret = 0;

    int tmp = 1;
    for(int i=0;i<n;++i){
            if(!(tmp & mask)){
            int cmp = comp(last,i);
            if(cmp==1){
                ret += dp(mask|tmp,dom[i].first);
                ret %= INF;
            }else if(cmp==-1){
                ret += dp(mask|tmp,dom[i].second);
                ret %= INF;
            }
        }
        tmp <<= 1;
    }
    return ret;
}

int main(){

//#ifndef ONLINE_JUDGE
//    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
////    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
//#endif

    freopen("let.in"   , "r" ,stdin  ) ;
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;++i)cin>>dom[i].first>>dom[i].second;
        memset(memo,-1,sizeof memo);
        all = (1<<(n))-1;
        ll ans = 0;
        int tmp = 1;
        for(int i=0;i<n;++i){
            ans += dp(tmp,dom[i].first);
            ans += dp(tmp,dom[i].second);
            ans %= INF;
            tmp<<=1;
        }
        cout<<ans<<"\n";
    }

    return 0;
}
