#include <bits/stdc++.h>

using namespace std ;
#define ll long long int
#define A 54059 /* a prime */
#define B 76963 /* another prime */
#define C 1000000007 /* yet another prime */
#define FIRSTH 37 /* also prime */

ll hash_str(string s)
{
   ll h = FIRSTH;
   for(int i = 0 ; i < s.size() ; ++i){
     h = (h * A) ^ (s[i] * B);
	 h %= C ;
   }
   return h; // or return h % C;
}

int main(){
	cout << hash_str("") <<endl;
	return 0 ;
}
