#include <iostream>
#include <vector>

using namespace std;

int main(){
    int first, last, x2 = 0, y2=0;
    bool yes = false;
    cin>>first>>last;
    int total=first, spiral = 1, count;
    while (total+spiral<last){
        total += spiral;
        count++;
        if (count%2 == 0){
            spiral++;
        }
    }
    if (count%2==1){
        y2 = 1;
    }
    else if (count%2==0){
        x2 = 1;
    }

    int arr [spiral+y2][spiral+x2];
    for (int y = 0; y<spiral+y2; y++){
        for (int x = 0; x<spiral+x2; x++){
            arr[y][x] = -1;
        }
    }
    int starter = 0;
    int start = first+(spiral+y2)*(spiral+x2)-1;
    int direction = 0;
    for (int y = 0; y<spiral+y2; y++){
        for (int x = 0; x<spiral+x2; x++){
            if (start>last){
                starter++;
            }
            if (direction%4==0){
                if (x+1==spiral+x2){
                    direction++;
                }
                arr[y][x] = start;
            }
            else if (direction%4==1){
                if (y+1==spiral+y2){
                    direction++;
                }
                arr[y][x] = start;
            }
            else if (direction%4==2){
                if (x+1==spiral+x2){
                    direction++;
                }
                arr[y][x] = start;
            }
            else if (direction%4==3){
                if (x+1==spiral+x2){
                    direction++;
                }
                arr[y][x] = start;
            }
            start--;
        }
    }

}