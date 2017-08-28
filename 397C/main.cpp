#include <bits/stdc++.h>

using namespace std;
#define ll long long int
ll k,x,y;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif


    cin>>k>>x>>y;
    if(x<k){
        if(y == 0 || y%k > 0){
            cout<< -1 <<endl;
            return 0;
        }
    }

    if(y < k){
        if(x == 0 || x%k > 0){
            cout<< -1 << endl;
            return 0;
        }
    }

    cout<<x/k + y/k <<endl;

    return 0;
}
