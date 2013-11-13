#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct Book  //���������
{
  string aname;  //������� ������
  string bname;  //�������� �����
  int year;      //��� �������
  int price;     //����
  int amount;    //����������
};


void printBook(Book *books, int n);  //����� ������ ���� �� �����
void totalAmount(Book *books, int n, int *ta);  //���������� ����� ��������� ������ �����
void infoBook(Book *books, int n, int *ta,int priceControl);  //���������� � ����� �������� ����

void main()
{
  int n;  //���������� ����
  int *ta;  //����� ���������
  int priceControl; //����������� ���� �����
  cout << " Enter books amount:   ";
  cin >> n;

  Book *books;  //��������� �� ���������
  books = new Book[n];
  ta = new int[n];   //������ ����� ���������

  ifstream in;  //����� ��� ������
  in.open("Books.txt");  //��������� ���� ��� ������

  for(int i = 0; i < n; i++)  //������ �� �����
  {
	in >> books[i].aname;
	in >> books[i].bname;
	in >> books[i].year;
	in >> books[i].price;
	in >> books[i].amount;
  }


  in.close();  //��������� �����

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

  delete[] books;  //����������� ������

  system("pause");
}


void printBook(Book *books, int n)  //����� ����������� ������ �� �����
{
  cout<<"     Author   "<<"      Name  "<<"  Year  "<<"  Price  "<<"  Amount  "<< endl;

  for(int i = 0; i < n; i++)
  {
	cout << setw(10) << books[i].aname << "   "<< setw(14) << books[i].bname << "  "<< setw(4) << books[i].year << "  "<< setw(4) << books[i].price << "  "<< setw(2) << books[i].amount << "  " << endl;
  }
  cout << endl;
}


void totalAmount(Book *books, int n, int *ta)  //���������� ����� ��������� ������ �����
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


void infoBook(Book *books, int n, int *ta, int priceControl)  //���������� � ����� �������� ����
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
bool flag;
flag=false;

for (i=0; i < n; i++){
	k=0;
	buf=books[i].aname;
	for (i=0; i < n; i++) {
	if (books[i].aname==buf && k<3) {
		k=k+1;
		if (k=3){ if (flag==false) 	{
			cout << "     Author   " << "      Name  " << endl;
			flag=true;			}
			cout << setw(10) << books[i].aname << endl;}
							}
if (flag==false) 	{
	cout << "    net avtora s kolihistvom knig bolie 3  " << endl;
					}
}
}


}
}

}
}
