#include <iostream>

int main(){
    std:: string T, S;
    int count = S.size();  
    std::cin>>T>>S;
    bool yes = false;

    while (count!=0){
        size_t include = T.rfind(S);
        if (include !=std::string::npos){
            yes = true;
            break;
        }
        S.insert(S.begin()+S.size(), S[0]);
        S.erase(S.begin());
    }
    if (yes==true)std::cout<<"yes";
    else std::cout<<"no";
}