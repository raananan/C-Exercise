#include<stdio.h>

int main(){
	int a, x=3;					//x=3	a=-
	printf("\n");				//x=3	a=-
	for(a=0;a<3;a++){			//x=3	a=0	-> x=2	a=1 -> x=2  a=2 -> x=2  a=3
		if(!a || x++){			//x=3	a=0	-> x=3  a=1 -> x=3  a=2
			x--;				//x=2	a=0 -> x=2  a=1 -> x=2  a=2
		}
	}							//x=2	a=3
	printf("%d", x);			//print 2 (x=2)
	x=3;						//x=3	a=3
	printf("\n");
	for(a=1;a<3;a++){			//x=3	a=1 -> x=3  a=2 -> x=3  a=3
		if(!a || x++){			//x=4	a=1 -> x=4  a=2
			x--;				//x=3	a=1 -> x=3  a=2
		}
	}							//x=3	a=3
	printf("%d", x);			//print 3 (x=3)
	x=13;						//x=13	a=3
	printf("\n");				
	for(a=7;a<x;a-=2){			//x=13	a=7 -> x=6  a=5 -> x=1  a=3
		x=x%a;					//x=6	a=7 -> x=1  a=5
	}							//x=1	a=3
	printf("%d", x);			//print 1 (x=1)
	
	return 0;
}
