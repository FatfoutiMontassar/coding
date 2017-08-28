#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
int t,tc,n;
bool isPrime[11111] ;

void sieve(){
    memset(isPrime,true,sizeof isPrime) ;
    isPrime[1] = false ;
    for(int i = 2 ; i <= 10000 ; i++){
        if(isPrime[i]){
            for(int j = i*i ; j <= 10000 ; j += i)isPrime[j] = false ;
        }
    }
return ;
}

bool test(int x){
    if(isPrime[x] == true){
        set<int > St ;
        int aux = x ;
        while(St.insert(aux).S){
            int temp(0) ;
            while(aux){
                temp += (aux%10)*(aux%10) ;
                aux /= 10 ;
            }
            aux = temp ;
        }
        return (aux == 1) ;
    }else{
        return false ;
    }
}
int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    sieve() ;

    cin >> t ;
    while(t--){
        cin >> tc >> n ;
        cout << tc << ' ' << n << ' ' ;
        if(test(n))cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
