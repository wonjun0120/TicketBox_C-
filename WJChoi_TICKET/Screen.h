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
	int nTicketPrice; // 티켓 가격 
	int nRowMax, nColMax; // 좌석 행과 열 최대 값
	int nCurrentReservedId; // 발급된 마지막 예약 번호
	Ticket ** pSeatArray; // 스크린 좌석에 대한 티켓 배열 
	string strMovieName; // 스크린 상영중인 영화 제목
public: 
	Screen(string name, int price, int r, int c);
	~Screen(); 
	void showSeatMap(); // 좌석 예약 여부 맵으로 보기
	virtual void showMovieMenu();    // 영화 예매 메뉴
	//업캐스팅 된 후 컴파일이 되야 제목이 나오므로 가상함수 사용?***
	virtual void showMovieInfo() = 0; // 영화 소개 정보 

	void reserveTicket();      // 좌석 예약하기

	int getTicketPrice() { return nTicketPrice; }	//티켓가격 반환 
	void Payment();     // 결제하기

	//통계 계산시 필요한 자료들 반환
	Ticket ** getArray() { return pSeatArray; }
	int getCol() { return nColMax; }
	int getRow() { return nRowMax; }
};

//아래 클래스들의 생성자는 콜론 초기화를 이용하고 있다. 
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

//관리자 통계 화면
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
	void showMovieInfo() { cout << "관리자" << endl; }
	void showMovieMenu();
};
#endif