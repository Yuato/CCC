#include <bits/stdc++.h>

int main(){
    int num,R,S,D,value,value_holder=0,max=0,count = 0;
    std::string computer;
    std::cin>>num;
    int values [num];
    std::string computer_name [num];
    
    for (int i = 0; i<num; i++){
        std::cin>>computer>>R>>S>>D;
        value = 2*R + 3*S + D;
        computer_name[i] = computer;
        values[i] = value;
        if (value>=value_holder){
            max = value;
        }
        value_holder = value;
    }
    for (int n = 0; n<num; n++){
        if ((values[n] ==max) && (count == 0)){
            std::cout<<computer_name[n];
            count++;
        }
        else if (values[n]==max) 
        {
            std::cout<<std::endl<<computer_name[n];
        }
    }
}
