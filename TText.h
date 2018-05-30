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
    void backNode();//����� �����
	int nextNode();//������
	int downNode();//����
    void addNextNode(string str);//���������� ��������� ������
    void addDownNode(string str);//���������� ��������� ��������� 
    void deleteTree(Node *tmp_n);//������� ��� ������
    void deletelurr();//������� ������
    Node* getcurrent();//�������� ��������� �� ������� ��������
    string printNode(Node *tmp_n);//������ ������� ��������

    string printAllText();//������ ����� ������
    void editNode(string str);//������������� ��������
    string getCurrString();//����� ������� ��������� ������
    void reset();//����� ��������=������
    Node *findNode(Node *tmp_n, string str);//����� ��-��
    Node* getHead();//����� ��������� �� ������
    void setCurrNode(string str);//������ ���-� ���-�� 
};



