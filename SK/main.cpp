#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
int t , nTracks , fav , lSeg , q , nSeg ,curr ;
int len[22] ;
int cum[22] ;

int main(){
    freopen("kill.in"   , "r" ,stdin  ) ;
    cin >> t ;
    while(t--){
        cin >> nTracks >> fav ;
        --fav;
        for(int i = 0 ; i < nTracks ; ++i){
            cin >> len[i] ;
            cum[i] = len[i] + ( i ? cum[i-1] : 0 ) ;
        }
        int startFavTrack = (fav ? cum[fav-1] : 0 ) ;
        int endFavTrack = cum[fav] ;

        cin >> q ;
        while(q--){
            cin >> nSeg ;
            int ans(0) ;
            for(int i = 0 ; i < nSeg ; i++){
                cin >> lSeg ;
                if(i&1){
                    /// 3 parts , better treat them seperately

                    /// part 1
                    if(curr>=endFavTrack){
                        /// add zero
                    }else if(curr<=startFavTrack){
                        ans += max(0,min(endFavTrack,curr+lSeg)-startFavTrack) ;
                    }else{
                        ans += max(0,min(endFavTrack,curr+lSeg)-curr) ;
                    }


                    if(curr+lSeg>cum[nTracks-1]){
                        lSeg  -= (cum[nTracks-1]-curr) ;
                        curr = 0 ;
                    }else{
                        curr += lSeg ;
                        continue ;
                    }

                    /// part 2
                    ans += (lSeg/cum[nTracks-1])*len[fav] ;

                    lSeg -= ( (lSeg/cum[nTracks-1])*cum[nTracks-1] ) ;
                    if(lSeg == 0)continue ;

                    /// part 3
                    if(curr>=endFavTrack){
                        /// add zero
                    }else if(curr<=startFavTrack){
                        ans += max(0,min(endFavTrack,curr+lSeg)-startFavTrack) ;

                    }else{
                        ans += max(0,min(endFavTrack,curr+lSeg)-curr) ;
                    }
                    curr += lSeg ;
                }else{
                    ans += lSeg ;
                    curr = (fav != 0 ? cum[fav-1] : 0 ) ;
                    curr += (lSeg%len[fav] ? lSeg%len[fav] : len[fav]  ) ;
                    /// beCarefulHere
                    curr %= cum[nTracks-1] ;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
