#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
struct state {
    string name ;
    ll score ;
    state(int score_,string name_){
        score = score_ ;
        name = name_ ;
    }
};

bool operator <(const state& x, const state& y) {
        if(x.score < y.score) return true;
        else if(x.score == y.score)return x.name > y.name ;
        else return false ;
}

state tab[11111] ;
ll b[11111] ;
ll n,m,x ;
string name;

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    int t ;
    cin >> t ;
    while(t--){
        cin >> n ;
        for(int i = 0 ; i < n ; i++){
            cin >> tab[i].S >> tab[i].F ;
        }
        sort(tab,tab+n) ;
        deque<int > Q ;
        cin >> m ;
        if(m!=0){
            for(int i = 0 ; i < m ; i++){
                cin >> b[i] ;
            }

            cin >> name ;
            int id = M[name] ;

            sort(b,b+m) ;
            for(int i = 0 ; i < m-1 ; i++){
                Q.push_back(b[i]) ;
            }
            state bestValue = state(0,"") ;
            for(int i = 0 ; i < n ; i++){
                if(tab[i].S == name){
                    pQ.push(state(tab[i].S+b[m-1],tab[i].F)) ;
                    bestValue = state(tab[i].S+b[m-1],tab[i].F) ;
                }else{
                    pQ.push(state(tab[i].S,tab[i].F))
                }
            }
    //        cout << (pQ.top()).name << endl;
            while(!pQ.empty()){
                state = pQ.top() ;
                pQ.pop()
                if(state.name == name)break;
                Q.pop_back() ;
            }
            vector<state > vect ;
            while(!pQ.empty()){
                vect.push_back(pQ.top()) ;
                pQ.pop() ;
            }
            sort(vect.begin(),vect.end()) ;
            deque<state> newQ ;
            for(int j = 0 ; j < vect.size() ; j++){
                newQ.push(vect[j]) ;
            }
            while(!Q.empty()){
                state = newQ.top() ;

                if(Q.begin())
            }
        }
        else{

        }
    }
    return 0;
}
