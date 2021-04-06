#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

short checkSograim(char str[]){
	char arr[100] = { 0 };
	int i, j = -1;
	for (i = 0; i < strlen(str); i++){
		if (str[i] == '(' || str[i] == '{' || str[i] == '['){
			arr[++j] = str[i];
		}
		else if (str[i] == ')' || str[i] == '}' || str[i] == ']'){
			if (j == -1) return 0;
			if (abs(str[i] - arr[j] > 2)) return 0;
			j--;

			/*switch (str[i]){
			case ')':
				if (j != 0 && arr[j - 1] == '('){
					arr[j - 1] = '\0';
					j--;
				}
				else{
					return 0;
				}
				break;
			case '}':
				if (j != 0 && arr[j - 1] == '{'){
					arr[j - 1] = '\0';
					j--;
				}
				else{
					return 0;
				}
				break;
			case ']':
				if (j != 0 && arr[j - 1] == '['){
					arr[j - 1] = '\0';
					j--;
				}
			default:
				break;
			}*/
		}
	}
	if (j != -1)
		return 0;
	return 1;
}

int main(){
	char targil[] = "{(3+4)[5*7]4}";
	char targil2[] = "{([)*4+2(])";
	char targil3[] = "[{4}](3+1)";
	printf("%d\n", checkSograim(targil));
	printf("%d\n", checkSograim(targil2));
	printf("%d\n", checkSograim(targil3));

	system("pause");
	return 0;
}