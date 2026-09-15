#pragma once
#include "Tree.h"
#include "user.h"
class Social_media
{
	Tree <user<string>>t;
	user<string> u;
public:
	void insert();
	void delete_();
	void search();
	void display();
};
