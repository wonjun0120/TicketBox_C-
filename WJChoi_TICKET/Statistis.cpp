#include "Statistis.h"
#include <iostream>
#include <string>
#include "Screen.h"
#include "Pay.h"

using namespace std;

Statistics::Statistics(Ticket ** pTicketInfo, int r, int c) {

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {

			//구매자수 계산
			if (pTicketInfo[i][j].getPayMethod() == MOBILE_PHONE_PAYMENT) {
				MobileBuyer+=1;	//모바일 구매자수 1 증가
				totalTicketPrice += pTicketInfo[i][j].getPayAmount();
			}

			else if (pTicketInfo[i][j].getPayMethod() == BANK_TRANSFER_PAYMENT) {
				BankBuyer+=1;	//계좌이체 구매자수 1 증가
				totalTicketPrice += pTicketInfo[i][j].getPayAmount();
			}
			else if (pTicketInfo[i][j].getPayMethod() == CREDIT_CARD_PAYMENT) {
				CreditBuyer+=1;	//신용카드 구매자수 1 증가
				totalTicketPrice += pTicketInfo[i][j].getPayAmount();
			}


		}
	}
}

void FamilyStatistics::showScreenInfo() {
	//메뉴 출력
	cout << "========================================" << endl;
	cout << "     통계 메뉴 FamilyScreen " << endl;
	cout << "========================================" << endl;
	cout << " ===결제 수단별 이용자 수 === " << endl;
	cout << " 모바일   : " << getMB() << endl;
	cout << " 계좌이체 : " << getBB() << endl;
	cout << " 신용카드 : " << getCB() << endl;
	cout << endl;
	cout << " 티켓 판매량 : " << getTB();
	cout << "\t총 매출 : " << getTP() << endl;
	cout << endl;
}

void AdultStatistics::showScreenInfo() {
	//메뉴 출력
	cout << "========================================" << endl;
	cout << "     통계 메뉴 AdultScreen " << endl;
	cout << "========================================" << endl;
	cout << " ===결제 수단별 이용자 수 === " << endl;
	cout << " 모바일   : " << getMB() << endl;
	cout << " 계좌이체 : " << getBB() << endl;
	cout << " 신용카드 : " << getCB() << endl;
	cout << endl;
	cout << " 티켓 판매량 : " << getTB();
	cout << "\t총 매출 : " << getTP() << endl;
	cout << endl;
}

void PremiumStatistics::showScreenInfo() {
	//메뉴 출력
	cout << "========================================" << endl;
	cout << "     통계 메뉴 PremiumScreen " << endl;
	cout << "========================================" << endl;
	cout << " ===결제 수단별 이용자 수 === " << endl;
	cout << " 모바일   : " << getMB() << endl;
	cout << " 계좌이체 : " << getBB() << endl;
	cout << " 신용카드 : " << getCB() << endl;
	cout << endl;
	cout << " 티켓 판매량 : " << getTB();
	cout << "\t총 매출 : " << getTP() << endl;
	cout << endl;
}
