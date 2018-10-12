/* Name: phoneFunc.c  ver 1.3
 * Content: 전화번호 컨트롤 함수.
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

/* 함    수: void InputPhoneData(void)
 * 기    능: 전화번호 관련 데이터 입력 받아서 저장. 
 * 반    환: void.
 *
 */
void InputPhoneData(void)
{
    // phoneData data;
    phoneData * pData;
    
    if(numOfData>=LIST_NUM)
    {
        puts("메모리 공간이 부족합니다.");
        return;
    }
    
    pData = (phoneData *)malloc(sizeof(phoneData));  // 새로 추가!

    fputs("이름 입력: ", stdout);
    // gets(data.name);
    gets(pData->name);
    
    fputs("전화번호 입력: ", stdout);
    // gets(data.phoneNum);
    gets(pData->phoneNum);
    
    // phoneList[numOfData]=data;
    phoneList[numOfData]=pData;

    numOfData++;
    
    puts("입력이 완료되었습니다.");
    getchar();
}

/* 함    수: void ShowAllData(void)
 * 기    능: 저장된 데이터 전체 출력. 
 * 반    환: void.
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
    
    puts("출력이 완료되었습니다.");
    getchar();
}

/* 함    수: void SearchPhoneData(void)
 * 기    능: 이름을 통한 데이터 검색. 
 * 반    환: void.
 *
 */
void SearchPhoneData(void)
{
    int i;
    char searchName[NAME_LEN];
    
    fputs("찾는 이름은? ", stdout);
    gets(searchName);
    
    for(i=0; i<numOfData; i++)
    {
        //if(!strcmp(phoneList[i].name, searchName))
        if(!strcmp(phoneList[i]->name, searchName))
        {
            // ShowPhoneInfo(phoneList[i]);
            ShowPhoneInfoByPtr(phoneList[i]);

            puts("검색이 완료되었습니다.");
            getchar();
            return;
        }
    }
    	
    puts("찾는 이름의 데이터가 존재하지 않습니다.");
    getchar();
}

/* 함    수: void DeletePhoneData(void)
 * 기    능: 이름을 참조하여 데이터 삭제. 
 * 반    환: void.
 *
 */
void DeletePhoneData(void)
{
    int i, j;
    char delName[NAME_LEN];
    
    fputs("찾는 이름은? ", stdout);
    gets(delName);
    
    for(i=0; i<numOfData; i++)
    {
        // if(!strcmp(phoneList[i].name, delName))
        if(!strcmp(phoneList[i]->name, delName))
        {
            free(phoneList[i]);  // 새로 추가!

            for(j=i; j<numOfData-1; j++)
            {
                phoneList[j]=phoneList[j+1];
            }
    
            numOfData--;
            puts("삭제가 완료되었습니다.");
            getchar();
            return;
        }
    }
    
    puts("찾는 이름의 데이터가 존재하지 않습니다.");
    getchar();
}


/* end of file */