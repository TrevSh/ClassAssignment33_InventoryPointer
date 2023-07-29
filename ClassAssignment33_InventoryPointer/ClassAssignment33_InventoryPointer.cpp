#include <iostream>
#include <string>
#include <vector>

//returns pointer to a string element
std::string* ptrToElement(std::vector<std::string>* const pVec, int i);

int main()
{
    std::vector<std::string> inventory;
    inventory.push_back("sword");
    inventory.push_back("armor");
    inventory.push_back("shield");

    //display string object that the returned pointer points to
    std::cout << "Sending the objected pointed to by returned pointer: \n";
    std::cout << *(ptrToElement(&inventory, 0)) << "\n\n";

    //assigns one pointer to another -- inexpensive assignment
    std::cout << "Assigning the returned pointer to another pointer. \n";
    std::string* pStr = ptrToElement(&inventory, 1);
    std::cout << "Sending the object pointed to by new pointer to cout.\n";
    std::cout << *pStr << "\n\n";

    //Copies a string object == expensive assignment
    std::cout << "Assigning object pointed by pointer to a string object. \n";
    std::string str = *(ptrToElement(&inventory, 2));
    std::cout << "Sending the new string object to cout: \n";
    std::cout << str << "\n\n";

    //Altering the string object through a returned pointer
    std::cout << "Altering an object through a returned pointer. \n";
    *pStr = "healing potion";
    std::cout << "Sending the altered object to cout: \n";
    std::cout << inventory[1] << "\n";

    system("pause");
}

std::string* ptrToElement(std::vector<std::string>* const pVec, int i) {
    //Returns address of the string in position of i of vector that pVec points to
    return &((*pVec)[i]);
}