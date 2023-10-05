#include <iostream>

int main(){
    int delivered, collision;
    std::cin>>delivered>> collision;
    int total = delivered*50 - collision*10;
    if (delivered>collision){
        total+=500;
    }
    std::cout<<total;
}