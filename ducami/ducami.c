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
