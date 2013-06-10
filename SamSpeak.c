/*
 ============================================================================
 Name        : SamSpeak.c
 Author      : Taha Ibrahim DRAIDIA
 Version     : 1.0
 Copyright   : Copyright 2012-2013 Taha Ibrahim DRAIDIA
 Description : Make Your Windows Computer Talk
 ============================================================================
 */
/*
 ============================================================================
   
    SamSpeak is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    SamSpeak is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with SamSpeak.  If not, see <http://www.gnu.org/licenses/>.
 ===========================================================================
*/
/********************************* Headers *********************************/

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define BUFSIZE 4096

/*==========================================================================*/
void intro()
{
    printf("\n");
	printf("\t////////////////////////////////////////////////////\n");
	printf("\t///////// SamSpeak By Taha Ibrahim DRAIDIA /////////\n");
	printf("\t////////////////////////////////////////////////////\n");
	printf("\n");
}

/*==========================================================================*/

void VbFile()
{
    DWORD dwRetVal;
    DWORD dwBufSize=BUFSIZE;    // length of the buffer
    char lpPathBuffer[BUFSIZE]; // buffer for path
    char both[100] = { 0 };
    char data[150];
    char *file = "Speak.vbs";
    // Get the temp path.
    dwRetVal = GetTempPath(dwBufSize, lpPathBuffer);

    if (dwRetVal > dwBufSize)
    {
        printf ("Get Temp Path failed with error %d.\n",
                GetLastError());
    }
    /*use strcat to concat the path with the file*/
    strcpy(both, lpPathBuffer);
    strcat(both, file);
    FILE *speech = fopen(both,"w");
    if(speech)
    {
       printf("Msg: ");
       gets(data);
       fprintf(speech,"Dim say\nSet say = WScript.CreateObject(\"SAPI.SpVoice\")\nsay.Speak \"%s\"", data);
       fclose(speech);
       /* use system () to execute the Speak.vbs */
       system(both);
    }
    else
    {
        printf("couldn't open the file\n");
    }
     return ;
}

/*==========================================================================*/

int main(void)
{
    SetConsoleTitle("SamSpeak By Taha Ibrahim DRAIDIA");
    intro();
    while(1)
    VbFile();
    return 0;
}
