#include <iostream>
#include <string.h>

using std::cout;
using std::endl;
using std::cin;

struct account {
    int id;
    char name[30];
    int money;
};

struct account arr[1000];
int ids[1000];

int main()
{
    int select;
    int i = 0;
    int cid, money;
    while(1) {
        cout << "-----Menu-----" << endl << "1. 계좌개설" << endl << "2. 입금" << endl << "3. 출금" << endl << "4. 계좌정보 전체 출력" << endl << "5. 프로그램 종료" << endl << "선택 :";
        cin >> select;
        switch (select) {
            case 1:
                cout << endl << "[계좌개설]" << endl << "계좌ID:";
                cin >> cid;
                arr[cid].id = cid;
                cout << "이 름:";
                cin >> arr[cid].name;
                cout << "입금액:";
                cin >> arr[cid].money;
                ids[i] = arr[cid].id;
                i++;
                break;
            case 2:
                cout << endl << "[입 금]" << endl << "계좌ID:";
                cin >> cid;
                cout << "입금액:";
                cin >> money;
                arr[cid].money += money;
                break;
            case 3:
                cout << endl << "[출 금]" << endl << "계좌ID:";
                cin >> cid;
                cout << "출금액:";
                cin >> money;
                arr[cid].money -= money;
                break;
            case 4:
                for(int j = 0; j<=i-1; j++) {
                    cout << endl << "계좌ID: " << arr[ids[j]].id << endl << "이름: " << arr[ids[j]].name << endl << "잔액: " << arr[ids[j]].money << endl << endl;
                }
                break;
            case 5:
                return 0;
         }
    }
}
