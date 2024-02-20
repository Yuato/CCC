#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

//The sheep at (x, y) might be eaten.
int main(){
    int sheeps;
    double x,y;
    std::cin>>sheeps;
    double south[sheeps];
    double east[sheeps];
    for (int i = 0; i<sheeps; i++){
        std::cin>>x>>y;
        south[i]=y*100;
        east[i]=x*100;
    }
    std::vector<bool>in (sheeps, true);
    for (int first = 0; first<sheeps; first++){
        for (int sec = 0; sec<sheeps; sec++){
            if (south[first]>south[sec]){
                if (east[first]>east[sec]){
                    //pow creates an out of bound error causing incorrect values when the sheep's x coord is small
                    if (pow((unsigned long)pow((unsigned long)east[first]-100000,2)+pow((unsigned long)south[first],2),0.5)>pow(pow(east[sec]-100000,2)+pow(south[sec],2),0.5)){
                        in[first] = false;
                    }
                }
                else if (east[first]<east[sec]){
                    if (pow(pow(east[first],2)+pow((unsigned long)south[first],2),0.5)>pow(pow((unsigned long)east[sec],2)+pow(south[sec],2),0.5)){
                        in[first] = false;
                    }
                }
                else {
                    in[first] = false;
                }
            }
            else if (south[first]<south[sec]){
                if (east[first]<east[sec]){
                    if (pow(pow((unsigned long)east[first]-100000,2)+pow(south[first],2),0.5)<pow(pow((unsigned long)east[sec]-100000,2)+pow(south[sec],2),0.5)){
                        in[sec] = false;
                    }
                }
                else if (east[first]>east[sec]){
                    if (pow(pow((unsigned long)east[first],2)+pow(south[first],2),0.5)<pow(pow((unsigned long)east[sec],2)+pow(south[sec],2),0.5)){
                        in[sec] = false;
                    }
                }
                else {
                    in[sec] = false;
                }
            }
        }
    }
    for (int s = 0; s<sheeps; s++){
        if(in[s])
        std::cout<<std::setprecision(2)<<std::fixed<<"The sheep at ("<<east[s]/100<<", "<< south[s]/100<<") might be eaten."<<'\n';
    }
    return 0;
}