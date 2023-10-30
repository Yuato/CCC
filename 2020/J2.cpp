#include <iostream>

int main(){
    int P,N,R, total = 0, day = 0, infects=0;
    std::cin>>P>>N>>R;
    total = N;
    infects = N;
    while (infects<=P){
        total = total*R;
        infects+=total;
        day++;
    }
    std::cout<<day;
}