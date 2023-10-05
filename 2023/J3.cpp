#include <bits/stdc++.h>

int main(){
    int numppl,x = 0, count = 0;
    std::vector<int>number_available = {0,0,0,0,0};
    std::string person;
    std::cin>>numppl;
    while (numppl!=0){
        std::cin>>person;
        std::vector<char>available (person.begin(), person.end());
        for (int i = 0; i<5; i++){
            if (available[i]=='Y'){
                number_available[i] += 1;
            }
        }
        numppl--;
    }
    x = *max_element(number_available.begin(), number_available.end());
    for (int n = 0; n<5; n++){
        if ((number_available[n]==x)and(count==0)){
            std::cout<<n+1;
            count++;
        }
        else if (number_available[n]==x){
            std::cout<<","<<n+1;
        }
    }
}