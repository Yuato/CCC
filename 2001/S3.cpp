#include <bits/stdc++.h>
//Worsks some cases
int main(){
    int total = 0;
    std::string road;
    std::map<char, std::vector<char>> roads;
    std::vector<std::string>connect;
    std::vector<char>possible;
    std::vector<char>checked;

    roads['A'] = {}; roads['B'] = {}; roads['C'] = {}; roads['D'] = {}; roads['E'] = {}; roads['F'] = {}; roads['G'] = {}; roads['H'] = {}; roads['I'] = {}; roads['J'] = {}; roads['K'] = {}; roads['L'] = {}; roads['M'] = {}; roads['N'] = {}; roads['O'] = {}; roads['P'] = {}; roads['Q'] = {}; roads['R'] = {}; roads['S'] = {}; roads['T'] = {}; roads['U'] = {}; roads['V'] = {}; roads['W'] = {}; roads['X'] = {}; roads['Y'] = {}; roads['Z'] = {};
    std::cin>>road;
    while (road != "**"){
        roads[road[0]].push_back(road[1]); roads[road[1]].push_back(road[0]);
        connect.push_back(road);
        std::cin>>road;
    }

    for (int i = 0; i<connect.size(); i++){
        possible.clear();
        checked.clear();
        char point1 = connect[i][0];
        char point2 = connect[i][1];
        if (point1 = 'A'){
            for (int i = 0; i<roads['A'].size(); i++){
                if (roads['A'][i]!=point2){
                    possible.push_back(roads['A'][i]);
                    checked.push_back(roads['A'][i]);
                }
            }
        }
        if (point2 = 'A'){
            for (int i = 0; i<roads['A'].size(); i++){
                if (roads['A'][i]!=point1){
                    possible.push_back(roads['A'][i]);
                    checked.push_back(roads['A'][i]);
                }
            }
        }
        else {
            possible.insert(possible.end(), roads['A'].begin(), roads['A'].end());
            checked.insert(possible.end(), roads['A'].begin(), roads['A'].end());
        }
        bool dis = true;
        while (possible.size()>0){
            std::vector<char>::iterator it;
            for (int n = 0; n<roads[possible[0]].size(); n++){
                it = std::find(checked.begin(), checked.end(), roads[possible[0]][n]);
                char str[3] = {possible[0],roads[possible[0]][n],'\0'};
                char reverse[3] = {roads[possible[0]][n],possible[0],'\0'};
                if ((it == checked.end())&&(str!=connect[i])&&(reverse!=connect[i])){
                    possible.push_back(roads[possible[0]][n]);
                    checked.push_back(roads[possible[0]][n]);
                }
                if (possible.back() == 'B'){
                    dis = false;
                    break;
                }
            }
            possible.erase(possible.begin());
            if (dis == false){
                break;
            }
        }
        if (dis){
            std::cout<<connect[i]<<'\n';
            total++;
        }
    }
    std::cout<<"There are "<<total<<" disconnecting roads."<<'\n';
}