#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>

int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++ cas) {
    ll a, b;
    scanf("%lld%lld", &a, &b);
    ll r1(0LL), r2(0LL);
    for (int i = 0; i < 63; ++ i) {
      int a1 = a & 1, b1 = b & 1;
      a >>= 1; b >>= 1;
      if (!((!a1) && (!b1) && a == b)) r1 |= 1ll << i;
      if (a1 && b1 && a == b) r2 |= 1ll << i;
    }
    printf("Case %d: %lld %lld\n", cas, r1, r2);
  }
  return 0;
}
