#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
int n,m;
int freq[100010] ;
vector<int> cities ;
vector<int> towers ;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    cin >> n >> m ;

    cities.resize(n) ;
    for(int i = 0 ; i < n ; i++)cin >> cities[i] ;

    towers.resize(m) ;
    for(int i = 0 ; i < m ; i++)cin >> towers[i] ;

    ll l = 0 ;
    ll r = 2000000000 ;

    while(l<r){
        int mid = (l+r)/2 ;
        memset(freq,0,sizeof freq) ;
//        cout << mid << endl;
        for(int i = 0 ; i < m ; i++){
            vector<int > :: iterator it1 = lower_bound(cities.begin(),cities.end(),towers[i]-mid) ;
            vector<int > :: iterator it2 = upper_bound(cities.begin(),cities.end(),towers[i]+mid) ;
            int low = (int)(it1-cities.begin()) ;
            int hig = (int)(it2-cities.begin())-1 ;
//            cout << low << ' ' << hig << endl;
            freq[low]++;
            freq[hig+1]--;
//            cout <<low << ' ' << hig << endl;
        }
        bool ok = ( freq[0] > 0 ) ;
        for(int i = 1 ; i < n && ok ; i++){
            freq[i] += freq[i-1] ;
            if(freq[i]<=0){
                ok = false ;
            }
        }
        if(ok){
            r = mid ;
        }else{
            l = mid +1 ;
        }
    }
    cout << r << endl;
    return 0;
}
