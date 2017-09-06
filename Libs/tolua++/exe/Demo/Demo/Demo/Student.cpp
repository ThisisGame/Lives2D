#include "Student.h"  
  
  
Student::Student():People()
{  
	mType = "Student";
}  
  
void Student::Run()  
{  
    cout << "Student Run :"<< endl;  
} 
  
void Student::Run(int a)  
{  
    cout << "Student Run" <<a<< endl;  
}

void Student::Run(std::string varStr)
{
	std::cout << "Run " << varStr.c_str() << std::endl;
}
  
Student::~Student()  
{  
} 