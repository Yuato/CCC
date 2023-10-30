#include <iostream>
#include <vector>

int main(){
    std::vector<double> flows;
    int num, command, power;
    std::cin>>num;
    for (int i = 0; i<num; i++){
        std::cin>>power;
        flows.push_back((double)power);
    }
    while (true){
        int stream, percent;
        std::cin>>command;

        if (command == 99){
            std::cin>>stream>>percent;
            double new_power = flows[stream-1]*(double)percent/100;
            double holder = flows[stream-1];
            flows[stream-1] = new_power;
            flows.insert(flows.begin()+stream,holder-new_power);
        }
        else if (command == 88){
            std::cin>>stream;
            flows[stream-1] = flows[stream-1] + flows[stream];
            flows.erase(flows.begin()+stream);
        }
        else if (command == 77){
            break;
        }
    }

      for (int iter = 0; iter<flows.size(); iter++){
        std::cout<<(int)(flows[iter]+0.5);
        if(iter!=flows.size()-1)std::cout<<" ";
      }
}