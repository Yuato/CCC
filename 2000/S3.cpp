#include <iostream>
#include <vector>
#include <algorithm>
// 3
// http://ccc.uwaterloo.ca
// <HTML> <TITLE>This is the CCC page</TITLE>
// Hello there boys
// and girls.  <B>Let's</B> try <A HREF="http://abc.def/ghi"> a
// little
// problem </A>
// </HTML>
// http://abc.def/ghi
// <HTML> Now is the <TITLE>time</TITLE> for all good people to program.
// <A HREF="http://www.www.www.com">hello</A><A HREF="http://xxx">bye</A>
// </HTML>
// http://www.www.www.com
// <HTML>
// <TITLE>Weird and Wonderful World</TITLE>
// </HTML>
// http://ccc.uwaterloo.ca
// http://www.www.www.com
// http://www.www.www.com
// http://ccc.uwaterloo.ca
// The End
int main(){
    bool yes = false;
    int num, count = 0, number = 0;
    std::string URL, next, link, next2;
    std::cin>>num;
    std::vector<std::string>URLs;
    std::vector <std::string>Links;
    std::vector<int>num_links;
    num_links.push_back(0);
    std::getline(std::cin, URL);
    std::getline(std::cin, URL);
    URLs.push_back(URL);

    while (true){
        std::getline(std::cin, next);
        if (next.rfind("<HTML>")!=std::string::npos){
            count++;
        }
        if (next.rfind("</HTML>")!=std::string::npos){
            count++;
        }
        if (count == 2 ){
            count = 0;
            num--;
            if (num==0)break;
            std::getline(std::cin, URL);
            URLs.push_back(URL);
        }
        else if (count == 1){
            size_t start_location = next.rfind("<A HREF=\"");
            std::vector<std::string>hold;
            while (start_location!=std::string::npos){
                yes = true;
                size_t end_location = next.rfind("\">");
                std::string link = next.substr(start_location+9, end_location-start_location-9);
                hold.insert(hold.begin(), link);
                next.erase(start_location, end_location+2);
                number++;
                start_location = next.rfind("<A HREF=\"");
            }
            for (int i = 0; i <hold.size(); i++){
                Links.push_back(hold[i]);
            }
            if (yes) num_links.push_back(number);
            yes = false;
        }
    }

    for (int i = 0; i < URLs.size(); i++){
        for (int n = num_links[i-1]; n <num_links[i]; n++){
            std::cout<<"Link from "<<URLs[i-1]<<" to "<< Links[n]<<'\n';
        }
    }

    while (next!="The End"){
        std::getline(std::cin, next);
        std::getline(std::cin, next2);
        int start, end;
        for (int i = 0; i <URLs.size(); i++){
            if (next == URLs[i]){start = i;break;}
        }
        if ( std::find(Links.begin()+num_links[start], Links.begin()+num_links[start+1], next2) != Links.begin()+num_links[start+1]){
            std::cout<<"Can surf from "<<next<<" to "<<next2<<"."<<'\n';
        }
        else std::cout<<"Can't surf from "<<next<<" to "<<next2<<"."<<'\n';
    }
}