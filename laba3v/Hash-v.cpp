#include "C:\Users\urkae\Desktop\������������\c��3\githab\laba3v\Hash-v.h"
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <math.h>
#include <string>


	int number(int& n)
	{
		using std::cin;
		cin >> n;
		while (!cin.good())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin.clear();
			cin >> n;
		}
		return 1;
	}


	Hash::Hash() //������ ����������� ��� ������������� ����������� � �������� ����������� ������(�������) �� ���������;
	{
		len = 1;
		tab = new struct Item [len];
		tab[0] = conItem();
		N = 0;
	}

	Hash::Hash(int count) //�������� ����������� ������(�������) � �������������� �������� ����������� ��������� �� ������� ������ � ����������
	{
		
		int c2 = count;
		len = 1;
		while (c2 > 1)
		{
			c2 = c2 / 2;
			len = len * 2;
		}
		(*this).tab = new struct Item[len];
		for (int i = 0; i < len; i++)
		{
			tab[i] = conItem();
		}
		N = 0;

		int m = 1, l = 1;
		struct Item dob = conItem();
		while (N < count)
		{
			//srand(time(0));
			m = m*3;
			l = l+3;
			for (int i = 0; i < l; ++i)
				dob.info[i] = 'a'; //���� ��������
			dob.info[l] = '\0';
			
			dob.key = m;

			try {
				*this += dob;
			}
			catch (std::exception& ex) {
			}
			std::cout << " N:" << N;
			dob = conItem();
		}
		N = count;
	}

	Hash::~Hash()
	{
		std::cout << "\ndie N len"<<N<<len;
		//for (int i = 0; i < len; i++)
		//{
		//	if (tab[i].info != nullptr) {
		//		delete[] tab[i].info;
		//	}
		//}
		delete [] tab;
	}

	

	std::istream& operator >> (std::istream& c, Hash& h) //���� �������� ������� � �������� ������ 
	{
		h.pre = h.conItem();
		std::cout << "Enter the key:\n";
		number(h.pre.key);
		std::cout << "Enter the information:\n";
	
		
		char* st = new char[MAX];
		c >> st;
		//std::cout << "strlen istream: " << strlen(st) << "    aaaAAa ";
		
		for (int i = 0; i < strlen(st); i++)
			h.pre.info[i] = st[i];
		h.pre.info[strlen(st)] = '\0';
		delete[] st;
		h.pre.busy = 1;
		return c;
	}

	struct Item Hash::conItem() //�������� ����������� ���������(�������� �������) � �������������� ��������� ���������� �� ���������;
	{
		struct Item el;
		el.key = -1;
		el.busy = 0;
		el.info = new char[MAX+1];
		for (int i = 0; i < MAX; i++)
			el.info[i] = ' ';
		el.info[MAX] = '\0';
		return el;

	}

	std::ostream& operator << (std::ostream& c, const Hash& h) // ����� ������� � �������� �����
	{
		c << "Busy\tKey\tInfo\n";
		if (h.N == 0)
			throw std::runtime_error("There aren`t items");
		for (int i = 0; i < h.len; i++)
		{
			c << h.tab[i].busy << "\t" << h.tab[i].key << "\t"; 
			for (int j = 0; j < strlen(h.tab[i].info); j++)
				c << h.tab[i].info[j];
				
			c << "\n";
		}
		return c;
	}

	int Hash::operator ()(int k) //����� �������� ������� �� �����
	{
		//std::cout << " N="<<N;
		
			int it = 0; //���������� ��������
			int j = k % len;
			
			if (tab[j].busy == 1)
			{
				while ((tab[j].busy != 0) && (it < len))
				{
					//std::cout << " FLAG#" << it << " item#" << tab[j].key;
					if ((tab[j].busy == 1) && (tab[j].key == k))
						return j;
					j = (j + step);
					j = j % len;
					it = it + 1;
				}
			}
		return -1;
	}

	Hash& Hash::operator +=(struct Item NOV) //���������� �������� � �������
	{
		int l = (*this)(NOV.key);
		if (l > -1)
			throw std::runtime_error("This item already exists");

		if (N == len)
			throw std::runtime_error("Vector overflow. Do reorganization!!!");

		int it = 0; //���������� ��������

		int j = NOV.key % len;

		while ((tab[j].busy == 1) && (it < len))
		{
			j = (j + step) % len;
			it = it + 1;
		}	
		if (it >= len)
			throw std::runtime_error("Vector overflow");
		 
		tab[j].key = NOV.key;
		tab[j].busy = 1;
		std::cout << "\nMMMMM[2]\n";
		for (int i = 0; i < strlen(NOV.info); i++)
			tab[j].info[i] = NOV.info[i];
		std::cout << "\nMMMMM[3]\n";
		tab[j].info[strlen(NOV.info)] = '\0';
		std::cout << "\nMMMMM[4]\n";
		N = N + 1;
		
		return *this;
	}

	struct Item Hash::operator [](int k)// ������� ���������� �� ������� �� ��������� �����
	{
		int index = (*this)(k);
		if (index == -1)
			throw std::runtime_error("This item doesn`t exist");
		else
			return tab[index];

	}

	void Hash::operator -=(int k) //�������� �������� �� �������(� �������� � ���� ���������) �� �����
	{
		int index = (*this)(k);
		if (index == -1)
			throw std::runtime_error("This item doesn`t exist");
		tab[index].busy = -1;
		N = N - 1;
		return;
	}

	Hash& Hash::reorg()//������ ������� �� ���������� ��������� � ������������� �������.
	{
		if (N == 0)
			throw std::runtime_error("There aren`t items");

		Hash nov;
		std::cout << "N: " << N << "   len: " << len << "  ";
		
		if (N == len)
			nov.len = 2 * len;
		else
			nov.len = len;
		std::cout << "N: " << N << "   novlen: " << nov.len << "  ";
		nov.tab = new struct Item[nov.len];
		std::cout << "\na\n";
		for (int i = 0; i < nov.len; i++)
		{
			nov.tab[i] = conItem();
		}
		std::cout << "\naa\n";
		//struct Item dob = conItem();
		std::cout << "\naaa\n";
		int i = 0;
		while (i < len)
		{
			if (tab[i].busy == 1)
			{
				
				//dob.key = tab[i].key;
				//for (int j = 0; j < strlen(tab[i].info); j++)
				//	dob.info[j] = tab[i].info[j];
				//dob.info[strlen(tab[i].info)] = '\0';

				std::cout << "\nMMMMM\n";
				try {
					//nov += dob;
					nov += tab[i];
				}
				catch (std::exception& ex) {
				}
				std::cout << "\nMMMMM[5]?\n";
				
			}
			i = i + 1;
		}
		
		std::cout << "\naayjl\n";
		return nov;
	}







