#include <bits/stdc++.h>

using namespace std;
#define ll long long int
ll t,n ;
ll tab[100007] ;

int main()
{
    cin >> t ;
    while(t--){
        cin >> n ;
        for(int i = 0 ; i < n ; i++)cin >> tab[i] ;
        ll sum(0LL) ;
        for(int i = 1 ; i < n ; i++){
            if(tab[i]+sum<tab[i-1]){
                sum += (tab[i-1]-tab[i]-sum) ;
                tab[i] += sum ;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
