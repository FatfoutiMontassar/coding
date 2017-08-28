#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second

int main(){

//#ifndef ONLINE_JUDGE
//    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
////    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
//#endif

ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
freopen("hack.in","r",stdin);

    int t;
    cin>>t;
    string s,ns,si;
    int n;
    while(t--){
        cin>>s>>n;
        int ni = n;
        si = s;
        ns = s;
        set<string> se;
        int it = 0;
        while(n-- && se.find(s)==se.end()){
            se.insert(s);
            it++;
            for(int i=1;i<s.size()-1;++i){
                ns[i] = (char)((int)( s[i-1]+s[i+1]-'0'-'0')%10 + '0');
            }
            s = ns;
        }
        if(!n){
            cout<<s<<"\n";
            continue;
        }
        if(it)ni %= it;
        for(int i=0;i<ni;++i){
            for(int i=1;i<s.size()-1;++i){
                ns[i] = (char)((int)(s[i-1]+s[i+1]-'0'-'0')%10 + '0');
            }
            s = ns;
        }
        cout<<s<<"\n";

    }


    return 0;
}
