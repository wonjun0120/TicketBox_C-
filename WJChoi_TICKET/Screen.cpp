#include "Screen.h"
#include "Pay.h"
#include "Statistis.h"
#include <iostream>
#include <string>

using namespace std;

Screen::Screen(string name, int price, int r, int c) {	//생성자
	strMovieName = name;	//스크린 상영중인 영화 제목
	nRowMax = r;	//좌석 행
	nColMax = c;	//좌석 열
	nTicketPrice = price;	//티켓 가격
	//2차원 배열 동적할당 - 스크린 좌석에 대한 티켓 배열
	pSeatArray = new Ticket*[nRowMax];
	for (int r = 0; r< nRowMax; r++) {
		pSeatArray[r] = new Ticket[nColMax];
	}
	//동적할당된 2차원 배열을 초기화, SEAT_EPT...=> Ticket헤더파일에 정의되어있음,'-'을 의미
	for (int i = 0; i< nRowMax; i++) {
		for (int j = 0; j< nColMax; j++) {
			pSeatArray[i][j].setCheck(SEAT_EMPTY_MARK);
		}
	}
	nCurrentReservedId = 99;	//발급된 마지막 예약번호, 예약번호는 100부터 시작, 초깃값은 99
}

Screen::~Screen() {	//소멸자
	//동적할당한 2차원배열을 해제
	for (int i = 0; i < nRowMax; i++) {
		delete[] pSeatArray[i];
	}
	delete[]pSeatArray;
}

void Screen::showSeatMap() {	//좌석 보여주기

	cout << "\t[ 좌석 예약 현황 ]" << endl;
	cout << "\t";
	for (int i = 0; i < nRowMax; i++) {	//열 번호 출력
		cout << "[" << i + 1 << "] ";
	}
	cout << endl;
	
	//좌석 출력
	for (int i = 0; i < nRowMax; i++) {
		cout << "[" << i + 1 << "]\t";	//행 번호 출력
		for (int j = 0; j < nColMax; j++) {
			cout << "[" << pSeatArray[i][j].getCheck() << "] ";	//객체 배열에 저장된 값을 출력
		}
		cout << endl;
	}
}


