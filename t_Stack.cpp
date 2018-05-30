#include "t_Stack.h"


t_Stack::t_Stack()
{
    header = NULL;
}

t_Stack::~t_Stack()
{
}

bool t_Stack::isEmpty()
{
    return (header == NULL);
}

void t_Stack::push(Node * p_node)
{
    reqNode *t_pushTree = new reqNode;
    t_pushTree->t_node = p_node;
    t_pushTree->nextNode = NULL;
    if (header == NULL)
	{
        header = t_pushTree;
	}
	else
	{
        t_pushTree->nextNode = header;
        header = t_pushTree;
	}
}

Node * t_Stack::pop()
{
	if (isEmpty()) throw - 1;

    reqNode *t_popTree = header;
    Node *t_popNode = header->t_node;
    header = header->nextNode;
    delete t_popTree;
    return t_popNode;
}
