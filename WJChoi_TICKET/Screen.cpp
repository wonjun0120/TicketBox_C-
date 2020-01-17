#include "Screen.h"
#include "Pay.h"
#include "Statistis.h"
#include <iostream>
#include <string>

using namespace std;

Screen::Screen(string name, int price, int r, int c) {	//������
	strMovieName = name;	//��ũ�� ������ ��ȭ ����
	nRowMax = r;	//�¼� ��
	nColMax = c;	//�¼� ��
	nTicketPrice = price;	//Ƽ�� ����
	//2���� �迭 �����Ҵ� - ��ũ�� �¼��� ���� Ƽ�� �迭
	pSeatArray = new Ticket*[nRowMax];
	for (int r = 0; r< nRowMax; r++) {
		pSeatArray[r] = new Ticket[nColMax];
	}
	//�����Ҵ�� 2���� �迭�� �ʱ�ȭ, SEAT_EPT...=> Ticket������Ͽ� ���ǵǾ�����,'-'�� �ǹ�
	for (int i = 0; i< nRowMax; i++) {
		for (int j = 0; j< nColMax; j++) {
			pSeatArray[i][j].setCheck(SEAT_EMPTY_MARK);
		}
	}
	nCurrentReservedId = 99;	//�߱޵� ������ �����ȣ, �����ȣ�� 100���� ����, �ʱ갪�� 99
}

Screen::~Screen() {	//�Ҹ���
	//�����Ҵ��� 2�����迭�� ����
	for (int i = 0; i < nRowMax; i++) {
		delete[] pSeatArray[i];
	}
	delete[]pSeatArray;
}

void Screen::showSeatMap() {	//�¼� �����ֱ�

	cout << "\t[ �¼� ���� ��Ȳ ]" << endl;
	cout << "\t";
	for (int i = 0; i < nRowMax; i++) {	//�� ��ȣ ���
		cout << "[" << i + 1 << "] ";
	}
	cout << endl;
	
	//�¼� ���
	for (int i = 0; i < nRowMax; i++) {
		cout << "[" << i + 1 << "]\t";	//�� ��ȣ ���
		for (int j = 0; j < nColMax; j++) {
			cout << "[" << pSeatArray[i][j].getCheck() << "] ";	//��ü �迭�� ����� ���� ���
		}
		cout << endl;
	}
}


