#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
ll t,n,k,l,r,mid;

ll sum(ll x){
    return x*n - x*(x+1)/2 ;
}

int main(){
//    freopen("cheers.in"   , "r" ,stdin  ) ;
    scanf("%lld",&t) ;
    while(t--){
        scanf("%lld %lld",&n,&k) ;
        l = 0 ;
        r = n ;
        for(int i = 0 ; i < 40 ; i++){
            mid = (l+r)/2 ;
            if( k > sum(mid)  && k <= sum(mid+1) ){
                break;
            }else if(sum(mid) < k){
                l = mid+1 ;
            }else{
                r = mid-1 ;
            }
        }
        printf("%lld %lld\n",mid+1,(k-sum(mid)) + (mid+1)) ;
    }
    return 0;
}
