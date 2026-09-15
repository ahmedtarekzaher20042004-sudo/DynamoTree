#pragma once
#include <iostream>
#include<string>
#include "quearr.h"
using namespace std;
template <class T>
class user
{
public:
	quearr<T>data;
	string info;
	user();
	bool operator==(const string& value);
	bool operator>( const user<T>& value);
	bool operator<( const user<T>& value);
	bool operator!=(const string& value);
	bool operator!=(const user<T>& value);
	void operator=( const string&value);
	void operator=( const user<T>&value);
	void print();
	friend ostream& operator<<(ostream& out,user& ob)
	{
		out << "User Name Is : " << ob.info<<endl;
		out << "User Activities IS :- \n" << ob.data << endl;
		return out;
	}
	friend istream& operator>>(istream& in, user& ob)
	{
		cout << "Enter User Name : ";
		in >> ob.info;
		cout << "Enter Activites :- \n";
		in >> ob.data;
		return in;
	}
	char operator[](const int&);
};

template<class T>
user<T>::user()
{
	info = " ";
}


template <class T>
void user<T>::operator=(const string& value)
{
	//data = value;
	info = value;
}
template <class T>
void user<T>::operator=(const user<T>& value)
{
	data = value.data;
	info = value.info;
}

template <class T>
bool user<T>::operator==(const string& value)
{
	return info == value;
}

template <class T>
bool user<T>::operator<(const user<T>& value)
{
	return info < value.info;
}

template <class T>
bool user<T>::operator>(const user<T>& value)
{
	return info > value.info;
}

template <class T>
bool user<T>::operator!=(const string& value)
{
	return info != value;
}

template <class T>
bool user<T>::operator!=(const user<T>& value)
{
	return info != value.info;
}

template <class T>
void user<T>::print()
{
	data.printque();
}

template <class T>
char user<T>::operator[](const int &index)
{
	return info[index];
}