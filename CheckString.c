#include<stdio.h>
#include<string.h>

int calcstr(char str[]);
int main(){
	int i, op_flag=0, notnum=0;
	char targil[] = "25-25";
	//check if legit
	for(i=0;i<strlen(targil);i++){
		if(!(isdigit(targil[i]))){
			if(targil[i]!='+' && targil[i]!='-' && targil[i]!='/' && targil[i]!='*'){
				notnum++;
				break;
			}
			else{
				op_flag++;
			}
		}
		else{
			continue;
		}
	}
	if(op_flag!=1 || notnum){
		printf("error! please rewrite your string!");
	}
	else{
		printf("%s result is %d", targil, calcstr(targil));
	}
	
	return 0;
}
int calcstr(char str[]){
	int i, i_sum = 0, sum[2] = {0}, res;
	char op;
	//num calculations
	for(i=0;i<strlen(str);i++){
		if(isdigit(str[i])){
			sum[i_sum]+=str[i]-48;
			if(i!=strlen(str)-1){
				if(isdigit(str[i+1])){
					sum[i_sum]*=10;
				}
			}
		}
		else{
			op=str[i];
			i_sum++;
		}
	}
	//operation select
	if(op=='+'){
		res=sum[0]+sum[1];
	}
	if(op=='-'){
		res=sum[0]-sum[1];
	}
	if(op=='/'){
		res=sum[0]/sum[1];
	}
	if(op=='*'){
		res=sum[0]*sum[1];
	}
	
	return res;
}
