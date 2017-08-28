#include <bits/stdc++.h>


using namespace std;
int N ;
vector<pair<int,int > > v ;
vector<int > LIS ;

int lis(){
    int ans = 1 ;
    for(int i = 1 ; i < N ; i++){
        for(int j = 0 ; j < i ; j++){
            if((v[j].first <= v[i].first && v[j].second <= v[i].second )
               && !(v[j].first == v[i].first && v[j].second == v[i].second ) ){
                LIS[i] = max(LIS[i],LIS[j]+1);
                ans = max(ans , LIS[i] ) ;
            }
        }
    }
return ans ;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif

    int t ;
    cin >> t ;
    while(t--){
        cin >> N ;
        LIS.clear() ; LIS.resize(N) ;
        v.clear()   ; v.resize(N)   ;
        for(int i = 0 ; i < N ; i++){cin >> v[i].first  ; LIS[i] = 1 ; }
        for(int i = 0 ; i < N ; i++){cin >> v[i].second ; }
        sort(v.begin() , v.end() );
        int ans = lis() ;
        cout << ans << endl;
    }
    return 0;
}
