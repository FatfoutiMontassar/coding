#include <bits/stdc++.h>

using namespace std;
const int NMAX = 1000007 ;
int n,ans;

vector<int> v ;
int F[NMAX] ;
int G[NMAX] ;
int H[NMAX] ;

bool ok[NMAX];


int main()
{
#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif

    cin >> n;
    ans = n ;

    for(int i = 1 ; i <= n ; i++){
        cin>>F[i];
        if(ok[F[i]] == false)ok[F[i]] = true;
        else ans--;
    }


    memset(ok , false , sizeof ok);

    v.push_back(0);

    for(int i = 1 ; i <= n ; i++){

        if(ok[F[i]] == false){

            ok[F[i]] = true;
            v.push_back(F[i]);
        }
    }

    for(int i = 1 ; i <= ans ; i++){
        H[i] = v[i];
        G[i] = i;
    }

    for(int i = 1 ; i <= n ; i++){

        G[i] = max(1,G[i]);

    }

    for(int i = 1 ; i <= ans ; i++){

        if(G[H[i]] != i){

            cout<< -1 << endl;
            return 0;

        }
    }

    cout<< ans <<endl;

    for(int i = 1 ; i <= n  ; i++)cout<< G[i] << ' ' ; cout << endl;
    for(int i = 1 ; i <= ans; i++)cout<< H[i] << ' ' ; cout << endl;

    return 0;
}
