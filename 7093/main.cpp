#include<bits/stdc++.h>

using namespace std ;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
#define pb push_back
#define ul unsigned long
int t,tc;
ul number, ans;

ul fun(){

	ul sign, expon, mantissa, res;
	int expv;

	sign = (number & 0x80000000) ;
	expon = (number & 0x7f000000) >> 24;
	expv = expon - 64;
	mantissa = number & 0xffffff;
	if(mantissa == 0) {
		return 0;
	}
	expv *= 4;
	while((mantissa & 0x800000) == 0){
		mantissa <<= 1;
		expv--;
	}
	/// 0111'1111'1000'0000'0000'0000'0000'0000
	/// 0x7f800000
	expv--;
	if(expv > 127) {
		res = sign | 0x7f800000;
	} else if(expv < -149) {
		res = sign;
	} else if(expv >= -126) {
		expon = expv + 127;
		expon <<= 23;
		res = sign | expon | (mantissa & 0x7fffff);
	} else {
		while(expv < -126) {
			expv++;
			mantissa >>= 1;
		}
		expon = 0;
		res = sign | expon | (mantissa & 0x7fffff);
	}
	return res;
}

int main(){

	scanf("%d", &t);

    while(t--){
		scanf("%d %lX", &tc, &number) ;
		ans = fun();
		printf("%d %08lX\n", tc , ans);
	}
	return 0;
}
