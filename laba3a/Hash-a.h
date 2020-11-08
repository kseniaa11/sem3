#include <cstring>
#include <stdio.h>
#include <iostream>


const int szinfo = 5; //макс размер инфы
const int sztab = 15; //размер таблицы
const int step = 4; //шаг перемешивани€


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
	Hash reorg(); //реорганизаци€
public:
	Hash(); //пустой конструктор дл€ инициализации экземпл€ров и массивов экземпл€ров класса(таблицы) по умолчанию;
	Hash(int count); //создание экземпл€ров класса(таблицы) с инициализацией заданным количеством элементов из массива ключей и информации;
	~Hash() {};// деструктор
	struct Item conItem(); //создание экземпл€ров структуры(элемента таблицы) с инициализацией начальным состо€нием по умолчанию;
	void printHash(); // вывод таблицы в выходной поток
	int find(int k); //поиск элемента таблицы по ключу(дл€ других функций)
	void add(int k, const char* inf); //добавление элемента в таблицу
	struct Item getinfo(int k);// выборка информации из таблицы по заданному ключу(дл€ диалоговой программы)
	void del(int k); //удаление элемента из таблицы(с отметкой в поле зан€тости) по ключу
};

