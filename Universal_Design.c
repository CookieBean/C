#include <stdio.h>
int isSensorOn = 0;
int state_a[3] = {0, 120, 240}; // 기본 차지 각도 30도
int state_b[3] = {60, 180, 300};
int arr[3] = {0, 0, 0};
int brr[3] = {0, 0, 0};
int absolute(int k) {
  if(k<0) return -k;
  else return k;
}
void rotation(int a, int person, int deg) {
  if(a == 1) {
    state_a[person]+=deg;
    for(int i=0;i<=2;i++) {
      if(state_a[i]-30<state_a[person] && i!=person) {
        state_a[i] = state_a[person]+30*i;
      }
    }
    for(int i=0;i<=2;i++) state_a[i] %= 360;
  }
  if(a == 2) {
    state_b[person]+=deg;
    for(int i=0;i<=2;i++) {
      if(state_b[i]-30<state_b[person] && i!=person) {
        state_b[i] = state_b[person]+30*i;
      }
    }
    for(int i=0;i<=2;i++) state_b[i] %= 360;
  }
}
int main() {
  while(1) {
    puts("-----할 동작-----");
    puts("1. 회전\n2. 입장\n3. 퇴장\n4. 현재 상태\n--------------------\n");
    int num, isPersonExist = 0;
    scanf("%d", &num);
    if(num == 1) {
      for(int i=0;i<3;i++) {
        if(arr[i] || brr[i]) isPersonExist = 1;
      }
      int person, deg, a;
      puts("1. 안쪽(a열), 2. 바깥쪽(b열)");
      while(1) {
        scanf("%d %d %d", &a, &person, &deg);
        if((a == 1 || a == 2) && person<=2 && person>=0) {
          rotation(a, person, deg);
          break;
        } else {
          puts("사용할 수 없는 인풋입니다");
        }
      }
    } else if(num == 2) {
      puts("앉고싶은 열을 선택하세요");
      puts("1. 안쪽(a열), 2. 바깥쪽(b열)");
      int a, min = 360, min_ch;
      while(1) {
        scanf("%d", &a);
        if(a == 1) {
          if(arr[0] && arr[1] && arr[2]) {
            puts("이미 해당 열에 모든 사람이 앉고 있습니다");
            break;
          }
          for(int i=0;i<3;i++) {
            if(min>absolute(state_a[i])) {
              min = absolute(state_a[i]);
              min_ch = i;
            }
          }
          rotation(1, min_ch, 360-min);
          break;
        } else if(a == 2) {
          if(brr[0] && brr[1] && brr[2]) {
            puts("이미 해당 열에 모든 사람이 앉고 있습니다");
            break;
          }
          for(int i=0;i<3;i++) {
            if(min>absolute(state_b[i])) {
              min = absolute(state_b[i]);
              min_ch = i;
            }
          }
          rotation(2, min_ch, 360-min);
          break;
        } else {
          puts("사용할 수 없는 인풋입니다");
        }
      }
    } else if(num == 3) {
      puts("현재 앉고 계신 의자의 열과 번호를 말해주세요");
      puts("*참고 : 1. 안쪽(a열), 2. 바깥쪽(b열)");
      int a, b;
      while(1) {
        scanf("%d %d", &a, &b);
        if(a == 1) {
          if(!arr[b]) {
            puts("해당 의자에 사람이 존재하지 않습니다.");
            break;
          }
          rotation(a, b, 360-state_a[b]);
          arr[b] = 0;
          break;
        }
        else if(a = 2) {
          if(!brr[b]) {
            puts("해당 의자에 사람이 존재하지 않습니다.");
            break;
          }
          rotation(a, b, 360-state_b[b]);
          brr[b] = 0;
          break;
        }
        else puts("사용할 수 없는 인풋입니다");
      }
    } else if(num == 4) {
      printf("--------------------------\na열 : 1번자리 : %d 탑승여부 : %d 2번자리 : %d 탑승여부 : %d 3번자리 : %d 탑승여부 : %d\n", state_a[0], arr[0], state_a[1], arr[1], state_a[2], arr[2]);
      printf("b열 : 1번자리 : %d 탑승여부 : %d 2번자리 : %d 탑승여부 : %d 3번자리 : %d 탑승여부 : %d\n--------------------------\n", state_b[0], brr[0], state_b[1], brr[1], state_b[2], brr[2]);
    } else {
      puts("사용할 수 없는 인풋입니다");
    }
  }
}
