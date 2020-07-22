#include <stdio.h>
#include <string.h>

#define MAX_STAFF 100

typedef struct _STAFF {
	char name[21];
	char position[11];
	char team[51];
	int id;
} STAFF;

STAFF staff[MAX_STAFF];
int index = 0;

void printMenu();
void selectMenu(int input);
void addStaff();
void fireStaff();
void printStaff();

int main() {
	int input = 0;

	while (1) {
		printMenu();
		printf("선택 : ");  scanf("%d", &input);
		selectMenu(input);
	}
}

void printMenu() {
	printf("----메뉴----\n");
	printf("1. 사원 추가\n");
	printf("2. 사원 삭제\n");
	printf("3. 사원 출력\n");
	printf("4. 종료\n");
}

void selectMenu(int input) {
	switch (input)
	{
	case 1:
		printf("\n[사원 추가]\n");
		addStaff();
		break;
	case 2:
		printf("\n[사원 해고]\n");
		fireStaff();
		break;
	case 3:
		printf("\n[사원 출력]\n");
		printStaff();
		break;
	case 4:
		printf("프로그램을 종료합니다.\n");
		exit(0);
	default:
		break;
	}
	printf("\n");
}

void addStaff() {
	int id;
	char name[21], position[11], team[51];

	printf("사원 번호를 입력해주세요 : "); scanf("%d", &id);
	printf("이름을 입력해주세요 : "); scanf("%s", name);
	printf("부서를 입력해주세요 : "); scanf("%s", team);
	printf("직책을 입력해주세요 : "); scanf("%s", position);

	staff[index].id = id;
	strcpy(staff[index].name, name);
	strcpy(staff[index].team, team);
	strcpy(staff[index].position, position);

	++index;
}

void fireStaff() {
	int id;

	printf("해고할 사원의 번호를 입력해주세요 : "); scanf("%d", &id);

	for (int i = 0; i < index; i++) {
		if (staff[i].id == id) {
			printf("%d - %s의 사원을 해고합니다.\n", staff[i].id, staff[i].name);
			for (int j = i; j < index; j++) {
				staff[j] = staff[j + 1];
			}
			index--;
			return;
		}
	}

	printf("사원을 찾을 수 없습니다.\n");
}

void printStaff() {
	for (int i = 0; i < index; i++) {
		printf("사원 번호 : %d\n", staff[i].id);
		printf("사원 이름 : %s\n", staff[i].name);
		printf("사원 부서 : %s\n", staff[i].team);
		printf("사원 직책 : %s\n", staff[i].position);
		printf("\n");
	}
}