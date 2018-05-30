#include "TText.h"
#include <iostream>
#include <string.h>

TText::TText()
{
    T_header = new Node;
    T_curr = T_header;
    T_header->N_down = NULL;
    T_header->N_next = NULL;
    T_header->str = " ";
}


TText::~TText()
{
}

void TText::reset()
{
    T_curr = T_header;
}

void TText::setCurrNode(string str)
{
    Node* w_node = findNode(T_header, str);
     if(w_node) T_curr = w_node;
}

void TText::backNode()
{
    if (T_Stack.isEmpty()) throw - 3;
    T_curr = T_Stack.pop();
}

int TText::nextNode()
{
	if (T_curr == NULL || T_curr->N_next == NULL) return -1;
	T_Stack.push(T_curr);
	T_curr = T_curr->N_next;
	return 0;

}
int TText::downNode()
{
	if (T_curr == NULL || T_curr->N_down == NULL) return -1;
	T_Stack.push(T_curr);
	T_curr = T_curr->N_down;
	return 0;

}


void TText::addNextNode(string str)
{
    Node *t_node = new Node;
    t_node->str = str;
    t_node->N_next = T_curr->N_next;
    t_node->lvl = T_curr->lvl;
    T_curr->N_next = t_node;
    T_Stack.push(T_curr);
    T_curr = T_curr->N_next;
}

void TText::addDownNode(string str)
{
    Node *t_node = new Node;
    t_node->str = str;
    t_node->N_next = T_curr->N_down;
    t_node->lvl = T_curr->lvl++;
    T_curr->N_down = t_node;
    T_Stack.push(T_curr);
    T_curr = T_curr->N_down;
}

Node* TText::findNode(Node *tmp_n, string str)
{
    Node *f_node=NULL;
    if(tmp_n==NULL) return NULL;
        cout<<tmp_n->str<<std::endl;

        if(!strcmp( tmp_n->str.data(), str.data()))
            return tmp_n;
        if(f_node=findNode(tmp_n->N_down, str))
                    return f_node;
        else if(f_node=findNode(tmp_n->N_next, str))
                    return f_node;
        else return f_node;
}


void TText::deleteTree(Node* tmp_n)
{
    if (tmp_n == NULL) return;
    deleteTree(tmp_n->N_next);
    deleteTree(tmp_n->N_down);
    delete tmp_n;
    tmp_n = NULL;
}

void TText::deletelurr()
{
    Node *t = T_curr;
    backNode();
    if (T_curr->N_next == t)
        T_curr->N_next = t->N_next;
    if (T_curr->N_down == t)
        T_curr->N_down = t->N_next;
 
     t->N_next = NULL; 
	 deleteTree(t);

}

Node* TText::getcurrent()
{
    return T_curr;
}


string TText::printNode(Node* tmp_n)
{
    if (tmp_n == NULL) return "";
    string str;
    for (int i = 0; i < tmp_n->lvl; i++)
                cout<<"lvl:"<<tmp_n->lvl<<endl;

    str += tmp_n->str;
    str += '\n';
    str += printNode(tmp_n->N_down);
    str += printNode(tmp_n->N_next);
    return str;
}




string TText::printAllText()
{    
    return printNode(T_header);
}


string TText::getCurrString()
{
    return T_curr->str;
}

Node * TText::getHead()
{
    return T_header;
}

void TText::editNode(string str)
{
    T_curr->str = str;
}
