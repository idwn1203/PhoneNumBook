/* Name: main.c  ver 1.1
* Content: main �Լ�.
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


/* ��    ��: int main (void)
* ��    ��: ����� ���� ó��. 
* ��    ȯ: ���� ���� �� 0.
*/
int main(void)
{
	int inputMenu = 0;
	while(1)
	{
		ShowMenu();
		fputs("�����ϼ��� : ", stdout);
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
			puts("�̿��� �ּż� ������~");
			break;
		}
	}    
	return 0;
}

/* end of file */

/*
//�Լ�
call by value
call by reference
*/

