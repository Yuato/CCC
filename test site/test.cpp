# include <bits/stdc++.h>

int main(){
    std::string s;
    std::getline(std::cin, s);
    std::vector<char> v(s.begin(), s.end());
    for (int i =0; i<v.size(); i++){
        std::cout<<v[i];
    }
}