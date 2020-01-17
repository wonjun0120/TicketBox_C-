#include "TicketBox.h"
#include "Screen.h"
#include <iostream>
#include <string>

using namespace std;

KpuTicketBox::KpuTicketBox() {

}

KpuTicketBox::~KpuTicketBox() {
	//�������� ������ ��ü���� ����
	delete pFamillyScreen;
	delete pAdultScreen;
	delete pPremiumScreen;
	delete pManagement;
}

Screen * KpuTicketBox::selectMenu() {	//Ƽ�Ϲڽ� �޴�����
	int num = 0;	//����� ���� �޴� ��ȣ
	bool pass = true;
	string pwd;
	int trynum = 0;

	//�󿵰� ���� �޴� ���
	cout << "=========================" << endl;
	cout << "     �󿵰� ���� �޴�" << endl;
	cout << "=========================" << endl;
	cout << " 1. ������ȭ 1��" << endl;
	cout << " 2. ���ο�ȭ 2��" << endl;
	cout << " 3. �����̾���ȭ 3��" << endl;
	cout << " 9. ��� ����" << endl;
	cout << " \n����(1-3,9) �׿� ���� : ";
	cin >> num; 
	cout << endl;	//�Է¹ް� �ٷ� ���� ���

	switch (num)	//�ش��ϴ� ��ȭ���� ��ȣ�� �Է¹��� �� �� ��ȭ�� ��ü�� ��ȯ
	{
	case 1:
		return pFamillyScreen;
	case 2:
		return pAdultScreen;
	case 3:
		return pPremiumScreen;
	case 9:	//������ ���
		cout << "������ ����� �����ϼ̽��ϴ�." << endl;
		cout << "�ش� ����� �����ڸ� ����� �����մϴ�." << endl;
		cout << "������ ��ȣ�� �Է��� �ֽʽÿ�" << endl;
		while (pass) {
			cout << "��ȣ :";
			cin >> pwd;
			if (pwd.compare(TICKETBOX_MANAGER_PWD) == 0) {	//������ ��ȣ�� �´� ���
				pass = false;	//�ݺ� ����
								//������ ��� ����

				manageInitialize();
				return pManagement;
				//return 0;	
			}
			else if (trynum == MAX_TRY) {
				cout << MAX_TRY << "ȸ �̻� ������ ��ȣ�� �߸� �Է��ϼ̽��ϴ�." << endl;
				cout << "���α׷� �ڵ� �����մϴ�" << endl;
				return 0;
			}
			else {
				trynum++;	//�Է� Ƚ�� ����
				cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
				cout << MAX_TRY << "ȸ �߸� �Է½� ���α׷��� �ڵ� ����˴ϴ�." << endl;
				cout << MAX_TRY - trynum << "ȸ ���ҽ��ϴ�." << endl;
			}
		}
	default:
		cout << "���α׷��� �����մϴ�." << endl;
		return 0;
	}
}

// ��ũ�� ��ü ���� 
void KpuTicketBox::Initialize() { 
	// Screen(��ȭ����, Ƽ�ϰ���, �¼�(nRowMax), �¼�(nColMax)) 
	pFamillyScreen = new FamillyScreen("�����", 8000, 10, 10); 
	pAdultScreen = new AdultScreen("������", 10000, 10, 10); 
	pPremiumScreen = new PremiumScreen("�׸���", 30000, 5, 5);
}

void KpuTicketBox::manageInitialize() {	//���
	
	FamillyScreen cpf(*pFamillyScreen);
	AdultScreen cpa(*pAdultScreen);
	PremiumScreen cpp(*pPremiumScreen);

	pManagement = new Management(cpf, cpa, cpp);
}