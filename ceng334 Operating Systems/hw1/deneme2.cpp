#include <iostream>
#include <string>
#include <vector>
#include <sys/types.h>
#include <typeinfo>
#include <array>
#include <list>

std::vector<std::string> split (std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    std::cout << "splite girdi" << std::endl;
    return res;
}


void readInput(std::vector<std::vector<std::string>> &bidders){
    int a, b, c;
    std::cin >> a >> b >> c;
    std::vector<std::string> lines;
        //burasi bidderlari string olarak aliyor.
    for (int i = 0; i < c; i++ )
    {
        std::string path;
        int argno ;
        std::vector<std::string> args;
        std::cin >> path >> argno;
        std::cout << "su an path ve arg no alindi" << std::endl;
        args.push_back(path);

        for (int j = 0; j < argno; j++){
            std::string ar;
            std:: cin >> ar;
            args.push_back(ar);
        }
        std::cout << "argumanlar args vectore pushlandi" << std::endl;
        bidders.push_back(args);

    }
}

int main(){
    std::string line;

    // bidders tum bidderlari alıyor 2d vector.
    // bidders[i] kacinci bidder oldugu. bidders[i][j] kacinci arguman oldugu ismi falan.
    // bidders[2][0] => "./different_bidder" mesela.
    // bidders[2][1] => 2 arguman sayisi yani.
    // bidders[2][2] => ilk arguman.
    std::vector<std::vector<std::string>> bidders;
    



    readInput(bidders);

    for(auto l: bidders) {
        std::cout << "----" << std::endl;
        for(auto k : l) std::cout << k << std::endl;
    }

    // her bidder'in 2 tane fd sini tutan vector olmali.
    // bidderFDs.
    // 
    std::vector<std::array<int,2>> bidderFDs;
    std::array <int,2> arr;
    arr[0] = 452;
    arr[1] = 1;
    bidderFDs.push_back(arr);
    std::cout << bidderFDs[0][1];

}




