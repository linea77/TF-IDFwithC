#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strlen()
#include <stdlib.h> //strcpy()
#include <math.h>
#include <ctype.h> //isupper()

//대문자 -> 소문자 변환 함수
void turn2Lower(char* str) {
	int len = strlen(str) + 1;
	for (int i = 0; i < len; i++) {
		if (isupper(str[i])) {
			str[i] = str[i] - 'A' + 'a';
		}
	}
}

//기호 제거
void removeSigns(char* str) {
	for (; *str; ++str) { //널문자가 나오면 False, 증가한 후 대입
		if ((*str < 'a') || (*str > 'z')) {
			strcpy(str, str + 1);
			str--;
		}
	}
}


int main(void) {
	double n = 0;


	
	//1. 중요도 구할 단어 입력받아 소문자로 바꿈
	char user[20];
	printf("단어를 입력하세요 : ");
	scanf("%s", &user);
	turn2Lower(user);

	//2. 파일열기
	FILE* fpsMain = fopen("Warhol.txt", "rt"); n++;
	FILE* fpsNJP = fopen("NamJunePark.txt", "rt"); n++;
	FILE* fpsBv = fopen("Beethoven.txt", "rt"); n++;
	FILE* fpsHay = fopen("Haydn.txt", "rt"); n++;
	FILE* fpsPcs = fopen("Picasso.txt", "rt"); n++;
	if( (fpsMain == NULL) || (fpsNJP == NULL)|| (fpsBv == NULL) || (fpsHay == NULL) || (fpsPcs == NULL)){
		printf("실패 - 종료\n");
		return 1;
	}

	
	//3. TF 구하기
	double TF = 0;
	
	char cha[20];
	char* word;
	while (feof(fpsMain) == 0) {
		fscanf(fpsMain, "%s", &cha);
		turn2Lower(cha);
		removeSigns(cha);
		//printf("%s\n", cha);
		int comp = strcmp(cha, user);
		if (comp == 0) {
			TF++;
		}
	}
	fclose(fpsMain);
	
	//4. DF구하기
	double DF = 0;
	if (TF != 0)
		DF++;

	while (feof(fpsNJP) == 0) {
		fscanf(fpsNJP, "%s", &cha);
		turn2Lower(cha);
		removeSigns(cha);
		//printf("%s\n", cha);
		
		int comp = strcmp(cha, user);
		if (comp == 0) {
			DF++;
			break;
		}
		
	}
	fclose(fpsNJP);

	while (feof(fpsBv) == 0) {
		fscanf(fpsBv, "%s", &cha);
		turn2Lower(cha);
		removeSigns(cha);
		//printf("%s\n", cha);
		
		int comp = strcmp(cha, user);
		if (comp == 0) {
			DF++;
			break;
		}
		
	}
	fclose(fpsBv);

	while (feof(fpsHay) == 0) {
		fscanf(fpsHay, "%s", &cha);
		turn2Lower(cha);
		removeSigns(cha);
		//printf("%s\n", cha);

		int comp = strcmp(cha, user);
		if (comp == 0) {
			DF++;
			break;
		}

	}
	fclose(fpsHay);

	
	while (feof(fpsPcs) == 0) {
		fscanf(fpsPcs, "%s", &cha);
		turn2Lower(cha);
		removeSigns(cha);
		//printf("%s\n", cha);

		int comp = strcmp(cha, user);
		if (comp == 0) {
			DF++;
			break;
		}

	}
	fclose(fpsPcs);
	

	//5. IDF 구하기
	double IDF = log(n / (1 + DF));

	//6. TF-IDF
	double TfIdf = DF * IDF;


	printf("TF : %f\n", TF);
	printf("DF : %f\n", DF);
	printf("IDF : %f\n", IDF);
	printf("TF-IDF : %f\n", TfIdf);
	printf("\n");

	return 0;
}