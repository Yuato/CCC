#include <bits/stdc++.h>
int main(){
    int num,value,R,S,D;
    std::string computer;
    std::vector<int>value_holder = {-1,-1};
    std::vector<std::string>names = {};
    std::vector<std::string>names2 = {};
    std::cin>>num;
    while(num>0){
        std::cin>>computer>>R>>S>>D;
        value = 2*R + 3*S + D;
        if (value>value_holder[0]){
            value_holder.insert(value_holder.begin(),value);
            names.insert(names.begin(), computer);
        }
        else if (value>value_holder[1]){
            value_holder.insert(value_holder.begin()+1,value);
            names.insert(names.begin()+1, computer);
        }
        num--;
    }
    if ((value_holder[0]==value_holder[1]) && (names.size()>1)){
        for (int i = 0; i<value_holder.size(); i++)
            if (value_holder[i]==value_holder[0]){
                names2.push_back(names[i]);
        }
        sort(names2.begin(), names2.end());
        std::cout<<names2[0]<<'\n'<<names2[1];
    }
    else if(names.size()>1){
        std::cout<<names[0]<<'\n'<<names[1];
    }
    else if(names.size()==1){
        std::cout<<names[0];
    }
}