void Screen::reserveTicket() {	//좌석 예약하기
	bool pass = true;
	while (pass) {
		int row = 0, col = 0;

		cout << "  [ 좌석 예약 ]" << endl;
		cout << "좌석 행 번호 입력(1 - 10) :";
		cin >> row;
		row -= 1;	//프로그램에서 번호는 0부터 시작
		cout << "좌석 열 번호 입력(1 - 10) :";
		cin >> col;
		col -= 1;	//프로그램에서 번호는 0부터 시작

		if (pSeatArray[row][col].getCheck() == '-') {	//좌석이 예매되지 않은 경우
			nCurrentReservedId++;	//예약번호 1 증가

			pSeatArray[row][col].setReservedID(nCurrentReservedId);	//예약번호 셋팅
			pSeatArray[row][col].setSeat(row, col);	//지정한 좌석 셋팅
			pSeatArray[row][col].setCheck(SEAT_RESERVED_MARK);	//예약된 좌석으로 변경
			cout << "행[" << row + 1 << "] 열[" << col + 1 << "] " << nCurrentReservedId << " 예약 번호로 접수되었습니다." << endl;
			pass = false;
		}
		else //이미 좌석이 예매된 경우
		{
			int menu = 0;
			cout << "이 좌석은 이미 예약된 상태입니다." << endl;
			cout << "다시 입력은 1번, 이전 메뉴로 이동은 2번을 선택해주세요" << endl;
			cout << "메뉴 선택 :";
			cin >> menu;

			if (menu == 1) continue;
			else if (menu == 2) break;
			else cout << "잘못입력하셨습니다." << endl;

		}
	}
}
void Screen::Payment() {	//결제하기
	int reserveNum = 0;	//예약번호
	int payMethod = 0; //결제 수단
	int r = 0, c = 0;	//행번호, 열번호(컴퓨터 기준), 사용자기준 => +1
	
	//입력버퍼 확인**
	cout << "  [ 좌석 예약 결제 ]" << endl;
	cout << "예약 번호 입력 :";
	cin >> reserveNum;

	if ((reserveNum > nCurrentReservedId) || (reserveNum < 100)) {	//존재하지 않는 예약번호를 입력한 경우
		cout << "예약번호가 존재하지 않습니다." << endl;
		cout << "메뉴화면으로 넘어갑니다." << endl;
	}
	else {	//입력받은 예약번호가 존재하는 경우
			//예약번호에 맞는 좌석번호를 찾음
		for (int i = 0; i < nRowMax; i++) {
			for (int j = 0; j < nColMax; j++) {
				//해당하는 예약번호의 좌석을 찾은 경우
				if (pSeatArray[i][j].getReservedID() == reserveNum) {
					r = i; c = j;	//좌석번호 저장
				}
			}
		}

		cout << "========================================" << endl;
		cout << "     결제 방식 선택" << endl;
		cout << "========================================" << endl;
		cout << " 1. 모바일 결제" << endl;
		cout << " 2. 은행 이체 결제" << endl;
		cout << " 3. 카드 결제" << endl;
		cout << endl;

		cout << " 결제 방식(1-3) :";
		cin >> payMethod;

		switch (payMethod)	//선택한 결제 방식에 따라 코드 변경
		{
		case 1: {//모바일 결제
			MobilePay Mpay(MOBILE_PHONE_INTEREST_RATE);	//결제 수수료를 인자로 입력

			//좌석 정보 변경
			pSeatArray[r][c].setPayMethod(MOBILE_PHONE_PAYMENT);	//결제 수단 저장
			pSeatArray[r][c].setPayAmount(Mpay.charge(nTicketPrice));	//최종 결제금액 계산(MobilePay 클래스 사용)
			//개인정보 입력후 최종 결제금액 반환
			pSeatArray[r][c].setCheck(SEAT_COMPLETION_MARK);	//좌석 정보 변경=> 예약에서 결제 완료
			cout << "모바일 결제가 완료되었습니다. :" << pSeatArray[r][c].getPayAmount() << endl;	//최종 결제 금액 출력
			break;
		}

		case 2: {//은행 이체 결제
			BankTransfer Bpay(BANK_TRANSFER_INTEREST_RATE);	//결제 수수료를 인자로 입력

														//좌석 정보 변경
			pSeatArray[r][c].setPayMethod(BANK_TRANSFER_PAYMENT);	//결제 수단 저장
			pSeatArray[r][c].setPayAmount(Bpay.charge(nTicketPrice));	//최종 결제금액 계산(MobilePay 클래스 사용)
																		//개인정보 입력후 최종 결제금액 반환
			pSeatArray[r][c].setCheck(SEAT_COMPLETION_MARK);	//좌석 정보 변경=> 예약에서 결제 완료
			cout << "KPU 은행 결제가 완료되었습니다. :" << pSeatArray[r][c].getPayAmount() << endl;	//최종 결제 금액 출력
			break;
		}
		case 3: {//신용카드 결제
			CardPay Cpay(CREDIT_CARD_INTEREST_RATE);	//결제 수수료를 인자로 입력

															//좌석 정보 변경
			pSeatArray[r][c].setPayMethod(CREDIT_CARD_PAYMENT);	//결제 수단 저장
			pSeatArray[r][c].setPayAmount(Cpay.charge(nTicketPrice));	//최종 결제금액 계산(MobilePay 클래스 사용)
																		//개인정보 입력후 최종 결제금액 반환
			pSeatArray[r][c].setCheck(SEAT_COMPLETION_MARK);	//좌석 정보 변경=> 예약에서 결제 완료
			cout << "신용카드 결제가 완료되었습니다. :" << pSeatArray[r][c].getPayAmount() << endl;	//최종 결제 금액 출력
			break;
		}
		default: {
			cout << "잘못입력하셨습니다." << endl;
			cout << "메뉴화면으로 넘어갑니다." << endl;
			break;
		}
		}
	}
}

//가상함수로 정의된 부분, 사용자가 선택한 상영관에 따라서 영화의 이름이 출력되어야 함(업캐스팅)
void Screen::showMovieMenu() {

	//메뉴 출력
	cout << "========================================" << endl;
	cout << "     영화 메뉴 - " << strMovieName << endl;
	cout << "========================================" << endl;
	cout << " 1. 상영 영화 정보" << endl;
	cout << " 2. 좌석 예약 현황" << endl;
	cout << " 3. 좌석 예약 하기" << endl;
	cout << " 4. 좌석 결제 하기" << endl;
	cout << " 5. 메인 메뉴 이동" << endl;
	cout << endl;

}

//가상함수로 정의된 부분 해당하는 클래스에 맞게 오버라이딩
void FamillyScreen::showMovieInfo() {	
	cout << "========================================" << endl;
	cout << "     [ "<<strMovieName<<" ]"<< endl;
	cout << "========================================" << endl;
	cout << "  영화관 : 가족영화 1관" << endl;
	cout << "  주인공 : 로버트 다우니 주니어" << endl;
	cout << "  줄거리 : 인피니티 워 이후 절반만 살아남은 지구 ..." << endl;
	cout << "  가격 : "<< nTicketPrice<< endl;	
	cout << endl;
}

void AdultScreen::showMovieInfo() {
	cout << "========================================" << endl;
	cout << "     [ " << strMovieName << " ]" << endl;
	cout << "========================================" << endl;
	cout << "  영화관 : 성인영화 2관" << endl;
	cout << "  주인공 : 마동석, 김무열" << endl;
	cout << "  줄거리 : 연쇄살인마의 표적이 되었다 살아난 조직 보스 ..." << endl;
	cout << "  가격 : " << nTicketPrice << endl;
	cout << endl;
}