void Screen::reserveTicket() {	//�¼� �����ϱ�
	bool pass = true;
	while (pass) {
		int row = 0, col = 0;

		cout << "  [ �¼� ���� ]" << endl;
		cout << "�¼� �� ��ȣ �Է�(1 - 10) :";
		cin >> row;
		row -= 1;	//���α׷����� ��ȣ�� 0���� ����
		cout << "�¼� �� ��ȣ �Է�(1 - 10) :";
		cin >> col;
		col -= 1;	//���α׷����� ��ȣ�� 0���� ����

		if (pSeatArray[row][col].getCheck() == '-') {	//�¼��� ���ŵ��� ���� ���
			nCurrentReservedId++;	//�����ȣ 1 ����

			pSeatArray[row][col].setReservedID(nCurrentReservedId);	//�����ȣ ����
			pSeatArray[row][col].setSeat(row, col);	//������ �¼� ����
			pSeatArray[row][col].setCheck(SEAT_RESERVED_MARK);	//����� �¼����� ����
			cout << "��[" << row + 1 << "] ��[" << col + 1 << "] " << nCurrentReservedId << " ���� ��ȣ�� �����Ǿ����ϴ�." << endl;
			pass = false;
		}
		else //�̹� �¼��� ���ŵ� ���
		{
			int menu = 0;
			cout << "�� �¼��� �̹� ����� �����Դϴ�." << endl;
			cout << "�ٽ� �Է��� 1��, ���� �޴��� �̵��� 2���� �������ּ���" << endl;
			cout << "�޴� ���� :";
			cin >> menu;

			if (menu == 1) continue;
			else if (menu == 2) break;
			else cout << "�߸��Է��ϼ̽��ϴ�." << endl;

		}
	}
}
void Screen::Payment() {	//�����ϱ�
	int reserveNum = 0;	//�����ȣ
	int payMethod = 0; //���� ����
	int r = 0, c = 0;	//���ȣ, ����ȣ(��ǻ�� ����), ����ڱ��� => +1
	
	//�Է¹��� Ȯ��**
	cout << "  [ �¼� ���� ���� ]" << endl;
	cout << "���� ��ȣ �Է� :";
	cin >> reserveNum;

	if ((reserveNum > nCurrentReservedId) || (reserveNum < 100)) {	//�������� �ʴ� �����ȣ�� �Է��� ���
		cout << "�����ȣ�� �������� �ʽ��ϴ�." << endl;
		cout << "�޴�ȭ������ �Ѿ�ϴ�." << endl;
	}
	else {	//�Է¹��� �����ȣ�� �����ϴ� ���
			//�����ȣ�� �´� �¼���ȣ�� ã��
		for (int i = 0; i < nRowMax; i++) {
			for (int j = 0; j < nColMax; j++) {
				//�ش��ϴ� �����ȣ�� �¼��� ã�� ���
				if (pSeatArray[i][j].getReservedID() == reserveNum) {
					r = i; c = j;	//�¼���ȣ ����
				}
			}
		}

		cout << "========================================" << endl;
		cout << "     ���� ��� ����" << endl;
		cout << "========================================" << endl;
		cout << " 1. ����� ����" << endl;
		cout << " 2. ���� ��ü ����" << endl;
		cout << " 3. ī�� ����" << endl;
		cout << endl;

		cout << " ���� ���(1-3) :";
		cin >> payMethod;

		switch (payMethod)	//������ ���� ��Ŀ� ���� �ڵ� ����
		{
		case 1: {//����� ����
			MobilePay Mpay(MOBILE_PHONE_INTEREST_RATE);	//���� �����Ḧ ���ڷ� �Է�

			//�¼� ���� ����
			pSeatArray[r][c].setPayMethod(MOBILE_PHONE_PAYMENT);	//���� ���� ����
			pSeatArray[r][c].setPayAmount(Mpay.charge(nTicketPrice));	//���� �����ݾ� ���(MobilePay Ŭ���� ���)
			//�������� �Է��� ���� �����ݾ� ��ȯ
			pSeatArray[r][c].setCheck(SEAT_COMPLETION_MARK);	//�¼� ���� ����=> ���࿡�� ���� �Ϸ�
			cout << "����� ������ �Ϸ�Ǿ����ϴ�. :" << pSeatArray[r][c].getPayAmount() << endl;	//���� ���� �ݾ� ���
			break;
		}

		case 2: {//���� ��ü ����
			BankTransfer Bpay(BANK_TRANSFER_INTEREST_RATE);	//���� �����Ḧ ���ڷ� �Է�

														//�¼� ���� ����
			pSeatArray[r][c].setPayMethod(BANK_TRANSFER_PAYMENT);	//���� ���� ����
			pSeatArray[r][c].setPayAmount(Bpay.charge(nTicketPrice));	//���� �����ݾ� ���(MobilePay Ŭ���� ���)
																		//�������� �Է��� ���� �����ݾ� ��ȯ
			pSeatArray[r][c].setCheck(SEAT_COMPLETION_MARK);	//�¼� ���� ����=> ���࿡�� ���� �Ϸ�
			cout << "KPU ���� ������ �Ϸ�Ǿ����ϴ�. :" << pSeatArray[r][c].getPayAmount() << endl;	//���� ���� �ݾ� ���
			break;
		}
		case 3: {//�ſ�ī�� ����
			CardPay Cpay(CREDIT_CARD_INTEREST_RATE);	//���� �����Ḧ ���ڷ� �Է�

															//�¼� ���� ����
			pSeatArray[r][c].setPayMethod(CREDIT_CARD_PAYMENT);	//���� ���� ����
			pSeatArray[r][c].setPayAmount(Cpay.charge(nTicketPrice));	//���� �����ݾ� ���(MobilePay Ŭ���� ���)
																		//�������� �Է��� ���� �����ݾ� ��ȯ
			pSeatArray[r][c].setCheck(SEAT_COMPLETION_MARK);	//�¼� ���� ����=> ���࿡�� ���� �Ϸ�
			cout << "�ſ�ī�� ������ �Ϸ�Ǿ����ϴ�. :" << pSeatArray[r][c].getPayAmount() << endl;	//���� ���� �ݾ� ���
			break;
		}
		default: {
			cout << "�߸��Է��ϼ̽��ϴ�." << endl;
			cout << "�޴�ȭ������ �Ѿ�ϴ�." << endl;
			break;
		}
		}
	}
}

