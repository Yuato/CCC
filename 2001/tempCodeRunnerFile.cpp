#include <iostream>
#include <vector>
//CAD578KAHAS47TQKA

// Cards Dealt              Points
// Clubs A                       6
// Diamonds 5 7 8 K A            7
// Hearts A                      6
// Spades 4 7 T Q K A            9
//                        Total 28
using namespace std;

int points(string cards){
    int points=0;
    if (cards.size()==0){
        points+=3;
    }
    if (cards.size()==1){
        points+=2;
    }
    if (cards.size()==2){
        points+=1;
    }
    if (cards.rfind('A')!=string::npos){
        points+=4;
    }
    if (cards.rfind('K')!=string::npos){
        points+=3;
    }
    if (cards.rfind('Q')!=string::npos){
        points+=2;
    }
    if (cards.rfind('J')!=string::npos){
        points+=1;
    }
    return points;
}

int main(){
    string cards, print;
    cin>>cards;
    size_t c = cards.rfind('C');
    size_t d = cards.rfind('D');
    size_t h = cards.rfind('H');
    size_t s = cards.rfind('S');
    string C = cards.substr(c+1,d-c-1);
    string D = cards.substr(d+1,h-d-1);
    string H = cards.substr(h+1,s-h-1);
    string S = cards.substr(s+1,cards.size()-s);
    cout<<"Cards Dealt              Points";
    
    cout<<'\n'<<"Clubs";
    for (int i = 0; i<C.size(); i++){
        cout<<" "<<C[i];
    }
    cout<<" "<<points(C);
    
    cout<<'\n'<<"Diamonds";
    for (int i = 0; i<D.size(); i++){
        cout<<" "<<D[i];
    }
    cout<<" "<<points(D);
    
    cout<<'\n'<<"Hearts";
    for (int i = 0; i<H.size(); i++){
        cout<<" "<<H[i];
    }
    cout<<" "<<points(H);
    
    cout<<'\n'<<"Spades";
    
    for (int i = 0; i<S.size(); i++){
        cout<<" "<<S[i];
    }
    cout<<" "<<points(S);

    cout<<'\n'<<"                      Total "<<(((int)points(C))+points(D)+points(H)+points(S));
}