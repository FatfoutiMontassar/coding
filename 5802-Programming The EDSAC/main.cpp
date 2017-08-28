#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
#define ld long double
#define pb push_back
int t , tc ;
ld val ;
const string alpha = "PQWERTYUIOJ#SZK*?F@D!HNM&LXGABCV" ;
vector<ld> pos ;
map<ld,int > M ;

void run(){
    pos.clear() ;
    int mask = (1<<17)-1 ;
    for(int i = 0 ; i <= mask ; i++){
        ld ret = 0.0 ;
        for(int j = 15 ; j >= 0 ; j--){
            ret += ( (i&(1<<j)) != 0 ? 1.0/(ld)((int)(1<<(16-j))) : 0.0 ) ;
        }
        if((i&(1<<16)) != 0)ret -= 1 ;
        M[ret] = i ;
        pos.pb(ret) ;
    }
    sort(pos.begin(),pos.end()) ;
return ;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    run() ;
    cin >> t ;
    while(t--){
        cin >> tc >> val ;
        cout << tc << ' ' ;
        bool neg = (val < 0 ? true : false ) ;

        if(val>=1.0 || val<-1.0){
            cout << "INVALID VALUE" << endl;
            continue ;
        }

        int msk = 0 ;
        if(val<0){
            for(int i = 0 ; i < pos.size() ; i++){
                if(pos[i]>=val){
                    msk = M[pos[i]] ;
                    break;
                }
            }
        }else{
            for(int i = 0 ; i < pos.size() ; i++){
                int j = pos.size()-1-i ;
                if(pos[j]<=val){
                    msk = M[pos[j]] ;
                    break;
                }
            }
        }

        int idxChar = 0 ;
        int data = 0 ;

        for(int i = 0 ; i < 5 ; i++){
            idxChar += (msk&(1<<(12+i))) ;
        }
        idxChar>>=12 ;

        for(int i = 0 ; i < 11 ; i++){
            data += (msk&(1<<(1+i))) ;
        }
        data>>=1 ;
        cout << alpha[idxChar] << ' ' << data << (msk&1 ? " D" : " F" )<< endl;
    }
    return 0;
}
