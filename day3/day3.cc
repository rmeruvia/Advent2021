#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>


int day3_part1(){

    std::ifstream myfile("day3.txt");
    std::string current;
    getline(myfile,current);

    int len_binary = current.length();
    std::vector<int> count_ones;
    int total = 1;

    float gamma = 0;
    float epsilon = 0;

    for(int i = 0; i < len_binary - 1; i++) count_ones.push_back(current[i] - '0');

    while(true){
        getline(myfile,current);
        if(myfile.eof()) break;
        for(int i = 0; i < len_binary; i++) count_ones[i] += current[i] - '0';
        total++;
    }

    for(int i = count_ones.size(); i >= 0; i--){
        if(count_ones[count_ones.size() - i] >= total/2){
            gamma += pow(2,i);
            epsilon += 0;
        }
        else{
            gamma += 0;
            epsilon += pow(2,i);
        }
    }

    return gamma*epsilon;
}

float calcOxy(std::vector<std::string> in){

    float dec = 0;
    // Already used the first bit
    for(int i = 1; i < in[0].length(); i++){
        std::vector<std::string> ones;
        std::vector<std::string> zeros;
        for(int k = 0; k < in.size(); k++){
            if(in[k][i] == '1') ones.push_back(in[k]);
            else zeros.push_back(in[k]);
        }
        if(ones.size() >= zeros.size()) in = ones;
        else in = zeros;
    }

    for(int i = in[0].length(); i > 0; i--)
        dec += pow(2,i - 1)*(in[0][in[0].length()-i] - '0');

    return dec;
}

int calcCO2(std::vector<std::string> in){

    float dec = 0;
    // Already used the first bit
    for(int i = 1; i < in[0].length(); i++){
        std::vector<std::string> ones;
        std::vector<std::string> zeros;
        for(int k = 0; k < in.size(); k++){
            if(in[k][i] == '1') ones.push_back(in[k]);
            else zeros.push_back(in[k]);
        }
        if(ones.size() >= zeros.size()) in = zeros;
        else in = ones;
    }

    for(int i = in[0].length(); i > 0; i--)
        dec += pow(2,i - 1)*(in[0][in[0].length()-i] - '0');

    return dec;
}

int day3_part2(){

    std::ifstream myfile("day3.txt");
    std::string current;
    getline(myfile,current);

    int len_binary = current.length();
    std::vector<std::string> msb_ones;
    std::vector<std::string> msb_zeros;
    int total = 1;

    float oxy = 0;
    float co2 = 0;

    while(true){
        getline(myfile,current);
        if(myfile.eof()) break;
        if(current[0] == '1') msb_ones.push_back(current);
        else msb_zeros.push_back(current);
        total++;
    }

    if(msb_ones.size() > msb_zeros.size()){
        oxy = calcOxy(msb_ones);
        co2 = calcCO2(msb_zeros);
    }
    else{
        oxy = calcOxy(msb_zeros);
        co2 = calcCO2(msb_ones);
    }

    return oxy*co2;
}

int main(){

    int power_consumption = day3_part1();

    std::cout << "Power Consumption: " << power_consumption << std::endl;

    float life_support = day3_part2();

    std::cout << "Life Support Rating: " << life_support << std::endl;

    return 0;

}
