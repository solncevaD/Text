#pragma once
#include <string>

using namespace std;



struct Node
{
	string str;
    Node *N_next;
    Node *N_down;
	int lvl;
	Node()
	{
        lvl = 0;
		str = "";
        N_down = N_next = NULL;
	}
};

struct reqNode
{
    Node *t_node;
    reqNode *nextNode;
};

class t_Stack
{
    reqNode *header;
public:
	t_Stack();
	~t_Stack();
	bool isEmpty();//проверка на пустоту
	void push(Node *t);//положить в стек
	Node* pop();//вытолкнуть
};

