#include <iostream> //cout için
using namespace std;

int kuyruk[10];//100 elemanlý kuyruk oluþturduk
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
		if (bas == -1)//kuyruk boþsa
			bas = 0;//artýk boþ deðil
		son++;
		sayac++;
		if (son == 10) 
			son = 0;
		kuyruk[son] = veri;
		cout << "Veri Eklendi." << endl;
	}
}
void pop() {//baþtan veri sil
	if (isEmpty())//kuyruk boþ mu
		cout << "Kuyruk bos." << endl;
	else {
		bas++;
		sayac--;
		if (bas == 10)
			bas = 0;//kuyruðun baþýnýn dizinin dýþýna çýkmamasý için kontrol.kuyruðun baþý indis olarak en fazla 9 deðerini alabilir þu anki durumda. 
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
//bu özelliðimizden feragat ediyoruz
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