#include "TicketBox.h"
#include "Screen.h"
#include <iostream>
#include <string>

using namespace std;

KpuTicketBox::KpuTicketBox() {

}

KpuTicketBox::~KpuTicketBox() {
	//동적으로 생성한 객체들을 해제
	delete pFamillyScreen;
	delete pAdultScreen;
	delete pPremiumScreen;
	delete pManagement;
}

Screen * KpuTicketBox::selectMenu() {	//티켓박스 메뉴선택
	int num = 0;	//사용자 선택 메뉴 번호
	bool pass = true;
	string pwd;
	int trynum = 0;

	//상영관 메인 메뉴 출력
	cout << "=========================" << endl;
	cout << "     상영관 메인 메뉴" << endl;
	cout << "=========================" << endl;
	cout << " 1. 가족영화 1관" << endl;
	cout << " 2. 성인영화 2관" << endl;
	cout << " 3. 프리미엄영화 3관" << endl;
	cout << " 9. 통계 관리" << endl;
	cout << " \n선택(1-3,9) 그외 종료 : ";
	cin >> num; 
	cout << endl;	//입력받고 바로 엔터 출력

	switch (num)	//해당하는 영화관의 번호를 입력받은 뒤 그 영화관 객체를 반환
	{
	case 1:
		return pFamillyScreen;
	case 2:
		return pAdultScreen;
	case 3:
		return pPremiumScreen;
	case 9:	//관리자 통계
		cout << "통계관리 기능을 선택하셨습니다." << endl;
		cout << "해당 기능은 관리자만 사용이 가능합니다." << endl;
		cout << "관리자 암호를 입력해 주십시오" << endl;
		while (pass) {
			cout << "암호 :";
			cin >> pwd;
			if (pwd.compare(TICKETBOX_MANAGER_PWD) == 0) {	//관리자 암호가 맞는 경우
				pass = false;	//반복 중지
								//관리자 모드 실행

				manageInitialize();
				return pManagement;
				//return 0;	
			}
			else if (trynum == MAX_TRY) {
				cout << MAX_TRY << "회 이상 관리자 암호를 잘못 입력하셨습니다." << endl;
				cout << "프로그램 자동 종료합니다" << endl;
				return 0;
			}
			else {
				trynum++;	//입력 횟수 증가
				cout << "잘못 입력하셨습니다." << endl;
				cout << MAX_TRY << "회 잘못 입력시 프로그램은 자동 종료됩니다." << endl;
				cout << MAX_TRY - trynum << "회 남았습니다." << endl;
			}
		}
	default:
		cout << "프로그램을 종료합니다." << endl;
		return 0;
	}
}

// 스크린 객체 생성 
void KpuTicketBox::Initialize() { 
	// Screen(영화제목, 티켓가격, 좌석(nRowMax), 좌석(nColMax)) 
	pFamillyScreen = new FamillyScreen("어벤저스", 8000, 10, 10); 
	pAdultScreen = new AdultScreen("악인전", 10000, 10, 10); 
	pPremiumScreen = new PremiumScreen("그린북", 30000, 5, 5);
}

void KpuTicketBox::manageInitialize() {	//통계
	
	FamillyScreen cpf(*pFamillyScreen);
	AdultScreen cpa(*pAdultScreen);
	PremiumScreen cpp(*pPremiumScreen);

	pManagement = new Management(cpf, cpa, cpp);
}