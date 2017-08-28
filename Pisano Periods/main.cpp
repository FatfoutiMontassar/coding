#include <bits/stdc++.h>
#define ll long long

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second


int per(int n) {
    int a(0),b(1),c;
    int i = 0;
    while(1){
        c = (a+b)%n;
        a = b;
        b = c;
        if(a==0 && b ==1)return i+1;
        ++i;
    }
}


int main(){

#ifndef ONLINE_JUDGE
//    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif

    int t;
    cin>>t;
    int cs;
    ll n;
    while(t--){
        cin>>cs>>n;
        cout<<cs<<" "<<per(n)<<"\n";
    }

    return 0;
}
