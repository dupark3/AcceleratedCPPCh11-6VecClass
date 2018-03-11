#include <iostream>

#include "Vec.h"

int main()
{
    Vec<double> defaultVec;
    defaultVec.push_back(1.55);
    defaultVec.push_back(2.55);
    defaultVec.push_back(3.55);
    defaultVec.push_back(4.55);
    defaultVec.push_back(5.55);
    Vec<double> argumentVec(5, 3.14);

    Vec<double> copyVec(argumentVec);

    Vec<double> assignmentVec;
    assignmentVec = defaultVec;

    defaultVec.erase(defaultVec.begin() + 2);
    copyVec.clear();
    
    for (size_t i = 0; i != defaultVec.size(); ++i)
        std::cout << defaultVec[i] << " ";
    std::cout << std::endl;
    for (size_t i = 0; i != argumentVec.size(); ++i)
        std::cout << argumentVec[i] << " ";
    std::cout << std::endl;
    for (size_t i = 0; i != copyVec.size(); ++i)
        std::cout << copyVec[i] << " ";
    std::cout << std::endl;
    for (size_t i = 0; i != assignmentVec.size(); ++i)
        std::cout << assignmentVec[i] << " ";

    return 0;
}
