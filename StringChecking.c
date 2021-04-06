#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
char *func(char *str);
int main(){

	char str[] = "C exam question 4 SUMMER 2017";

	puts(func(str));

	system("pause");
	return 0;
}

char *func(char *str){

	char *newstring;
	int i = 0;
	int size;


	while (str[i] != '\0'){
		if (isalpha(str[i]) || isdigit(str[i]) || isspace(str[i])){
			i++;
		}
		else
		{
			return NULL;
		}

	}
	size = i;
	i = 0;
	newstring = (char*)calloc(size, sizeof(char));

	while (str[i] != '\0'){

		newstring[i] = (tolower(str[i]));
		
		i++;

	}

	newstring[i] = '\0';
	//puts(newstring);
	i = 0;
	if (isalpha(newstring[i])){
		newstring[i] = toupper(newstring[i]);
		i++;
	}
	while (newstring[i] != '\0'){
		if (isspace(newstring[i])){
			if (!isdigit(newstring[i + 1])){
				newstring[i + 1] = toupper(newstring[i + 1]);

			}

		}

		i++;
	}
	




	



	return newstring;

}