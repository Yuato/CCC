#include <bits/stdc++.h>

int main(){
    std::vector<std::vector<char>>keyboard
    {
    {'A', 'B', 'C', 'D', 'E', 'F'},
    {'G', 'H', 'I',	'J', 'K','L'},
    {'M', 'N', 'O', 'P', 'Q', 'R'},
    {'S', 'T', 'U',	'V', 'W', 'X'},
    {'Y', 'Z', ' ', '-', '.', 'e'}
    };
    std::string s;
    std::getline(std::cin, s);
    std::vector<char> v(s.begin(), s.end());
    v.push_back('e');
    int coord_x = 0;
    int coord_y = 0;
    int cursor = 0;
    bool checked = false;
    for (int i = 0; i<v.size(); i++){
        for (int y = 0; y<5; y++){
            for (int x = 0; x<6; x++){
                if (keyboard[y][x]==v[i]){
                    cursor = cursor + abs((y-coord_y)) + abs((x-coord_x));
                    coord_y = y;
                    coord_x = x;
                    checked = true;
                    break;
                }
            }
            if (checked == true){
                break;
            }
        }
        checked = false;
    }
    std::cout<<cursor;
}