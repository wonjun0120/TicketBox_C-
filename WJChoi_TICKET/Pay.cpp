#include "Pay.h"
#include <iostream>
#include <string>

using namespace std;

int CardPay::charge(int amount) {	//3번. 카드 결제 선택시 실행
	int payAmount = 0;
	// 결제금액 = 티켓 가격 +  티켓 가격 * 모바일수수료 비율 
	payAmount = amount + (amount * interest);

	string cardNum;	//카드 번호
	string name;	//이름
	bool pass = true;	//반복문의 조건

	while (pass) {	//개인정보 입력
		cout << "\t[ 신용카드 결제 ]" << endl;
		cout << "카드 번호 입력(12자리수) :";
		cin >> cardNum;
		//입력받은 데이터가 정해진 기준을 충족시키는지 판단
		if (cardNum.length() == 12) {//입력받은 데이터가 정해진 기준을 충족시키는 경우
			pass = false;	//다시 반복X
		}
		else {//입력받은 데이터가 정해진 기준을 충족시키지 못할 때
			cout << "잘못입력하셨습니다. 다시 입력하시기 바랍니다." << endl;
			cin.ignore();	//입력버퍼를 비우는 용도
			continue;	//처음부터 진행
		}
		cout << "이름 :";
		cin >> name;
	}



	return payAmount;
}

int BankTransfer::charge(int amount) {	//2번. 은행 이체 선택시 실행
	int payAmount = 0;
	// 결제금액 = 티켓 가격 +  티켓 가격 * 모바일수수료 비율 
	payAmount = amount + (amount * interest);

	string accountNum;	//계좌 번호
	string name;	//이름
	bool pass = true;	//반복문의 조건

	while (pass) {	//개인정보 입력
		cout << "\t[ KPU 은행 결제 ]" << endl;
		cout << "은행 번호 입력(12자리수) :";
		cin >> accountNum;
		//입력받은 데이터가 정해진 기준을 충족시키는지 판단
		if (accountNum.length() == 12) {//입력받은 데이터가 정해진 기준을 충족시키는 경우
			pass = false;	//다시 반복X
		}
		else {//입력받은 데이터가 정해진 기준을 충족시키지 못할 때
			cout << "잘못입력하셨습니다. 다시 입력하시기 바랍니다." << endl;
			cin.ignore();	//입력버퍼를 비우는 용도
			continue;	//처음부터 진행
		}
		cout << "이름 :";
		cin >> name;
	}

	return payAmount;
}

int MobilePay::charge(int amount) {	//1번. 모바일 결제 선택시 실행
	int payAmount = 0;
	// 결제금액 = 티켓 가격 +  티켓 가격 * 모바일수수료 비율 
	payAmount = amount + (amount * interest);

	string phoneNum;	//핸드폰 번호
	string name;	//이름
	bool pass = true;	//반복문의 조건

	while (pass) {	//개인정보 입력
		cout << "\t[ 모바일 결제 ]" << endl;
		cout << "핸드폰 번호 입력(11자리수) :";
		cin >> phoneNum;
		//입력받은 데이터가 정해진 기준을 충족시키는지 판단
		if (phoneNum.length() == 11) {//입력받은 데이터가 정해진 기준을 충족시키는 경우
			pass = false;	//다시 반복X
		}
		else {//입력받은 데이터가 정해진 기준을 충족시키지 못할 때
			cout << "잘못입력하셨습니다. 다시 입력하시기 바랍니다." << endl;
			cin.ignore();	//입력버퍼를 비우는 용도
			continue;	//처음부터 진행
		}
		cout << "이름 :";
		cin >> name;
	}

	return payAmount;
}

