#include "C:\Users\urkae\Desktop\лабараторные\cем3\githab\laba3v\Hash-v.h"
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


	Hash::Hash() //пустой конструктор дл€ инициализации экземпл€ров и массивов экземпл€ров класса(таблицы) по умолчанию;
	{
		len = MAX;
		tab = new struct Item [len];
		for(int i=0;i<MAX;i++)
			conItem(tab[i]);
		N = 0;
	}

	Hash::Hash(int count) //создание экземпл€ров класса(таблицы) с инициализацией заданным количеством элементов из массива ключей и информации
	{
		
		
		len = MAX;
		
		(*this).tab = new struct Item[len];
		for (int i = 0; i < len; i++)
		{
			 conItem(tab[i]);
		}
		N = 0;

		int m = 1;
		struct Item dob;
		conItem(dob);
		//std::cout << " count:" << count;
		for (int i = 0; i < szinfo; i++)
				dob.info[i] = '\0';
			dob.info[szinfo] = '\0';
		for(int t=0;t<count;t++)
		{
			dob.info[t] = 'k';
			//srand(time(0));
			m = m*2;
			
			
			dob.key = t+m;

			try {
				*this += dob;
			}
			catch (std::exception& ex) {
			}
			//std::cout << " N:" << N;
		
		}
		N = count;
	}

	Hash::Hash (const Hash& h)
	{
		N = h.N;
		len = h.len;
		tab = new struct Item[len];
		for (int i = 0; i < len; i++)
		{
			tab[i].busy = h.tab[i].busy;
			tab[i].key = h.tab[i].key;
			for (int u=0;u<szinfo;u++)
				tab[i].info[u] = h.tab[i].info[u];
			tab[i].info[szinfo] = '\0';
			
		}
	}

	Hash::~Hash()
	{
		std::cout << "\ndie N len "<<N<<len;
		for (int i = 0; i < len; i++)
		{
			if (tab[i].info != nullptr) {
				delete[] tab[i].info;
			}
		}
		delete [] tab;
	}

	

	std::istream& operator >> (std::istream& c, Hash& h) //ввод элемента таблицы с входного потока 
	{
		 h.conItem(h.pre);
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

	void Hash::conItem(struct Item& I) //создание экземпл€ров структуры(элемента таблицы) с инициализацией начальным состо€нием по умолчанию;
	{
		I.key = -1;
		I.busy = 0;
		I.info = new char[szinfo+1];
		for (int i = 0; i < szinfo; i++)
			I.info[i] ='f';
		I.info[szinfo] = '\0';
		return;

	}

	std::ostream& operator << (std::ostream& c, const Hash& h) // вывод таблицы в выходной поток
	{
		c << "Busy\tKey\tInfo\n";
		if (h.N == 0)
			throw std::runtime_error("There aren`t items");
		for (int i = 0; i < h.len; i++)
		{
			c << h.tab[i].busy << "\t" << h.tab[i].key << "\t"; 
			for (int j = 0; j < strlen(h.tab[i].info); j++)
			{
				if (h.tab[i].info[j] == '\0')
					break;
				c << h.tab[i].info[j];
			}
				
			c << "\n";
			
		}
		return c;
	}

	int Hash::operator ()(int k) //поиск элемента таблицы по ключу
	{
		//std::cout << " N="<<N;
		
			int it = 0; //количество итераций
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

	Hash& Hash::operator +=(struct Item NOV) //добавление элемента в таблицу
	{
		int l = (*this)(NOV.key);
		if (l > -1)
			throw std::runtime_error("This item already exists");

		if (N == len)
			throw std::runtime_error("Vector overflow. Do reorganization!!!");

		int it = 0; //количество итераций

		int j = NOV.key % len;

		while ((tab[j].busy == 1) && (it < MAX))
		{
			j = (j + step) % MAX;
			it = it + 1;
		}	
		if (it >= len)
			throw std::runtime_error("Vector overflow");
		 
		tab[j].key = NOV.key;
		tab[j].busy = 1;
		//std::cout << "\nMMMMM[2]\n";
		int i = 0;
		//std::cout << " i1:" << tab[j].info;		
		//67yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy,u=.ystd::cout << " i2:" << NOV.info;

		while ((tab[j].info[i] != '\0') && (NOV.info[i] != '\0'))
		{
			tab[j].info[i] = NOV.info[i];
			i++;
		}
		tab[j].info[i] = '\0';
		//std::cout << "\nMMMMM[3]\n";
		//tab[j].info[strlen(NOV.info)] = '\0';
		//std::cout << "\nMMMMM[4]\n";
		N = N + 1;
		
		return *this;
	}

	struct Item Hash::operator [](int k)// выборка информации из таблицы по заданному ключу
	{
int index = (*this)(k);
if (index == -1)
throw std::runtime_error("This item doesn`t exist");
else
return tab[index];

	}

	void Hash::operator -=(int k) //удаление элемента из таблицы(с отметкой в поле зан€тости) по ключу
	{
		int index = (*this)(k);
		if (index == -1)
			throw std::runtime_error("This item doesn`t exist");
		tab[index].busy = -1;
		N = N - 1;
		return;
	}

	Hash& Hash::operator = (Hash& h)
	{
		N = h.N;
		len = h.len;
		//tab = new struct Item[len];

		for (int i = 0; i < MAX; i++)
		{
			this->tab[i].busy = h.tab[i].busy;
			this->tab[i].key = h.tab[i].key;
			for (int t = 0; t < szinfo; t++)
			{
				this->tab[i].info[t] = h.tab[i].info[t];
			}
			this->tab[i].info[szinfo] = '\0';
		}

		return *this;
	}

	struct Item& Hash::operator = (struct Item& I)
	{
		struct Item el;
		conItem(el);
		el.busy = I.busy;
		el.key = I.key;
		int j = 0;

		for (int j = 0; j < szinfo; j++)
			el.info[j] = I.info[j];
		el.info[szinfo] = '\0';

		//while ((el.info[j] != '\0') && (I.info[j] != '\0'))
		//{
		//	el.info[j] = I.info[j];
		//	j++;
		//}
		//el.info[strlen(I.info)] = '\0';

		return el;
	}

	void Hash::reorg(Hash& h)//чистка таблицы от Уудаленных элементовФ Ц реорганизаци€ таблицы.
	{
		if (N == 0)
		{
			for (int i = 0; i < MAX; i++)
				conItem(tab[i]);
			return;
		}

		Hash nov;
		//std::cout << "N: " << h.N << "   len: " << h.len << "  ";

		//std::cout << "\na\n";

		//std::cout << "\naa\n";
		struct Item dob;

		//std::cout << "\naaa\n";
		int i = 0;
		while (i < h.len)
		{
			if (h.tab[i].busy == 1)
			{
				conItem(dob);
				dob.key = tab[i].key;
				for (int s = 0; s < szinfo; s++)
					dob.info[s] = tab[i].info[s];
				dob.info[szinfo] = '\0';

				//std::cout << "\nMMMMM\n";
				try {
					nov += dob;
				}
				catch (std::exception& ex) {
				}
				//std::cout << "\nMMMMM[5]?\n";

			}
			i = i + 1;
		}
		this->N = nov.N;
		
		for(int i = 0; i < MAX; i++)
		{
			this->tab[i].busy = nov.tab[i].busy;
			this->tab[i].key = nov.tab[i].key;
			for (int t = 0; t < szinfo; t++)
			{
				this->tab[i].info[t] = nov.tab[i].info[t];
			}
			this->tab[i].info[szinfo] = '\0';
		}

		//std::cout << "\naayjl\n";
		return;
	}







