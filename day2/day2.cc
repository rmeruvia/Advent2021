#include <iostream>
#include <fstream>
#include <string>

void day2_part1(int &depth, int &horizontal){
    std::ifstream myfile("day2.txt");
    std::string current;
    std::string substr1;
    int update = 0;
    while(true)
    {
        getline(myfile, current);
        if(myfile.eof()) break;
        substr1 = current.substr(0,current.length()-2);
        update = stoi(current.substr(current.length()-2,current.length()-1));
        if (substr1 == "up") depth -= update;
        else if (substr1 == "down") depth += update;
        else horizontal += update;
    }
}

void day2_part2(int &depth, int &horizontal, int &aim){
    std::ifstream myfile("day2.txt");
    std::string current;
    std::string substr1;
    int update = 0;
    while(true)
    {
        getline(myfile, current);
        if(myfile.eof()) break;
        substr1 = current.substr(0,current.length()-2);
        update = stoi(current.substr(current.length()-2,current.length()-1));
        if (substr1 == "up") aim -= update;
        else if (substr1 == "down") aim += update;
        else{
            horizontal += update;
            depth += update*aim;
        }
    }
}

int main(){

    int depth = 0;
    int horizontal = 0;
    int aim = 0;

    day2_part1(depth, horizontal);

    std::cout << "Product pt. 1: " << depth*horizontal << std::endl;

    day2_part2(depth=0, horizontal=0, aim);

    std::cout << "Product pt. 2: " << horizontal*depth << std::endl;

    return 0;
}
