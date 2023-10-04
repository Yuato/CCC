#include <iostream>

int main(){
    float weight, height;
    std::cin>>weight>>height;
    float BMI = weight/height/height;
    if (BMI<18.5){
        std::cout<<"Underweight";
    }

    else if (BMI>25.0){
        std::cout<<"Overweight";
    }

    else{
        std::cout<<"Normal weight";
    }
}