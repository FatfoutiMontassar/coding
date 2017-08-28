#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
#define buli(x) (int)( __builtin_popcount( x ) )
#define sqr(x) ((x)*(x))
#define sqrt(x) pow(x,0.5)

int n ;
char name[22] ;
double dp[(1<<17)+7] ;
double X[20] ;
double Y[20] ;

double solve(int mask){
    double ret((double)(INF)) ;
    if(buli(mask) == 2*n)return 0 ;
    if(dp[mask] >= 0 )return dp[mask] ;

    for(int i = 0 ; i < 2*n ; i++)if((int)(mask&(1<<i)) == 0 ){
        for(int j = i+1 ; j < 2*n ; j++)if((int)(mask&(1<<j)) == 0 ){
            ret = min( ret , sqrt( sqr(X[i]-X[j])+sqr(Y[i]-Y[j]) )
                + solve( (mask|(1<<i))|(1<<j) ) ) ;
        }
    }
    return dp[mask] = ret ;
}

int main(){

//#ifndef ONLINE_JUDGE
//    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
////    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
//#endif
    int tc(1) ;
    while(scanf("%d",&n)){
      if(n == 0)break ;
        for(int i = 0 ; i < 2*n ;i++){
            scanf("%s %lf %lf",name,X+i,Y+i) ;
        }
        for(int i = 0 ; i <= (1<<(2*n+1)) ; i++){
            dp[i] = -1 ;
        }
        double ans = solve(0) ;
        printf("Case %d: %0.2lf\n",tc++,ans) ;
    }
    return 0;
}
