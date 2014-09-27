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

int result[16];

char* info[17] =
{
    "==================================test report====================================",
    "TC1.1:   CreateMenu[r null]",
    "TC1.2:   CreateMenu[r tMenu*]",
    "TC2.1:   CreateCmdNode(null, null, null)",
    "TC2.2:   CreateCmdNode(tMenu, null, null)",
    "TC2.3:   CreateCmdNode(null, char*, null)",
    "TC2.4:   CreateCmdNode(null, null, char*)",
    "TC2.5:   CreateCmdNode(tMenu, char*, null)",
    "TC2.6:   CreateCmdNode(tMenu, null, char*)",
    "TC2.7:   CreateCmdNode(null, char*, char*)",
    "TC2.8:   CreateCmdNode(tMenu, char*, char*)",
    "TC3.1:   MenuStart(null)",
    "TC3.2:   MenuStart(tMenu)",
    "TC4.1:   MenuStop(null)",
    "TC4.2:   MenuStop(tMenu)",
    "TC5.1:   DeleteMenu(null)",
    "TC5.2:   DeleteMenu(tMenu)"
};

int Help();

int main()
{
    /*initialize result array*/
    int i;
    for(i = 0; i < 24; i++)
    {
        result[i] = 1;
    }

    /*test function of CreateMenu()*/
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

    /*test function of AddCommand (does not matter the 4th parameter is null or not null)*/
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

    /* test function of MenuStart(tMenu *pMenu)*/
    int menuStart = MenuStart(pMenu1);
    if(menuStart != FAILURE)
    {
        debug("TC3.1 success.\n");
        result[10] = 0;
    }
    menuStart = MenuStart(createMenu);
    if(menuStart == SUCCESS)
    {
        debug("TC3.2 success\n");
        result[11] = 0;
    }

    /*test function of MenuStop(tMenu *pMenu)*/
    int menuStop = MenuStop(pMenu1);
    if(menuStop != FAILURE)
    {
        debug("TC4.1 success.\n");
        result[12] = 0;
    }
    menuStop = MenuStop(createMenu);
    if(menuStop == SUCCESS)
    {
        debug("TC4.2 success\n");
        result[13] = 0;
    }

    /*test function of DeleteMenu(tMenu *pMenu)*/
    int deleteMenu = DeleteMenu(pMenu1);
    if(deleteMenu != FAILURE)
    {
        debug("TC5.1 success.\n");
        result[14] = 0;
    }
    deleteMenu = DeleteMenu(createMenu);
    if(deleteMenu == SUCCESS)
    {
        debug("TC5.2 success\n");
        result[15] = 0;
    }

    /*print the result*/
    printf("\n%s\n", info[0]);
    for(i = 0; i < 16; i++)
    {
        if(result[i] == 1)
        {
            printf("Testcase %s\n%s\n\n", info[i+1], "Failure");               
        }
        else
        {
            printf("Testcase %s\n%s\n\n", info[i+1], "Success");
        }
    }
    printf("%s\n", info[0]);
    return 0;
}

int Help()
{
}
