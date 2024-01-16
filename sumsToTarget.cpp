/*

This program reads a target number and then a list of numbers from an input file then returns any two numbers (including repeats) that
 add up to the target number. The program is written to accept 5 input files and output 5 output files. This is intentionally
  a O(n^2) nested for loop implementation.

*/

#include <iostream>
#include <fstream>
#include <vector>

int main(){
    const int NUMBER_OF_FILES = 5;
    
    std::ifstream inFile;
    int targetNumber;

    //loop for each input file
    for (int i = 0; i < NUMBER_OF_FILES; i++){
        
        //create a numbered output file for each input file
        std::string outputFileName = "outputFile" + std::to_string(i) + ".txt";
        std::ofstream outFile (outputFileName);


        //request and recieve input file
        std::cout << "Enter the input file: \n";
        std::string inputFileName;
        std::cin >>inputFileName;

        //open input file , store target number
        inFile.open(inputFileName);
        if (inFile){
            inFile >> targetNumber;
            outFile << "The target number is: " << targetNumber << "\n";
        }
        
        //raise error and alert user if input file doesn't open
        else {
            std::cerr << "Error opening input file " << i + 1 << ".\n";
            return 1;
        }

        //create readIntegers vector, read ints into readIntegers until there are none left
        std::vector<int> readIntegers;
        int value;
        while (inFile >> value){
            readIntegers.emplace_back(value);

        }

        //assignment called for nested for loop
        for (auto& value: readIntegers){
            for (auto& value2 : readIntegers){
                if(value + value2 == targetNumber){
                    if(value == value2) 
                        outFile << value << " ";
                    else
                        outFile << value << "," << value2 << " ";
                }
            }
            
        }
        
        //close input and output files
        inFile.close();
        outFile.close();
       
    }

    return 0;
}