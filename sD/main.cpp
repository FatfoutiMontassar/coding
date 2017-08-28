#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
#define MAXN 1000007
int t,n ;
int tab[MAXN] ;
vector<int > primeFactors[MAXN] ;

void fun(int x){
    if(primeFactors[x].size()>0)return ;
    int aux = x ;
    for(int i = 2 ; i*i <= x ; ++i){
        if(aux%i == 0){
            primeFactors[x].push_back(i);
            while(aux%i == 0)aux/=i ;
        }
        if(aux==1)break;
    }
    if(aux!=1)primeFactors[x].push_back(aux) ;
return ;
}



int main(){

    freopen("dealing.in"   , "r" ,stdin  ) ;
    scanf("%d",&t) ;
    while(t--){
        scanf("%d",&n) ;
        int ans(0) ;
        int l = 0 ;
        int r = 0 ;
        set<int> St ;
        while(r<n){
            scanf("%d",tab+r) ;
            fun(tab[r]) ;
            while(1){
                bool flag = true ;
                for(int i = 0 ; i < primeFactors[tab[r]].size() ; ++i){
                    if(St.count(primeFactors[tab[r]][i]) != 0){
                        flag = false ;
                        break ;
                    }
                }
                if(!flag){
                    for(int i = 0 ; i < primeFactors[tab[l]].size() ; ++i){
                        St.erase(St.find(primeFactors[tab[l]][i])) ;
                    }
                    ++l;
                }else{
                    break ;
                }
            }
            for(int i = 0 ; i < primeFactors[tab[r]].size() ; ++i){
                St.insert(primeFactors[tab[r]][i]) ;
            }
            ans = max(ans,r-l+1) ;
            ++r;
        }
        printf("%d\n",ans) ;
    }
    return 0;
}
