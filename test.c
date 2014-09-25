/**************************************************************************************************/
/* Copyright (C) RootAmaris                                                                       */
/*                                                                                                */
/*  FILE NAME             :  test.c                                                               */
/*  PRINCIPAL AUTHOR      :  RootAmaris                                                           */
/*  SUBSYSTEM NAME        :  test                                                                 */
/*  MODULE NAME           :  test                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/25                                                           */
/*  DESCRIPTION           :  This is a menu test program                                          */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by RootAmaris, 2014/09/25
 * 
 */

#include <stdio.h>
#include "menu.h"

#define debug
#define FAILURE -1
#define SUCCESS 0

int result[24];

char* info[15] =
{
    {"==================================test report===================================="},
    {"TC1.1:   CreateMenu[r null]"},
    {"TC1.2:   CreateMenu[r tMenu*]"},
    {"TC2.1:   CreateCmdNode(null, null, null)"},
    {"TC2.2:   CreateCmdNode(tMenu, null, null)"},
    {"TC2.3:   CreateCmdNode(null, char*, null)"},
    {"TC2.4:   CreateCmdNode(null, null, char*)"},
    {"TC2.5:   CreateCmdNode(tMenu, char*, null)"},
    {"TC2.6:   CreateCmdNode(tMenu, null, char*)"},
    {"TC2.7:   CreateCmdNode(null, char*, char*)"},
    {"TC2.8:   CreateCmdNode(tMenu, char*, char*)"},
    {"TC3.1:   ShowAllCommand(null)"},
    {"TC3.2:   ShowAllCommand(tMenu)"},
    {"TC4.1:   ShowAllInformation(null)"},
    {"TC4.2:   ShowAllInformation(tMenu)"}
};

int Help();

int main()
{
    int i;
    for(i = 0; i < 24; i++)
    {
        result[i] = 1;
    }
    tMenu *createMenu = CreateMenu();
    if(createMenu == NULL)
    {
        debug("TC1.1 fail.\n");
        result[0] = 1;
    }
    else
    {
        debug("TC1.1 Success.\n");
        result[1]  = 0;
    }
    printf("\n%s\n", info[0]);
    for(i = 0; i < 2; i++)
    {
        if(result[i] == 1)
        {
            printf("Testcase Number 1.%d : %s\n%s\n",i+1, info[i+1], "Failure");               
        }
        else
        {
            printf("Testcase Number 1.%d : %s\n%s\n",i+1, info[i+1], "Success");
        }
    }

    tMenu *pMenu1 = NULL;
    char* pCommand1 = NULL;
    char* pCommand2 = "testcmd";
    char* pDesc1 = NULL;
    char* pDesc2 = "testdesc";
   
    int addCmd = AddCommand(pMenu1, pCommand1, pDesc1, Help);
    if(addCmd != FAILURE)
    {
        debug("TC2.1 fail.\n");
        result[2] = 0;       
    }
   
    addCmd = AddCommand(createMenu, pCommand1, pDesc1, Help);
    if(addCmd != FAILURE)
    {
        debug("TC2.2 fail.\n");
        result[3] = 0;
    }   
   
    addCmd = AddCommand(pMenu1, pCommand2, pDesc1, Help);
    if(addCmd != FAILURE)
    {
        debug("TC2.3 success.\n");
        result[4] = 0;
    }
   
    addCmd = AddCommand(pMenu1, pCommand1, pDesc2, Help);
    if(addCmd != FAILURE)
    {
        debug("TC2.4 success.\n");
        result[5] = 0;       
    }

    addCmd = AddCommand(createMenu, pCommand2, pDesc1, Help);
    if(addCmd != FAILURE)
    {
        debug("TC2.5 success.\n");
        result[6] = 0;       
    }

    addCmd = AddCommand(createMenu, pCommand1, pDesc2, Help);
    if(addCmd != FAILURE)
    {
        debug("TC2.6 success.\n");
        result[7] = 0;       
    }

    addCmd = AddCommand(pMenu1, pCommand2, pDesc2, Help);
    if(addCmd != FAILURE)
    {
        debug("TC2.7 success.\n");
        result[8] = 0;       
    }

    addCmd = AddCommand(createMenu, pCommand2, pDesc2, Help);
    if(addCmd == SUCCESS)
    {
        debug("TC2.8 success.\n");
        result[9] = 0;       
    }

     /* more test case ...*/

    /* test report */
    printf("\n%s\n", info[0]);
    for(i = 2; i < 10; i++)
    {
        if(result[i] == 1)
        {
            printf("Testcase Number 2.%d : %s\n%s\n",i-1, info[i+1], "Failure");               
        }
        else
        {
            printf("Testcase Number 2.%d : %s\n%s\n",i-1, info[i+1], "Success");
        }
    }

    int showCmd = ShowAllCommand(pMenu1);
    if(showCmd != FAILURE)
    {
        debug("TC3.1 success.\n");
        result[10] = 0;
    }
    showCmd = ShowAllCommand(createMenu);
    if(showCmd == SUCCESS)
    {
        debug("TC3.1 success\n");
        result[11] = 0;
    }
    printf("\n%s\n", info[0]);
    for(i = 10; i < 12; i++)
    {
        if(result[i] == 1)
        {
            printf("Testcase Number 3.%d : %s\n%s\n", i-9, info[i+1], "Failure");               
        }
        else
        {
            printf("Testcase Number 3.%d : %s\n%s\n", i-9, info[i+1], "Success");
        }
    }

    int showInfo = ShowAllInformation(pMenu1);
    if(showInfo != FAILURE)
    {
        debug("TC4.1 success.\n");
        result[12] = 0;
    }
    showInfo = ShowAllInformation(createMenu);
    if(showInfo == SUCCESS)
    {
        debug("TC4.2 success\n");
        result[13] = 0;
    }
    printf("\n%s\n", info[0]);
    for(i = 12; i < 14; i++)
    {
        if(result[i] == 1)
        {
            printf("Testcase Number 4.%d : %s\n%s\n", i-11, info[i+1], "Failure");               
        }
        else
        {
            printf("Testcase Number 4.%d : %s\n%s\n", i-11, info[i+1], "Success");
        }
    }

    return 0;
}

int Help()
{
}
