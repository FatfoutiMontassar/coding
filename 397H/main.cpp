#include <bits/stdc++.h>

using namespace std;
const int N = 1000005;
int f[N],g[N],h[N];
vector<int> ff;
bool vis[N];
int n,ans;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin>>n;

    ans = n;

    for(int i=1;i<=n;i++){
        cin>>f[i];
        if(!vis[f[i]]) vis[f[i]] = true;
        else ans--;
    }

    memset(vis,false,sizeof vis);

    ff.push_back(0);

    for(int i=1;i<=n;i++){
        if(!vis[f[i]]){
            vis[f[i]] = true;
            ff.push_back(f[i]);
        }
    }


    for(int i=1;i<=ans;i++){
        h[i] = ff[i];
        g[i] = i;
    }

    for(int i=1;i<=n;i++){
        g[i] = max(1,g[i]);
    }

    for(int i=1;i<=ans;i++){
        if(g[h[i]] != i){
            cout<< -1 << endl;
            return 0;
        }
    }

    cout<<ans<<endl;
    for(int i = 1 ; i <= n   ; i++)cout<< g[i] << ' ' ; cout << endl;
    for(int i = 1 ; i <= ans ; i++)cout<< h[i] << ' ' ; cout << endl;

    return 0;
}
