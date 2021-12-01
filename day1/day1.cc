#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int day1_part1()
{
    std::ifstream myfile("day1.txt");
    std::string current;
    getline(myfile, current);
    int highest = stoi(current);
    int total = 0;
    while(!myfile.eof())
    {
        if(stoi(current) > highest)
            total++;
        highest = stoi(current);
        getline(myfile, current);
    }
    return total;
}

int day1_part2()
{
    std::ifstream myfile("day1.txt");
    std::string current;
    std::vector<int> numbers;
    // Put data into a vector so it is easier to iterate over
    while(true){
        getline(myfile, current);
        if(myfile.eof()) break;
        numbers.push_back(stoi(current));
    }
    int sum1 = numbers[0] + numbers[1] + numbers[3];
    int sum2 = 0;
    int total = 0;
    for(int i = 1; i <= numbers.size()-3; i++){
        // Sum here to start
        sum2 = numbers[i] + numbers[i+1] + numbers[i+2];
        if(sum2 > sum1)
            total++;
        sum1 = sum2;
    }
    return total;
}

int main()
{
    int total1 = day1_part1();
    std::cout << "Total # of increases for pt1: " << total1 << std::endl;
    int total2 = day1_part2();
    std::cout << "Total # of increases for pt2: " << total2 << std::endl;
    return 0;
}
