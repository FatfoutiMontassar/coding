#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
int n;
string s ;
int memo[51][51];

int fun(char a,char b){

    if(a=='('){
        if(b==')') return 0;
        else return 1;
    }
    else if(a=='['){
        if(b==']') return 0;
        else return 1;
    }
    else if(a==')'){
        if(b==')' || b==']') return 1;
        return 2;
    }
    else if(a==']'){
        if(b==')' || b==']') return 1;
        return 2;
    }
}

int solve(int l,int r){
    if(l > r) return 0;
    if(memo[l][r] != -1)return memo[l][r];
    int ans = INF;
    for(int i=l+1;i<=r;i+=2){
        ans = min(ans ,solve(l+1,i-1) + solve(i+1,r) + fun(s[l],s[i]) );
    }
    return memo[l][r] = ans;
}

int main()
{
//#ifndef ONLINE_JUDGE
//    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
////    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
//#endif
    freopen("balalance.in"   , "r" ,stdin  ) ;
    int t ;
    cin>>t;
    while(t--){
        cin>>s;
        memset(memo,-1,sizeof memo);
        if(int(s.size())&1) cout<< -1 << endl;
        else{
            cout<<solve(0,int(s.size())-1) << endl;
        }
    }
    return 0;
}
