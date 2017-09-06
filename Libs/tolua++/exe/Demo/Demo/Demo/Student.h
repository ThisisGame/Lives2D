#pragma once  
  
#include<iostream>  
using namespace std;  
  
class People
{
public:
	std::string mType;

public:
	People() {};
	~People() {};
};

class PeopleManager
{
public:
	void AddPeople(People* varPeoPle)
	{
		std::cout << "People type:" << varPeoPle->mType.c_str() << std::endl;
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