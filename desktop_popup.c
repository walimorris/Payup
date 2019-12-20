#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{ 
	char command[100]; 	

	strcpy(command, "notify-send \"Hello World\""); 
	system(command); 

	return 0; 
	
} 
