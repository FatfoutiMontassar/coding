#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second

int main(){

    char files[3][10] = { "1.in" , "2.in" , "3.in" } ;
    for(int i = 0 ; i < 3 ; i++){
        freopen( files[i] , "r" , stdin ) ;
        string flag ;
        getline(cin,flag) ;
        cout << flag << endl;
    }
    return 0;
}
