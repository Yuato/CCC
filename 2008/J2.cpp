#include <bits/stdc++.h>

int main(){
    std::vector<std::string> song = {"A", "B", "C", "D", "E"};
    int button, hits;
    while (true){
        std::cin>>button>>hits;
        if (button == 1){
            for (int i = 0; i<hits; i++){
                song.push_back(song[0]);
                song.erase(song.begin());
            }
        }

        else if (button == 2){
            for (int i =0; i<hits; i++){
                song.insert(song.begin(), song[4]);
                song.erase(song.begin()+5);
            }
        }

        else if (button == 3){
            song.insert(song.begin()+2,song[0]);
            song.erase(song.begin());
        }
        else if (button==4){
            break;
        }
    }
    for (int n = 0; n<5; n++){
        std::cout<<song[n]<<" ";
    }
} 