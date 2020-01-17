#include <iostream>
#include <string>
#include"Pay.h"
#include"Screen.h"
#include"Statistis.h"
#include"Ticket.h"
#include"TicketBox.h"

using namespace std;

int main() {
	KpuTicketBox tBox;	//티켓박스 객체 생성
	Screen * screen = NULL;		//현재 스크린객체 주소가 가리키고 있는 객체 없음
	bool bScreenMenu = true;	//boolScreenMenu=> 스크린 메뉴 실행 여부
	int select = 0;		//사용자 선택
	
	tBox.Initialize();	//초기화
	while (1) {	//무한 반복문
		if (bScreenMenu) {	//bScreenMenu가 참일때 실행
			screen = tBox.selectMenu();	//현재 스크린은 티켓박스 객체에서 메뉴를 선택한뒤 반환된 값(업캐스팅)
			bScreenMenu = false;	//스크린 메뉴 다시 실행하지X
			if (!screen) return 0;	//만약 스크린에 값이 없을 경우 종료
		} 
		screen->showMovieMenu();	//스크린 객체의 영화 메뉴를 보여주는 멤버함수 실행

		cout << "메뉴를 선택하세요: ";
		cin >> select; cout << endl; 
		switch (select) {
		case 1: // 영화 정보 
			screen->showMovieInfo(); 
			break; 
		case 2: // 좌석 현황 
			screen->showSeatMap();
			break; 
		case 3:	//좌석 예매
			screen->reserveTicket();
			break;
		case 4:	//좌석 결제
			screen->Payment();
			break;
		case 5: // 스크린 메인 메뉴
			bScreenMenu = true;
			break; 
		default:
			cout << "잘못입력하셨습니다. 다시 입력하시기 바랍니다." << endl;
			break;
		} 
	} 
	return 0;
}

