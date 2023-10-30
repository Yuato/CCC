#include <iostream>
#include <vector>

int main(){
    std::vector<std::string>direction;
    std::vector<std::string> street;
    street.push_back("HOME");
    std::string D, name;
    while (true){
        std::cin>>D>>name;
        if (D == "R") direction.push_back("LEFT");
        street.push_back(name);
        if (D == "L") direction.push_back("RIGHT");
        if (name == "SCHOOL") break;
    }
    for (int i = direction.size()-1; i>=0; i--){
        if (i==0)std::cout<<"Turn "<<direction[i]<<" into your HOME.";
        else std::cout<<"Turn "<<direction[i]<<" onto "<<street[i]<<" street."<<'\n';
    }
}