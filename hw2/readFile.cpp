// readFile.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
#include <iostream>

using namespace std;

int main(int argc,char* argv[])
{
    string filename = argv[1];
    std::vector<int> power; 
    //Define the input file stream
    std::ifstream myFile(filename);
    std::string line;
    if (!myFile.is_open()) throw std::runtime_error("Could not open file");

    int val;
    int count = 0;
    while (std::getline(myFile, line))
    {
        if (count > 0) {
            int pow; 

            //Here...string manipulation
            std::stringstream s_stream(line);
            std::vector<std::string> result;
            while (s_stream.good())
            {
                std::string substr;
                getline(s_stream, substr, ',');
                result.push_back(substr);
            }
            power.push_back(stoi(result[1]));
        }
        count++;
    }

    for (std::vector<int>::const_iterator i = power.begin(); i != power.end(); i++)
        std::cout << *i << ' ';
}


