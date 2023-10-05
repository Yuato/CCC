#include <bits/stdc++.h>

int main(){
    std::map<std::string, int> peppers {
        {"Poblano",	1500},
        {"Mirasol",	6000},
        {"Serrano",	15500},
        {"Cayenne",	40000},
        {"Thai",	75000},
        {"Habanero", 125000}
    };
    int num, scoville = 0;
    std::string pepper;
    int counter = 0;
    std::cin>> num;
    while (counter!=num){
        std::cin>>pepper;
        scoville += peppers[pepper];
        counter++;
    }
    std::cout<<scoville;
}