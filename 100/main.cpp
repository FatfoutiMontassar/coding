#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
#define ll long long int
ll a,b,ret ;
ll ans[10007] ;

int main(){

    for(int i = 1 ; i < 10007 ; i++){
        ll aux(i),cnt(1) ;
        while(aux!=1){
            if(aux&1)aux = aux*3+1 ;
            else aux /= 2 ;
            cnt++;
        }
        ans[i] = cnt ;
    }
    while(scanf("%d %d",&a,&b) != EOF ){
        ret = 0 ;
        for(int i = min(a,b) ; i <= max(a,b) ; i++){
            ret = max(ret,ans[i]) ;
        }
        printf("%d %d %lld\n",a,b,ret) ;
    }
    return 0;
}
