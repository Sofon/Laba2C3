#include <vcl.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct PRICE //���������
{
 string tavar; //�������� ������
 string magazin;  //�������� ������
 int zen;  //������ ���������� � ������
};



void sortTavar(PRICE *PRICEC, int n);    //���������� �� �������
void zadaniTavar(PRICE *PRICEC, int n,string zadanniitovar);// ����� � ������� �����

void main()
{

 int n;
 string zadanniitovar;
 cout<<" Kol posojirov :   ";
 cin>>n;
 cout<<endl;
 cout<<" nyznii tavar : ";
 cin>>zadanniitovar;
 cout<<endl;
 if(n<=0)  //��������� ������ ��� ��������
 {
  cout<<" kol ili ves < 0."<<endl;
  system("pause");
  return;
 }

 PRICE *PRICEC;  //��������� �� ���������
 PRICEC=new PRICE[n];


 ifstream in;  //����� ��� ������
 in.open("PRICEC.txt",ios::in);  //��������� ���� ��� ������

 if(in==NULL)  //��������� ������ ��� ��������
 {
  cout<<" Ne udalos' otkryt' fajl."<<endl;
  system("pause");
  return;
 }

 for(int i=0;i<n;i++)  //������ �� �����
 {
  in>>PRICEC[i].tavar;
  in>>PRICEC[i].magazin;
  in>>PRICEC[i].zen;}


 in.close();  //��������� �����
 cout<<endl;
 cout<<" Sortirovka po Alfavitu:"<<endl;
 sortTavar(PRICEC,n);
 cout<<" Ves raven zadannomu:"<<endl;
 zadaniTavar(PRICEC,n,zadanniitovar);
 cout<<endl;

 delete[] PRICEC;  //����������� ������

 system("pause");
}



void sortTavar(PRICE *PRICEC, int n)  //���������� �� �������
{
 string min;
 PRICE Buf;
 int minI;

 for(int i=0;i<n;i++)
 {
  min=PRICEC[i].tavar;
  minI=i;
  for(int j=i;j<n;j++)
  {
   if(strcmp(PRICEC[j].tavar.c_str(),min.c_str())<0)
   {
	min=PRICEC[j].tavar;
	minI=j;
   }
  }
  Buf=PRICEC[i];
  PRICEC[i]=PRICEC[minI];
  PRICEC[minI]=Buf;
 }
 cout<<"---------------------------------------------------------------------------------"<<endl;
 cout<<"    tavar   "<<"  magazin  "<<"  zen  "<<endl;
 cout<<"---------------------------------------------------------------------------------"<<endl;
 for(int i=0;i<n;i++)
 {
  cout<<setw(11)<<PRICEC[i].tavar<<"   ";
  cout<<setw(11)<<PRICEC[i].magazin<<"   ";
  cout<<setw(11)<<PRICEC[i].zen<<"   ";
  }
  cout<<endl;
}




void zadaniiTavar(PRICE *PRICEC, int n,string zadanniitovar)
{
 int i;
 bool flag;
 for(i=0;i<n;i++)
		 { flag=false;
		   if ((PRICEC[i].tavar==zadanniitovar) || (flag=false)) {
			 flag=true;
		   }
		 }
		if (flag=false) {

		}
 for(i=0;i<n;i++)
 {
  if (PRICEC[i].tavar==zadanniitovar) 	{
 cout<<"--------------------------------"<<endl;
 cout<<"    tavar   "<<"  magazin  "<<"   zen   "<<endl;
 cout<<"--------------------------------"<<endl;
 cout<<setw(11)<<PRICEC[i].tavar<<setw(11)<<PRICEC[i].magazin<<setw(11)<<PRICEC[i].zen<<endl;

						}
 }



}


