module; 
#include<iostream>       

export module idc; // module declaration

export class idc{
public:
    idc() = default;
    ~idc() = default;
    void welcome();
};


void idc::welcome()    
{
    std::cout << "Hello from Building 12 Room T12!" << std::endl;
}