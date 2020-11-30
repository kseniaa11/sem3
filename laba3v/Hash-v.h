#include <cstring>
#include <stdio.h>
#include <iostream>
#include <math.h>

const int szinfo = 5;
const int MAX = 100; //
const int step = 4; //


int number(int& n);


typedef struct Item
{
	int key; // ���� >0
	int busy; //���� ��������� 0\1\-1
	char* info; //����������
}Item;

class Hash
{
private:
	
	//int mas1[sztab] = { 17,21,34,55,67,78,3,42,39,8,10,46,82,5,99 };
	//const char* mas2[sztab] = { "abcde","fghij","klmno","pqrst", "uvwxy","z0123", "45678","9ABCD", "EFGHI","JKLMN", "OPQRS","TUVWX", "YZ987","65432","10abc" };
	
	int N; //���������� ������� ���������
	
	int len; //������ ������� � ���������� ������
	

public:
	struct Item pre;
	struct Item* tab; //������ ���������
	
	Hash(); //������ ����������� ��� ������������� ����������� � �������� ����������� ������(�������) �� ���������;
	Hash(int count); //�������� ����������� ������(�������) � �������������� �������� ����������� ��������� �� ������� ������ � ����������;
	~Hash();// ����������
	//Hash set(int novoe);
	friend std::istream& operator >> (std::istream& c, Hash& el); //���� �������� ������� � �������� ������ 
	struct Item conItem(); //�������� ����������� ���������(�������� �������) � �������������� ��������� ���������� �� ���������;
	friend std::ostream& operator << (std::ostream& c, const Hash& h); // ����� ������� � �������� �����
	int operator () (int k); //����� �������� ������� �� �����(��� ������ �������)
	Hash& operator +=(struct Item s); //���������� �������� � �������
	struct Item operator [](int k);// ������� ���������� �� ������� �� ��������� �����(��� ���������� ���������)
	void operator -=(int k); //�������� �������� �� �������(� �������� � ���� ���������) �� �����
	Hash& reorg(); //�������������

};

