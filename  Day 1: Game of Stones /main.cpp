#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
int t,n ;
int plays[3] = {2,3,5} ;
bool ans[111] ;


int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    ans[0] = false ;
    for(int i = 1 ; i <= 100 ; i++){
        bool flag = true ;
        for(int j = 0 ; j < 3 ; j++){
            if(i>=plays[j]){
                if(ans[i-plays[j]] == false){
                    ans[i] = true ;
                    flag = false ;
                    break;
                }
            }
        }
        if(flag)ans[i] = false ;
    }
    cin >> t ;
    while(t--){
        cin >> n ;
        if(ans[n])cout << "First" << endl;
        else cout << "Second" << endl;
    }


    return 0;
}
