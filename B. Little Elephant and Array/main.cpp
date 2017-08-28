#include <bits/stdc++.h>
/// not finished !
using namespace std;
#define S second
#define F first

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif

    int ret = 0 ;
    scanf("%d%d",&n,&m) ;
    for(int i = 0 ; i < n ; i++)
        scanf("%d",a+i) ;

    for(int i = 0 ; i < m ; i++){
        scanf("%d%d",&q[i].F,&q[i].S) ;
    }

    build(1,0,n-1) ;
    return 0;
}
