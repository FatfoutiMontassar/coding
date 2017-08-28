#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second

int sound[27];
int n,p,q;

bool issame(char a,char b)
{
    int aa = (int)a - 'a';
    int bb = (int)b - 'a';
    if(sound[aa] == bb) return true;
    if(a == b) return true;
    return false;
}

bool ispalin(string s)
{
    for(int i=0;i<(int)s.size()/2;i++)
    {
        int ii = (int)s.size()-i-1;
        //cout<<s[i]<<" "<<s[ii]<<endl;
        if(issame(s[i],s[ii])) continue;
        else return false;
    }
    return true;
}

int main(){

//#ifndef ONLINE_JUDGE
//    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
////    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
//#endif

    ifstream cin("brief.in");
    cin>>n;
    while(n--)
    {
        memset(sound,0,sizeof sound);
        cin>>p;
        for(int i=0;i<p;i++)
        {
            char a,b;
            cin>>a>>b;
            int aa = (int)a - 'a';
            int bb = (int)b - 'a';
            sound[aa] = bb;
            sound[bb] = aa;
        }
        cin>>q;
        while(q--)
        {
            string s;
            cin>>s;
            cout<<s<<" ";
            if(ispalin(s)) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}
