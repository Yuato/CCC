#include <iostream>
#include <vector>

int main(){
    std::string tunner;
    std::cin>>tunner;
    std::vector<char>characters{tunner.begin(), tunner.end()};
    int begin=0, end;
    for (int i = 0; i <characters.size(); i++){
        end = i;
        if (characters[i]=='-'){
            for (int n = begin; n<end;n++){
                std::cout<<characters[n];
            }
            std::cout<<" loosen ";
            i++;
            while ((int(characters[i])<58) && (int(characters[i])>47)){
                std::cout<<characters[i];
                i++;
            }
            if (i!=characters.size())std::cout<<'\n';
            begin = i;
        }
        else if (characters[i]=='+'){
            for (int n = begin; n<end;n++){
                std::cout<<characters[n];
            }
            std::cout<<" tighten ";
            i++;
            while ((characters[i]<58) && (characters[i]>47)){
                std::cout<<characters[i];
                i++;
            }
            if (i!=characters.size())std::cout<<'\n';
            begin = i;
        }
    }

}