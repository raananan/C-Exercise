#include<stdio.h>

void strcomb(char target[], char src[]);
void strcop(char target[], char src[]);
int strl(char str[]);
int main(){
	char st[30] = "hello world";
	char st2[] = "goodbye";
	printf("%d\n", strl(st));
	
	strcomb(st, st2);
	printf("%s\n", st);
	
	strcop(st, st2);
	printf("%s\n", st);
	
	return 0;
}
int strl(char str[]){
	int i=0;
	while(str[i]!='\0'){
		i++;
	}
	return i;
}
void strcop(char target[], char src[]){
	int i, j=strl(target);
	for(i=0;i<j;i++){
		target[i] = 0;
	}
	for(i=0;i<strl(src);i++){
		target[i] = src[i];
	}
}
void strcomb(char target[], char src[]){
	int i, j=0, k=strl(target), com=k+strl(src);
	for(i=k;i<com;i++){
		target[i] = src[j];
		j++;
	}	
}
