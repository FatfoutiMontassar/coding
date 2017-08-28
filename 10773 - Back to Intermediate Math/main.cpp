#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
#define EPS 0.000000001
int t ;
double d,u,v ;


int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> t ;
    for(int test = 1 ; test <= t ; test++){
        cin >> d >> u >> v ;
        if(abs(u) < EPS ){
            cout << "can\'t determine" << endl;
            continue ;
        }
        double ans1 =  ;
        double ans2 = 0 ;

        cout << abs(ans1-ans2) << endl;
    }
    return 0;
}
