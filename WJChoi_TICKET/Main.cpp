#include <iostream>
#include <string>
#include"Pay.h"
#include"Screen.h"
#include"Statistis.h"
#include"Ticket.h"
#include"TicketBox.h"

using namespace std;

int main() {
	KpuTicketBox tBox;	//Ƽ�Ϲڽ� ��ü ����
	Screen * screen = NULL;		//���� ��ũ����ü �ּҰ� ����Ű�� �ִ� ��ü ����
	bool bScreenMenu = true;	//boolScreenMenu=> ��ũ�� �޴� ���� ����
	int select = 0;		//����� ����
	
	tBox.Initialize();	//�ʱ�ȭ
	while (1) {	//���� �ݺ���
		if (bScreenMenu) {	//bScreenMenu�� ���϶� ����
			screen = tBox.selectMenu();	//���� ��ũ���� Ƽ�Ϲڽ� ��ü���� �޴��� �����ѵ� ��ȯ�� ��(��ĳ����)
			bScreenMenu = false;	//��ũ�� �޴� �ٽ� ��������X
			if (!screen) return 0;	//���� ��ũ���� ���� ���� ��� ����
		} 
		screen->showMovieMenu();	//��ũ�� ��ü�� ��ȭ �޴��� �����ִ� ����Լ� ����

		cout << "�޴��� �����ϼ���: ";
		cin >> select; cout << endl; 
		switch (select) {
		case 1: // ��ȭ ���� 
			screen->showMovieInfo(); 
			break; 
		case 2: // �¼� ��Ȳ 
			screen->showSeatMap();
			break; 
		case 3:	//�¼� ����
			screen->reserveTicket();
			break;
		case 4:	//�¼� ����
			screen->Payment();
			break;
		case 5: // ��ũ�� ���� �޴�
			bScreenMenu = true;
			break; 
		default:
			cout << "�߸��Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻñ� �ٶ��ϴ�." << endl;
			break;
		} 
	} 
	return 0;
}

