
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void cleanKey(char* unfiltered)
{
		int i=0,j=0,len;
		char *tmp;

		tmp=malloc(sizeof(unfiltered)+1);

		len=strlen(unfiltered);

		for(i=0;i<=len;i++)
		{
			if((unfiltered[i]>='a') && (unfiltered[i]<='z') || (unfiltered[i]>='A') && (unfiltered[i]<= 'Z'))
			{
				tmp[j]=tolower(unfiltered[i]);
				j++;
			}
		}

		strcpy(unfiltered,tmp);

		free(tmp);
}

void filterKey(char* unfiltered)
{
		int i=0,j=0,len;
		char *tmp;

		tmp=malloc(sizeof(unfiltered)+1);

		len=strlen(unfiltered);

		for(i=0;i<=len;i++)
		{
			if((unfiltered[i]>='a') && (unfiltered[i]<='z') || (unfiltered[i]>='A') && (unfiltered[i]<= 'Z'))
			{
				tmp[j]=tolower(unfiltered[i]);
				j++;
			}
		}

		strcpy(unfiltered,tmp);

		if(j<512)
		{
				for(i=0;j<512;j++)
				{
					unfiltered[j]=unfiltered[i];
					i++;
				}
		}

		free(tmp);
}

void filterPlaintext(char* unfiltered)
{
		int i=0,j=0,len;
		char *tmp;

		tmp=malloc(sizeof(unfiltered)+1);

		len=strlen(unfiltered);

		for(i=0;i<=len;i++)
		{
			if((unfiltered[i]>='a') && (unfiltered[i]<='z') || (unfiltered[i]>='A') && (unfiltered[i]<= 'Z'))
			{
				tmp[j]=tolower(unfiltered[i]);
				j++;
			}
		}

		strcpy(unfiltered,tmp);

		if(j<512)
		{
				for(i=0;j<512;j++)
				{
					strcat(unfiltered,"x");
				}
		}

		free(tmp);
}

void vig(char *key, char *plaintext, char* ciphertext)
{
		int i=0;

		for(i=0;i<512;i++)
		{
			ciphertext[i]=('a'+(plaintext[i]-'a'+key[i]-'a')%26);
		}

		ciphertext[i]='\0';
}

int main(int argc, char **argv)
{
		int i,len,j=0;
		char plaintext[2000], ciphertext[2000], key[2000];
		long fsize;

		FILE* fp;

		fp=fopen(argv[1], "rb");
		fseek(fp,0,SEEK_END);
		fsize=ftell(fp);
		fseek(fp, 0, SEEK_SET);
		fread(key,fsize,1,fp);
		fclose(fp);

		fp=fopen(argv[2], "rb");
		fseek(fp,0,SEEK_END);
		fsize=ftell(fp);
		fseek(fp, 0, SEEK_SET);
		fread(plaintext,fsize,1,fp);
		fclose(fp);

		printf("\n\n");

		cleanKey(key);

		len=strlen(key);

		printf("Vigenere Key:\n\n");
		for(i=0;i<=len;i++)
		{
			printf("%c",key[i]);
			j++;

			if(j%80==0&j!=0)
			{
				printf("\n");
			}
		}

		printf("\n\n");

		filterKey(key);

		filterPlaintext(plaintext);

		len=strlen(plaintext);

		j=0;

		printf("\nPlaintext:\n\n");

		for(i=0;i<=len;i++)
		{
			printf("%c",plaintext[i]);
			j++;

			if(j%80==0&j!=0)
			{
				printf("\n");
			}
		}

		printf("\n\n");

		vig(key,plaintext,ciphertext);

		len=strlen(ciphertext);

		printf("\nCiphertext:\n\n");

		j=0;

		for(i=0;i<=len;i++)
		{
			printf("%c",ciphertext[i]);
			j++;

			if(j%80==0&j!=0)
			{
				printf("\n");
			}
		}

		return 0;
}
