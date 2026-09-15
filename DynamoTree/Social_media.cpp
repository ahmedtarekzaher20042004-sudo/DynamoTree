#include "Social_media.h"
#include<iostream>
using namespace std;
void Social_media::insert()
{
	user<string>u;
	cin >> u;
	t.insert(u);
}
void Social_media::delete_()
{
	cout << "Enter User Name : ";
	string name;
	t.deletion(name);
}
void Social_media::search()
{
	cout << "Enter User Name : ";
	string name;
	cin >> name;
	t.searching(name);
}
void Social_media::display()
{
	t.display();
}