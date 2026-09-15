#pragma once
#include <iostream>
#include "node.h"
using namespace std;
template <class T>
class Tree
{
private:
	int heigh(node <T> *);
	T *hash;
	int Hsize;
	int B_factor(node <T> *);
	void inorder(node <T> *);
	int hashing( const T&);
	int probing(const T&);
	void insert_in_hash(const T&);
	void delete_from_hash(const T&);
	node <T> * root;
	node <T> * succ(node <T> *);
	node <T> * pre(node <T> *);
	node <T> * ll( node <T> *);
	node <T> * rr( node <T> *);
	node <T> * rl( node <T> *);
	node <T> * lr( node <T> *);
	node <T> * delete_(node <T> *, const T&);
	node <T>* delete_node(const T&);
	void search(const T&);
public:
	Tree();
	node <T> * insert(const T&);
	void display();
	void searching(const string& name);
	int search_by_hash(const T &key);
	void deletion(const string&);
	~Tree();
};
template <class T>
Tree<T>::Tree()
{
	root = nullptr;
	Hsize = 0;
	hash = new T [50];
}

template <class T>
int Tree<T>::hashing( const T& key)
{
	long long sum = 0;
	string name = key.info;
	for (int i = 0; i < name.size(); i++)
	{
		sum += (name[i]);
	}
	return sum % 11;
}

template<class T>
int Tree<T>::probing(const T& key)
{
	int index = hashing(key);
	int i = 0;
	string temp = " ";
	while (hash[(index + i) % 11] !=temp)
	{
		i++;
	}
	return (index + i) % 11;
}

template <class T>
void Tree<T>::delete_from_hash(const T& key)
{
	int index = hashing(key);
	int i = 0;
	int exist = 0;
	string temp = " ";
	while (hash[(index + i) % 11] != key)
	{
		if (hash[(index + i) % 11] == temp || i == 50)
		{
			exist++;
			break;
		}
		i++;
	}
	if (!exist)
	{
		Hsize--;
		hash[(index + i) % 11] = temp;
	}
}

template <class T>
void Tree<T>::insert_in_hash(const T& key)
{
	if (Hsize!=50)
	{
		int index = hashing(key);
		string temp = " ";
		if (hash[index] !=temp)
		{
			index = probing(key);
		}
		hash[index] = key;
		Hsize++;
	}
}

template <class T>
int Tree<T>::search_by_hash(const T& key)
{
	int index = hashing(key);
	int i = 0;
	while (hash[(index + i) % 11] != key)
	{
		if (hash[(index + i) % 11] ==nullptr)
		{
			cout << "NOT Exsit \n";
			return -1;
		}
		else if (i == 50)
		{
			cout << "NOT Exsit \n";
			return -1;
		}
		i++;
	}
	return (index + i) % 11;
}
template <class T>
void Tree<T>::inorder(node <T>*t)
{
	if (t)
	{
		inorder(t->left);
		cout << t->data <<" ";
		inorder(t->right);
	}
	else return;
}

template <class T>
node <T> * Tree<T>::insert(const T& value)
{
	 node<T> *t, * p = root, *q = nullptr;
	if (!root)
	{
		root = new node<T>;
		root->data = value;
		root->left = root->right = nullptr;
		//T name = value;
		insert_in_hash(value);
		cout << "\n\t\t\t\t\t\t\t\Added\n";
		return root;
	}
	else
	{
	 	while (p)
		{
			q = p;
			if (p->data > value)
			{
				p = p->left;
			}
			else if (p->data < value)
			{
				p = p->right;
			}
			else
				return NULL;
		}

		insert_in_hash(value);
		t = new node<T>;
		t->data = value;
		t->right = t->left = nullptr;
		if (q->data<value)
		{
			q->right = t;
		}
		else q->left = t;

		p = root;
		if (B_factor(p) == 2 && B_factor(p->left) == 1)
		{
			return ll(p);
		}
		else if (B_factor(p) == 2 && B_factor(p->left) == -1)
		{
			return lr(p);
		}
		else if (B_factor(p) == -2 && B_factor(p->right) == -1)
		{
			return rr(p);
		}
		else if (B_factor(p) == -2 && B_factor(p->right) == 1)
		{
			return rl(p);
		}
		cout << "\n\t\t\t\t\t\t\t\Added\n";
	}
	return p;
}
template <class T>
 void Tree<T>::search(const T&value)
{

	int index =search_by_hash(value);
	if (index == -1)
	{
		cout << "NOT Found \n";
	}
	else
	cout << hash[index];

	/*node <T>* p = root;
	if (root == nullptr) return nullptr;
	while (p)
	{
		if (p->data > value)
		{
			p = p->left;
		}
		else if (p->data < value)
		{
			p = p->right;
		}
		else
			return p;
	}
	return nullptr;*/
}


 template <class T>
 void Tree<T>::searching(const string &name)
 {
	 user<string>u;
	 u.info = name;
	 search(u);
 }

