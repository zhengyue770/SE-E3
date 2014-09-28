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

int returnResult[21];

char* info[22] =
{
    "==================================test report====================================",
    "TC1.1:   CreateMenu[]",
    "TC2.1:   AddCommand(null, null, null)",
    "TC2.2:   AddCommand(tMenu, null, null)",
    "TC2.3:   AddCommand(null, char*, null)",
    "TC2.4:   AddCommand(null, null, char*)",
    "TC2.5:   AddCommand(tMenu, char*, null)",
    "TC2.6:   AddCommand(tMenu, null, char*)",
    "TC2.7:   AddCommand(null, char*, char*)",
    "TC2.8:   AddCommand(tMenu, char*, char*)",
    "TC3.1:   ShowAllCommand(null)",
    "TC3.2:   ShowAllCommand(tMenu)",
    "TC4.1:   ShowAllInformation(null)",
    "TC4.2:   ShowAllInformation(tMenu)",
    "TC5.1:   MenuStop(null)",
    "TC5.2:   MenuStop(tMenu)",
    "TC6.1:   DeleteCommand(null, null)",
    "TC6.2:   DeleteCommand(null, char*)",
    "TC6.3:   DeleteCommand(tMenu, null)",
    "TC6.4:   DeleteCommand(tMenu, char*)",
    "TC7.1:   DeleteMenu(null)",
    "TC7.2:   DeleteMenu(tMenu)"
};

int Help();
int GetVersion(tMenu *pMenu);

