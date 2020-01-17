#ifndef SCREEN_H 
#define SCREEN_H 
#include "Ticket.h" 
#include "Statistis.h"
#include <iostream>
#include<string>
using namespace std; 

//class FamilyStatistics;
//class AdultStatistics;
//class PremiumStatistics;

class Screen { 
protected:
	int nTicketPrice; // Ƽ�� ���� 
	int nRowMax, nColMax; // �¼� ��� �� �ִ� ��
	int nCurrentReservedId; // �߱޵� ������ ���� ��ȣ
	Ticket ** pSeatArray; // ��ũ�� �¼��� ���� Ƽ�� �迭 
	string strMovieName; // ��ũ�� ������ ��ȭ ����
public: 
	Screen(string name, int price, int r, int c);
	~Screen(); 
	void showSeatMap(); // �¼� ���� ���� ������ ����
	virtual void showMovieMenu();    // ��ȭ ���� �޴�
	//��ĳ���� �� �� �������� �Ǿ� ������ �����Ƿ� �����Լ� ���?***
	virtual void showMovieInfo() = 0; // ��ȭ �Ұ� ���� 

	void reserveTicket();      // �¼� �����ϱ�

	int getTicketPrice() { return nTicketPrice; }	//Ƽ�ϰ��� ��ȯ 
	void Payment();     // �����ϱ�

	//��� ���� �ʿ��� �ڷ�� ��ȯ
	Ticket ** getArray() { return pSeatArray; }
	int getCol() { return nColMax; }
	int getRow() { return nRowMax; }
};

//�Ʒ� Ŭ�������� �����ڴ� �ݷ� �ʱ�ȭ�� �̿��ϰ� �ִ�. 
class FamillyScreen : public Screen {
public: 
	FamillyScreen(string name, int price, int r, int c) : Screen( name, price, r, c) {} 
	void showMovieInfo(); 
	FamillyScreen(FamillyScreen & cp);
}; 

class AdultScreen : public Screen {
public:
	AdultScreen(string name, int price, int r, int c) : Screen(name, price, r, c) {}
	void showMovieInfo(); 
	AdultScreen(AdultScreen& cp);
}; 

class PremiumScreen : public Screen {
public: 
	PremiumScreen(string name, int price, int r, int c) : Screen(name, price, r, c) {}
	void showMovieInfo();
	PremiumScreen(PremiumScreen& cp);
}; 

//������ ��� ȭ��
class Management : public Screen {
	Ticket ** a1, **a2, **a3;
	int r1, r2, r3;
	int c1, c2, c3;
	FamilyStatistics *f;
	AdultStatistics *a;
	PremiumStatistics *p;
public:
	Management(FamillyScreen Fs, AdultScreen As, PremiumScreen Ps);
	~Management();
	void Initialize();
	void showMovieInfo() { cout << "������" << endl; }
	void showMovieMenu();
};
#endif