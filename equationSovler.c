/*
	Exercise 5
	Quadratic eqation solver
	EXTRA: make it solve more than one equation!
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void menu(char choice);
void linear(double a, double b);
void quadratic(double a, double b, double c);
void cubic(int a, int b, int c, int d);
void printArray(int arr[], int numElements);

int main(){

	char choice;
	
	printf("### MENU ###\n");
	printf("a: Linear equation\n");
	printf("b: Quadratic eqation\n");
	printf("c: Cubic eqation. WORK IN PROGRESS!\n");
	
	choice = getchar();
	
	menu(choice);

	return 0;
}

void menu(char choice){

	double a, b, c;
	int ca,cb,cc,cd;
	int d;

	switch(choice){
	
		case 'a':
			printf("Linear eqation solver\n");
			printf("Enter A:");
			scanf("%lf", &a);
	
			printf("Enter B:");
			scanf("%lf", &b);
	
			linear(a, b);
			break;
			
		case 'b': 
			printf("Quadratic eqation solver\n");
			printf("Enter A:");
			scanf("%lf", &a);
	
			printf("Enter B:");
			scanf("%lf", &b);
	
			printf("Enter C:");
			scanf("%lf", &c);
			
			quadratic(a, b, c);
			break;
			
			case 'c': 
			printf("Cubic eqation solver\nOnly integers!\n");
			printf("Enter A:");
			scanf("%d", &ca);
	
			printf("Enter B:");
			scanf("%d", &cb);
	
			printf("Enter C:");
			scanf("%d", &cc);
			
			printf("Enter D:");
			scanf("%d", &cd);
			
			cubic(ca, cb, cc, cd);
			break;
		default:
			printf("ERROR: wrong input");
	}
}


void linear(double a, double b){
	
	double result;
	
	//calculating x
	result = (((b * -1)/a) * -1);
	printf("x = %0.3f\n", result);
	
}

void quadratic(double a, double b, double c){

	double determinant, firstResult, secondResult;
	
	if(a == 0){
		linear(b, c);
		return;
	}
	
	//calculating the determinant.
	determinant = ((pow(b,2)) - (4*a*c));
	
	//the equatoin is only solvable if the determinant is bigger than 0.
	if(determinant > 0){
	
		//caluclating x1
		firstResult = (((-b) + sqrt(determinant))/(2 * a) * -1);
		printf("x1 = %0.3f\n", firstResult);
		
		//caluclating x2
		secondResult = (((-b) - sqrt(determinant))/(2 * a) * -1);
		printf("x2 = %0.3f\n", secondResult);
	} else if(determinant == 0){
	
		firstResult = ((b * -1)/(2 * a) * -1);
		printf("x1 = %0.3f\n", firstResult);
	
	
	} else {
		printf("ERROR: Determinant < 0 \n");
	}
}

void cubic(int a, int b, int c, int d){
	
	if(a == 0){
		quadratic(b, c, (double)d);
		return;
	}
	
	if(d == 0){
		quadratic(a, b, c);
		printf("x3 = 0\n");
		return;
	}
	
	int i, counter, MAX_FACTORS, numbersInFactorA, numbersInFactorD;
	MAX_FACTORS = 50;
	int factorsA[MAX_FACTORS], factorsD[MAX_FACTORS]; 
	double allFactors[MAX_FACTORS];
	
	counter = 0;
	
	//factorize a
	printf("factors of a = %d is:\n", a);
	for(int i = 1; i <= a; ++i){
		if(a % i == 0){
			if(i <= MAX_FACTORS){
				factorsA[counter] = i;
				counter++;
			}
		}
	}
	numbersInFactorA = counter;
	printArray(factorsA, numbersInFactorA);
	counter = 0;
	
	
	//factorize the constant d
	printf("factors of d = %d is:\n", d);
	for(int i = 1; i <= d; ++i){
		if(d % i == 0){
			if(i <= MAX_FACTORS){
				factorsD[counter] = i;
				counter++;
			}
		}
	}
	
	numbersInFactorD = counter;
	printArray(factorsD, numbersInFactorD);
	counter = 0;
	
	printf("------------\n");
	
	for(int i = 0; i < numbersInFactorD; ++i){
		int factor = factorsD[i];
		//printf("%d\n", factor);
		
		if((
		(a*(pow(factor, 3))) + 
		(b*(pow(factor, 2))) + 
		(c*(factor)) + 
		d) == 0){
			printf("%d is a solution\n", factor);
		}
		
		if((
		(a*(pow((factor*-1), 3))) + 
		(b*(pow((factor*-1), 2))) + 
		(c*((factor*-1))) + 
		d) == 0){
			printf("-%d is a solution\n", factor);
		}
		
		counter++;
	}
	
	/*
	//test possible solutions of equation from the factors
	for(int i = 0; i < numbersInFactorA; ++i){
	
		printf("%d\n", i);
	
		for(int j = 0; j < numbersInFactorD; ++j){
		
		printf("%d\n", j);
		
			double calcRes = factorsA[i] / factorsD[j];
			allFactors[counter] = calcRes;
			printf("%f / %f = %f\n", (double)factorsA[i], (double)factorsD[j], allFactors[counter]);
			counter++;
		}
	}
	*/
}

void printArray(int arr[], int elementsInArray){
	
	for(int i = 0; i < elementsInArray; ++i){
		printf("%d\n", arr[i]);
	}
}

