#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
struct request {
    int requestedVideo ;
    int endPoint ;
    int number ;
    request(){}
};

ll numberOfVideos , numberOfEndPoints , numberOfRequestDescription , numberOfCacheServers , capacityOfACacheServer ;
int connectedServers[1007][1007] ;
request requestDescription[1000007] ;
int sizeOfVideo[10007] ;
int requestLatencyFromDataCenter[10007] ;
int numberOfServersConnectedToThisPoint[1007] ;
int connectedServerId[1007][1007] ;
int sizeOfServer[1007] ;
bool vis[1007][10007] ;
ll preprocessed[1007] ;

vector<vector<int > > ans ;

int calcGain(int req,int server){
    return (requestLatencyFromDataCenter[requestDescription[req].endPoint] -
         connectedServers[requestDescription[req].endPoint][server]) ;
}

bool cmp1(request a,request b){
    return sizeOfVideo[a.requestedVideo] > sizeOfVideo[b.requestedVideo] ;
}

bool cmp(request a,request b){
    ll scoreA = (ll)(a.number) ;
    ll scoreB = (ll)(b.number) ;

    ll moy1(preprocessed[a.endPoint]),moy2(preprocessed[b.endPoint]);
    /*
    for(int i = 0 ; i < numberOfServersConnectedToThisPoint[a.endPoint] ; i++){
        moy1 += (connectedServers[a.endPoint][connectedServerId[a.endPoint][i]]) ;
    }

    moy1 /= numberOfServersConnectedToThisPoint[a.endPoint] ;
    */
    scoreA *= (requestLatencyFromDataCenter[a.endPoint]*numberOfServersConnectedToThisPoint[a.endPoint]-moy1) ;
    /*
    for(int i = 0 ; i < numberOfServersConnectedToThisPoint[b.endPoint] ; i++){
        moy2 += (connectedServers[b.endPoint][connectedServerId[b.endPoint][i]]) ;
    }

    moy2 /= numberOfServersConnectedToThisPoint[b.endPoint] ;
    */
    scoreB *= (requestLatencyFromDataCenter[b.endPoint]*numberOfServersConnectedToThisPoint[b.endPoint]-moy2) ;

    return scoreA > scoreB ;
}

int main(){

        freopen("/home/montaf/Documents/videos_worth_spreading.in" , "r" ,stdin  ) ;
        freopen("/home/montaf/Documents/videos_worth_spreading.out" , "w" ,stdout ) ;

        memset(vis,false,sizeof vis) ;

        cin >> numberOfVideos >> numberOfEndPoints >> numberOfRequestDescription >> numberOfCacheServers >> capacityOfACacheServer ;
        for(int i = 0 ; i < numberOfCacheServers ; ++i){
            sizeOfServer[i] = capacityOfACacheServer ;
        }
        ans.clear() ;
        ans.resize(numberOfCacheServers) ;

        for(int i = 0 ; i < numberOfCacheServers ; ++i){
            ans[i].clear() ;
        }

        for(int i = 0 ; i < numberOfVideos ; ++i){
            cin >> sizeOfVideo[i] ;
        }

        for(int i = 0 ; i < numberOfEndPoints ; ++i){
            cin >> requestLatencyFromDataCenter[i] ;
            cin >> numberOfServersConnectedToThisPoint[i] ;
            for(int j = 0 ; j < numberOfServersConnectedToThisPoint[i] ; ++j){
                int id ;
                cin >> id ;
                cin >> connectedServers[i][id] ;
                connectedServerId[i][j] = id ;
            }
        }
//        cout << "ok" << endl;
//        return 0 ;
        for(int i = 0 ; i < numberOfEndPoints ; i++){
            preprocessed[i] = 0 ;
            for(int j  = 0 ; j < numberOfServersConnectedToThisPoint[i] ; j++){
                preprocessed[i] += (ll)connectedServers[i][connectedServerId[i][j]] ;
            }
//            preprocessed[i] /= numberOfServersConnectedToThisPoint[i] ;
        }
//        cout << "ok" << endl;
//        return 0 ;

        for(int i = 0 ; i < numberOfRequestDescription ; ++i){
            cin >> requestDescription[i].requestedVideo >> requestDescription[i].endPoint >> requestDescription[i].number ;
        }

        sort(requestDescription,requestDescription+numberOfRequestDescription,cmp1) ;

        for(int i = 0 ; i < numberOfRequestDescription ; ++i){
    //        cout << requestDescription[i].requestedVideo << ' ' << requestDescription[i].endPoint << ' ' << requestDescription[i].number << endl;
            int gain(-1) ;
            int idx(-1) ;
            for(int j = 0 ; j < numberOfServersConnectedToThisPoint[requestDescription[i].endPoint] ; ++j){
                if(sizeOfServer[connectedServerId[requestDescription[i].endPoint][j]] >=
                    sizeOfVideo[requestDescription[i].requestedVideo] &&
                        (!vis[connectedServerId[requestDescription[i].endPoint][j]][requestDescription[i].requestedVideo] ) ){
                        int tempGain = calcGain(i,connectedServerId[requestDescription[i].endPoint][j]) ;
                        if(tempGain > gain){
                            gain = tempGain ;
                            idx = connectedServerId[requestDescription[i].endPoint][j] ;
                        }
                }
            }
            if(idx>=0){
                sizeOfServer[idx] -= sizeOfVideo[requestDescription[i].requestedVideo] ;
                ans[idx].push_back(requestDescription[i].requestedVideo) ;
                vis[idx][requestDescription[i].requestedVideo] = true ;
            }
        }
        int cnt(0) ;

        for(int i = 0 ; i < ans.size() ; ++i)if(ans[i].size()>0)cnt++;

        cout << cnt << endl;

        for(int i = 0 ; i < ans.size() ; i++){
            if(ans[i].size() == 0 )continue ;
            cout << i << ' ' ;
            for(int j = 0 ; j < ans[i].size() ; ++j){
                cout << ans[i][j] << ' ' ;
            }
            cout << endl;
        }

    return 0;
}
