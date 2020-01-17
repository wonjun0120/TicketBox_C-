#include "Pay.h"
#include <iostream>
#include <string>

using namespace std;

int CardPay::charge(int amount) {	//3��. ī�� ���� ���ý� ����
	int payAmount = 0;
	// �����ݾ� = Ƽ�� ���� +  Ƽ�� ���� * ����ϼ����� ���� 
	payAmount = amount + (amount * interest);

	string cardNum;	//ī�� ��ȣ
	string name;	//�̸�
	bool pass = true;	//�ݺ����� ����

	while (pass) {	//�������� �Է�
		cout << "\t[ �ſ�ī�� ���� ]" << endl;
		cout << "ī�� ��ȣ �Է�(12�ڸ���) :";
		cin >> cardNum;
		//�Է¹��� �����Ͱ� ������ ������ ������Ű���� �Ǵ�
		if (cardNum.length() == 12) {//�Է¹��� �����Ͱ� ������ ������ ������Ű�� ���
			pass = false;	//�ٽ� �ݺ�X
		}
		else {//�Է¹��� �����Ͱ� ������ ������ ������Ű�� ���� ��
			cout << "�߸��Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻñ� �ٶ��ϴ�." << endl;
			cin.ignore();	//�Է¹��۸� ���� �뵵
			continue;	//ó������ ����
		}
		cout << "�̸� :";
		cin >> name;
	}



	return payAmount;
}

int BankTransfer::charge(int amount) {	//2��. ���� ��ü ���ý� ����
	int payAmount = 0;
	// �����ݾ� = Ƽ�� ���� +  Ƽ�� ���� * ����ϼ����� ���� 
	payAmount = amount + (amount * interest);

	string accountNum;	//���� ��ȣ
	string name;	//�̸�
	bool pass = true;	//�ݺ����� ����

	while (pass) {	//�������� �Է�
		cout << "\t[ KPU ���� ���� ]" << endl;
		cout << "���� ��ȣ �Է�(12�ڸ���) :";
		cin >> accountNum;
		//�Է¹��� �����Ͱ� ������ ������ ������Ű���� �Ǵ�
		if (accountNum.length() == 12) {//�Է¹��� �����Ͱ� ������ ������ ������Ű�� ���
			pass = false;	//�ٽ� �ݺ�X
		}
		else {//�Է¹��� �����Ͱ� ������ ������ ������Ű�� ���� ��
			cout << "�߸��Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻñ� �ٶ��ϴ�." << endl;
			cin.ignore();	//�Է¹��۸� ���� �뵵
			continue;	//ó������ ����
		}
		cout << "�̸� :";
		cin >> name;
	}

	return payAmount;
}

int MobilePay::charge(int amount) {	//1��. ����� ���� ���ý� ����
	int payAmount = 0;
	// �����ݾ� = Ƽ�� ���� +  Ƽ�� ���� * ����ϼ����� ���� 
	payAmount = amount + (amount * interest);

	string phoneNum;	//�ڵ��� ��ȣ
	string name;	//�̸�
	bool pass = true;	//�ݺ����� ����

	while (pass) {	//�������� �Է�
		cout << "\t[ ����� ���� ]" << endl;
		cout << "�ڵ��� ��ȣ �Է�(11�ڸ���) :";
		cin >> phoneNum;
		//�Է¹��� �����Ͱ� ������ ������ ������Ű���� �Ǵ�
		if (phoneNum.length() == 11) {//�Է¹��� �����Ͱ� ������ ������ ������Ű�� ���
			pass = false;	//�ٽ� �ݺ�X
		}
		else {//�Է¹��� �����Ͱ� ������ ������ ������Ű�� ���� ��
			cout << "�߸��Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻñ� �ٶ��ϴ�." << endl;
			cin.ignore();	//�Է¹��۸� ���� �뵵
			continue;	//ó������ ����
		}
		cout << "�̸� :";
		cin >> name;
	}

	return payAmount;
}