template <class T>
node <T>* Tree<T>::delete_(node <T>* p,const T& value)
{
	if (p)
	{
		if (!p->right && !p->left)
		{
			if (p == root)
			{
				root = nullptr;
			}
			//delete_from_hash(value);
			delete p;
			return nullptr;
		}
		else
		{
			if (p->data > value)
			{
				p->left = delete_(p->left, value);
			}
			else if (p->data < value)
			{
				p->right = delete_(p->right, value);
			}
			else
			{
				//delete_from_hash(value);
				node <T>* q;
				if (heigh(p->left) > heigh(p->right))
				{
					q = pre(p->left);
					p->data = q->data;
					p->left = delete_(p->left, q->data);
				}
				else
				{
					q = succ(p->right);
					p->data = q->data;
					p->right = delete_(p->right, q->data);
				}
			}
		}
		if (B_factor(p) == 2 && B_factor(p->left) == 1)
		{
			return ll(p);
		}
		else if (B_factor(p) == 2 && B_factor(p->left) == -1)
		{
			return lr(p);
		}
		else if (B_factor(p) == -2 && B_factor(p->right) == -1)
		{
			return rr(p);
		}
		else if (B_factor(p) == -2 && B_factor(p->right) == 1)
		{
			return rl(p);
		}
		else if (B_factor(p) == -2 && B_factor(p->right) == 0)
		{
			return rr(p);
		}
		else if (B_factor(p) == 2 && B_factor(p->left) == 0)
		{
			return ll(p);
		}
		return p;
	}
	cout << "Empty\n";
	return nullptr;
}

template <class T>
node <T>* Tree<T>::delete_node(const T&key)
{
	if (root)
	{
		cout << "\t\t\t\t Deleted \n";
		return delete_(root, key);
	}
	else
	{
		cout << "Empty To Delete \n";
		return nullptr;
	}
}

template <class T>
void Tree<T>::deletion(const string& name)
{
	//cout << "Enter User Name : ";
	user<string>u;
	u.info = name;
	delete_node(u);
}

template <class T>
void Tree<T>::display() 
{ 
	if (root)
	{
		inorder(root);
		cout << endl;
	}
	else
		cout << "Empty\n";
}
template <class T>
node <T>* Tree<T>::ll(node <T>* p)
{
	node <T>* pl, * plr;
	pl = p->left;
	plr = pl->right;
	pl->right = p;
	p->left = plr;
	p->heigh = heigh(p);
	pl->heigh = heigh(pl);
	if (plr)
		plr->heigh = heigh(plr);
	if (p == root)
		root = pl;
	return pl;
}


template <class T>
node <T>* Tree<T>::rr(node <T>* p)
{
	node <T>* pr, * prl;
	pr = p->right;
	prl = pr->left;
	pr->left = p;
	p->right = prl;
	p->heigh = heigh(p);
	pr->heigh = heigh(pr);
	if (prl)
		prl->heigh = heigh(prl);
	if (p == root) root = pr;
	return pr;
}


template <class T>
node <T>* Tree<T>::lr(node <T>* p)
{
	node <T>* pl, * plr;
	pl = p->left;
	plr = pl->right;
	p->left = plr->right;
	pl->right = plr->left;
	plr->right = p;
	plr->left = pl;
	p->heigh = heigh(p);
	pl->heigh = heigh(pl);
	plr->heigh = heigh(plr);
	if (p == root)
	{
		root = plr;
	}
	return plr;
}


template <class T>
node <T>* Tree<T>::rl(node <T>* p)
{
	node <T>* pr, * prl;
	pr = p->right;
	prl = pr->left;
	p->right = prl->left;
	pr->left = prl->right;
	prl->left = p;
	prl->right = pr;
	p->heigh = heigh(p);
	pr->heigh = heigh(pr);
	prl->heigh = heigh(prl);
	if (root == p) root = prl;
	return prl;
}

template <class T>
int Tree<T>::heigh(node <T> * t)
{
	node<T>* p = t;
	if (p)
	{
		int left = 0, right = 0;
		left = heigh(p->left);
		right = heigh(p->right);
		return ((left > right) ? left + 1 : right + 1);
	}
	else return 0;
}


template <class T>
int Tree<T>::B_factor(node <T> * p)
{
	if (p)
	{
		int left = 0, right = 0;
		left = heigh(p->left);
		right = heigh(p->right);
		return (left - right);
	}
	else
		return 0;
}


template <class T>
node <T> * Tree<T>::pre(node<T> *p)
{
	while (p->right)
	{
		p = p->right;
	}
	return p;
}

template <class T>
node <T> * Tree<T>::succ(node<T> *p)
{
	while (p->left)
	{
		p = p->left;
	}
	return p;
}
template <class T>
Tree<T>::~Tree()
{
	if (root)
	{
		node <T>* p = root;
		node<T>* r = p->right, * l = p->left;
		int i = 1;
		while (l)
		{
			if (l)
			{
				T temp = l->data;
				delete_(root, temp);
				l = root->left;
			}
			else
			{
				break;
			}
		}
		while (r)
		{
			if (r)
			{
				delete_(root, r->data);
				r = root->right;
			}
			else
				break;
		}
		delete root;
		root = nullptr;
		delete[] hash;
	}
}