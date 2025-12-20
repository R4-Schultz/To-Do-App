#include <iostream>
#include <vector>
#include <string>   
#include <fstream>
std::vector<std::string> list;
std::string filename;

void printList()
{
    int positionInList;

    for(std::string task: list){
        std::cout << "(" << positionInList << "): " << task << std::endl;
        positionInList++;
    }
    std::cout<<std::endl;
}

void parseFile()
{
    list.clear();
    std::string line;
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Could not open file.\n";
        return;
    }
    while (std::getline(file, line)) {
        if (!line.empty())
            list.push_back(line);
    }
}

void addToList()
{
    std::string userInput;
    std::string userAnswer; 
    int counter = 0;
    std::cout << "What would you like to add the list? \n" ;
    std::getline(std::cin, userInput);
    list.push_back(userInput);
    std::cout<<"Would you like to add more to the list? (y/n) ";
    std::getline(std::cin, userAnswer);
    if(userAnswer == "y" || userAnswer == "Y"){
        addToList();
    }
}

void removeItemInList()
{
    int totalItems = list.size();
    std::vector<std::string> tempList;
    std::string index;
    int counter = 0;
    std::cout<<"What task would you like to remove? (1-" << totalItems << ")" << std::endl;
    std::getline(std::cin, index);
    
    for(std::string task: list)
    {
        if(counter+1 != stoi(index))
        {
            tempList.push_back(task);
            counter++;
        }
        else if(counter+1 == stoi(index))
        {
            counter++;
        }
    }
    list.clear();
    list.assign(tempList.begin(),tempList.end());
}
void saveToFile()
{
    std::ofstream myFile(filename);
    for(std::string task: list)
    {
        myFile << task << "\n";
    }
    myFile.close();
}

void printMenu()
{
    std::string userInput = "0";
    while(stoi(userInput) != 5)
    {
        std::cout<<"(1) Print out current To-Do list"<<std::endl;
        std::cout<<"(2) Add a Task to the To-Do list"<<std::endl;
        std::cout<<"(3) Remove a Task to the To-Do list"<<std::endl;
        std::cout<<"(4) Save current To-Do list to a file"<<std::endl;
        std::cout<<"(5) Quit"<<std::endl;
        std::cout<<"Please Select Your Action (1-5): ";
        std::getline(std::cin, userInput);
        if(stoi(userInput) == 1)
            printList();
        else if(stoi(userInput) == 2)
            addToList();
        else if(stoi(userInput) == 3)
            removeItemInList();
        else if(stoi(userInput) == 4)
            saveToFile(); 
        else if(stoi(userInput) == 5)
            std::cout<<"Goodbye" << std::endl;
        else
            std::cout<<"INVALID ANSWER"<<std::endl;
    }
}

int main() {
    std::cout<<"Hello! Welcome to your To-Do List"<<std::endl;
    std::cout<<"Please type the name of text file you intend to use for your list (list.txt): ";
    std::getline(std::cin, filename);
    parseFile();

    printMenu();
    return 0;
}