#include <iostream>
#include <vector>

using namespace std;
int main(){
    bool reachable = false;
    int distance, power, club, next;
    cin>>distance>>club;
    vector<int>hit(distance+1,0);
    hit[0]=1;
    vector<int>clubs;
    for (int i = 0; i <club; i ++){
        cin>>power;
        clubs.push_back(power);
    }
    for (int i = 0; i<distance;i++){
        if (hit[i]!=0){
            for (int n = 0; n<club; n++){
                next = i+clubs[n];
                if(next<distance){
                    if (hit[next]==0){
                        hit[next]=hit[i]+1;
                    }
                }
                if (next == distance){
                    hit[next] = hit[i]+1;
                    reachable = true;
                    break;
                }
            }
            if (reachable == true){
                break;
            }
        }
    }
    if (reachable){
        cout<<"Roberta wins in "<<hit[distance]-1<<" strokes.";
    }
    else cout<<"Roberta acknowledges defeat.";
}