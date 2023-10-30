#include <iostream>

int main(){
    int drops, max_x=0, min_x=100, max_y=0, min_y=100;
    std::string coord;
    std::cin>>drops;
    int X[drops];
    int Y[drops];
    int num = drops;

    while (drops!=0){
        std::cin>>coord;
        size_t comma = coord.rfind(",");
        X[drops-1] = stoi(coord.substr(0,comma));
        Y[drops-1] = stoi(coord.substr(comma+1,-1));
        drops--;
    }
    for (int i = 0; i<num; i++){
        if (X[i]<min_x)min_x=X[i];
        if (X[i]>max_x)max_x = X[i];
        if (Y[i]<min_y)min_y=Y[i];
        if (Y[i]>max_y)max_y = Y[i];
    }
    std::cout<<min_x-1<<","<<min_y-1<<'\n';
    std::cout<<max_x+1<<","<<max_y+1;
}