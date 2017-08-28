#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
int t,tc,nb ;
string text,s ;

int get(char c){
    if(isdigit(c))return (int)(c-'0') ;
    else return (int)(c-'A'+10) ;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/out.out"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out1.out" , "w" ,stdout ) ;
#endif
//    ofstream cout("/home/montaf/Documents/out1.out");
//    ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    cin >> t ;
    while(t--){
        cin >> tc >> nb ;
        nb*=2;
        text = "" ;
        for(int i = 0 ; i < (nb+79)/80 ; i++){
            string perm ;
            cin >> perm ;
            text += perm ;
        }
        string ans = "" ;
        for(int i = 0 ; i < text.size() ; i+= 4){
            int aux = get(text[i]) ;
            aux<<=4 ;
            aux += get(text[i+1]) ;

            if( (aux&(1<<7)) != 0){
                aux &= ((1<<7)-1) ;
                string val = "" ;
                val += text[i+2] ;
                val += text[i+3] ;
                for(int j = 0 ; j < aux+3 ; j++)ans += val ;
            }else{
                aux++;
                for(int j = i+2 ; j < (aux)*2+i+2 ; j++)ans += text[j] ;
                i += (aux)*2-2 ;
            }
        }
        cout << tc << ' ' << (int)ans.size() / 2<< endl;
        for(int i = 0 ; i < (ans.size() +79)/80  ; i++){
            cout << ans.substr(i*80,min(80,(int)ans.size()-i*80)) << endl;
        }
    }
    return 0;
}
