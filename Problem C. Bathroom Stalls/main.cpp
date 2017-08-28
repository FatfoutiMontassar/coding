#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
#define state pair< pair < int , int > , pair < int , int > >
int t,n,k ;
int ri[1111111] ;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    /// *....*
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ; cout.tie(0) ;
    cin >> t ;
    int tc(1) ;
    while(t--){
        cin >> n >> k ;
        ri[0] = n+1 ;

        ri[n+1] = n+1 ;

        int mind = 0 ;
        int maxd = 0 ;

        for(int i = 0 ; i < k ; i++){
//            cout << i << endl;
            int d = -1 ;
            int D = -1 ;
            int pos = -1 ;
            int r = -1 ;
//            cout << "i : "<<i<<endl;
            for(int j = 0 ; j < n+1 ; j=ri[j]){
//                cout << "*" << endl;
                int num = (ri[j] - j - 1 ) ;
//                cout << num << endl;
                if(num>0){
                    int x = num-1 ;
                    int newd = min( x/2,(x+1)/2 ) ;
                    int newD = max( x/2,(x+1)/2 ) ;
                    if(newd>d || (newd == d && newD > D ) ){
                        d = newd ;
                        D = newD ;
                        pos = j+(x/2)+1 ;
                        r = j ;
                    }
                }
            }
//            cout << "pos : "<<pos << endl;
            ri[pos] = ri[r] ;
            ri[r] = pos ;
            mind = d ;
            maxd = D ;
        }
        /**********************************************/
        priority_queue<state > Q ;
        Q.push({{min((n-1)/2,n/2),max((n-1)/2,n/2)},{0,n+1}}) ;
        int minid = min((n-1)/2,n/2) ;
        int maxid = max((n-1)/2,n/2) ;
        for(int i = 0 ; i < k ; i++){
            state st = Q.top() ;
            Q.pop() ;
            int from = st.S.F ;
            int to   = st.S.S ;
            int dd    = st.F.F ;
            int DD    = st.F.S ;
            minid = dd ;
            maxid = DD ;
            Q.push({{min((dd-1)/2,dd/2),max((dd-1)/2,dd/2)},{from,from+dd+1}}) ;
            Q.push({{min((DD-1)/2,DD/2),max((DD-1)/2,DD/2)},{from+dd+1,to}}) ;
        }
//        cout << "Case #"<<tc++<<": "<<maxd<<" "<<mind << endl;
        /****************************************************/
//        cout << "Case #"<<tc++<<": "<<maxd <<" "<<mind << endl;
        if(mind != minid || maxd != maxid)cout << "error" << endl;
    }
    return 0;
}
