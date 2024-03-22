//Solved (checked with DMOJ)
#include <iostream>
#include <array>
#include <iterator>
#include <algorithm>

int main(){ 
    int count = 0, height, width, change_x=0, change_y=0, steps, left_x = 0, left_y = 0;
    int direction[4] = {1, 1,-1, -1};
    int left[4] = {-1,1,1,-1};
    int W,H, CW,CH;
    std::cin>>W>>H>>CW>>CH>>steps;
    height = 0;
    width = CW;
    int grid [H][W];
    grid[height][width] = 1;
    for (int h = 0; h<H; h++){
        for (int w = 0; w<W; w++){
            grid[h][w] = 0;
        }
    }
    for (int h = 0; h<CH; h++){
        for (int w = 0; w<CW; w++){
            grid[h][w] = 1;
        }
    }
    for (int h = H-CH; h<H; h++){
        for (int w = 0; w<CW; w++){
            grid[h][w] = 1;
        }
    }
    for (int h = 0; h<CH; h++){
        for (int w = W-CW; w<W; w++){
            grid[h][w] = 1;
        }
    }
    for (int h = H-CH; h<H; h++){
        for (int w = W-CW; w<W; w++){
            grid[h][w] = 1;
        }
    }

    while(true){
        
        if (steps==0) break;

        else if (count%2==0){
            change_x = direction[count%4];
            left_y = left[count%4];
        }
        else if (count%2==1){
            change_y = direction[count%4];
            left_x = left [count%4];
        }
        
        if ((grid[height+change_y][width+change_x]==1)||(height+change_y==H)||(height+change_y==-1)||(width+change_x==W)||(width+change_x==-1)){
            count++;
            change_x = 0;
            change_y = 0;
        }
        if ((grid[height+left_y][width+left_x]==0)&&(height+left_y!=H)&&(height+left_y!=-1)&&(width+left_x!=W)&&(width+left_x!=-1)){
            count--;
            change_x = 0;
            change_y = 0;
        } 
        
        if ((change_x!=0)||(change_y!=0)){
            grid[height+change_y][width+change_x] =1;
            height += change_y;
            width += change_x;
            steps--;
        }
        
        change_x=0; 
        left_x = 0;
        left_y = 0;
        change_y=0;
    }
    std::cout<<height+1<<"\n"<<width+1;
}