#include <iostream>

int main(){
    int start,end,count = 0, RSA = 0;
    std::cin>>start>>end;
    for (int i = start; i<end+1; i++){
        for (int n = 1; n<i+1; n++){
            if (i%n==0)count++;
            if (count>4) n = i;
        }
        if (count==4)RSA++;
        count = 0;
    }
    std::cout<<"The number of RSA numbers between "<<start<< " and "<< end<< " is " <<RSA;
}