#include <iostream>
#include <sstream>
// Input will be: Aapple, Dorange, etc
// The first letter will be A or D which will mean add or delete respectively
// Keys are lower-case- apple, orange etc
// Length of key is at most 10
// Hash table will have exactly 26 slots (a-z)
// Each slot has 3 statuses: "never used", "tombstone", "occupied" with the default being "never used"
// The last character of the key will be the hash value, so apple will have the hash value as 'e'
class HashTable{

    private:
        struct Entry
        {
            std::string data;
            std::string status = "no entry";
        };

        static const int tableSize = 26;

        Entry mEntry[tableSize];

        int findHash(char key){
            
            int index = 97 - key;
            
            return index;
        }

        int find(int pos){
            while(true){
                if(pos>25){
                    return -1;
                }
                if(mEntry[pos].status == "no entry"){
                    return pos;
                }
                pos = pos + 1;
            }
        }

    public:

        void addEntry(std::string value){
            
            int positionRequired = findHash(value[value.length()-1]);
            int positionAvailable = find(positionRequired);
            if(positionAvailable == -1){
                std::cout<<"table is full!"<<std::endl;
                return;
            }else{
                mEntry[positionAvailable].data = value;
                mEntry[positionAvailable].status = "occupied";
            }
        }

        void deleteEntry(std::string key){

        }

        void displayTable(){
            std::cout<<"========Hash Table===========\n";
            for(auto& item: mEntry){
                std::cout<<"status: "<<item.status<<"\ndata: "<<item.data<<std::endl;
                std::cout<<"=========================\n";
            }
        }

};



int main(){
    std::cout<<"assignment V0.01\n";
    std::string input;
    getline(std::cin,input);
    std::stringstream ss(input);
    HashTable table;

    while(ss.good()){
        std::string token;
        ss>>token;
        // std::cout<<token<<"\n";
        // //input: Hello world!
        // //output:Hello
        // //       world!
        std::string inputName = token.substr(1);
        if(token[0] == 'A'){
            std::cout<< "Add - "<<inputName<<std::endl;
            table.addEntry(inputName);
            

        }else if (token[0] == 'D'){
            std::cout<< "Delete - "<<inputName<<std::endl;
        }
        
    }

    table.displayTable();



    return 0;
}