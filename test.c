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

#define debug printf
#define FAILURE -1
#define SUCCESS 0

int returnResult[21];
char* result[21];

char* info[23] =
{
    "==================================retrun test report====================================",
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
    "TC7.2:   DeleteMenu(tMenu)",
    "======================================Test Result======================================="
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
        result[i] = "Not pass";
    }

    /*test return of CreateMenu()*/
    i = 0;
    debug("\n\033[;32mTest function of create menu:\033[0m\n");
    tMenu *createMenu = CreateMenu();
    if(createMenu == NULL)
    {
        debug("\nCreate menu fail.\n");
        returnResult[i++] = 1;
    }
    else
    {
        debug("\nCreate menu success~\n");
        result[i] = "Pass";
        returnResult[i++]  = 0;
    }

    /*test return of AddCommand (does not matter the 4th parameter is null or not null)*/
    debug("\n\033[;32mTest return of add command(no less than one null in parameters):\033[0m\n");
    char* pCommand = "Test";
    char* pDesc = "Testing...";  
    int addCmd = AddCommand(NULL, NULL, NULL, Help);
    if(addCmd != FAILURE)
    {
        debug("\nAdd command %s success.\n", pCommand);
        returnResult[i++] = 0;       
    }
    else
    {
        debug("\nAdd command %s fail.\n", pCommand);
        result[i] = "Pass";
        i++;
    }   
    addCmd = AddCommand(createMenu, NULL, NULL, Help);
    if(addCmd != FAILURE)
    {
        debug("\nAdd command %s success.\n", pCommand);
        returnResult[i++] = 0;
    }
    else
    {
        debug("\nAdd command %s fail.\n", pCommand);
        result[i] = "Pass";
        i++;
    }    
    addCmd = AddCommand(NULL, pCommand, NULL, Help);
    if(addCmd != FAILURE)
    {
        debug("\nAdd command %s success.\n", pCommand);
        returnResult[i++] = 0;
    }
    else
    {
        debug("\nAdd command %s fail.\n", pCommand);
        result[i] = "Pass";
        i++;
    } 
    addCmd = AddCommand(NULL, NULL, pDesc, Help);
    if(addCmd != FAILURE)
    {
        debug("\nAdd command %s success.\n", pCommand);
        returnResult[i++] = 0;       
    }
    else
    {
        debug("\nAdd command %s fail.\n", pCommand);
        result[i] = "Pass";
        i++;
    } 
    addCmd = AddCommand(createMenu, pCommand, NULL, Help);
    if(addCmd != FAILURE)
    {
        debug("\nAdd command %s success.\n", pCommand);
        returnResult[i++] = 0;       
    }
    else
    {
        debug("\nAdd command %s fail.\n", pCommand);
        result[i] = "Pass";
        i++;
    } 
    addCmd = AddCommand(createMenu, NULL, pDesc, Help);
    if(addCmd != FAILURE)
    {
        debug("\nAdd command %s success.\n", pCommand);
        returnResult[i++] = 0;       
    }
    else
    {
        debug("\nAdd command %s fail.\n", pCommand);
        result[i] = "Pass";
        i++;
    } 
    addCmd = AddCommand(NULL, pCommand, pDesc, Help);
    if(addCmd != FAILURE)
    {
        debug("\nAdd command %s success.\n", pCommand);
        returnResult[i++] = 0;       
    }
    else
    {
        debug("\nAdd command %s fail.\n", pCommand);
        result[i] = "Pass";
        i++;
    } 
    debug("\n\033[;32mTest function of add command(correct parameters):\033[0m\n");
    addCmd = AddCommand(createMenu, "cmdlist", "This command show all commands!", ShowAllCommand);
    AddCommand(createMenu, "help", "This command show you what all of these commands are use for!",
               ShowAllInformation);
    AddCommand(createMenu, "version", "This command show version number!", GetVersion);
    AddCommand(createMenu, "exit", "This command can exit menu!", MenuStop);
    if(addCmd == SUCCESS)
    {
        debug("\nAdd command %s success.\n", pCommand);
        result[i] = "Pass";
        returnResult[i++] = 0;       
    }
    else
    {
        debug("\nAdd command %s fail.\n", pCommand);
        i++;
    } 

    /*test return of ShowAllCommand(tMenu *pMenu)*/
    debug("\n\033[;32mTest return of show command(no less than one null in parameters):\033[0m\n");
    int showCmd = ShowAllCommand(NULL);
    if(showCmd != FAILURE)
    {
        debug("\nShow all commands success.\n");
        returnResult[i++] = 0;
    }
    else
    {
        debug("\nShow all commands fail.\n");
        result[i] = "Pass";
        i++;
    }
    debug("\n\033[;32mTest function of show command(correct parameters):\033[0m\n");
    showCmd = ShowAllCommand(createMenu);
    if(showCmd == SUCCESS)
    {
        debug("\nShow all commands success.\n");
        result[i] = "Pass";
        returnResult[i++] = 0;
    }
    else
    {
        debug("\nShow all commands fail.\n");
        i++;
    }
 
    /*test return of ShowAllInformation(tMenu *pMenu)*/
    debug("\n\033[;32mTest return of show information(no less than one null in parameters):\033[0m\n");
    int showInfo = ShowAllInformation(NULL);
    if(showInfo != FAILURE)
    {
        debug("\nShow all information success.\n");
        returnResult[i++] = 0;
    }
    else
    {
        debug("\nShow all information fail.\n");
        result[i] = "Pass";
        i++;
    }
    debug("\n\033[;32mTest function of show information(correct parameters):\033[0m\n");
    showInfo = ShowAllInformation(createMenu);
    if(showInfo == SUCCESS)
    {
        debug("\nShow all information success.\n");
        result[i] = "Pass";
        returnResult[i++] = 0;
    }
    else
    {
        debug("\nShow all information fail.\n");
        i++;
    }
    debug("\n\033[;32mTest function of menu start:\033[0m\n");
    MenuStart(createMenu);

    /*test return of MenuStop(tMenu *pMenu)*/
    debug("\n\033[;32mTest return of menu stop(no less than one null in parameters):\033[0m\n");
    int menuStop = MenuStop(NULL);
    if(menuStop != FAILURE)
    {
        debug("\nmenu stop success.\n");
        returnResult[i++] = 0;
    }
    else
    {
        debug("\nmenu stop fail.\n");
        result[i] = "Pass";
        i++;
    }
    debug("\n\033[;32mTest function of menu stop(correct parameters):\033[0m\n");
    menuStop = MenuStop(createMenu);
    if(menuStop == SUCCESS)
    {
        debug("\nmenu stop success.\n");
        result[i] = "Pass";
        returnResult[i++] = 0;
    }
    else
    {
        debug("\nmenu stop fail.\n");
        i++;
    }

    /*test return of DeleteCommand(tMenu *pMenu, char* pCommand)*/
    debug("\n\033[;32mTest return of delete command(no less than one null in parameters):\033[0m\n");
    int deleteCmd = DeleteCommand(NULL, NULL);
    if(deleteCmd != FAILURE)
    {
        debug("\nDelete command success.\n");
        returnResult[i++] = 0;
    }
    else
    {
        debug("\nDelete command fail.\n");
        result[i] = "Pass";
        i++;
    }
    deleteCmd = DeleteCommand(NULL, pCommand);
    if(deleteCmd != FAILURE)
    {
        debug("\nDelete command success.\n");
        returnResult[i++] = 0;
    }
    else
    {
        debug("\nDelete command fail.\n");
        result[i] = "Pass";
        i++;
    }
    deleteCmd = DeleteCommand(createMenu, NULL);
    if(deleteCmd != FAILURE)
    {
        debug("\nDelete command success.\n");
        returnResult[i++] = 0;
    }
    else
    {
        debug("\nDelete command fail.\n");
        result[i] = "Pass";
        i++;
    }
    debug("\n\033[;32mTest function of delete command(correct parameters):\033[0m\n");
    deleteCmd = DeleteCommand(createMenu, "version");
    if(deleteCmd == SUCCESS)
    {
        debug("\nDelete command success.\n");
        result[i] = "Pass";
        returnResult[i++] = 0;
    }
    else
    {
        debug("\nDelete command fail.\n");
        i++;
    }
    debug("\n\033[;32mShow all command information after deleting command:\033[0m\n");
    ShowAllInformation(createMenu);

    /*test return of DeleteMenu(tMenu *pMenu)*/
    debug("\n\033[;32mTest return of delete menu(no less than one null in parameters):\033[0m\n");
    int deleteMenu = DeleteMenu(NULL);
    if(deleteMenu != FAILURE)
    {
        debug("\nDelete menu success.\n");
        returnResult[i++] = 0;
    }
    else
    {
        debug("\nDelete menu fail.\n");
        result[i] = "Pass";
        i++;
    }
    debug("\n\033[;32mTest function of delete menu(correct parameters):\033[0m\n");
    deleteMenu = DeleteMenu(createMenu);
    if(deleteMenu == SUCCESS)
    {
        debug("\nDelete menu success.\n");
        result[i] = "Pass";
        returnResult[i++] = 0;
    }
    else
    {
        debug("\nDelete menu fail.\n");
        i++;
    }
    debug("\n\033[;32mShow all command information after deleting menu:\033[0m\n");
    ShowAllInformation(createMenu);

    /*print the result*/
    printf("\n\033[;32m%s\033[0m\n", info[0]);
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
    printf("\n\033[;32m%s\033[0m\n", info[22]);
    for(i = 0; i < 21; i++)
    {
        printf("Testcase %s: %s\n\n", info[i+1], result[i]);
    }
    return 0;
}

int GetVersion(tMenu *pMenu)
{
    printf("Version: v3.1\n");
    return 0;
}

int Help()
{
}
