#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second

set<int> se;
int ma[1000010];
int n,x;

int main(){

//#ifndef ONLINE_JUDGE
//    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
////    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
//#endif
//ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
freopen("find.in","r",stdin);
    int t;
    cin>>t;
    while(t--){
        se.clear();
        memset(ma,0,sizeof ma);
        int mx = -1;
        cin>>n;
        for(int i=0;i<n;++i){
            scanf("%d",&x);
            if(x>1)se.insert(x);
            ++ma[x];
            mx = max(mx,x);
        }
        ll ans = 1ll*(n-ma[0])*(ma[0]) + 1ll*(n-ma[0]-ma[1])*ma[1];
        for(auto it = se.begin();it!=se.end();++it){
            int cur = (*it);
            int j = 2*cur;
            while(j<=mx){
                ans += 1ll*ma[cur]*ma[j];
                j += cur;
            }
        }
        cout<<ans<<"\n";
    }


    return 0;
}
