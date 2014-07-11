
#include"StdAfx.h"
#include <iostream>
#include <string>
#include "afx.h"
using namespace std;
void main()
{
	FILE *fp;
	int e=0;
	char buffer[20];
	CString str="C:\\Users\\M\\Documents\\Tencent Files\\1207662918\\Msg2.0.db";
	fp=fopen( (LPSTR)(LPCTSTR)str,"rb");
	int filesize;
	fseek(fp,0,2);
	filesize=ftell(fp);
	fseek(fp,0,0);
	for(;e<filesize;)
	{
		fread(buffer,20,1,fp);
		fseek(fp,e,0);
		if ((buffer[0]>=48&&buffer[0]<=57)&(buffer[2]>=48&&buffer[2]<=57)&(buffer[4]>=48&&buffer[4]<=57)&(buffer[6]>=48&&buffer[6]<=57)&(buffer[8]>=48&&buffer[8]<=57)
			& (buffer[10]>=48&&buffer[10]<=57)&(buffer[12]>=48&&buffer[12]<=57)&(buffer[14]>=48&&buffer[14]<=57)&(buffer[16]>=48&&buffer[16]<=57))
		{
			//printf("%c%c%c%c%c%c%c%c%c",buffer[0],buffer[2],buffer[4],buffer[6],buffer[8],buffer[10],buffer[12],buffer[14],buffer[16]);
			int realbuffer[10];
			for (int i=0;i<9;i++)
			{
				
				realbuffer[i]=buffer[2*i];
			}

			if (buffer[18]>=48&&buffer[18]<=57)
				{
					//printf("%c\n",buffer[18]);
					realbuffer[9]=buffer[18];
					printf("%c%c%c%c%c%c%c%c%c%c\n",realbuffer[0],realbuffer[1],realbuffer[2],realbuffer[3],realbuffer[4],realbuffer[5],realbuffer[6],realbuffer[7],realbuffer[8],realbuffer[9]);
					e+=20;
				}
			else
				{
					//printf("\n");
					printf("%c%c%c%c%c%c%c%c%c\n",realbuffer[0],realbuffer[1],realbuffer[2],realbuffer[3],realbuffer[4],realbuffer[5],realbuffer[6],realbuffer[7],realbuffer[8]);
					e+=16;
				}
			//printf("%s\n",realbuffer);							
		}
		e++;
	}
	cout<<endl<<"It is over!";
	}