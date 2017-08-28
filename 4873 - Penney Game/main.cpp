#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
int t,tc ;
string tab[8] = {"HTH" ,"HTT" ,"THH" ,"THT" ,"TTH", "TTT" ,"HHT","HHH" } ;
string s ;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    sort(tab,tab+8) ;
    cin >> t ;
    while(t--){
        cin >> tc ;
        cin >> s ;
        vector<int > ans(8,0) ;
        for(int i = 0 ; i < s.size() -2 ; i++){
            string aux = "" ;
            for(int j = i ; j <= i+2 ; j++){
                aux += s[j] ;
            }
            for(int j = 0 ; j < 8 ; j++){
                if(aux == tab[j]){
                    ans[j]++;
                    break;
                }
            }
        }

        cout << tc ;
        for(int i = 0 ; i < 8 ; i++){
            cout << ' ' << ans[7-i] ;
        }
        cout << endl;
    }


    return 0;
}
