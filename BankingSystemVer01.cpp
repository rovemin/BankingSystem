#include <iostream>
#include <cstring>

using namespace std;
const int NAME = 20;
const int ACCARR = 100;

void ShowMenu();        //�޴� ���
void MakeAccount();     //���� ����
void Deposit();         //�Ա�
void Withdraw();        //���
void ShowAllAccInfo();  //���� ���� ��ü ���
void CheckAccNum();     //������ ���� �� Ȯ��

enum Choice {MAKE=1, DEPOSIT, WITHDRAW, ALLACCINFO, CHECKACCNUM, EXIT};

typedef struct {
    int accID;          //����ID
    char name[NAME];    //�̸�
    int balance;        //�ܾ�
} Account;

Account accArr[ACCARR]; //Account ������ ���� �迭
int accNum = 0;         //����� Account ��

int main() {
    int choice;

    while(1) {
        ShowMenu();
        cout << "����: ";
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
                cout << "�߸��� �Է��Դϴ�." << endl;
        }
    }

    return 0;
}

void ShowMenu() {
    cout << "\n-----Menu-----" << endl;
    cout << "1. ���� ����" << endl;
    cout << "2. �Ա�" << endl;
    cout << "3. ���" << endl;
    cout << "4. ���� ���� ��ü ���" << endl;
    cout << "5. ������ ���� �� Ȯ��" << endl;
    cout << "6. ���α׷� ����" << endl;
}

void MakeAccount() {
    int id;
    char name[NAME];
    int balance;

    cout << "\n[���� ����]" << endl;
    cout << "����ID: ";
    cin >> id;
    cout << "�̸�: ";
    cin >> name;
    cout << "�Աݾ�: ";
    cin >> balance;
    
    accArr[accNum].accID = id;
    accArr[accNum].balance = balance;
    strcpy(accArr[accNum].name, name);
    accNum++;
}

void Deposit() {
    int id, money;

    cout << "\n[�Ա�]" << endl;
    cout << "����ID: ";
    cin >> id;
    cout << "�Աݾ�: ";
    cin >> money;

    for(int i=0; i<accNum; i++) {
        if(accArr[i].accID == id) {
            accArr[i].balance += money;
            cout << "�ԱݿϷ�" << endl;
            return;
        }
    }
    cout << "��ȿ���� ���� ����ID�Դϴ�." << endl;
}

void Withdraw() {
    int id, money;

    cout << "\n[���]" << endl;
    cout << "����ID: ";
    cin >> id;
    cout << "��ݾ�: ";
    cin >> money;

    for(int i=0; i<accNum; i++) {
        if(accArr[i].accID == id) {
            if(accArr[i].balance < money) {
                cout << "�ܾ׺���" << endl;
                return;
            }

            accArr[i].balance -= money;
            cout << "��ݿϷ�" << endl;
            return;
        }
    }
    cout << "��ȿ���� ���� ����ID�Դϴ�." << endl;
}

void ShowAllAccInfo() {
    cout << "\n[��ü ���� ����]" << endl;

    for(int i=0; i<accNum; i++) {
        cout << "\n����ID: " << accArr[i].accID << endl;
        cout << "�̸�: " << accArr[i].name << endl;
        cout << "�Աݾ�: " << accArr[i].balance << endl;
    }
}

void CheckAccNum() {
    cout << "\n������ ���� ��: " << accNum << endl;
    cout << "�� �ý��ۿ��� �� " << ACCARR << "���� ���¸� ������ �� �ֽ��ϴ�." << endl;
}