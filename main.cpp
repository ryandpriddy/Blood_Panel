/*Ryan Priddy
 May 29, 2023
 Initial comments:
    -The purpose of this example program was created to show my capability to use Inheritance, OOP, Polymorphism, Data reading,
        math, pointers, references, constructors, destructors.
    -I found a blood test example online and constructed the program around the txt file.
    -For this example, I am assuming we don't know the order of the blood tests from the report
    -I am assuming we do know the first four lines are patient identifiers, but they will not be used in this example
    -Although a good extension to this program would be to create a Patient Profile class and store the panel object vector in
        the patient's object.
    -Example document only had levels in normal range so code does not address outliers
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Test.h"

std::vector<std::string> splitString(const std::string& line, char delimiter); //Function declarations
int checkTest(const std::string& test);
std::vector<BloodTest*> runTest();
void printAll(const std::vector<BloodTest*>& panel);

int main() {
    std::vector<BloodTest*> heapExample = runTest(); //calls function that runs the rest of the program

    for (const auto& obj : heapExample)  //since these objects are on the heap, MUST be deleted or memory leak
        delete obj; //will call destructors of child then parent class since virtual keyword used

    return 0;
}

std::vector<BloodTest*> runTest(){
    std::ifstream file("Blood_Test.txt"); //Open file to read
    std::vector<BloodTest*> panel; //vector to hold pointer objects

    //Local variables of Stack memory usage
    if (file) { //if the file was able to be opened
        std::string line; //string to store each line read
        int count = 0; //counter to keep track of each line
        BloodTest* test; //creating pointer object of Class BloodTest
        while (std::getline(file, line)) { //continue while there are more lines in the file
            if(count>4){ //starting after patient information
                std::vector<std::string> values = splitString(line, ','); //function reads each line and separates line based on ','
                std::vector<std::string> level = splitString(values[1], ' '); //function then reads part of previous line and separates based on ' '
                std::vector<std::string> range;
                if(values.size()>2) { //one blood test where there are additional words and needs to be broken down more
                    range = splitString(values[2], ' ');  //separates based on ' '
                }
                switch(checkTest(values[0])) { //function analyzes test name and returns number correlating to that test
                    //the use of 'new' results in dynamically allocated memory for objects on the heap
                    //Polymorphism because BloodTest* test but initialization of objects are of child class
                    case 0: test = new Hb(values[0], std::stod(level[1]), std::stod(range[1]), std::stod(range[3]), level[2]);
                        break;
                    case 1: test = new RBC(values[0], std::stod(level[1]), std::stod(range[1]), std::stod(range[3]), level[2]+" "+level[3]);
                        break;
                    case 2: test = new WBC(values[0], std::stod(level[1]), std::stod(range[1]), std::stod(range[3]), level[2]);
                        break;
                    case 3: test = new Platelet(values[0], std::stod(level[1]), std::stod(range[1]), std::stod(range[3]), level[2]);
                        break;
                    case 4: test = new Hct(values[0], std::stod(level[1]), std::stod(range[1]), std::stod(range[3]), level[2]);
                        break;
                    case 5: test = new MCV(values[0], std::stod(level[1]), std::stod(range[1]), std::stod(range[3]), level[2]);
                        break;
                    case 6: test = new MCH(values[0], std::stod(level[1]), std::stod(range[1]), std::stod(range[3]), level[2]);
                        break;
                    case 7: test = new MCHC(values[0], std::stod(level[1]), std::stod(range[1]), std::stod(range[3]), level[2]);
                        break;
                        //two kinds of constructors in BloodTest class and child classes because two formatting styles for blood test results
                    case 8: test = new Neutrophil(values[0], std::stoi(level[1]));
                        break;
                    case 9: test = new Lymphocyte(values[0], std::stoi(level[1]));
                        break;
                    case 10: test = new Monocyte(values[0], std::stoi(level[1]));
                        break;
                    case 11: test = new Eosinophil(values[0], std::stoi(level[1]));
                        break;
                    case 12: test = new Basophil(values[0], std::stoi(level[1]));
                        break;
                    default: std::cout << "ERROR: Could not find blood test."; //In event checkTest function cannot find test type
                }
                panel.push_back(test); //adds newly initialized test to vector to store all blood test objects
            }
            count++; //increment with each line
        }
        file.close(); //Close the file
    }
    else
        std::cout << "Failed to open the file." << std::endl; //Error message if the file was unable to be opened

    printAll(panel); //function to print out each blood test stored in vector
    return panel;
}

std::vector<std::string> splitString(const std::string& line, char delimiter) { //accepts reference to string and delimiter for separation
    std::vector<std::string> words;
    std::istringstream iss(line);
    std::string word;

    while (std::getline(iss, word, delimiter)) //separating the line by ',' into separate strings (word)
        words.push_back(word); //storing each word into a vector words

    return words; //returns the vector words
}
int checkTest(const std::string& test) {
    std::string types[] = {"Hb", "RBC", "WBC", "Platelet", "Hct", "MCV", "MCH)", "MCHC", "Neutro", "Lympho", "Mono", "Eos",
                           "Baso"};
    for (int i = 0; i < (sizeof(types) / sizeof(types[0])); i++) { //increments through each array element
        if (test.find(types[i]) != std::string::npos) //checks if array element matches some part of the passed in string reference
            return i;
    }
    return -1; //triggers default in switch statement if no match found
}
void printAll(const std::vector<BloodTest*>& panel)  {
    for(BloodTest* ptr : panel) //increments through each pointer object in vector and calls print statement
        ptr -> print();
}
