#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif

    int t;
    cin>>t;
    while(t--){
        int n,fav;
        cin>>n>>fav;
        fav--;
        cin>>len[0];
        int cur (0);
        for(int i=1;i<n;++i){
            cin>>x;
            if(i==fav)cur = len[i-1];
            len[i] = len[i-1]+x;
        }
        cin>>days;
        for(int i=0;i<days;++i){
            cin>>nseg;
            int ln;
            for(int j=0;j<nseg;++j){
                cin>>ln;
                if(j&1){
                    cur += ln;
                }
                else{
                    ans += ln;
                    cur += ln;

                }
            }
        }
    }

    return 0;
}
