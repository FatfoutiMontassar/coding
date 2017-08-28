#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
int n ;
pair<int ,int > state[1007] ;


int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    while( cin >> n ){
        for(int i = 0 ; i < n ; i++){
            cin >> state[i].F >> state[i].S ;
        }
        queue<int > Q ;
        stack<int > S ;
        priority_queue<int > PQ ;
        int poss = 0 ;

        bool  okQ(true) ;
        bool  okS(true) ;
        bool okPQ(true) ;

        for(int i = 0 ; i < n ; i++){
            if(state[i].F == 1){
                Q.push(state[i].S) ;
            }else{
                int x = Q.front() ;
                Q.pop() ;
                if(x != state[i].S){
                    okQ = false ;
                    break;
                }
            }
        }
        poss += ( okQ ) ;

        for(int i = 0 ; i < n ; i++){
            if(state[i].F == 1){
                S.push(state[i].S) ;
            }else{
                int x = S.top() ;
                S.pop() ;
                if(x != state[i].S){
                    okS = false ;
                    break;
                }

            }
        }
        poss += ( okS ) ;

        for(int i = 0 ; i < n ; i++){
            if(state[i].F == 1){
                PQ.push(state[i].S) ;
            }else{
                int x = PQ.top() ;
                PQ.pop() ;
                if(x != state[i].S){
                    okPQ = false ;
                    break;
                }

            }
        }
        poss += ( okPQ ) ;

        if(poss == 0){
            cout << "impossible" << endl;
        }else if(poss == 1 ){
            if(okQ){
                cout << "queue" << endl;
            }else if(okS){
                cout << "stack" << endl;
            }else{
                cout << "priority queue" << endl;
            }
        }else{
            cout << "not sure" << endl;
        }

    }
    return 0;
}
