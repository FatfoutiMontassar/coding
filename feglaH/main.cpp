#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
#define ld long double
ld a,b,c ;

int main(){

    freopen("unit.in"   , "r" ,stdin  ) ;

    int t ;
    cin >> t ;
    while(t--){
        cin >> a >> b >> c ;
        cout << ceil(log2(a))+ceil(log2(b))+ceil(log2(c)) << endl;
    }
    return 0;
}
