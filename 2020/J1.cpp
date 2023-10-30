#include <iostream>

int main(){
    int S,M,L;
    std::cin>>S>>M>>L;
    int total = S+2*M+3*L;
    if (total>=10)std::cout<<"happy";
    else std::cout<<"sad";
}