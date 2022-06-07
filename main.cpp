#include <iostream>
#include <sstream>
// Input will be: Aapple, Dorange, etc
// The first letter will be A or D which will mean add or delete respectively
// Keys are lower-case- apple, orange etc
// Length of key is at most 10
// Hash table will have exactly 26 slots (a-z)
// Each slot has 3 statuses: "never used", "tombstone", "occupied" with the default being "never used"
// The last character of the key will be the hash value, so apple will have the hash value as 'e'


int main(){
    std::cout<<"assignment V0.01\n";
    std::string input;
    getline(std::cin,input);
    std::stringstream ss(input);
    while(ss.good()){
        std::string token;
        ss>>token;
        std::cout<<token<<"\n";
        //input: Hello world!
        //output:Hello
        //       world!
        std::string inputName = token.substr(1);
        if(token[0] == 'A'){
            std::cout<< "Add - "<<inputName<<std::endl;

        }else if (token[0] == 'D'){
            std::cout<< "Delete - "<<inputName<<std::endl;
        }
        
    }


    return 0;
}