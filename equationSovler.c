/*
	Exercise 5
	Quadratic eqation solver
	EXTRA: make it solve more than one equation!
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void menu(char choice);
void linear(float a, float b);
void quadratic(float a, float b, float c);
void cubic(float a, float b, float c, int d);


int main(){

	char choice;
	
	printf("### MENU ###\n");
	printf("a: Linear equation\n");
	printf("b: Quadratic eqation\n");
	printf("c: Cubic eqation\n");
	
	choice = getchar();
	
	menu(choice);

	return 0;
}

void menu(char choice){

	float a, b, c;
	int d;

	switch(choice){
	
		case 'a':
			printf("Linear eqation solver\n");
			printf("Enter A:");
			scanf("%f", &a);
	
			printf("Enter B:");
			scanf("%f", &b);
	
			linear(a, b);
			break;
			
		case 'b': 
			printf("Quadratic eqation solver\n");
			printf("Enter A:");
			scanf("%f", &a);
	
			printf("Enter B:");
			scanf("%f", &b);
	
			printf("Enter C:");
			scanf("%f", &c);
			
			quadratic(a, b, c);
			break;
			
			case 'c': 
			printf("Cubic eqation solver\nOnly integers!\n");
			printf("Enter A:");
			scanf("%f", &a);
	
			printf("Enter B:");
			scanf("%f", &b);
	
			printf("Enter C:");
			scanf("%f", &c);
			
			printf("Enter D:");
			scanf("%d", &d);
			
			cubic(a, b, c, d);
			break;
		default:
			printf("ERROR: wrong input");
	}
}


void linear(float a, float b){
	
	float result;
	
	//calculating x
	result = ((b * -1)/a);
	printf("x = %0.3f\n", result);
	
}

void quadratic(float a, float b, float c){

	float determinant, firstResult, secondResult;
	
	if(a == 0){
		linear(b, c);
		return;
	}
	
	//calculating the determinant.
	determinant = ((pow(b,2)) - (4*a*c));
	
	//the equatoin is only solvable if the determinant is bigger than 0.
	if(determinant > 0){
	
		//caluclating x1
		firstResult = ((-b) + sqrt(determinant))/(2 * a);
		printf("x1 = %0.3f\n", firstResult);
		
		//caluclating x2
		secondResult = ((-b) - sqrt(determinant))/(2 * a);
		printf("x2 = %0.3f\n", secondResult);
	} else {
		printf("ERROR: the determinant is less than 0\n");
	}
}

void cubic(float a, float b, float c, int d){
	
	if(a == 0){
		quadratic(b, c, (float)d);
		return;
	}
	
	if(d == 0){
		quadratic(a, b, c);
		printf("x3 = 0\n");
		return;
	}
	
	int i, counter, MAX_FACTORS;
	MAX_FACTORS = 50;
	int factors[MAX_FACTORS];
	
	counter = 0;
	printf("factors of %d is:\n", d);
	
	//factorize the constant d
	for(int i = 1; i < d; ++i){
		if(d % i == 0){
			if(i <= MAX_FACTORS){
				factors[counter] = i;
				printf("%d\n", i);
				counter++;
			}
		}
	}
	
	printf("------\n");
	
	//test possible solutions of equation from the factors
	int numbersInFactorArr = counter;
	counter = 0;
	
	for(int j = 0; j < numbersInFactorArr; ++j){
		int factor = factors[j];
		
		if(((a*(pow(factor, 3))) + (b*(pow(factor, 2))) + (c*(factor)) + d) == 0){
			printf("%d is a solution\n", factor);
		}
		counter++;
	}
}

