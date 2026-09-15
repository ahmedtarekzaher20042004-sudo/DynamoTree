#pragma once
#include "quearr.h"
#include<iostream>
#include<string>
#include "user.h"
using namespace std;
template <class T>
class node
{
public:
	T data;
	int heigh;
	node* left;
	node* right;
	bool operator ==( node& value);
	bool operator>( node& value);
	bool operator<( node& value);
	void operator=( node&);
	friend ostream& operator<<(ostream& out,  node<T>& ob)
	{
		out << ob.data;
		return out;
	}
	friend istream& operator>>(istream& in,  node& ob)
	{
		in >> ob.data;
	}
};
template <class T>
void node<T>::operator=(node& value)
{
	data = value.data;
}
template <class T>
bool node<T>::operator==( node&value)
{
	return data == value.data;
}
template <class T>
bool node<T>::operator<( node& value)
{
	return data< value.data;
}
template <class T>
bool node<T>::operator>( node&value)
{
	return data > value.data;
}