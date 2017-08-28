#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
int t,tc,x,y ;

void fun(){

	if(y > x) {
        cout << 2 << ' ' << x << ' ' << y << endl;
	} else if (y >= 4) {
        cout << 6 << ' ' << 1 << ' ' << 2 << ' ' << 3 << ' ' << x+5-y << ' ' << x+2 << ' ' << x+3 << endl;
	} else {
        cout << "NO PATH" << endl;
	}
return ;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif

   cin >> t ;
   while(t--){
        cin >> tc >> x >> y ;
        cout << tc << ' ' ;
        fun() ;
   }
   return 0;
}
