#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
int t,tc,nb;
string text ;

char ch(int x){
    if(x<10)return (char)(x+'0') ;
    else return (char)(x-10+'A') ;
}

string hexa(int x){
    int n1 = (x&15) ;
    int n2 = (x&240) ;
    n2>>=4 ;
    string ret = "" ;
    ret += ch(n2) ;
    ret += ch(n1) ;
return ret ;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
    freopen("/home/montaf/Documents/stress.out" , "w" ,stdout ) ;
#endif
    ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
//    return 0 ;
    cin >> t ;
    while(t--){
        cin >> tc >> nb ;
        nb*=2;
        text = "" ;
        for(int i = 0 ; i < (nb+79)/80 ; i++){
            string perm ;
            cin >> perm ;
            text += perm ;
        }
//        cout << text << endl;
        string ans = "" ;
        for(int i = 0 ; i < text.size() ; i+= 2){
            string last = "" ;
            last+= text[i] ;
            last+= text[i+1] ;
//            cout << last << endl;
            string block = last ;
            int cnt(1) ;
            bool diff = false;
            if(i+2>=text.size()){
                ans += "00" ;
                ans += last ;
            }
            for(int j = i+2 ; j < text.size() ; j += 2){
                string curr = "" ;
                curr += text[j] ;
                curr += text[j+1] ;
                block += curr ;
                if(curr==last){
                    cnt++ ;
                    if(cnt == 3){
                        if(diff)
                        {
                            i = j-6;
                            block = block.substr(0,block.size()-6) ;
                            ans += hexa((int)block.size()/2-1) ;
                            ans += block ;
                            break ;
                            ///S7I7A
                        }
                    }
                    if(cnt == 130){
                        ans += hexa(127+128) ;
                        ans += curr ;
                        i = j;
                        break;
                    }
                }
                else {
                    diff = true;
                    if(cnt>=3){
                        ans += hexa(128+cnt-3) ;
                        ans += block[0] ;
                        ans += block[1] ;
                        i = j-2 ;
                        break;
                    }
                    if(block.size()==256){
                        ans += hexa(127) ;
                        ans += block ;
                        i = j ;
                        break;
                    }
                    cnt = 1 ;
                }
                if(j == text.size()-2){
//                    cout << "b " << block << endl;
                    if(diff || cnt <3){
                        ans += hexa((int)block.size()/2-1) ;
                        ans += block ;
                        i = INF ;
                    }else{
                        ans += hexa(128+cnt-3) ;
                        ans += curr ;
                        i = INF ;
                    }
                }
                last = curr ;
            }
//            cout << "*"<<block << endl;
        }
//        cout << endl;
//        cout << ans << endl;
        cout << tc << ' ' << (int)ans.size() / 2<< endl;
        for(int i = 0 ; i < (ans.size() +79)/80  ; i++){
            cout << ans.substr(i*80,min(80,(int)ans.size()-i*80)) << endl;
        }


    }


    return 0;
}
