#include <iostream> //cout i�in
using namespace std;

int kuyruk[10];//100 elemanl� kuyruk olu�turduk
int bas = -1, son = -1, sayac = 0;
bool isFull() {
	return sayac == 10;
}
bool isEmpty() {
	return sayac == 0;
}
void push(int veri) {//sona veri ekle
	if (isFull())//kuyruk doluysa	
		cout << "Kuyruk dolu." << endl;
	else
	{
		if (bas == -1)//kuyruk bo�sa
			bas = 0;//art�k bo� de�il
		son++;
		sayac++;
		if (son == 10) 
			son = 0;
		kuyruk[son] = veri;
		cout << "Veri Eklendi." << endl;
	}
}
void pop() {//ba�tan veri sil
	if (isEmpty())//kuyruk bo� mu
		cout << "Kuyruk bos." << endl;
	else {
		bas++;
		sayac--;
		if (bas == 10)
			bas = 0;//kuyru�un ba��n�n dizinin d���na ��kmamas� i�in kontrol.kuyru�un ba�� indis olarak en fazla 9 de�erini alabilir �u anki durumda. 
		cout << "Kuyrugun Basi Silindi." << endl;
	}
}
int front() {
	if (bas == -1 || bas > son)
		cout << "Kuyruk Bos." << endl;
	else
		return kuyruk[bas];
}
int back() {
	if (bas == -1 || bas > son)
		cout << "Kuyruk Bos." << endl;
	else
		return kuyruk[son];
}
//bu �zelli�imizden feragat ediyoruz
/* void display() {
	if (isEmpty())
		cout << "Kuyruk Bos." << endl;
	else
	{
		for (int i = bas;i <= son;i++)
			cout << kuyruk[i] << " ";
		cout << endl;
	}
}*/
int main() {
	int secim, veri;
	cout << "1) Kuyruga Ekleme Yap" << endl;
	cout << "2) Kuyrugun Basini Sil" << endl;
	//cout << "3) Kuyruktaki Verileri Yazdir" << endl;
	cout << "3) Cikis" << endl;
	do {
		cout << "Seciminizi Girin : ";
		cin >> secim;
		switch (secim)
		{
		case 1:cout << "Eklemek Istediginiz Sayiyi Gir : ";
			cin >> veri;
			push(veri);
			cout << endl;
			break;
		case 2:pop();
			break;
		/*case 3:display();
			break;*/
		case 3:cout << "Cikis Yapildi." << endl;
			break;

		default:cout << "Gecersiz Secim." << endl;
		}
	} while (secim != 3);
	return 0;
}