//�����Լ��� ���ǵ� �κ�, ����ڰ� ������ �󿵰��� ���� ��ȭ�� �̸��� ��µǾ�� ��(��ĳ����)
void Screen::showMovieMenu() {

	//�޴� ���
	cout << "========================================" << endl;
	cout << "     ��ȭ �޴� - " << strMovieName << endl;
	cout << "========================================" << endl;
	cout << " 1. �� ��ȭ ����" << endl;
	cout << " 2. �¼� ���� ��Ȳ" << endl;
	cout << " 3. �¼� ���� �ϱ�" << endl;
	cout << " 4. �¼� ���� �ϱ�" << endl;
	cout << " 5. ���� �޴� �̵�" << endl;
	cout << endl;

}

//�����Լ��� ���ǵ� �κ� �ش��ϴ� Ŭ������ �°� �������̵�
void FamillyScreen::showMovieInfo() {	
	cout << "========================================" << endl;
	cout << "     [ "<<strMovieName<<" ]"<< endl;
	cout << "========================================" << endl;
	cout << "  ��ȭ�� : ������ȭ 1��" << endl;
	cout << "  ���ΰ� : �ι�Ʈ �ٿ�� �ִϾ�" << endl;
	cout << "  �ٰŸ� : ���Ǵ�Ƽ �� ���� ���ݸ� ��Ƴ��� ���� ..." << endl;
	cout << "  ���� : "<< nTicketPrice<< endl;	
	cout << endl;
}

void AdultScreen::showMovieInfo() {
	cout << "========================================" << endl;
	cout << "     [ " << strMovieName << " ]" << endl;
	cout << "========================================" << endl;
	cout << "  ��ȭ�� : ���ο�ȭ 2��" << endl;
	cout << "  ���ΰ� : ������, �蹫��" << endl;
	cout << "  �ٰŸ� : ������θ��� ǥ���� �Ǿ��� ��Ƴ� ���� ���� ..." << endl;
	cout << "  ���� : " << nTicketPrice << endl;
	cout << endl;
}

void PremiumScreen::showMovieInfo() {
	cout << "========================================" << endl;
	cout << "     [ " << strMovieName << " ]" << endl;
	cout << "========================================" << endl;
	cout << "  ��ȭ�� : �����̾���ȭ 3��" << endl;
	cout << "  ���ΰ� : ��� ���ٽ�, �����ȶ� �˸�" << endl;
	cout << "  �ٰŸ� : ����, ���ݵ� �ٸ� �� ������ Ư���� ������ ���� ..." << endl;
	cout << "  ���� : " << nTicketPrice << endl;
}


//���� ���縦 ���� ���������
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


Management::Management(FamillyScreen Fs, AdultScreen As, PremiumScreen Ps) : Screen("������", 0, 0, 0) {
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
void Management::Initialize() {	//��� ��ü ����
	f = new FamilyStatistics(a1, r1, c1);
	a = new AdultStatistics(a2, r2, c2);
	p = new PremiumStatistics(a3, r3, c3);
}

Management::~Management() {	//�Ҹ���
					//�����Ҵ��� 2�����迭�� ����
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
		cout << "     ��� �޴� - " << endl;
		cout << "========================================" << endl;
		cout << " 1. ������ȭ 1��" << endl;
		cout << " 2. ���ο�ȭ 2��" << endl;
		cout << " 3. �����̾���ȭ 3��" << endl;
		cout << " 5. ����" << endl;
		cout << "�޴��� �����ϼ��� : " << endl;
		cin >> n; cout << endl;

		switch (n)
		{
		case 1:	//������ȭ 1��
			f->showScreenInfo();
			break;
		case 2:	//���ο�ȭ 2��
			a->showScreenInfo();
			break;
		case 3:	//�����̾� ��ȭ 3��
			p->showScreenInfo();
			break;
		case 5:	//����
			cout << "���α׷��� �����մϴ�." << endl;
			pass = false;
			exit(0);	//���α׷� ����
							//return;
		default:
			cout << "�߸��Է��ϼ̽��ϴ�." << endl;
			break;
		}
	}


}
