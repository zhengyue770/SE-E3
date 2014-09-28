/**************************************************************************************************/
/* Copyright (C) RootAmaris                                                                       */
/*                                                                                                */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  RootAmaris                                                           */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/25                                                           */
/*  DESCRIPTION           :  This is a menu operation program                                     */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by RootAmaris, 2014/09/25
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

#define CMD_MAX_LEN 128
#define FAILURE -1
#define SUCCESS 0

/*menu struct*/
struct Menu
{
    ;
};

/*create a menu*/
tMenu* CreateMenu()
{
    tMenu *p = (tMenu *)malloc(sizeof(tMenu));
    return p;
}

/*add a command into menu*/
int AddCommand(tMenu *pMenu, char* pCommand, char* pDesc, int (*pOpt)())
{
    if(pMenu == NULL || pCommand == NULL || pDesc == NULL)
    {
        return FAILURE;
    }
    printf("function...\n");
    return SUCCESS;   
}

/*print all commands in menu on screen*/
int ShowAllCommand(tMenu *pMenu)
{
    if(pMenu == NULL)
    {
        return FAILURE;
    }
    printf("function...\n");
    return SUCCESS;   
}

/*print all commands and their functions on screen*/
int ShowAllInformation(tMenu *pMenu)
{
    if(pMenu == NULL)
    {
        return FAILURE;
    }
    printf("function...\n");
    return SUCCESS;
}

/*start the menu program*/
char pInputCmd[CMD_MAX_LEN];
void MenuStart(tMenu *pMenu)
{
    while(1)
    {
        if(pMenu == NULL)
        {
            printf("\nMenu start fail.\n");
            break;
        }
        printf("function...\n");
        break;
    } 
}

/*stop the menu program*/
int MenuStop(tMenu *pMenu)
{
    if(pMenu == NULL)
    {
        return FAILURE;
    }
    printf("function...\n");
    return SUCCESS;
}

/*delete command named pCommand*/
int DeleteCommand(tMenu *pMenu, char* pCommand)
{
    if(pMenu == NULL || pCommand == NULL)
    {
        return FAILURE;
    }
    printf("function...\n");
    return SUCCESS;
}

/*delete menu*/
int DeleteMenu(tMenu *pMenu)
{
    if(pMenu == NULL)
    {
        return FAILURE;
    }
    printf("function...\n");
    return SUCCESS;
}
