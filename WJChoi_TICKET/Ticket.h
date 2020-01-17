#ifndef TICKET_H 
#define TICKET_H

#define SEAT_EMPTY_MARK '-' 
#define SEAT_RESERVED_MARK 'R' 
#define SEAT_COMPLETION_MARK '$' 

class Ticket {
	int nRow; // �¼� ��
	int nCol; // �¼� �� 
	char charCheck; // ���� ����
	int nReservedID; // ���� ��ȣ
	int nPayAmount; // ���� �ݾ�
	int nPayMethod; // ���� ����
public: 
	Ticket() {} 
	void setCheck(char check) { charCheck = check; }	//���� ����
	char getCheck() { return charCheck; }	//���� Ȯ��
	//�¼� ����
	// �¼� ��ȣ ���� 
	void setSeat(int r, int c) { nRow = r; nCol = c; } 
	// �¼� ���� ��ȣ ���� 
	void setReservedID(int reserved) { nReservedID = reserved; }
	//�¼� ����
	int getReservedID() { return nReservedID; }	//�����ȣ ��ȯ
	void setPayAmount(int amount) { nPayAmount = amount; }	//�����ݾ� ����
	int getPayAmount() { return nPayAmount; }	// �����ݾ� ��ȯ
	void setPayMethod(int method) { nPayMethod = method; }	//���� ���� ����
	int getPayMethod() { return nPayMethod; }	//���� ���� ��ȯ
};
#endif