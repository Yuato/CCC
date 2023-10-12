#include <iostream>

int main(){
    int players, goal, foul, rating, stars=0;
    bool plus = true;
    std::cin>>players;
    for (int i = 0; i <players; i++){
        std::cin>>goal>>foul;
        rating = goal*5-foul*3;
        if (rating>40){
            stars++;
        }
        else{
            plus = false;
        }
    }
    if (plus){
        std::cout<<stars<<"+";
    }
    else{
        std::cout<<stars;
    }
}