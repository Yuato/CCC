#include <iostream>
#include <vector>
#include <algorithm>
#define psi std::pair<std::string,int>

int main(){
    std::string name;
    int time, total = 0, max, ppl;
    int min;
    std::cin>>max>>ppl;
    std::vector<psi>bridge;
    std::vector<std::string>names;
    std::cin>>name>>time;
    bridge.push_back(std::pair(name,time));
    names.push_back(name);
    std::vector<int>place;
    min = 100;

    for (int i = 1; i <ppl; i++){
        std::cin>>name>>time;
        names.push_back(name);
        for (int n = 0; n<i; n++){
            if (bridge[n].second<time){
                bridge.insert(bridge.begin()+n, std::pair(name, time));
                break;
            }
            else if (n+1 == i){
                bridge.push_back(std::pair(name, time));
            }
        }
    }

    int x = ppl%max;

    for (int i = 0; i<ppl; i++){
        for (int n = 0; n<ppl; n++){
            if ((names[n]==bridge[i].first)&&(n<min)){
                min = n;
            }
        }
        if (((i+1)%max==0)||(i+1 == ppl)){
            place.push_back(min);
        }
        else if ((i+1)%max == 1){
            for (int n = 0; n<ppl; n++){
                if (names[n]==bridge[i].first){
                    min = n;
                    break;
                }
            }
        }
        if ((i + 1 == ppl)||((i+1)%max==1)){
            total += bridge[i].second;
        }
    }
    std::sort (place.begin(), place.end());


    std::cout<<"Total Time: "<< total<<'\n';

    while (place.size()>0){
        int y = 0;
        for (int i = 0; i<bridge.size(); i++){
            if (bridge[i].first == names[place[0]]){
                y = i;
                break;
            }
        }
        int x = y/max;
        int maximum = (x+1) * max;
        if (maximum>=ppl){
            maximum = ppl;
        }
        for (int i = x*max; i<maximum; i++){
            std::cout<<bridge[i].first;
            if (i+1!=maximum){
                std::cout<<" ";
            }
        }
        place.erase(place.begin());
        if (place.size()>0) std::cout<<'\n';
    }
}