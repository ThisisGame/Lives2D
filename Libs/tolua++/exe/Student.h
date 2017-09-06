#pragma once  
  
#include<iostream>  
using namespace std;  
  
class People
{

};

class PeopleManager
{
public:
	void AddPeople()
	{
		std::cout << "People type" << std::endl;
	}
};

class Student :public People
{  
public:
	Student();  
	~Student();  
  
	void Run();  
  
	void Run(int a);  

	void Run(std::string varStr);
};  