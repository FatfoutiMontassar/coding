#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
int t ;
string s ,sorted ;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> t ;
    while(t--){
        cin >> s ;
        sorted = s ;
        sort(sorted.rbegin(),sorted.rend()) ;
        if(s == sorted)cout << "DONE" << endl;
        else {
            next_permutation(s.begin(),s.end()) ;
            cout << s << endl;
        }
    }
    return 0;
}
