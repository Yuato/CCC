//CCC '02 S2 - Fraction Action
//working (checked with DMOJ)

#include <iostream>

int main(){
    int num, den, i=2;
    std::cin>>num>>den;
    bool space = false, run = false;
    if ((num>=den)||(num==0)){
        std::cout<<num/den;
        run = true;
    }
    num = num-(num/den)*den;
    if ((num!=0)&&(run)){
        space = true;
    }
    while (i<=num){
        if ((num%i==0)&&(den%i==0)){
            num = num/i;
            den = den/i;
        }
        else{
            i++;
        }
    }
    if (space)std::cout<<" ";
    if (num!=0){
        std::cout<<num<<"/"<<den;
    }
    std::cout<<'\n';
}