#include <cstring>
#include <stdio.h>
#include <iostream>


const int szinfo = 5; //���� ������ ����
const int sztab = 15; //������ �������
const int step = 4; //��� �������������


int number(int& n);


typedef struct Item
{
	int key; // ���� >0
	int busy; //���� ��������� 0\1
	char info[szinfo+1]; //����������
}Item;

class Hash
{
private:
	
	int mas1[sztab] = { 17,21,34,55,67,78,3,42,39,8,10,46,82,5,99 };
	const char* mas2[sztab] = { "abcde","fghij","klmno","pqrst", "uvwxy","z0123", "45678","9ABCD", "EFGHI","JKLMN", "OPQRS","TUVWX", "YZ987","65432","10abc" };

	int N; //���������� ������� ���������
	struct Item tab[sztab]; //������ ���������
	Hash reorg(); //�������������
public:
	Hash(); //������ ����������� ��� ������������� ����������� � �������� ����������� ������(�������) �� ���������;
	Hash(int count); //�������� ����������� ������(�������) � �������������� �������� ����������� ��������� �� ������� ������ � ����������;
	~Hash() {};// ����������
	struct Item conItem(); //�������� ����������� ���������(�������� �������) � �������������� ��������� ���������� �� ���������;
	void printHash(); // ����� ������� � �������� �����
	int find(int k); //����� �������� ������� �� �����(��� ������ �������)
	void add(int k, const char* inf); //���������� �������� � �������
	struct Item getinfo(int k);// ������� ���������� �� ������� �� ��������� �����(��� ���������� ���������)
	void del(int k); //�������� �������� �� �������(� �������� � ���� ���������) �� �����
};

