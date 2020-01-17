#ifndef TICKETBOX_H
#define TICKETBOX_H
#define TICKETBOX_MANAGER_PWD "admin"	//관리자 모드 비밀번호
#define MAX_TRY 5
#include "stddef.h"	//"식별자 NULL이가 정의되어있지 않습니다." 오류 해결
//헤더파일 순환참조로 인해 발생하는 오류를 막기위해 클래스를 상단에서 선언
class Screen;
class FamillyScreen;
class AdultScreen;
class PremiumScreen;
class Management;

class TicketBox {
public:
	virtual Screen * selectMenu() { return NULL; } // 상영관 선택 메뉴 ( 1관, 2관, 3관) 
	void Initialize() {}
};

class KpuTicketBox : public TicketBox {

	FamillyScreen * pFamillyScreen; 
	AdultScreen * pAdultScreen; 
	PremiumScreen * pPremiumScreen;
	Management * pManagement;
public:
	KpuTicketBox(); 
	~KpuTicketBox(); 
	Screen * selectMenu(); 
	void Initialize();
	void manageInitialize();

};

#endif