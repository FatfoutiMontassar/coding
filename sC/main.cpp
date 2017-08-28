#include <bits/stdc++.h>
#define inf 1000000000;
using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second

int t;
ll n,k;

ll sum(int l,int r)
{
    if(l>r) return 0;
    return (ll)(r-l+1)*(ll)(r+l)/2;
}

int binary()
{
    int l = 1;
    int r = n;
    for(int i = 0;i<50;i++)
    {
        int mid = (l+r)/2;
        ll s = sum(n-mid,n-1);
        if(s > k) r = mid;
        else if(s < k) l = mid+1;
        else return mid;
    }
    if(sum(n-l,n-1)) return l;
    else return r;
}

int main(){


    //ifstream cin("cheers.in");
    freopen("cheers.in","r",stdin);
  //  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&k);
        int first = binary();
        int ans = first + (k - sum(n-first+1,n-1));
        printf("%d %d\n",first,ans);
    }

    return 0;
}
