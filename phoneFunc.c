/* Name: phoneFunc.c  ver 1.3
 * Content: ��ȭ��ȣ ��Ʈ�� �Լ�.
 * Implementation: YSW
 * 
 * Last modified 2008/01/01
 */

#include "common.h"
#include "phoneData.h"
#include "screenOut.h"

#define LIST_NUM   100

int numOfData=0;

// phoneData phoneList[LIST_NUM];
phoneData * phoneList[LIST_NUM];

/* ��    ��: void InputPhoneData(void)
 * ��    ��: ��ȭ��ȣ ���� ������ �Է� �޾Ƽ� ����. 
 * ��    ȯ: void.
 *
 */
void InputPhoneData(void)
{
    // phoneData data;
    phoneData * pData;
    
    if(numOfData>=LIST_NUM)
    {
        puts("�޸� ������ �����մϴ�.");
        return;
    }
    
    pData = (phoneData *)malloc(sizeof(phoneData));  // ���� �߰�!

    fputs("�̸� �Է�: ", stdout);
    // gets(data.name);
    gets(pData->name);
    
    fputs("��ȭ��ȣ �Է�: ", stdout);
    // gets(data.phoneNum);
    gets(pData->phoneNum);
    
    // phoneList[numOfData]=data;
    phoneList[numOfData]=pData;

    numOfData++;
    
    puts("�Է��� �Ϸ�Ǿ����ϴ�.");
    getchar();
}

/* ��    ��: void ShowAllData(void)
 * ��    ��: ����� ������ ��ü ���. 
 * ��    ȯ: void.
 *
 */
void ShowAllData(void)
{
    int i;
    
    for(i=0; i<numOfData; i++)
    {
        // ShowPhoneInfo(phoneList[i]);
        ShowPhoneInfoByPtr(phoneList[i]);
    }
    
    puts("����� �Ϸ�Ǿ����ϴ�.");
    getchar();
}

/* ��    ��: void SearchPhoneData(void)
 * ��    ��: �̸��� ���� ������ �˻�. 
 * ��    ȯ: void.
 *
 */
void SearchPhoneData(void)
{
    int i;
    char searchName[NAME_LEN];
    
    fputs("ã�� �̸���? ", stdout);
    gets(searchName);
    
    for(i=0; i<numOfData; i++)
    {
        //if(!strcmp(phoneList[i].name, searchName))
        if(!strcmp(phoneList[i]->name, searchName))
        {
            // ShowPhoneInfo(phoneList[i]);
            ShowPhoneInfoByPtr(phoneList[i]);

            puts("�˻��� �Ϸ�Ǿ����ϴ�.");
            getchar();
            return;
        }
    }
    	
    puts("ã�� �̸��� �����Ͱ� �������� �ʽ��ϴ�.");
    getchar();
}

/* ��    ��: void DeletePhoneData(void)
 * ��    ��: �̸��� �����Ͽ� ������ ����. 
 * ��    ȯ: void.
 *
 */
void DeletePhoneData(void)
{
    int i, j;
    char delName[NAME_LEN];
    
    fputs("ã�� �̸���? ", stdout);
    gets(delName);
    
    for(i=0; i<numOfData; i++)
    {
        // if(!strcmp(phoneList[i].name, delName))
        if(!strcmp(phoneList[i]->name, delName))
        {
            free(phoneList[i]);  // ���� �߰�!

            for(j=i; j<numOfData-1; j++)
            {
                phoneList[j]=phoneList[j+1];
            }
    
            numOfData--;
            puts("������ �Ϸ�Ǿ����ϴ�.");
            getchar();
            return;
        }
    }
    
    puts("ã�� �̸��� �����Ͱ� �������� �ʽ��ϴ�.");
    getchar();
}


/* end of file */