/*

This program takes 5 input filesand produces 5 output files. 
For each file a target value is read and the program finds N numbers that sum to that value. 
The user provides the N value.

*/



#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <fstream>
#include <set>


int main() {

    const int NUMBER_OF_FILES = 5;
    int addendCount;
    std::string inputFile;
    std::ifstream inFile;
    int targetNumber;

    for (int i = 0; i< NUMBER_OF_FILES; i++) {

        //name and open output file
        std::string outputFileName = "outputFile" + std::to_string(i) + ".txt";
        std::ofstream outFile(outputFileName);

        //get and open input file
        std::cout << "Enter the input file: \n";
        std::string inputFileName;
        std::cin >> inputFileName;
        inFile.open(inputFileName);

        //get and print targetNumber or return error if file not open
        if(inFile){
            
            inFile >> targetNumber;
            outFile << "The target number is: " << targetNumber << "\n";
        }
        else {
            std::cerr << "Error opening input file " << i + 1;
            return 1;
        }


        //store remaining integers in iinputFile in readIntegers
        std::vector<int> readIntegers;
        int value;


        while (inFile >> value ){
            readIntegers.emplace_back(value);

        }


        //get number of integers (addends) desired
        std::cout << "How many integers to add together to get the target number?\n";
        std::cin >> addendCount;

        //use a std::set to ensure unique combinations
        std::set<std::vector<int>> result;

        //sort readIntegers for next_permutation to give all permutations
        std::sort(readIntegers.begin(), readIntegers.end());

        //if permutation sums to targetNumber, add it to result set - only unique added (set)
        do {
            if (std::accumulate(readIntegers.begin(),readIntegers.begin()+addendCount ,0) == targetNumber) {
                result.emplace(readIntegers.begin(),readIntegers.begin()+addendCount);
            }
            
        }
        while (std::next_permutation(readIntegers.begin(), readIntegers.end()));

        //send each combination to output file
        for (auto& combination: result){
            for (auto& digit : combination){
                outFile << digit << " ";
            }
            outFile << "\n";
        }
        
        //immediately close filestreams instead of waiting until out of scope
        inFile.close();
        outFile.close();
        
    }

}