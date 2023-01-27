#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include<string.h>

using namespace std;


class MyString
{

private:

	char* str;
	int num;

public:

	MyString();

	MyString(const char* _str);

	MyString(const char* _str, int num);

	MyString& operator =(const MyString& obj);

	MyString(const MyString& obj);

	MyString operator +(const MyString& obj);

	void Print();

	~MyString();
};


MyString::MyString()
{
	str = nullptr;
}


MyString::MyString(const char* _str)
{
	str = new char[80 + 1];

	strcpy(str, _str);
}

MyString::MyString(const char* _str, int num)
{

	str = new char[num + 1];

	strcpy(str, _str);
}


MyString& MyString::operator=(const MyString& obj)
{
	if (str != nullptr)
	{
		delete[]str;
	}

	int length = strlen(obj.str);
	str = new char[length + 1];

	strcpy(str, obj.str);

	return *this;
}

MyString::MyString(const MyString& obj)
{
	int length = strlen(obj.str);
	str = new char[length + 1];

	strcpy(str, obj.str);
}

MyString MyString::operator+(const MyString& obj)
{
	MyString newStr;

	int length = strlen(str);
	int secondlength = strlen(obj.str);

	newStr.str = new char[length + secondlength + 1];

	int i = 0;

	for (; i < length; i++)
	{
		newStr.str[i] = str[i];
	}


	for (size_t j = 0; j < secondlength; j++, i++)
	{
		newStr.str[i] = obj.str[j];
	}

	newStr.str[length + secondlength] = '\0';

	return newStr;
}


void MyString::Print()
{
	{
		cout << str << endl;
	}
}

MyString::~MyString()
{

	delete[]str;
}

int main()
{


	MyString str1("Hello");
	MyString str2("World!",123);

	str1.Print();
	str2.Print();

	MyString str3 = str1 + str2;

	str3.Print();

	MyString str4(str3);

	str4.Print();

}
