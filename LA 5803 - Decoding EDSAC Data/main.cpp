#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
#define ld long double


int tt, n, t, num;
char c1, c2, s[] = "PQWERTYUIOJ#SZK*?F@D!HNM&LXGABCV";
ld ans, pow2[20];
string line ;

void preProcess(){
	pow2[0] = 1;
	for(int i = 1 ; i <= 20 ; i++)pow2[i] = pow2[i-1] * 0.5;
}

string getBinary(int N, int len){
	string res = "";
	while(N){
		res += (N % 2) + '0';
		N /= 2;
	}
	for(int k = 1 ; k <= len-res.size();k++)res += '0';
	reverse(res.begin(),res.end());
	return res;
}

string getCode(){
	string res = "";
	for(int i = 0 ; i < strlen(s) ; i++) if(s[i] == c1){
		res += getBinary(i, 5);
		break;
	}
	res += getBinary(num, 11);
	res += (c2 == 'F') ? '0' : '1';
	return res;
}


int main () {
#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
	preProcess();
    scanf(" %d ", &n);
    for(int i = 1 ; i <= n ; i++){
		gets(line) ;
		sscanf(line, "%d %c %d %c", &tt, &c1, &num, &c2);
		string code = getCode();
		ans = 0;
		for(int i = 0 ; i < 17 ; i++) if(code[i] == '1') ans += pow2[i];
		if(code[0] == '1') ans = 2 - ans, ans *= -1;
		sprintf(line, "%.20lf", ans);
		int it;
		for(it = strlen(line) - 1; it >= 0; it--){
			if(line[it] != '0') break;
		}
		if(line[it] == '.') it++; line[++it] = '\0';
		printf("%d %s\n", tt, line);

    }

    return 0;
}
