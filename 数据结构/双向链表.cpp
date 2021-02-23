#include <iostream>
#include <string>
#include<list>
using namespace std;
template <class T>
class Node
{
public:
	T sth;
	Node* next;
	Node* last;
public:
	Node() = default;
	~Node() = default;
};

template <class T>
class list
{
private:
	Node<T>* head;
	Node<T>* tail;
	Node<T>* ptr;
	int num;
public:
	list(int n);
	list();
	void Add(T sth);
	void ForTraversal();
	void ReTraversal();
	Node<T>& operator[](int index);
	void sort();
	Node<T>& getTail();
	Node<T>& getHead();
	~list();
};
template <class T>
void list<T>::sort()
{
	
	for (int i = 0;i<this->num-1;i++)
	{
		for (int j = 0; j < this->num - i - 1; j++)
		{
			//cout << this[j] << " ";
		}
	}
}
template <class T>
list<T>::list(int n)
{
	Node<T>* p = NULL;
	this->head = NULL;
	this->tail = NULL;
	this->num = n;
	for (int i = 0; i < n; i++)
	{
		p = new Node<T>;
		p->last = this->head;
		this->head = p;
	}
	for (int i = 0; i < n; i++)
	{
		p->next = this->tail;
		this->tail = p;
		p = p->last;
	}
}
template <class T>
void list<T>::Add(T sth)
{
	Node<T>* p = new Node<T>;
	if (num == 0)
	{
		this->head = p;
		this->tail = p;
		p->sth = sth;
	}
	else
	{
		this->head->next = p;
		p->last = this->head;
		this->head = p;
		p->sth = sth;
	}
	num++;
}
template <class T>
void list<T>::ForTraversal()
{
	Node<T>* p = this->tail;
	for (int i = 0; i < this->num; i++)
	{
		cout << p->sth << " ";
		p = p->next;
	}
}
template <class T>
void list<T>::ReTraversal()
{
	Node<T>* p = this->head;
	for (int i = 0; i < this->num; i++)
	{
		cout << p->sth << " ";
		p = p->last;
	}
}
template <class T>
Node<T>& list<T>::operator[](int index)
{
	this->ptr = this->tail;
	for (int i = 0; i < index; i++)
	{
		ptr = ptr->next;
	}
	//if(ptr!=NULL)
	return *ptr;
}

template <class T>
list<T>::list()
{
	this->head = NULL;
	this->tail = NULL;
	this->num = 0;
}
template <class T>
Node<T>& list<T>::getTail()
{
	return this->tail;
}
template <class T>
Node<T>& list<T>::getHead()
{
	return this->head;
}
template <class T>
list<T>::~list()
{
	if (this->num != 0)
	{
		Node<T>* p = head;
		for (int i = 0; i < this->num; i++)
		{
			this->head = p->last;
			delete p;
			p = this->head;
		}
	}
	this->num = 0;
	this->head = NULL;
	this->tail = NULL;
}
int main()
{
	list<int> l;
	list<int> l1;
	l.Add(87);
	l.Add(99);
	l.Add(73);
	l.Add(120);
	l.Add(934);
	l.ForTraversal();
	l.sort();
	cout << l[3].sth;
	//l.ForTraversal();
}