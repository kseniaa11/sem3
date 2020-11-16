#include <cstring>
#include <stdio.h>
#include <iostream>


const int szinfo = 5; //
const int sztab = 15; //
const int step = 4; //


int number(int& n);


typedef struct Item
{
	int key; // ключ >0
	int busy; //поле зан€тости 0\1
	char info[szinfo+1]; //информаци€
}Item;

class Hash
{
private:
	
	int mas1[sztab] = { 17,21,34,55,67,78,3,42,39,8,10,46,82,5,99 };
	const char* mas2[sztab] = { "abcde","fghij","klmno","pqrst", "uvwxy","z0123", "45678","9ABCD", "EFGHI","JKLMN", "OPQRS","TUVWX", "YZ987","65432","10abc" };

	int N; //количество зан€тых элементов
	struct Item tab[sztab]; //массив элементов
	void clean();//чистка таблицы от Уудаленных элементовФ Ц реорганизаци€ таблицы.

public:
	Hash(); //пустой конструктор дл€ инициализации экземпл€ров и массивов экземпл€ров класса(таблицы) по умолчанию;
	Hash(int count); //создание экземпл€ров класса(таблицы) с инициализацией заданным количеством элементов из массива ключей и информации;
	~Hash() {};// деструктор
	friend std::istream& operator >> (std::istream& c, struct Item& el); //ввод элемента таблицы с входного потока 
	struct Item conItem(); //создание экземпл€ров структуры(элемента таблицы) с инициализацией начальным состо€нием по умолчанию;
	friend std::ostream& operator << (std::ostream& c, const Hash& h); // вывод таблицы в выходной поток
	int operator () (int k); //поиск элемента таблицы по ключу(дл€ других функций)
	Hash& operator +=(struct Item s); //добавление элемента в таблицу
	struct Item operator [](int k);// выборка информации из таблицы по заданному ключу(дл€ диалоговой программы)
	void operator -=(int k); //удаление элемента из таблицы(с отметкой в поле зан€тости) по ключу
	Hash reorg(); //реорганизаци€

};