int main()
{
    /*initialize result array*/
    int i;
    for(i = 0; i < 21; i++)
    {
        returnResult[i] = 1;
    }

    /*test return of CreateMenu()*/
    i = 0;
    tMenu *createMenu = CreateMenu();
    if(createMenu == NULL)
    {
        debug("TC1.1 fail.\n");
        returnResult[i++] = 1;
    }
    else
    {
        debug("TC1.1 Success.\n");
        returnResult[i++]  = 0;
    }

    /*test return of AddCommand (does not matter the 4th parameter is null or not null)*/
    char* pCommand = "Test";
    char* pDesc = "Testing...";  
    int addCmd = AddCommand(NULL, NULL, NULL, Help);
    if(addCmd != FAILURE)
    {
        debug("TC2.1 success.\n");
        returnResult[i++] = 0;       
    }
    else
    {
        debug("TC2.1 fail.\n");
        i++;
    }   
    addCmd = AddCommand(createMenu, NULL, NULL, Help);
    if(addCmd != FAILURE)
    {
        debug("TC2.2 success.\n");
        returnResult[i++] = 0;
    }
    else
    {
        debug("TC2.2 fail.\n");
        i++;
    }    
    addCmd = AddCommand(NULL, pCommand, NULL, Help);
    if(addCmd != FAILURE)
    {
        debug("TC2.3 success.\n");
        returnResult[i++] = 0;
    }
    else
    {
        debug("TC2.3 fail.\n");
        i++;
    } 
    addCmd = AddCommand(NULL, NULL, pDesc, Help);
    if(addCmd != FAILURE)
    {
        debug("TC2.4 success.\n");
        returnResult[i++] = 0;       
    }
    else
    {
        debug("TC2.4 fail.\n");
        i++;
    } 
    addCmd = AddCommand(createMenu, pCommand, NULL, Help);
    if(addCmd != FAILURE)
    {
        debug("TC2.5 success.\n");
        returnResult[i++] = 0;       
    }
    else
    {
        debug("TC2.5 fail.\n");
        i++;
    } 
    addCmd = AddCommand(createMenu, NULL, pDesc, Help);
    if(addCmd != FAILURE)
    {
        debug("TC2.6 success.\n");
        returnResult[i++] = 0;       
    }
    else
    {
        debug("TC2.6 fail.\n");
        i++;
    } 
    addCmd = AddCommand(NULL, pCommand, pDesc, Help);
    if(addCmd != FAILURE)
    {
        debug("TC2.7 success.\n");
        returnResult[i++] = 0;       
    }
    else
    {
        debug("TC2.7 fail.\n");
        i++;
    } 
    addCmd = AddCommand(createMenu, "cmdlist", "This command show all commands!", ShowAllCommand);
    AddCommand(createMenu, "help", "This command show you what all of these commands are use for!",
               ShowAllInformation);
    AddCommand(createMenu, "version", "This command show version number!", GetVersion);
    AddCommand(createMenu, "exit", "This command can exit menu!", MenuStop);
    if(addCmd == SUCCESS)
    {
        debug("TC2.8 success.\n");
        returnResult[i++] = 0;       
    }
    else
    {
        debug("TC2.3 fail.\n");
        i++;
    } 

    /*test return of ShowAllCommand(tMenu *pMenu)*/
    int showCmd = ShowAllCommand(NULL);
    if(showCmd != FAILURE)
    {
        debug("TC3.1 success\n");
        returnResult[i++] = 0;
    }
    else
    {
        debug("TC3.1 fail.\n");
        i++;
    } 
    showCmd = ShowAllCommand(createMenu);
    if(showCmd == SUCCESS)
    {
        debug("TC3.2 success\n");
        returnResult[i++] = 0;
    }
    else
    {
        debug("TC3.2 fail.\n");
        i++;
    }
 
    /*test return of ShowAllInformation(tMenu *pMenu)*/
    int showInfo = ShowAllInformation(NULL);
    if(showInfo != FAILURE)
    {
        debug("TC4.1 success.\n");
        returnResult[i++] = 0;
    }
    else
    {
        debug("TC4.1 fail.\n");
        i++;
    }
    showInfo = ShowAllInformation(createMenu);
    if(showInfo == SUCCESS)
    {
        debug("TC4.2 success.\n");
        returnResult[i++] = 0;
    }
    else
    {
        debug("TC4.2 fail.\n");
        i++;
    }

    MenuStart(createMenu);

    /*test return of MenuStop(tMenu *pMenu)*/
    int menuStop = MenuStop(NULL);
    if(menuStop != FAILURE)
    {
        debug("TC5.1 success.\n");
        returnResult[i++] = 0;
    }
    else
    {
        debug("TC5.1 fail.\n");
        i++;
    }
    menuStop = MenuStop(createMenu);
    if(menuStop == SUCCESS)
    {
        debug("TC5.2 success\n");
        returnResult[i++] = 0;
    }
    else
    {
        debug("TC5.2 fail.\n");
        i++;
    }

    /*test return of DeleteCommand(tMenu *pMenu, char* pCommand)*/
    int deleteCmd = DeleteCommand(NULL, NULL);
    if(deleteCmd != FAILURE)
    {
        debug("TC6.1 success.\n");
        returnResult[i++] = 0;
    }
    else
    {
        debug("TC6.1 fail.\n");
        i++;
    }
    deleteCmd = DeleteCommand(NULL, pCommand);
    if(deleteCmd != FAILURE)
    {
        debug("TC6.2 success\n");
        returnResult[i++] = 0;
    }
    else
    {
        debug("TC6.2 fail.\n");
        i++;
    }
    deleteCmd = DeleteCommand(createMenu, NULL);
    if(deleteCmd != FAILURE)
    {
        debug("TC6.3 success.\n");
        returnResult[i++] = 0;
    }
    else
    {
        debug("TC6.3 fail.\n");
        i++;
    }
    deleteCmd = DeleteCommand(createMenu, "version");;
    if(deleteCmd == SUCCESS)
    {
        debug("TC6.4 success\n");
        returnResult[i++] = 0;
        
    }
    else
    {
        debug("TC6.4 fail.\n");
        i++;
    }
    ShowAllInformation(createMenu);

    /*test return of DeleteMenu(tMenu *pMenu)*/
    int deleteMenu = DeleteMenu(NULL);
    if(deleteMenu != FAILURE)
    {
        debug("TC7.1 success.\n");
        returnResult[i++] = 0;
    }
    else
    {
        debug("TC7.1 fail.\n");
        i++;
    }
    deleteMenu = DeleteMenu(createMenu);
    if(deleteMenu == SUCCESS)
    {
        debug("TC7.2 success\n");
        returnResult[i++] = 0;
    }
    else
    {
        debug("TC7.2 fail.\n");
        i++;
    }
    ShowAllInformation(createMenu);

    /*print the result*/
    printf("\n%s\n", info[0]);
    for(i = 0; i < 21; i++)
    {
        if(returnResult[i] == 1)
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

int GetVersion(tMenu *pMenu)
{
    printf("Version: v1.2\n");
    return 0;
}

int Help()
{
}
