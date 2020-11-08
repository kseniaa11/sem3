#include "Hash-a.h"
#include <stdio.h>
#include <iostream>




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
		for (int i = 0; i < sztab; i++)
		{
			tab[i] = conItem();
		}
		N = 0;

		if (count > sztab || count < 0)
			throw std::runtime_error("Invalid parametr");
		int m, l;
		while (N < count)
		{
			m = rand() % sztab;
			l = rand() % sztab;
			try {
				add(mas1[m], mas2[l]);
			}
				catch (std::exception& ex) {
					std::cout << ex.what() << std::endl;
			}
		}
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


	void Hash::printHash() // ����� ������� � �������� �����
	{

		std::cout << "Busy\tKey\tInfo\n";
		if (N == 0)
			throw std::runtime_error("There aren`t items");
		for (int i = 0; i < sztab; i++)
			std::cout << tab[i].busy << "\t" << tab[i].key << "\t" << tab[i].info << "\n";
		return;
	}

	int Hash::find(int k) //����� �������� ������� �� �����
	{
			int it = 0; //���������� ��������
			int j = k % sztab;
			
			if (tab[j].busy == 1)
			{
				while ((tab[j].busy == 1) && (it < sztab))
				{
					if ((tab[j].busy == 1) && (tab[j].key == k))
						return j;
					j = (j + step);
					j = j % sztab;
					it = it + 1;
				}
			}
		return -1;
	}

	void Hash::add(int k,  const char* inf) //���������� �������� � �������
	{
		if (find(k) > -1)
			throw std::runtime_error("This item already exists");

		if (k <= 0)
			throw std::runtime_error("Invalid parametr");

		int it = 0; //���������� ��������
		int j = k % sztab;

		while ((tab[j].busy == 1) && (it < sztab))
		{
			j = (j + step) % sztab;
			it = it + 1;
		}
		 
		if (it >= sztab)
			throw std::runtime_error("Vector overflow");
		tab[j].key = k;
		tab[j].busy = 1;
		for (int s=0;s<szinfo;s++)
			tab[j].info[s] = inf[s];
		
		N = N + 1;
		return;
	}

	struct Item Hash::getinfo(int k)// ������� ���������� �� ������� �� ��������� �����
	{
		int index = find(k);
		if (index == -1)
			throw std::runtime_error("This item doean`t exist");
		else
			return tab[index];

	}

	void Hash::del(int k) //�������� �������� �� �������(� �������� � ���� ���������) �� �����
	{
		int index = find(k);
		if (index == -1)
			throw std::runtime_error("This item doesn`t exist");
		tab[index].busy = 0;
		N = N - 1;
		*this = reorg();
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
				nov.add(tab[i].key, tab[i].info);
				j = j + 1;
			}
			i = i + 1;
		}
		nov.N = N;
		return nov;
	}







