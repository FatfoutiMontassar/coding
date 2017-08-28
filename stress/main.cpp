#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second

int main(){

#ifndef ONLINE_JUDGE
//    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
    freopen("/home/montaf/Documents/in.in" , "w" ,stdout ) ;
#endif

    cout << 100 << endl;
    for(int i = 0 ; i < 100 ; i++){
        int no = rand()%10 + 1 ;
        cout << i+1 << ' ' ;
        string out = "" ;
        for(int j = 0 ; j < no ; j++){
            int p = rand()%16 ;
            int n = rand()%5 + 1 ;
            for(int k = 0 ; k < n ; k++){
                if(p>=10)out += (char)(p-10+'A') ;
                else out += (char)(p+'0') ;
            }
        }
        if(out.size()&1)out += "0" ;
        cout << out.size()/2 << endl;
        cout << out << endl;
    }


    return 0;
}
