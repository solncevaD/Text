#pragma once
#include "t_Stack.h"

using namespace std;


class TText
{
    Node *T_header;
    Node *T_curr;
    t_Stack T_Stack;
public:
	TText();
	~TText();
    void backNode();//ходим назад
	int nextNode();//вперед
	int downNode();//вниз
    void addNextNode(string str);//добавление следующей строки
    void addDownNode(string str);//добавление следующей подстроки 
    void deleteTree(Node *tmp_n);//удалить все дерево
    void deletelurr();//удалить раздел
    Node* getcurrent();//получить указатель на текущее значение
    string printNode(Node *tmp_n);//печать текущее значение

    string printAllText();//печать всего текста
    void editNode(string str);//редактировать значение
    string getCurrString();//взять текущий указатель строки
    void reset();//текущ значение=голове
    Node *findNode(Node *tmp_n, string str);//поиск эл-та
    Node* getHead();//получ указатель на голову
    void setCurrNode(string str);//задаем тек-й ука-ль 
};



