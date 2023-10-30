#include <iostream>

// 100 free minutes then 25 cents per minute	15 cents per minute	20 cents per minute
// B	250 free minutes then 45 cents per minute	35 cents per minute	25 cents per minute
int main(){
    float daytime, evening, weekend;
    float A=0.0, B=0.0;
    std::cin>>daytime>> evening>> weekend;
    
    if (daytime>100){
        A += 0.25*(daytime-100);
    }
    if (daytime>250){
        B += 0.45*(daytime-250);
    }

    A += 0.15 * evening;
    B += 0.35 * evening;

    A += 0.2*weekend;
    B += 0.25*weekend;

    std::cout<<"Plan A costs "<<A<<'\n'<<"Plan B costs "<<B<<'\n';
    
    if (A>B) 
    {
        std::cout<<"Plan B is cheapest.";
    }
    else if (B>A) 
    {
        std::cout<<"Plan A is cheapest.";
    }
    else {
        std::cout<<"Plan A and B are the same price.";
    }
    return 0;
}