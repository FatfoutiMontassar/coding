#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
ll n,x,s1,s2 ;
vector<pair<ll,int> > a,b ;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> n ;
    s1 = 0 ;
    s2 = 0 ;
    for(int i = 0 ; i < n ; i++){
        cin >> x ;
        if(x>0){
            a.push_back({x,i}) ;
            s1 += x ;
        }else{
            x *= -1 ;
            b.push_back({x,i}) ;
            s2 += x ;
        }
    }

    if(a.size() == 0){cout << "second" << endl; return 0 ; }
    if(b.size() == 0){cout << "first" << endl; return 0 ; }

    if(s1!=s2){
        cout << (s1>s2 ? "first" : "second" ) << endl;
    }else{
        bool same = true ;
        for(int i = 0 ; i < min(a.size(),b.size()) ; i++){
            if(a[i].F != b[i].F){
                same = false ;
                break ;
            }
        }
        if(a.size() != b.size())same = false ;
        if(same){
            cout << ( (a.back()).S > (b.back()).S ? "first" : "second" ) << endl;
        }else{
            for(int i = 0 ; i < min(a.size(),b.size()) ; i++){
                if(a[i].F == b[i].F)continue ;
                else if(a[i].F<b[i].F){
                    cout << "second" << endl;
                    return 0 ;
                }else{
                    cout << "first" << endl;
                    return 0 ;
                }
            }
            if(a.size()>b.size())cout << "first" << endl;
            else cout << "second" << endl;
        }
    }

    return 0;
}
