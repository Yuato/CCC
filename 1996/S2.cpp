#include <iostream>
int main(){
    int num, position=0;
    std::string number, keep;
    std::cin>>num;
    for (int i = 0; i <num; i++){
        std::cin>>number;
        keep = number; 
        std::cout<<number<<'\n';
        while (true){
            if (number.length()<3) break;
            for (int n = number.length()-3; n>=0; n--){
                if (number[n]!='0'){
                    position = n;
                    break;
                    }
            }
            int last = number[number.length()-1]-'0';
            int sub = stoi(number.substr(position,-1));
            int conv = sub-last*11;
            std::string new_end = std::to_string(conv);

            if (number.length()-position>new_end.length()){
                while (number.length()-position!=new_end.length()){
                    new_end = "0"+new_end;
                }
            }
            std::string new_end2 = new_end.substr(0,number.length()-position-1);
            number.erase(position,-1);
            number+=new_end2;
            std::cout<<number<<'\n';
        }
        if (std::stoi(number)%11==0){
            std::cout<<"The number "<<keep<<" is divisible by 11."<<'\n';
        }
        else std::cout<<"The number "<<keep<<" is not divisible by 11."<<'\n';

        if (i!=num-1){
            std::cout<<'\n';
        }
    }
}