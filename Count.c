#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char cha;
	int countAll=0;
	int countExc=0;
	int countAlp = 0;
	FILE* fps;

	fps = fopen("Demian.txt", "rt");
	if (fps == NULL) {
		printf("실패 - 종료\n");
		return 1;
	}
	printf("텍스트 내용:\n");
	while (feof(fps) == 0) {
		fscanf(fps, "%c", &cha);
		printf("%c", cha);
		countAll++;

		if (cha == ' '){
			countExc++;
		}
		else if (cha >= 'A' && cha <= 'z') {
			countAlp++;
		}
		
	}

	fclose(fps);


	printf("\n");

	printf("공백 포함 : %d\n", countAll);
	printf("공백 미포함 : %d\n", countAll-countExc);
	printf("알파벳 수 : %d\n", countAlp);
	return 0;
}