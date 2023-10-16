#include <iostream>

int main(){
    int num, input;
    std::cin>>num;
    for (int i = 0; i <num; i++){
        std::cin>>input;
        int total = 0;
        for(int n = 1; n<input; n++){
            if (input%n==0)total +=n;
        }
        if (total<input)std::cout<<input<<" is a deficient number."<<'\n';
        else if (total ==input)std::cout<<input<<" is a perfect number."<<'\n';
        else if (total>input) std::cout<<input<<" is an abundant number."<<'\n';
    }
}