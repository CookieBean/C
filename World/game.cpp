#include <bits/stdc++.h>
using namespace std;
struct ter {
  int g_iron;
  int g_coal;
  int g_oil;
  int g_gas;
  int owner;
  int population;
  int fac; int fac_last;
  int elec; int elec_last;
};
struct player {
  float diplo;
  int money = 50;
  int fac;
  int iron;
  int coal;
  int oil;
  int gas;
  int elec; int atom;
  int population;
};
struct ter arr[20][20];
struct player brr[5];
int visited[20], money_sum;
queue<char*> M[5];
void show_ter() {
  for(int i=1;i<=19;i++) {
    for(int j=1;j<=19;j++) printf("%d ", arr[i][j].owner);
    puts("");
  }
  puts("---------------------------");
}
int all(int k) {
  for(int i=1;i<=19;i++) {
    for(int j=1;j<=19;j++) if(k != arr[i][j].owner) return 0;
  }
  return 1;
}
int main() {
  int people;
  srand(time(NULL));
  printf("인원수를 말해주세요 : \n");
  scanf("%d", &people);
  printf("%d인 게임을 시작합니다.\n", people);
  puts("지금부터 소 문명게임을 시작합니다.");
  puts("---------------------------");
  puts("참가자 분들의 승리조건은 다음과 같습니다.\n");
  puts("1. 모든 국가를 점령한다. 혹은 영토에서 나를 제외한 모든 국가가 없다."); // 무력우승
  puts("2. 외교수치를 100으로 모두 채운다."); // 외교우승
  puts("3. 현재 국고의 금액이 다른나라 모두의 합보다 크다."); // 금용우승
  puts("---------------------------");
  puts("그러나 자신이 꼴지를 할 것이라 예상된다면, 전부 패배하는 상황을 노려볼 수 있습니다.\n전부 패배하는 경우에는 직전에 가장 낮은 순위를 하고 있는 국가가 우승합니다.\n다음과 같은 조건에서는 모든 국가가 패배합니다.\n"); // 전부 패배
  puts("1. 모든 국가가 심각한 방사능으로 모두 오염되었을때"); // 원자력 3개 == 망
  puts("2. 모든 국가가 더이상 영토를 확장할 수 없을때\n");
  printf("이제 본 게임을 시작하기 전에 앞서 시작영역 추첨을 진행합니다.\n참가자 여러분은 Player1 부터 %d까지 원하는 위치의 영역을 선택해 주십시오\n(1, 1) 부터 (19, 19)\n", people);
  for(int i=1;i<=people;i++) {
    printf("player %d : \n", i);
    int x, y;
    scanf("%d %d", &x, &y);
    while(arr[x][y].owner) {
      puts("이미 선택된 영역입니다.");
      scanf("%d %d", &x, &y);
    }
    money_sum += brr[i].money;
    arr[x][y].owner = i;
    brr[i].population += arr[x][y].population;
  }
  puts("---------------------------");
  for(int i=1;i<=19;i++) {
    for(int j=1;j<=19;j++) {
      arr[i][j].g_iron = (rand() % 40) + 10; // 철 : 에너지 : 돈 = 1 : 1 : 5
      arr[i][j].g_coal = rand() % 35 + 15; // 4
      arr[i][j].g_oil = rand() % 50; // 3
      arr[i][j].g_gas = rand() % 25; // 2
      arr[i][j].population = (rand() % 50) + 50;
    }
  }
  puts("게임을 시작합니다.");
  int cnt = 0;
  while(1) {
    cnt++;
    for(int i=1;i<=people;i++) {
      money_sum = 0;
      for(int i=1;i<=people;i++) money_sum += brr[i].money;
      if(!visited[i]) {
        if(all(arr[1][1].owner)) {
          printf("모든 땅이 player %d의 영토입니다.\n", arr[1][1].owner);
          printf("우승자가 정해졌습니다!\n");
          printf("우승자는 player %d 입니다.\n", i);
          puts("게임을 종료합니다.");
          return 0;
        } else if(brr[i].diplo >= 100) {
          printf("player %d의 외교점수가 %f로 100 이상입니다.\n", i, brr[i].diplo);
          printf("우승자가 정해졌습니다!\n");
          printf("우승자는 player %d 입니다.\n", i);
          puts("게임을 종료합니다.");
          return 0;
        } else if(money_sum - brr[i].money < brr[i].money && people == 4) {
          printf("player %d의 국고에 있는 재화가 %d로, 다른나라의 합보다 많습니다.\n", i, brr[i].money);
          printf("우승자가 정해졌습니다!\n");
          printf("우승자는 player %d 입니다.\n", i);
          puts("게임을 종료합니다.");
          return 0;
        }
        puts("---------------------------");
        printf("%d번째 턴 : Player %d\n", cnt, i);
        while(1) {
          char bash[50];
          scanf("%s", bash);
          if(!strcmp(bash, "ter")) show_ter();
          else if(!strcmp(bash, "fac")) {
            int x, y, iron;
            printf("구동할 수 있는 공장이 존재하는 땅의 좌표를 말해주십시오.\n");
            scanf("%d %d", &x, &y);
            while(!(arr[x][y].owner == i && arr[x][y].fac && arr[x][y].fac_last != cnt)) {
              printf("현재 소유하고 있지 않는 땅이거나 공장이 존재하지 않는 땅입니다.\n");
              scanf("%d %d", &x, &y);
            }
            printf("현재 보유중인 재료들은 다음과 같습니다\n철광석 : %d, 전기 : %d\n", brr[i].iron, brr[i].elec);
            printf("철광석 1개와 전기 1개를 소비하여 돈 5원을 만들 수 있습니다.\n한턴에 한 공장에서 최대 교환 가능한 돈은 15원 입니다.\n");
            printf("사용할 철광석의 갯수를 입력해주세요.\n");
            scanf("%d", &iron);
            if(iron > 3 || iron > brr[i].iron || iron > brr[i].elec) {
              if(brr[i].elec < iron) {
                puts("현재 전기가 부족합니다.");
                puts("발전기를 가동하기 어렵다면, 모든 땅에 이미 설치되어있는 3전기 생산 원자력 발전기를 구동할 수 있습니다.");
                puts("그렇지만, 원자력 발전기는 한 턴마다 구동하면 국민들에게 좋지 않은 영향을 끼칩니다.");
                puts("따라서 3턴 이상 사용하면 해당 국가는 자동적으로 패배합니다.");
                printf("원자력 발전을 구동합니까? *현재 구동 횟수 : %d [y : 1/n : 0]", brr[i].atom);
                int ans;
                scanf("%d", &ans);
                if(ans) {
                  printf("원자력 발전을 통해 3전기를 획득합니다. 구동횟수는 증가합니다.\n");
                  if(brr[i].atom >= 3) {
                    printf("원자력 발전을 3회 이상 사용했습니다. 국가가 활동능력을 잃습니다.\n");
                    printf("앞으로 player %d는 턴 당 플레이어의 의사결정에서 배제됩니다.\n", i);
                  }
                } else {
                  printf("구동을 취소합니다.\n");
                }
              } else printf("명령을 수행할 수 없습니다.\n");
            } else {
              printf("성공적으로 돈을 교환하였습니다.\n");
              brr[i].money += iron*5;
              brr[i].iron -= iron;
              brr[i].elec -= iron;
            }
            puts("---------------------------");
          }
          else if(!strcmp(bash, "elec")) {
            int x, y;
            char res[20];
            printf("구동할 수 있는 발전기가 존재하는 땅의 좌표를 말해주십시오.\n");
            scanf("%d %d", &x, &y);
            while(!(arr[x][y].owner == i && arr[x][y].elec && arr[x][y].elec_last != cnt)) {
              printf("현재 소유하고 있지 않는 땅이거나 발전기가 존재하지 않는 땅입니다.\n");
              scanf("%d %d", &x, &y);
            }
            printf("발전에 사용할 자원을 고르세요. 발전량은 다음과 같습니다.\n");
            puts("4개 석탄 = 1 전기");
            puts("3개 원유 = 1 전기");
            puts("2개 천연가스 = 1 전기");
            puts("그리고 한 발전기가 한 턴에 최대로 발전할 수 있는 양은 6 전기 입니다.");
            scanf("%s", res);
            arr[x][y].elec_last = cnt;
            if(!strcmp(res, "석탄")) {
              printf("바꿀 석탄의 갯수를 입력하세요.(4의 배수)\n");
              int k;
              scanf("%d", &k);
              while(!(k%4 == 0 && k<=brr[arr[x][y].owner].coal)) {
                printf("입력한 만큼의 석탄이 존재하지 않거나, 4의 배수가 아닙니다.\n");
                scanf("%d", &k);
              }
              if(k >= 24) {
                printf("6 전기 생산 완료\n");
                brr[i].elec += 6;
              } else {
                printf("%d 전기 생산 완료\n", k/4);
                brr[i].elec += k/4;
              }
              brr[i].coal -= k;
            } else if(!strcmp(res, "원유")) {
              printf("바꿀 원유의 갯수를 입력하세요.(3의 배수)\n");
              int k;
              scanf("%d", &k);
              while(!(k%3 == 0 && k<=brr[arr[x][y].owner].oil)) {
                printf("입력한 만큼의 원유가 존재하지 않거나, 3의 배수가 아닙니다.\n");
                scanf("%d", &k);
              }
              if(k >= 18) {
                printf("6 전기 생산 완료\n");
                brr[i].elec += 6;
              } else {
                printf("%d 전기 생산 완료\n", k/3);
                brr[i].elec += k/3;
              }
              brr[i].oil -= k;
            } else if(!strcmp(res, "천연가스")) {
              printf("바꿀 천연가스의 갯수를 입력하세요.(2의 배수)\n");
              int k;
              while(!(k%2 == 0 && k<=brr[arr[x][y].owner].gas)) {
                printf("입력한 만큼의 천연가스가 존재하지 않거나, 2의 배수가 아닙니다.\n");
                scanf("%d", &k);
              }
              scanf("%d", &k);
              if(k >= 12) {
                printf("6 전기 생산 완료\n");
                brr[i].elec += 6;
              } else {
                printf("%d 전기 생산 완료\n", k/2);
                brr[i].elec += k/2;
              }
              brr[i].gas -= k;
            } else {
              printf("유효하지 않은 자원입니다.\n");
              arr[x][y].elec_last = cnt-1;
            }
            puts("---------------------------");
          } else if(!strcmp(bash, "build_elec")) {
            int x, y, ans;
            printf("발전소를 지을 땅의 좌표를 설정하십시오.\n");
            scanf("%d %d", &x, &y);
            while(arr[x][y].owner != i) {
              printf("입력한 땅은 현재 자신의 소유가 아닙니다. 다시 입력해 주십시오.\n");
              scanf("%d %d", &x, &y);
            }
            if(arr[x][y].elec) {
              printf("이미 발전소를 지은 땅입니다.\n");
            } else {
              printf("발전소를 지으려면 10원이 필요합니다. 수락하시겠습니까? [y : 1/n : 0]");
              scanf("%d", &ans);
              if(ans) {
                printf("발전소 건설에 성공하였습니다.\n");
                arr[x][y].elec++;
                brr[i].money -= 10;
                brr[i].elec++;
              } else {
                printf("발전소 건설이 거부되었습니다.\n");
              }
            }
            puts("---------------------------");
          } else if(!strcmp(bash, "build_fac")) {
            int x, y, ans;
            printf("공장을 지을 땅의 좌표를 설정하십시오.\n");
            scanf("%d %d", &x, &y);
            while(arr[x][y].owner != i) {
              printf("입력한 땅은 현재 자신의 소유가 아닙니다. 다시 입력해 주십시오.\n");
              scanf("%d %d", &x, &y);
            }
            if(arr[x][y].fac) {
              printf("이미 공장을 지은 땅입니다.\n");
            } else {
              printf("공장을 지으려면 20원이 필요합니다. 수락하시겠습니까? [y : 1/n : 0]");
              scanf("%d", &ans);
              if(ans) {
                brr[i].money -= 20;
                brr[i].fac++;
                arr[x][y].fac++;
                printf("공장 건설을 완료했습니다.\n");
              } else {
                printf("공장 건설을 취소합니다.\n");
              }
            }
            puts("---------------------------");
          } else if(!strcmp(bash, "me")) {
            printf("player %d의 정보 : \n", i);
            printf("외교점수 : %f\n", brr[i].diplo);
            printf("보유중인 돈의 양 : %d\n", brr[i].money);
            printf("총 공장수 : %d\n", brr[i].fac);
            printf("석탄 보유량 : %d\n", brr[i].coal);
            printf("원유 보유량 : %d\n", brr[i].oil);
            printf("천연가스 보유량 : %d\n", brr[i].gas);
            printf("총 발전소 수 : %d\n", brr[i].elec);
            printf("총 인구수 : %d\n", brr[i].population);
            printf("총 전기양 : %d\n", brr[i].elec);
            printf("철광석 보유량 : %d\n", brr[i].iron);
            puts("---------------------------");
          } else if(!strcmp(bash, "info")) {
            printf("조사할 땅의 좌표를 입력하십시오.");
            GOTO:
            int x = 0, y = 0;
            scanf("%d %d", &x, &y);
            if(!(arr[x][y].owner == i)) {
              printf("조사하려는 땅이 현재 소유가 아닙니다. 다시 입력해주세요.\n");
              goto GOTO;
            }
            printf("%d %d의 정보 : \n", x, y);
            printf("철광석 매장량 : %d\n", arr[x][y].g_iron);
            printf("석탄 매장량 : %d\n", arr[x][y].g_coal);
            printf("원유 매장량 : %d\n", arr[x][y].g_oil);
            printf("천연가스 매장량 : %d\n", arr[x][y].g_gas);
            printf("인구수 : %d\n", arr[x][y].population);
            printf("공장수 : %d\n", arr[x][y].fac);
            puts("---------------------------");
          } else if(!strcmp(bash, "req_res")) {
            puts("교환하려는 광물 종류를 말하세요.");
            char message[50];
            int amount, a, ans;
            scanf("%s", message);
            if(!strcmp(message, "철광석")) {
              printf("교환하려는 플레이어 번호를 말하세요.\n");
              scanf("%d", &a);
              printf("교환하려는 광물의 양을 말하세요. 범위는 0이상 %d이하입니다.\n", brr[a].iron);
              scanf("%d", &amount);
              while(0 > amount || brr[a].iron < amount) {
                printf("유효하지 않은 값입니다.\n");
                scanf("%d", &amount);
              }
              printf("*%d플레이어가 답합니다. 교환을 수락합니까? [y : 1/n : 0]", a);
              scanf("%d", &ans);
              if(ans) {
                printf("\n가격협상을 시작합니다.\n");
                printf("player %d부터 번갈아가며 가격을 정합니다.\n", i);
                printf("가격은 두 플레이어가 같은 가격을 제시하기 전까지 계속 진행됩니다. 언제든지 거래를 취소하고 싶다면 -1을 입력하십시오.\n");
                int k = -10, b = -11;
                while(!((k == b) || (k == -1) || (b == -1))) {
                  printf("player %d : \n", i);
                  scanf("%d", &k);
                  printf("player %d : \n", a);
                  scanf("%d", &b);
                }
                if(k == b) {
                  printf("거래가 성사되었습니다.\n");
                  printf("현재 철광석 %d만큼의 소유권이 player %d에서 player %d로 넘어갑니다.\n", amount, a, i);
                  brr[a].iron -= amount;
                  brr[a].money -= k;
                  brr[i].iron += amount;
                  brr[i].money -= k;
                } else {
                  printf("\n교환이 취소되었습니다.\n");
                }
              } else {
                printf("\n교환이 취소되었습니다.\n");
              }
            } else if(!strcmp(message, "석탄")) {
              printf("교환하려는 플레이어 번호를 말하세요.\n");
              scanf("%d", &a);
              printf("교환하려는 광물의 양을 말하세요. 범위는 0이상 %d이하입니다.\n", brr[a].coal);
              scanf("%d", &amount);
              while(0 > amount || brr[a].coal < amount) {
                printf("유효하지 않은 값입니다.\n");
                scanf("%d", &amount);
              }
              printf("*%d플레이어가 답합니다. 교환을 수락합니까? [y : 1/n : 0]", a);
              scanf("%d", &ans);
              if(ans) {
                printf("\n가격협상을 시작합니다.\n");
                printf("player %d부터 번갈아가며 가격을 정합니다.\n", i);
                printf("가격은 두 플레이어가 같은 가격을 제시하기 전까지 계속 진행됩니다. 언제든지 거래를 취소하고 싶다면 -1을 입력하십시오.\n");
                int k = -10, b = -11;
                while(!((k == b) || (k == -1) || (b == -1))) {
                  printf("player %d : \n", i);
                  scanf("%d", &k);
                  printf("player %d : \n", a);
                  scanf("%d", &b);
                }
                if(k == b) {
                  printf("거래가 성사되었습니다.\n");
                  printf("현재 석탄 %d만큼의 소유권이 player %d에서 player %d로 넘어갑니다.\n", amount, a, i);
                  brr[a].coal -= amount;
                  brr[a].money -= k;
                  brr[i].coal += amount;
                  brr[i].money -= k;
                } else {
                  printf("\n교환이 취소되었습니다.\n");
                }
              } else {
                printf("\n교환이 취소되었습니다.\n");
              }
            } else if(!strcmp(message, "원유")) {
              printf("교환하려는 플레이어 번호를 말하세요.\n");
              scanf("%d", &a);
              printf("교환하려는 광물의 양을 말하세요. 범위는 0이상 %d이하입니다.\n", brr[a].oil);
              scanf("%d", &amount);
              while(0 > amount || brr[a].iron < amount) {
                printf("유효하지 않은 값입니다.\n");
                scanf("%d", &amount);
              }
              printf("*%d플레이어가 답합니다. 교환을 수락합니까? [y : 1/n : 0]", a);
              scanf("%d", &ans);
              if(ans) {
                printf("\n가격협상을 시작합니다.\n");
                printf("player %d부터 번갈아가며 가격을 정합니다.\n", i);
                printf("가격은 두 플레이어가 같은 가격을 제시하기 전까지 계속 진행됩니다. 언제든지 거래를 취소하고 싶다면 -1을 입력하십시오.\n");
                int k = -10, b = -11;
                while(!((k == b) || (k == -1) || (b == -1))) {
                  printf("player %d : \n", i);
                  scanf("%d", &k);
                  printf("player %d : \n", a);
                  scanf("%d", &b);
                }
                if(k == b) {
                  printf("거래가 성사되었습니다.\n");
                  printf("현재 원유 %d만큼의 소유권이 player %d에서 player %d로 넘어갑니다.\n", amount, a, i);
                  brr[a].oil -= amount;
                  brr[a].money -= k;
                  brr[i].oil += amount;
                  brr[i].money -= k;
                } else {
                  printf("\n교환이 취소되었습니다.\n");
                }
              } else {
                printf("\n교환이 취소되었습니다.\n");
              }
            } else if(!strcmp(message, "천연가스")) {
              printf("교환하려는 플레이어 번호를 말하세요.\n");
              scanf("%d", &a);
              printf("교환하려는 광물의 양을 말하세요. 범위는 0이상 %d이하입니다.\n", brr[a].gas);
              scanf("%d", &amount);
              while(0 > amount || brr[a].gas < amount) {
                printf("유효하지 않은 값입니다.\n");
                scanf("%d", &amount);
              }
              printf("*%d플레이어가 답합니다. 교환을 수락합니까? [y : 1/n : 0]", a);
              scanf("%d", &ans);
              if(ans) {
                printf("\n가격협상을 시작합니다.\n");
                printf("player %d부터 번갈아가며 가격을 정합니다.\n", i);
                printf("가격은 두 플레이어가 같은 가격을 제시하기 전까지 계속 진행됩니다. 언제든지 거래를 취소하고 싶다면 -1을 입력하십시오.\n");
                int k = -10, b = -11;
                while(!((k == b) || (k == -1) || (b == -1))) {
                  printf("player %d : \n", i);
                  scanf("%d", &k);
                  printf("player %d : \n", a);
                  scanf("%d", &b);
                }
                if(k == b) {
                  printf("거래가 성사되었습니다.\n");
                  printf("현재 천연가스 %d만큼의 소유권이 player %d에서 player %d로 넘어갑니다.\n", amount, a, i);
                  brr[a].gas -= amount;
                  brr[a].money -= k;
                  brr[i].gas += amount;
                  brr[i].money -= k;
                } else {
                  printf("\n교환이 취소되었습니다.\n");
                }
              } else {
                printf("\n교환이 취소되었습니다.\n");
              }
            } else {
              puts("알 수 없는 광물이름입니다.");
            }
            puts("---------------------------");
          } else if(!strcmp(bash, "req_ter")) {
            int x, y;
            int ans;
            puts("교환하려는 땅의 좌표를 말하세요.");
            scanf("%d %d", &x, &y);
            while(arr[x][y].owner == i) {
              puts("이미 소유중인 땅입니다.");
              scanf("%d %d", &x, &y);
            }
            printf("해당 땅을 보유중인 플레이어는 player %d입니다.\n", arr[x][y].owner);
            printf("교환요청을 전송하겠습니까? [y : 1/n : 0]");
            scanf("%d", &ans);
            if(ans) {
              printf("\n*player %d가 답하는 질문입니다. 교환에 응하시겠습니까? [y : 1/n : 0]", arr[x][y].owner);
              scanf("%d", &ans);
              if(ans) {
                printf("\n가격협상을 시작합니다.\n");
                printf("player %d부터 번갈아가며 가격을 정합니다.\n", i);
                printf("가격은 두 플레이어가 같은 가격을 제시하기 전까지 계속 진행됩니다. 언제든지 거래를 취소하고 싶다면 -1을 입력하십시오.\n");
                int a = -10, b = -11;
                while(!((a == b) || (a == -1) || (b == -1))) {
                  printf("player %d : \n", i);
                  scanf("%d", &a);
                  printf("player %d : \n", arr[x][y].owner);
                  scanf("%d", &b);
                }
                if(a == b) {
                  printf("거래가 성사되었습니다.\n");
                  printf("현재 영토 %d %d는 소유권이 player %d에서 player %d로 넘어갑니다.\n", x, y, arr[x][y].owner, i);
                  brr[arr[x][y].owner].fac -= arr[x][y].fac;
                  brr[arr[x][y].owner].money += a;
                  arr[x][y].owner = i;
                  brr[arr[x][y].owner].fac += arr[x][y].fac;
                  brr[arr[x][y].owner].money -= a;
                } else {
                  printf("\n교환이 취소되었습니다.\n");
                }
              }
            } else {
              printf("\n교환이 취소되었습니다.\n");
            }
            puts("---------------------------");
          } else if(!strcmp(bash, "force_req")) {
            printf("땅의 강제교환은 돈의 손실 없이 많은 인구의 양으로 승부하는 방법입니다. \n또한, 강제적인 성격을 띄기 때문에 상대방의 동의여부는 중요하지 않습니다.\n");
            printf("빼앗고 싶은 땅의 좌표를 입력하십시오.");
            int x, y;
            int ans;
            scanf("%d %d", &x, &y);
            while(arr[x][y].owner == i) {
              puts("이미 소유중인 땅입니다.");
              scanf("%d %d", &x, &y);
            }
            printf("해당 땅을 보유중인 플레이어는 player %d입니다.\n", arr[x][y].owner);
            puts("인구대결을 진행합니다.");
            if(brr[arr[x][y].owner].population * 1.5 <= brr[i].population) {
              printf("Force_req를 진행할 수 있습니다. 진행할까요? [y : 1/ n : 0]");
              scanf("%d", &ans);
              if(ans) {
                printf("강제 바꾸기에 성공했습니다.\n");
                puts("전쟁으로 인한 피해로 국가의 인구 20%가 감소합니다.\n");
                brr[arr[x][y].owner].fac -= arr[x][y].fac;
                arr[x][y].owner = i;
                brr[i].fac += arr[x][y].fac;
                brr[i].population *= 0.8;
              } else {
                printf("강제 바꾸기를 취소합니다.");
              }
            } else {
              printf("인구 대결에서 이기지 못했습니다.");
            }
            puts("---------------------------");
          } else if(!strcmp(bash, "buy")) {
            int x, y;
            puts("어떤 영토를 구매하시겠습니까?");
            scanf("%d %d", &x, &y);
            printf("선택한 영토의 가격은 %d입니다. (가격은 영토에 매장되어있는 자원량에 맞게 책정됩니다.)", (arr[x][y].g_gas + arr[x][y].g_iron + arr[x][y].g_oil + arr[x][y].g_coal)/4);
            printf("구매하시겠습니까? [y : 1/n : 0]");
            int ans;
            scanf("%d", &ans);
            if(ans) {
              arr[x][y].owner = i;
              brr[i].population += arr[x][y].population;
              printf("구매에 성공했습니다.\n");
            } else {
              printf("구매가 거부되었습니다.\n");
            }
            puts("---------------------------");
          } else if(!strcmp(bash, "finish")) {
            puts("턴을 종료합니다.");
            puts("---------------------------");
            break;
          } else if(!strcmp(bash, "mine")) {
            int x, y, ans;
            char name[20];
            puts("채굴하려는 땅의 위치를 설정하십시오.");
            scanf("%d", &x); scanf("%d", &y);
            while(arr[x][y].owner != i) {
              puts("현재 채굴하려는 땅은 보유하고 있지 않습니다. 다시 설정해 주십시오.");
              scanf("%d", &x);
              if(x == -1) {
                puts("채굴을 취소합니다.\n");
                break;
              }
              scanf("%d", &y);
            }
            puts("채굴을 원하는 광석을 고르세요. 참고 자료로 현재 고른 땅의 매장량을 보여줍니다.");
            printf("%d %d의 정보 : \n", x, y);
            printf("철광석 매장량 : %d\n", arr[x][y].g_iron);
            printf("석탄 매장량 : %d\n", arr[x][y].g_coal);
            printf("원유 매장량 : %d\n", arr[x][y].g_oil);
            printf("천연가스 매장량 : %d\n", arr[x][y].g_gas);
            scanf("%s", name);
            if(!strcmp(name, "철광석")) {
              printf("채굴하고싶은 양을 말하세요. (0이상 %d이하)", arr[x][y].g_iron);
              scanf("%d", &ans);
              while(ans > arr[x][y].g_iron || ans < 0) {
                printf("채굴 불가능한 양입니다. 다시 입력해 주세요.\n");
                scanf("%d", &ans);
              }
              arr[x][y].g_iron -= ans;
              brr[i].iron += ans;
              brr[i].money -= ans/3+1;
              puts("광물을 성공적으로 채굴하였습니다.");
            } else if(!strcmp(name, "석탄")) {
              printf("채굴하고싶은 양을 말하세요. (0이상 %d이하)", arr[x][y].g_coal);
              scanf("%d", &ans);
              while(ans > arr[x][y].g_coal || ans < 0) {
                printf("채굴 불가능한 양입니다. 다시 입력해 주세요.\n");
                scanf("%d", &ans);
              }
              arr[x][y].g_coal -= ans;
              brr[i].coal += ans;
              brr[i].money -= ans/3+1;
              puts("광물을 성공적으로 채굴하였습니다.");
            } else if(!strcmp(name, "원유")) {
              printf("채굴하고싶은 양을 말하세요. (0이상 %d이하)", arr[x][y].g_oil);
              scanf("%d", &ans);
              while(ans > arr[x][y].g_oil || ans < 0) {
                printf("채굴 불가능한 양입니다. 다시 입력해 주세요.\n");
                scanf("%d", &ans);
              }
              arr[x][y].g_oil -= ans;
              brr[i].oil += ans;
              brr[i].money -= ans/3+1;
              puts("광물을 성공적으로 채굴하였습니다.");
            } else if(!strcmp(name, "천연가스")) {
              printf("채굴하고싶은 양을 말하세요. (0이상 %d이하)", arr[x][y].g_gas);
              scanf("%d", &ans);
              while(ans > arr[x][y].g_gas || ans < 0) {
                printf("채굴 불가능한 양입니다. 다시 입력해 주세요.\n");
                scanf("%d", &ans);
              }
              arr[x][y].g_gas -= ans;
              brr[i].gas += ans;
              brr[i].money -= ans/3+1;
              puts("광물을 성공적으로 채굴하였습니다.");
            } else {
              printf("알 수 없는 광석입니다.");
            }
            puts("---------------------------");
          } else {
            puts("알 수 없는 명령어 입니다. 다시 입력해 주십시오.");
          }
        }
      } else {
        puts("이미 배제된 플레이어 입니다. 스킵합니다.\n");
        puts("---------------------------");
      }
    }
    for(int i=1;i<=19;i++) {
      for(int j=1;j<=19;j++) {
        arr[i][j].population += 10;
        brr[arr[i][j].owner].population += 10;
      }
    }
  }
}
