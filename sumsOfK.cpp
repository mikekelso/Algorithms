#include <fstream>
#include <vector>
#include <iostream>

int main(){

    const int NUMBER_OF_FILES = 5;
    
    int targetNumber;
    std::string readString;
    std::ifstream inFile;
    std::ofstream outFile;
    

    for (int i = 0; i < NUMBER_OF_FILES; i++){
        
        bool valuesFound = false; 

        //declare ifstream, name and open input file
        std::string inputFileName = "in" + std::to_string(i+1) + ".txt";
        std::ifstream inFile (inputFileName);


        //declare ofstream, name and opne output file
        std::string outputFileName = "out" + std::to_string(i+1) + ".txt";
        std::ofstream outFile (outputFileName);


        //if input file opens, read string and target number - else return error
        if (inFile){
            inFile >> readString;
            inFile >> targetNumber;
            outFile << targetNumber << "\n";
            outFile << readString << "\n";
        }
        
        //raise error and alert user if input file doesn't open
        else {
            std::cerr << "Error opening input file " << i + 1 << ".\n";
            return 1;
        }
    

        //create readIntegers vector, read ints into readIntegers and output file
        std::vector<int> readIntegers;
        int value;
        while (inFile >> value){
            readIntegers.emplace_back(value);
            outFile << value << " ";

        }

        outFile << "\nExercise1 calculation complexity O(n^2)\n";


        // **assignment called for nested for loop**

        // print yes and addition equation of first pair of values 
        // that sum to target number
        
        for (auto& value: readIntegers){
            for (auto& value2 : readIntegers){
                
                    if(value + value2 == targetNumber){
                        outFile << "Yes\n"; 
                        valuesFound = true;
                        if(value == value2) 
                            outFile << value << "+" << value << "=" << targetNumber;
                        else
                            outFile << value << "+" << value2 << "=" << targetNumber;
                        break;
                    
                    }
                
            }
            if (valuesFound){
                break;
            }
            
        }
    

        if (!valuesFound) {
            outFile << "No";
        }
        
        
        //close input and output files
        inFile.close();
        outFile.close();
    }

}