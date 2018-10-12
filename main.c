/* Name: main.c  ver 1.1
* Content: main 함수.
* Implementation: YSW
* 
* Last modified 2008/01/01
*/
# define _CRT_SECURE_NO_WARNINGS

#include "common.h"
#include "screenOut.h"
#include "phoneFunc.h"
enum {
	INPUT=1, 
	SHOWALL, 
	SEARCH, 
	DELETE, 
	QUIT
};


/* 함    수: int main (void)
* 기    능: 사용자 선택 처리. 
* 반    환: 정상 종료 시 0.
*/
int main(void)
{
	int inputMenu = 0;
	while(1)
	{
		ShowMenu();
		fputs("선택하세요 : ", stdout);
		scanf("%d", &inputMenu);
		//fflush(stdin);

		switch(inputMenu)
		{
		case INPUT:
			InputPhoneData();
			break;
		case SHOWALL:
			ShowAllData();
			break;
		case SEARCH:
			SearchPhoneData();
			break;
		case DELETE:
			DeletePhoneData();
			break;        
		}

		if(inputMenu==QUIT)
		{
			puts("이용해 주셔서 고마워요~");
			break;
		}
	}    
	return 0;
}

/* end of file */

/*
//함수
call by value
call by reference
*/

