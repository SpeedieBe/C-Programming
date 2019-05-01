
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Function to Convert String to 8 bit checksum
int convertStringTo8Bit(char* string, int bit)
{
	int total=0,i=0,len=0;

	len=strlen(string);

	//Loop through string adding ascii values of subsets of array
	for (i = 0; i < len; i++)
	{
		//Check for overflow
		if(total>255)
		{
			total=(total-256);
		}

		//Add ascii values of string
		total+=string[i];

		//Check for overflow
		if(total>255)
		{
			total=(total-256);
		}
	}

	//return decimal values of 8 bit checksum
	return total;
}

//Function to Convert String to 16 bit checksum
int convertStringTo16Bit(char* string, int bit)
{
	int total=0,i=0,len=0,lf=0;

	len=strlen(string);

	//Check if padded is needed
	if(((len)%2)!=0)
	{
		lf=1;
	}

	//Loop through string adding ascii values of subsets of array
	for (i = 0; i <len; i+=2)
	{
		//Check for overflow
		if(total>65536)
		{
			total=(total-65536);
		}

		//if padded need and at end of string add pad
		if((i==(len-1)) && (lf==1))
		{
			total+='X';
		}

		//Add ascii values of string multiplying first characters by 256 to shift
		//add next subset
		total+=(string[i]*256);
		total+=string[i+1];

		//Check for overflow
		if(total>65536)
		{
			total=(total-65536);
		}
	}

	//return decimal values of 16 bit checksum
	return total;
}

//Function to Convert String to 32 bit checksum
int convertStringTo32Bit(char* string, int bit)
{
	int total=0,i=0,len=0,lf=0;

	len=strlen(string);

	if(((len)%4)!=0)
	{
		lf=(len%4);
	}

	//Check if padded is needed
	if(lf!=0)
	{
		//Add pads for as much as needed
		for(lf=lf;lf<=4;lf++)
		{
				strcat(string,"X");
		}
	}

	//Loop through string adding ascii values of subsets of array
	for (i = 0; i <len; i+=4)
	{
		//Check for overflow
		if(total>4294967296)
		{
			total=(total-4294967296);
		}

		//Add ascii values of string multiplying first characters by 16777216 to shift
		//add next subset	shifted by *65536
		//add next subset	shifted by *256
		//add next subset
		total+=(string[i]*16777216);
		total+=(string[i+1]*65536);
		total+=(string[i+2]*256);
		total+=(string[i+3]);

		//Check for overflow
		if(total>4294967296)
		{
			total=(total-4294967296);
		}

	}

	//return decimal values of 16 bit checksum
	return total;
}

int main(int argc, char **argv)
{
	//Define source (orginal) for input string and holder for the string, define
	//Length of string (len), integer value of checksum in decimal (checksum)
	char *orginal,*holder;
	int i=0,j=0,bit,checksum,len;
	int fsize=0;

	//Open input file
	FILE* fp;

	//Read file and allocate original and holder, copy input to original
	fp=fopen(argv[1], "rb");
	fseek(fp,0,SEEK_END);
	fsize=ftell(fp);
	fseek(fp, 0, SEEK_SET);
	orginal=malloc(sizeof(char)*fsize+4);
	holder=malloc(sizeof(char)*fsize+4);
	fread(orginal,fsize,1,fp);
	fclose(fp);

	//Take entered bit string and convert to integer then set to bit
	bit=atol(argv[2]);

	//copy original to holder string
	strcpy(holder,orginal);

	//Length is stringlenth of holder
	len=strlen(holder);

	//Print new line for formating
	printf("\n");

	//For loop to print all characters in holder array and new line every 40
	//characters
	for(i=0; i<len; i++)
	{
		printf("%c",holder[i]);
		j++;

		if(j%80==0 && j!=0)
		{
			printf("\n");
		}
	}

	//If the bit is 8 print new line & perform 8 bit checksum converstion
	if(bit==8)
	{
		{
			printf("\n");
		}
		checksum=convertStringTo8Bit(orginal,bit);
	}

	//If the bit is 16 print new line & perform 16 bit checksum converstion
	if(bit==16)
	{
		checksum=convertStringTo16Bit(orginal,bit);

		//Pad if needed
		if(((fsize)%2)!=0)
		{
			printf("X\n");
			fsize++;
		}

		//If not print new line by itself
		else
		{
			printf("\n");
		}
	}

	//If the bit is 32 print new line & perform 32 bit checksum converstion
	if(bit==32)
	{
		checksum=convertStringTo32Bit(orginal,bit);

		//Pad if needed
		if(((fsize)%4)!=0)
		{
			i=fsize%4;
			for(i=i;i<4;i++)
			{
				printf("X");
				fsize++;
			}
			printf("\n");
		}

		//If not print new line by itself
		else
		{
			printf("\n");
		}
	}

	//Print bit value and checksum decimal as hex then print number of characters
	printf("%2d bit checksum is %8x for all %4d chars\n", bit,checksum ,fsize);

	//Free allocated memory
	free(orginal);
	free(holder);

	return 0;
}
