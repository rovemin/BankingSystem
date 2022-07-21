#include <iostream>
#include <cstring>

using namespace std;
const int NAME = 20;
const int ACCARR = 100;

void ShowMenu();        //메뉴 출력
void MakeAccount();     //계좌 개설
void Deposit();         //입금
void Withdraw();        //출금
void ShowAllAccInfo();  //계좌 정보 전체 출력
void CheckAccNum();     //개설된 계좌 수 확인

enum Choice {MAKE=1, DEPOSIT, WITHDRAW, ALLACCINFO, CHECKACCNUM, EXIT};

typedef struct {
    int accID;          //계좌ID
    char name[NAME];    //이름
    int balance;        //잔액
} Account;

Account accArr[ACCARR]; //Account 저장을 위한 배열
int accNum = 0;         //저장된 Account 수

int main() {
    int choice;

    while(1) {
        ShowMenu();
        cout << "선택: ";
        cin >> choice;

        switch(choice) {
            case MAKE:
                MakeAccount();
                break;
            case DEPOSIT:
                Deposit();
                break;
            case WITHDRAW:
                Withdraw();
                break;
            case ALLACCINFO:
                ShowAllAccInfo();
                break;
            case CHECKACCNUM:
                CheckAccNum();
                break;
            case EXIT:
                return 0;
            default:
                cout << "잘못된 입력입니다." << endl;
        }
    }

    return 0;
}

void ShowMenu() {
    cout << "\n-----Menu-----" << endl;
    cout << "1. 계좌 개설" << endl;
    cout << "2. 입금" << endl;
    cout << "3. 출금" << endl;
    cout << "4. 계좌 정보 전체 출력" << endl;
    cout << "5. 개설된 계좌 수 확인" << endl;
    cout << "6. 프로그램 종료" << endl;
}

void MakeAccount() {
    int id;
    char name[NAME];
    int balance;

    cout << "\n[계좌 개설]" << endl;
    cout << "계좌ID: ";
    cin >> id;
    cout << "이름: ";
    cin >> name;
    cout << "입금액: ";
    cin >> balance;
    
    accArr[accNum].accID = id;
    accArr[accNum].balance = balance;
    strcpy(accArr[accNum].name, name);
    accNum++;
}

void Deposit() {
    int id, money;

    cout << "\n[입금]" << endl;
    cout << "계좌ID: ";
    cin >> id;
    cout << "입금액: ";
    cin >> money;

    for(int i=0; i<accNum; i++) {
        if(accArr[i].accID == id) {
            accArr[i].balance += money;
            cout << "입금완료" << endl;
            return;
        }
    }
    cout << "유효하지 않은 계좌ID입니다." << endl;
}

void Withdraw() {
    int id, money;

    cout << "\n[출금]" << endl;
    cout << "계좌ID: ";
    cin >> id;
    cout << "출금액: ";
    cin >> money;

    for(int i=0; i<accNum; i++) {
        if(accArr[i].accID == id) {
            if(accArr[i].balance < money) {
                cout << "잔액부족" << endl;
                return;
            }

            accArr[i].balance -= money;
            cout << "출금완료" << endl;
            return;
        }
    }
    cout << "유효하지 않은 계좌ID입니다." << endl;
}

void ShowAllAccInfo() {
    cout << "\n[전체 계좌 정보]" << endl;

    for(int i=0; i<accNum; i++) {
        cout << "\n계좌ID: " << accArr[i].accID << endl;
        cout << "이름: " << accArr[i].name << endl;
        cout << "입금액: " << accArr[i].balance << endl;
    }
}

void CheckAccNum() {
    cout << "\n개설된 계좌 수: " << accNum << endl;
    cout << "이 시스템에는 총 " << ACCARR << "개의 계좌를 개설할 수 있습니다." << endl;
}