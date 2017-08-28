#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
#define pb push_back
int t,tc,k ;
vector<int > ans[2222] ;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    vector<int > v(1,1) ;
    ans[1] = v ;
    for(int i = 2 ; i <= 2000 ; i++){
        vector<int > temp = ans[i-1] ;
        int idx(-1) ;
        for(int j = 0 ; j < temp.size() ; j++){
            if(temp[j] == 0){
                idx = j ;
                break ;
            }
        }
        vector<int > aux ;
        if(idx != -1){
            for(int j = 0 ; j < idx ; j++){
                aux.pb(temp[j]-1) ;
            }
            aux.pb(idx+1) ;
            for(int j = idx+1 ; j < temp.size() ; j++){
                aux.pb(temp[j]) ;
            }
        }else{
            for(int j = 0 ; j < temp.size() ; j++){
                aux.pb(temp[j]-1) ;
            }
            aux.pb(temp.size()+1) ;
        }
        ans[i] = aux ;
//        cout << i << ' ' << aux.size() << endl;
//        for(int j = 0 ; j < aux.size(); j++)cout << aux[j] << ' ' ;
//        cout << endl;
    }
    cin >> t ;
    for(int test = 1 ; test <= t ; test++){
        cin >> tc >> k ;
        cout << tc << ' ' << ans[k].size() << endl;
        int cnt(0) ;
        for(int i = 0 ; i < ans[k].size() ; i++){
            cout << ans[k][i] ;
            cnt++;
            if(cnt != 10 && (i+1) != ans[k].size() )cout << ' ' ;
            if(cnt == 10){
                cout << endl;
                cnt = 0 ;
            }
        }
        if(ans[k].size()%10 != 0)cout << endl;
    }
    return 0;
}
