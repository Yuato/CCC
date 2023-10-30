#include <bits/stdc++.h>


int main(){
    int X,Y,num, divisor;
    std::cin>>X>>Y;
    bool yes = false;
    std::vector<int>Tocheck_Y;
    std::vector<int>Tocheck_X;
    std::vector<int> checked;
    Tocheck_X.push_back(0);
    Tocheck_Y.push_back(0);
    int grid [Y][X];
    for (int y = 0; y<Y; y++){
        for (int x = 0; x<X; x++){
            std::cin>>num;
            grid[y][x]=num;
        }
    }
    while (Tocheck_X.size()!=0){
        std::vector<int>::iterator it;
        it = std::find(checked.begin(), checked.end(), grid[Tocheck_Y[0]][Tocheck_X[0]]);

        if (grid[Tocheck_Y[0]][Tocheck_X[0]]>0){
            for (int i = Y;i>0; i--){
                if((grid[Tocheck_Y[0]][Tocheck_X[0]]%i==0)&&(grid[Tocheck_Y[0]][Tocheck_X[0]]/i<=X)){
                    Tocheck_Y.push_back(i-1);
                    int x = (grid[Tocheck_Y[0]][Tocheck_X[0]]/i);
                    Tocheck_X.push_back(x-1);
                    if ((i==Y)&&(x==X)){
                        yes = true;
                        break;
                    }
                }
            }
            
            grid[Tocheck_Y[0]][Tocheck_X[0]] = 0;
            Tocheck_X.erase(Tocheck_X.begin());
            Tocheck_Y.erase(Tocheck_Y.begin());

            if (yes==true){
                std::cout<<"yes";
                break;
            }
        }

        else{
            Tocheck_X.erase(Tocheck_X.begin());
            Tocheck_Y.erase(Tocheck_Y.begin());
        }
    }
    if (yes == false)std::cout<<"no";
}
