#ifndef TICKETBOX_H
#define TICKETBOX_H
#define TICKETBOX_MANAGER_PWD "admin"	//������ ��� ��й�ȣ
#define MAX_TRY 5
#include "stddef.h"	//"�ĺ��� NULL�̰� ���ǵǾ����� �ʽ��ϴ�." ���� �ذ�
//������� ��ȯ������ ���� �߻��ϴ� ������ �������� Ŭ������ ��ܿ��� ����
class Screen;
class FamillyScreen;
class AdultScreen;
class PremiumScreen;
class Management;

class TicketBox {
public:
	virtual Screen * selectMenu() { return NULL; } // �󿵰� ���� �޴� ( 1��, 2��, 3��) 
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