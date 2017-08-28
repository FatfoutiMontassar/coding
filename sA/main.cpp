#include<bits/stdc++.h>

#define MAX_N 500007
using namespace std;
#define ll long long int
int t,n,q,ans,l,r,m;
string Text , pattern ;
string str[MAX_N];
int  start[MAX_N] ;
int endStr[MAX_N] ;
int      Z[MAX_N];

char f(int pos){
    if(pos<m)return pattern[pos] ;
    else if(pos == m)return '#' ;
    else return Text[start[l]+pos-(m+1)] ;
}


void Zrun(){
    int len = (endStr[r]-start[l] + m + 2 ) ;
    int L = 0, R = 0;
    for (int i=1;i<len;i++)
    {
        if (i > R)
        {
            L = R = i;
            while (R < len && f(R-L) == f(R)) R++;
            Z[i] = R-L;
            R--;
        }
        else
        {
            int k = i - L;
            if (Z[k] < R-i+1) Z[i] = Z[k];
            else
            {
                L = i;
                while (R < len && f(R-L) == f(R)) R++;
                Z[i] = R - L;
                R--;
            }
        }
        if (Z[i] == m)++ans ;
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
//    freopen("apersonal.in" , "r" ,stdin  ) ;
    cin >> t ;
    while(t--){
        cin >> n ;
        int tot = 0 ;
        Text = "" ;
        for(int i = 0 ; i < n ; i++){
            start[i] = tot ;
            cin >> str[i] ;
            tot += str[i].size() ;
            Text += str[i] ;
            endStr[i] = tot-1 ;
        }
        cin >> q ;
        while(q--){
            cin >> l >> r >> pattern ;
            m = pattern.size() ;
            pattern += "#" ;
            l-- ; r-- ;
            ans = 0 ;
            Zrun() ;
            cout << ans << endl;
        }
    }
    return 0;
}
