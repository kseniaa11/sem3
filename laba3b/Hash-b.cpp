#include "Hash-b.h"
#include <stdio.h>
#include <iostream>
#include <time.h>



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
		for (int i = 0; i < sztab; i++)
		{ 
			tab[i] = conItem();
		}
		N = 0;
	}

	Hash::Hash(int count) //�������� ����������� ������(�������) � �������������� �������� ����������� ��������� �� ������� ������ � ����������;
	{
		int mas1[sztab] = { 17,21,34,55,67,78,3,42,39,8,10,46,82,5,99 };
		const char* mas2[sztab] = { "abcde","fghij","klmno","pqrst", "uvwxy","z0123", "45678","9ABCD", "EFGHI","JKLMN", "OPQRS","TUVWX", "YZ987","65432","10abc" };

		for (int i = 0; i < sztab; i++)
		{
			tab[i] = conItem();
		}
		N = 0;

		if (count > sztab && count < 0)
			throw std::runtime_error("Invalid quantity of vector");
		int m, l;
		
		while (N < count)
		{
			srand(time(0));
			m = rand() % sztab;
			l = rand() % sztab;
			struct Item dob;
			dob.key = mas1[m];
			for (int s = 0; s < szinfo; s++)
				dob.info[s] = mas2[l][s];
			try {
				*this += dob;
			}
				catch (std::exception& ex) {
		}
	}


	std::istream& operator >> (std::istream& c, Hash& el) //���� �������� ������� � �������� ������ 
	{
		std::cout << "Enter the key:\n";
		number(el.pre.key);
		std::cout << "Enter the information:\n";
		c >> el.pre.info;
		el.pre.busy = 1;
		return c;
	}

	struct Item Hash::conItem() //�������� ����������� ���������(�������� �������) � �������������� ��������� ���������� �� ���������;
	{
		struct Item el;
		el.key = -1;
		el.busy = 0;
		for (int s = 0; s < szinfo; s++)
			el.info[s] = ' ';
		el.info[szinfo] = '\0';
		return el;

	}

	std::ostream& operator << (std::ostream& c, const Hash& h) // ����� ������� � �������� �����
	{
		c << "Busy\tKey\tInfo\n";
		if (h.N == 0)
			throw std::runtime_error("There aren`t items");
		for (int i = 0; i < sztab; i++)
			c << h.tab[i].busy << "\t" << h.tab[i].key << "\t" << h.tab[i].info << "\n";
		return c;
	}

	int Hash::operator ()(int k) //����� �������� ������� �� �����
	{
		//std::cout << " N="<<N;
		
			int it = 0; //���������� ��������
			int j = k % sztab;
			
			if (tab[j].busy == 1)
			{
				while ((tab[j].busy != 0) && (it < sztab))
				{
					//std::cout << " FLAG#" << it << " item#" << tab[j].key;
					if ((tab[j].busy == 1) && (tab[j].key == k))
						return j;
					j = (j + step);
					j = j % sztab;
					it = it + 1;
				}
			}
		return -1;
	}

	Hash& Hash::operator +=(struct Item NOV) //���������� �������� � �������
	{
		int l = (*this)(NOV.key);
		if ( l > -1)
			throw std::runtime_error("This item already exists");

		int it = 0; //���������� ��������
		int j = NOV.key % sztab;

		while ((tab[j].busy == 1) && (it < sztab))
		{
			j = (j + step) % sztab;
			it = it + 1;
		}
		 
		if (it >= sztab)
			throw std::runtime_error("Vector overflow");
		tab[j].key = NOV.key;
		tab[j].busy = 1;
		for (int s=0;s<szinfo;s++)
			tab[j].info[s] = NOV.info[s];
		
		N = N + 1;
		return *this;
	}

	struct Item Hash::operator [](int k)// ������� ���������� �� ������� �� ��������� �����
	{
		int index = (*this)(k);
		if (index == -1)
			throw std::runtime_error("This item doean`t exist");
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

	Hash Hash::reorg()//������ ������� �� ���������� ��������� � ������������� �������.
	{
		Hash nov;
		int i = 0, j = 0;
		while (i < sztab)
		{
			if (tab[i].busy == 1)
			{
				struct Item dob;
				dob.key = tab[i].key;
				for (int s = 0; s < szinfo; s++)
					dob.info[s] = tab[i].info[s];
				nov += dob;
				j = j + 1;
			}
			i = i + 1;
		}
		nov.N = N;
		return nov;
	}







