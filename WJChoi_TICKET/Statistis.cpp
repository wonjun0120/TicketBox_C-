#include "Statistis.h"
#include <iostream>
#include <string>
#include "Screen.h"
#include "Pay.h"

using namespace std;

Statistics::Statistics(Ticket ** pTicketInfo, int r, int c) {

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {

			//�����ڼ� ���
			if (pTicketInfo[i][j].getPayMethod() == MOBILE_PHONE_PAYMENT) {
				MobileBuyer+=1;	//����� �����ڼ� 1 ����
				totalTicketPrice += pTicketInfo[i][j].getPayAmount();
			}

			else if (pTicketInfo[i][j].getPayMethod() == BANK_TRANSFER_PAYMENT) {
				BankBuyer+=1;	//������ü �����ڼ� 1 ����
				totalTicketPrice += pTicketInfo[i][j].getPayAmount();
			}
			else if (pTicketInfo[i][j].getPayMethod() == CREDIT_CARD_PAYMENT) {
				CreditBuyer+=1;	//�ſ�ī�� �����ڼ� 1 ����
				totalTicketPrice += pTicketInfo[i][j].getPayAmount();
			}


		}
	}
}

void FamilyStatistics::showScreenInfo() {
	//�޴� ���
	cout << "========================================" << endl;
	cout << "     ��� �޴� FamilyScreen " << endl;
	cout << "========================================" << endl;
	cout << " ===���� ���ܺ� �̿��� �� === " << endl;
	cout << " �����   : " << getMB() << endl;
	cout << " ������ü : " << getBB() << endl;
	cout << " �ſ�ī�� : " << getCB() << endl;
	cout << endl;
	cout << " Ƽ�� �Ǹŷ� : " << getTB();
	cout << "\t�� ���� : " << getTP() << endl;
	cout << endl;
}

void AdultStatistics::showScreenInfo() {
	//�޴� ���
	cout << "========================================" << endl;
	cout << "     ��� �޴� AdultScreen " << endl;
	cout << "========================================" << endl;
	cout << " ===���� ���ܺ� �̿��� �� === " << endl;
	cout << " �����   : " << getMB() << endl;
	cout << " ������ü : " << getBB() << endl;
	cout << " �ſ�ī�� : " << getCB() << endl;
	cout << endl;
	cout << " Ƽ�� �Ǹŷ� : " << getTB();
	cout << "\t�� ���� : " << getTP() << endl;
	cout << endl;
}

void PremiumStatistics::showScreenInfo() {
	//�޴� ���
	cout << "========================================" << endl;
	cout << "     ��� �޴� PremiumScreen " << endl;
	cout << "========================================" << endl;
	cout << " ===���� ���ܺ� �̿��� �� === " << endl;
	cout << " �����   : " << getMB() << endl;
	cout << " ������ü : " << getBB() << endl;
	cout << " �ſ�ī�� : " << getCB() << endl;
	cout << endl;
	cout << " Ƽ�� �Ǹŷ� : " << getTB();
	cout << "\t�� ���� : " << getTP() << endl;
	cout << endl;
}
