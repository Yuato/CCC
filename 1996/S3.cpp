#include <iostream>
#include <string>
#include <algorithm>

int main(){
    int num,N,K;
    std::cin>>num;

    for (int i = 0; i<num; i++){
        std::cin>>N>>K;
        std::string binary = "";
        for (int k = 0; k<K; k++){
            binary+="1";
        }
        for (int n = 0; n<N-K; n++){
            binary+="0";
        }
        std::cout<<"The bit patterns are"<<'\n'<<binary<<'\n';
        while (true){
            std::size_t find = binary.rfind("10");
            if (find == std::string::npos) break;

            binary[find] = '0';
            binary[find+1] = '1';

            std::reverse(binary.begin()+(find+2), binary.end());

            std::cout<<binary<<'\n';
        }
        if (i!=num-1) std::cout<<'\n';
    }
}