void PremiumScreen::showMovieInfo() {
	cout << "========================================" << endl;
	cout << "     [ " << strMovieName << " ]" << endl;
	cout << "========================================" << endl;
	cout << "  영화관 : 프리미엄영화 3관" << endl;
	cout << "  주인공 : 비고 모텐슨, 마샬셜라 알리" << endl;
	cout << "  줄거리 : 취향, 성격도 다른 두 남자의 특별한 우정이 시작 ..." << endl;
	cout << "  가격 : " << nTicketPrice << endl;
}


//깊은 복사를 위한 복사생성자
FamillyScreen::FamillyScreen(FamillyScreen& cp):Screen(cp.strMovieName,cp.nTicketPrice,cp.nRowMax,cp.nColMax) {
	pSeatArray = new Ticket*[nRowMax];
	for (int r = 0; r < nRowMax; r++) {
		pSeatArray[r] = new Ticket[nColMax];
	}

	for (int i = 0; i< nRowMax; i++) { 
		for (int j = 0; j< nColMax; j++) { 
			pSeatArray[i][j] = cp.pSeatArray[i][j]; 
		} 
	}

}

AdultScreen::AdultScreen(AdultScreen& cp) :Screen(cp.strMovieName, cp.nTicketPrice, cp.nRowMax, cp.nColMax) {
	pSeatArray = new Ticket*[nRowMax];
	for (int r = 0; r < nRowMax; r++) {
		pSeatArray[r] = new Ticket[nColMax];
	}

	for (int i = 0; i< nRowMax; i++) {
		for (int j = 0; j< nColMax; j++) {
			pSeatArray[i][j] = cp.pSeatArray[i][j];
		}
	}

}

PremiumScreen::PremiumScreen(PremiumScreen& cp) :Screen(cp.strMovieName, cp.nTicketPrice, cp.nRowMax, cp.nColMax) {
	pSeatArray = new Ticket*[nRowMax];
	for (int r = 0; r < nRowMax; r++) {
		pSeatArray[r] = new Ticket[nColMax];
	}

	for (int i = 0; i< nRowMax; i++) {
		for (int j = 0; j< nColMax; j++) {
			pSeatArray[i][j] = cp.pSeatArray[i][j];
		}
	}

}


Management::Management(FamillyScreen Fs, AdultScreen As, PremiumScreen Ps) : Screen("관리자", 0, 0, 0) {
	r1 = Fs.getRow(); c1 = Fs.getCol();
	a1 = new Ticket*[r1];
	for (int i = 0; i < r1; i++) {
		a1[i] = new Ticket[c1];
	}
	for (int i = 0; i < r1; i++) {
		for (int j = 0; j < c1; j++) {
			a1[i][j] = Fs.getArray()[i][j];
		}
	}

	r2 = As.getRow(); c2 = As.getCol();
	a2 = new Ticket*[r2];
	for (int i = 0; i < r2; i++) {
	a2[i] = new Ticket[c2];
	}
	for (int i = 0; i < r2; i++) {
		for (int j = 0; j < c2; j++) {
			a2[i][j] = As.getArray()[i][j];
		}
	}

	r3 = Ps.getRow(); c3 = Ps.getCol();
	a3 = new Ticket*[r3];
	for (int i = 0; i < r3; i++) {
		a3[i] = new Ticket[c3];
	}
	for (int i = 0; i < r3; i++) {
		for (int j = 0; j < c3; j++) {
			a3[i][j] = Ps.getArray()[i][j];
		}
	}
}
void Management::Initialize() {	//통계 객체 생성
	f = new FamilyStatistics(a1, r1, c1);
	a = new AdultStatistics(a2, r2, c2);
	p = new PremiumStatistics(a3, r3, c3);
}

Management::~Management() {	//소멸자
					//동적할당한 2차원배열을 해제
	for (int i = 0; i < nRowMax; i++) {
		delete[] a1[i];
		delete[] a2[i];
		delete[] a3[i];
	}
	delete[]a1;	delete[]a2;	delete[]a3;
}

void Management::showMovieMenu() {
	int n = 0;
	bool pass = true;

	Initialize();

	while (pass) {
		cout << "========================================" << endl;
		cout << "     통계 메뉴 - " << endl;
		cout << "========================================" << endl;
		cout << " 1. 가족영화 1관" << endl;
		cout << " 2. 성인영화 2관" << endl;
		cout << " 3. 프리미엄영화 3관" << endl;
		cout << " 5. 종료" << endl;
		cout << "메뉴를 선택하세요 : " << endl;
		cin >> n; cout << endl;

		switch (n)
		{
		case 1:	//가족영화 1관
			f->showScreenInfo();
			break;
		case 2:	//성인영화 2관
			a->showScreenInfo();
			break;
		case 3:	//프리미엄 영화 3관
			p->showScreenInfo();
			break;
		case 5:	//종료
			cout << "프로그램을 종료합니다." << endl;
			pass = false;
			exit(0);	//프로그램 종료
							//return;
		default:
			cout << "잘못입력하셨습니다." << endl;
			break;
		}
	}


}
