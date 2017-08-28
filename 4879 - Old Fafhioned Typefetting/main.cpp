#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
#define pb push_back
int t ;
string s ;
map<string ,string> M ;
vector<string > words ;

bool iskilma(string text){
    for(int i = 0 ; i < text.size() ; i++){
        if(!isalpha(text[i])){
            return false ;
        }
    }
return true ;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("/home/montaf/Documents/in.in"   , "r" ,stdin  ) ;
//    freopen("/home/montaf/Documents/out.out" , "w" ,stdout ) ;
#endif
    string name = "fat7i" ;
    cout << name.substr(0,2) << endl;
    return 0 ;

    M["AE"] = "[AE]" ;
    M["ae"] = "[ae]" ;
    M["OE"] = "[OE]" ;
    M["oe"] = "[oe]" ;
    M["ct"] = "[ct]" ;
    M["ff"] = "[ff]" ;
    M["fi"] = "[fi]" ;
    M["fl"] = "[fl]" ;
    M["ffi"] = "[ffi]" ;
    M["ffl"] = "[ffl]" ;
    M["si"] = "[longsi]" ;
    M["sh"] = "[longsh]" ;
    M["sl"] = "[longsl]" ;
    M["ss"] = "[longss]" ;
    M["st"] = "[longst]" ;
    M["ssi"] = "[longssi]" ;
    cin >> t ;
    getline(cin,s) ;
    for(int tc = 1 ; tc <= t ; tc++){
        getline(cin,s) ;
        cout << s << endl;
        words.clear() ;
        int ptr(0) ;
        while(isdigit(s[ptr]))ptr++;
        ptr++;
        string aux = "" ;
        for(int i = ptr ; i < s.size() ; i++){
            if(s[i] == ' '){
                if(isKilma(aux)){
                    for(int j = 0 ; j < aux.size() ; j++){
                        if(aux[j] == 's'){
                            if(j<aux.size()-2){
                                if(aux[j+1] == aux[j+2] && aux[j+1] == 's'){
                                    if(j<aux.size()-3){
                                        char c = aux[j+3] ;
                                        if(c == 'i' || c == 'h' || c == 'l' || c == 's' || c == 't' ){
                                            ans +=
                                        }
                                    }
                                }
                            }
                            if(j+1 == aux.size()){
                                continue ;
                            }else{
                                char c = aux[j+1] ;
                                if( c == 'f' || c =='k' || c =='b'){
                                    continue ;
                                }else if(!isalpha(c)){
                                    ans += "[longs]" ;
                                 }
                            }
                        }else{
                            ans += aux[i] ;
                        }
                    }
                }else{

                }
                words.pb(" ") ;
                aux = "" ;
            }else{
                aux += s[i] ;
            }
        }
        cout << tc << ' ' ;
        for(int i = 0 ; i < words.size() ; i++)cout << words[i] ;
        cout << endl;
    }
    return 0;
}
