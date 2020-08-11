#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEE 100

typedef struct _Employee {
	char name[21];		// 사원 이름
	char position[11];	// 사원 직책
	char team[51];		// 사원 부서
	int id;				// 사원 번호
} Employee;

Employee employee[MAX_EMPLOYEE];
int index = 0;

void printMenu();
void selectMenu(int input);
void addEmployee();
void fireEmployee();
void printEmployee();

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
		addEmployee();
		break;
	case 2:
		printf("\n[사원 해고]\n");
		fireEmployee();
		break;
	case 3:
		printf("\n[사원 출력]\n");
		printEmployee();
		break;
	case 4:
		printf("프로그램을 종료합니다.\n");
		exit(0);
	default:
		break;
	}
	printf("\n");
}

void addEmployee() {
	if (index < MAX_EMPLOYEE) {
		int id;
		char name[21], position[11], team[51];

		printf("사원 번호를 입력해주세요 : "); scanf("%d", &id);
		printf("이름을 입력해주세요 : "); scanf("%s", name);
		printf("부서를 입력해주세요 : "); scanf("%s", team);
		printf("직책을 입력해주세요 : "); scanf("%s", position);

		employee[index].id = id;
		strcpy(employee[index].name, name);
		strcpy(employee[index].team, team);
		strcpy(employee[index].position, position);

		++index;
	}
	else
		printf("ERROR : 사원은 최대 100명 입니다.");
}

void fireEmployee() {
	int id;

	printf("해고할 사원의 번호를 입력해주세요 : "); scanf("%d", &id);

	for (int i = 0; i < index; i++) {
		if (employee[i].id == id) {
			printf("%d - %s의 사원을 해고합니다.\n", 
				employee[i].id, employee[i].name);
			for (int j = i; j < index; j++) {
				employee[j] = employee[j + 1];
			}
			index--;
			return;
		}
	}

	printf("ERROR : 사원을 찾을 수 없습니다.\n");
}

void printEmployee() {
	for (int i = 0; i < index; i++) {
		printf("사원 번호 : %d\n", employee[i].id);
		printf("사원 이름 : %s\n", employee[i].name);
		printf("사원 부서 : %s\n", employee[i].team);
		printf("사원 직책 : %s\n", employee[i].position);
		printf("\n");
	}
}