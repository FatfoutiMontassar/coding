#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
string number ;
int dp[111][5] ;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> number ;
    reverse(number.begin(),number.end()) ;
    for(int i = 0 ; i <= 1000 ; i += 8){
        bool flag = false ;
        for(int p = 0 ; p < 111 ; p++){
            for(int q = 0 ; q < 5 ; q++){
                dp[p][q] = 0 ;
            }
        }
        int idx(1) ;
        for(int p = 1 ; p <= number.size() ; p++){
            int q(1),x(i) ;
            while(x || i == 0 ){
                    if((int)(number[p-1]-'0') == x%10 )dp[p][q] = dp[p-1][q-1] + 1 ;
                    else dp[p][q] = max( dp[p-1][q] , dp[p][q-1] ) ;
                q++;
                idx = max(idx,q) ;
                x/=10 ;
                if(i == 0)break;
            }
        }
        if(dp[number.size()][idx-1] == idx-1){
            cout << "YES" << endl << i << endl;
            return 0 ;
        }
    }
    cout << "NO" << endl;

    return 0;
}
