#ifndef STATISTIS_H 
#define STATISTIS_H
#include "stddef.h"	//"�ĺ��� NULL�̰� ���ǵǾ����� �ʽ��ϴ�." ���� �ذ�
#include "Ticket.h"

class Statistics {

	int totalTicketPrice = 0;	//Ƽ�� ���� �Ѿ� 
	int MobileBuyer = 0;	//����� ������ ����
	int BankBuyer = 0;	//���� ������ ����
	int CreditBuyer = 0;	//�ſ�ī�� ������ ����
public:
	Statistics(Ticket ** pTicketInfo, int r, int c);	//������, �ش��ϴ� ��ũ���� ��ü�� �Ű������� ����
	virtual void showScreenInfo() = 0; //��ũ���� �޴� ���, �����Լ� ���
	int getMB() { return MobileBuyer; }
	int getBB() { return BankBuyer; }
	int getCB() { return CreditBuyer; }
	int getTB() { return MobileBuyer + BankBuyer + CreditBuyer; }
	int getTP() { return totalTicketPrice; }
};

class FamilyStatistics :public Statistics {	//���� ��ũ�� ���� Ŭ����
public:
	FamilyStatistics(Ticket ** pTicketInfo, int r, int c) :Statistics(pTicketInfo, r, c) {}
	void showScreenInfo();
};
class AdultStatistics :public Statistics {	//���� ��ũ�� ���� Ŭ����
	
public:
	AdultStatistics(Ticket ** pTicketInfo, int r, int c) :Statistics(pTicketInfo, r, c) {};
	void showScreenInfo();
};
class PremiumStatistics :public Statistics {	//�����̾� ��ũ�� ���� Ŭ����
	
public:
	PremiumStatistics(Ticket ** pTicketInfo, int r, int c) :Statistics(pTicketInfo, r, c) {};
	void showScreenInfo();
};
#endif

/*
�������� �ʿ��� ���
1. ������ ����ó��-> ������ ��ȣ�� Ƽ�Ϲڽ� ��ܿ� ���ǵǾ� ����
Ƽ�Ϲڽ� Ŭ�������� ������ Ȯ�� ��� �ۼ�
2. ������ ���� �� ����
3. ��ũ�� �� �� Ƽ�� ���� �ݾ� �Ѿ� �� Ƽ�� �Ǹŷ�
��ũ�� �� �� �����ȣ�� ���� ��ü�� ����
=> ���� �ݾ��� �ջ�
=> Ƽ�� �Ǹŷ� Ȯ��



-----------------------------------
�޴� ���
- �޴��� ǥ��
- ��ũ�� �� �� ������ ����
- ��ũ�� ���� �� Ƽ�� ���� �ݾ׹� �Ѿ� �� ������ ���� ����

*/