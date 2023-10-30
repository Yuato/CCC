#include <iostream>

int main(){
    std::string monkey;
    bool word = true;
    std::cin>>monkey;
    while (monkey!="X"){
        word = true;
        for (int i = 0; i < monkey.size(); i++){
            if (monkey[i]=='B'){
                word = false;
                for (int s = i+2; s <monkey.length(); s++){
                    if (monkey[s]=='S'){
                        word = true;
                        if (monkey[s-1]=='N')word = false;
                        monkey.erase(monkey.begin()+s);
                        break;
                    }
                }
                if ((monkey[i+1]!='A')&(monkey[i+1]!='B')){
                    word = false;
                }
            }
            else if ((monkey[i]=='A')&&(i+1!=monkey.length())){
                if (monkey[i+1]!='N') word = false;
            }

            if (word == false){
                std::cout<<"NO"<<'\n';
                break;
            }
        }
        if (word == true){
            std::cout<<"YES"<<'\n';
        }
        std::cin>>monkey;
    }
}