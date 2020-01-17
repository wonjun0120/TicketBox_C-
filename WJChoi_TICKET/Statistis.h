#ifndef STATISTIS_H 
#define STATISTIS_H
#include "stddef.h"	//"식별자 NULL이가 정의되어있지 않습니다." 오류 해결
#include "Ticket.h"

class Statistics {

	int totalTicketPrice = 0;	//티켓 결제 총액 
	int MobileBuyer = 0;	//모바일 구매자 숫자
	int BankBuyer = 0;	//은행 구매자 숫자
	int CreditBuyer = 0;	//신용카드 구매자 숫자
public:
	Statistics(Ticket ** pTicketInfo, int r, int c);	//생성자, 해당하는 스크린의 객체를 매개변수로 받음
	virtual void showScreenInfo() = 0; //스크린별 메뉴 출력, 가상함수 사용
	int getMB() { return MobileBuyer; }
	int getBB() { return BankBuyer; }
	int getCB() { return CreditBuyer; }
	int getTB() { return MobileBuyer + BankBuyer + CreditBuyer; }
	int getTP() { return totalTicketPrice; }
};

class FamilyStatistics :public Statistics {	//가족 스크린 관련 클래스
public:
	FamilyStatistics(Ticket ** pTicketInfo, int r, int c) :Statistics(pTicketInfo, r, c) {}
	void showScreenInfo();
};
class AdultStatistics :public Statistics {	//성인 스크린 관련 클래스
	
public:
	AdultStatistics(Ticket ** pTicketInfo, int r, int c) :Statistics(pTicketInfo, r, c) {};
	void showScreenInfo();
};
class PremiumStatistics :public Statistics {	//프리미엄 스크린 관련 클래스
	
public:
	PremiumStatistics(Ticket ** pTicketInfo, int r, int c) :Statistics(pTicketInfo, r, c) {};
	void showScreenInfo();
};
#endif

/*
통계관리에 필요한 기능
1. 관리자 인증처리-> 관리자 암호가 티켓박스 상단에 정의되어 있음
티켓박스 클래스에서 관리자 확인 멤버 작성
2. 관리자 인증 후 실행
3. 스크린 관 별 티켓 결제 금액 총액 및 티켓 판매량
스크린 관 별 예약번호를 통해 객체에 접근
=> 결제 금액을 합산
=> 티켓 판매량 확인



-----------------------------------
메뉴 기능
- 메뉴를 표시
- 스크린 관 별 선택지 제공
- 스크린 선택 후 티켓 결제 금액및 총액 등 열람할 정보 접근

*/