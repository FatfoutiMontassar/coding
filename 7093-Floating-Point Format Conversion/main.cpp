#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
#define pb push_back
int t,tc;
string number ;
map<char,int > M ;

int get(char x){
    if(isdigit(x))return (int)(x-'0') ;
    else{
        return (int)(x-'A'+10) ;
    }
}

string fun(){
    vector<bool > bits ;
    for(int i = 0 ; i < number.size() ; i++){
        int x = get(number[i]);
        for(int j = 0 ; j < 4 ; j++){
            if(x & (1<<j) > 0 )bits.pb(1) ;
            else bits.pb(0) ;
        }
    }
    for(int i = 0 ; i < bits.size() ; i++){
        cout << bits[i] << ' ' ;
    }
    cout << endl;
}


int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> t ;
    while(t--){
        cin >> tc >> number ;
        cout << tc << ' ' << fun() << endl;
    }
    return 0;
}
