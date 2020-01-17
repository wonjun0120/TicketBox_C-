#ifndef TICKET_H 
#define TICKET_H

#define SEAT_EMPTY_MARK '-' 
#define SEAT_RESERVED_MARK 'R' 
#define SEAT_COMPLETION_MARK '$' 

class Ticket {
	int nRow; // 좌석 행
	int nCol; // 좌석 열 
	char charCheck; // 예약 여부
	int nReservedID; // 예약 번호
	int nPayAmount; // 결제 금액
	int nPayMethod; // 결제 수단
public: 
	Ticket() {} 
	void setCheck(char check) { charCheck = check; }	//예약 변경
	char getCheck() { return charCheck; }	//예약 확인
	//좌석 예매
	// 좌석 번호 저장 
	void setSeat(int r, int c) { nRow = r; nCol = c; } 
	// 좌석 예약 번호 저장 
	void setReservedID(int reserved) { nReservedID = reserved; }
	//좌석 결제
	int getReservedID() { return nReservedID; }	//예약번호 반환
	void setPayAmount(int amount) { nPayAmount = amount; }	//결제금액 받음
	int getPayAmount() { return nPayAmount; }	// 결제금액 반환
	void setPayMethod(int method) { nPayMethod = method; }	//결제 수단 받음
	int getPayMethod() { return nPayMethod; }	//결제 수단 반환
};
#endif