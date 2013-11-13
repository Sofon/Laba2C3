#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct Book  //Структура
{
  string aname;  //Фамилия автора
  string bname;  //Название книги
  int year;      //Год издания
  int price;     //Цена
  int amount;    //Количество
};


void printBook(Book *books, int n);  //Вывод список книг на экран
void totalAmount(Book *books, int n, int *ta);  //Нахождение общей стоимости каждой книги
void infoBook(Book *books, int n, int *ta,int priceControl);  //Информация о книге заданной цены

void main()
{
  int n;  //Количество книг
  int *ta;  //Общая стоимость
  int priceControl; //Контрольная цена книги
  cout << " Enter books amount:   ";
  cin >> n;

  Book *books;  //Указатель на структуру
  books = new Book[n];
  ta = new int[n];   //Массив общей стоимости

  ifstream in;  //Поток для чтения
  in.open("Books.txt");  //Открываем файл для чтения

  for(int i = 0; i < n; i++)  //Читаем из фалйа
  {
	in >> books[i].aname;
	in >> books[i].bname;
	in >> books[i].year;
	in >> books[i].price;
	in >> books[i].amount;
  }


  in.close();  //Закрываем поток

  cout << "List of books:" << endl;
  printBook(books, n);
  cout << endl;

  cout << "Total amount:" << endl;
  totalAmount(books, n, ta);
  cout << endl;

  cout << "Enter control price:" << endl;
  cin >> priceControl;
  cout << "Control price book info:";
  infoBook(books, n, ta,priceControl);

  delete[] books;  //Освобождаем память

  system("pause");
}


void printBook(Book *books, int n)  //Вывод результатов тестов на экран
{
  cout<<"     Author   "<<"      Name  "<<"  Year  "<<"  Price  "<<"  Amount  "<< endl;

  for(int i = 0; i < n; i++)
  {
	cout << setw(10) << books[i].aname << "   "<< setw(14) << books[i].bname << "  "<< setw(4) << books[i].year << "  "<< setw(4) << books[i].price << "  "<< setw(2) << books[i].amount << "  " << endl;
  }
  cout << endl;
}


void totalAmount(Book *books, int n, int *ta)  //Нахождение общей стоимости каждой книги
{
  for(int i = 0; i < n; i++)
  {
	ta[i] = (books[i].price * books[i].amount);
  }
  cout<<"      Name  "<<"  Total price  "<< endl;
  for(int i=0;i<n;i++)
  {
	cout << setw(14) << books[i].bname << setw(6)<< ta[i] << endl;
  }
}


void infoBook(Book *books, int n, int *ta, int priceControl)  //Информация о книге заданной цены
{
  cout << "     Author   " << "      Name  " << "  Year  " << "  Amount  " << "   Total price  " << endl;
  for (int i; i < n; i++)
  {
	if (priceControl == books[i].price)
	{
	   cout << setw(10) << books[i].aname << "   "<< setw(14) << books[i].bname << "  "<< setw(4) << books[i].year << "  " << setw(2) << books[i].amount << "  " << setw(6) << ta[i] << "  " << endl;
	}
  }
}

Void zA(Book *books, int n)
{int i,k;
string buf;
cout << "     Author   " << "      Name  " << endl;
for (i=0; i < n; i++){
k=0
buf=books[i].aname
for (i=0; i < n; i++) {
if (books[i].aname==buf && k<3) {
k=k+1;
if (k=3) {
cout << setw(10) << books[i].aname << endl}
}

}
}


}
}

}
}
