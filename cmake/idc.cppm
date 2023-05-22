module; //this global module scope is needed to be able to do includes

#include <iostream>

export module idc; // module declaration

export class Idc{
public:
    Idc() = default;
    ~Idc() = default;
    void welcome()
    {
        std::cout << "Hello from Building 12 Room T12!" << std::endl;
    }
    void interact_with_audience() {};
};
