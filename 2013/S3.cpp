//working (checked with DMOJ)
#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int recur(int team, vector<pii>games, vector<int>scores){
    int count = 0;
    if (games.size()==0){
        bool win = true;
        for (int i = 0; i<4; i++){
            if (i!=team-1&&scores[team-1]<=scores[i]){
                win = false;
                break;
            }
        }
        if (win){
            return 1;
        }
        else{
            return 0;
        }
    }
    vector<pii>left;
    for (int i = 1; i<games.size(); i++){
        left.push_back(games[i]);
    }
    scores[games[0].first-1] = scores[games[0].first-1]+3;
    count += recur(team, left, scores);
    scores[games[0].first-1] = scores[games[0].first-1]-3;
    scores[games[0].second-1] = scores[games[0].second-1]+3;
    count += recur(team, left, scores);
    scores[games[0].first-1] = scores[games[0].first-1]+1;
    scores[games[0].second-1] = scores[games[0].second-1]-2;
    count += recur(team, left, scores);
    return count;
}

int main() {
    int team, played, t1, t2, s1, s2;
    cin>>team>>played;
    int arr[4];
    vector<pii>games;
    vector<int>points;
    games.push_back(pair(1,2));
    games.push_back(pair(1,3));
    games.push_back(pair(1,4));
    games.push_back(pair(2,3));
    games.push_back(pair(2,4));
    games.push_back(pair(3,4));
    for (int i = 0; i<4; i++){
        arr[i] = 0;
    }
    for (int i = 0; i<played; i++){
        cin>>t1>>t2>>s1>>s2;
        if (s1>s2){
            arr[t1-1]+=3;
        }
        else if (s1==s2){
            arr[t1-1]+=1;
            arr[t2-1]+=1;
        }
        else{
            arr[t2-1]+=3;
        }
        for (int i = 0; i<games.size(); i++){
            if (games[i].first==t1 && games[i].second==t2){
                games.erase(games.begin()+i);
                break;
            }
            else if (games[i].first==t2 && games[i].second==t1){
                games.erase(games.begin()+i);
                break;
            }
        }
    }
    for (int i = 0; i<4; i++){
        points.push_back(arr[i]);
    }
    int count = recur(team,games,points);
    cout<<count;
}