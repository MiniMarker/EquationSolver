#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void menu();
void linear(double a, double b);
void quadratic(double a, double b, double c);
void cubic(double a, double b, double c, double d);
void printArray(int arr[], int numElements);

int main() {

	printf("### MENU ###\n");
	printf("a: Linear equation\n");
	printf("b: Quadratic eqation\n");
	printf("c: Cubic eqation\n");

	menu();

	return 0;
}

void menu() {

	double a, b, c, d;
	int ca, cb, cc, cd;
	char choice;

	//get user input (singe char)
	choice = getchar();

	switch(choice) {

		case 'a':
			printf("Linear equation solver\n");
			printf("Enter A:");
			scanf("%lf", &a);

			printf("Enter B:");
			scanf("%lf", &b);

			linear(a, b);
			break;

		case 'b':
			printf("Quadratic equation solver\n");
			printf("Enter A:");
			scanf("%lf", &a);

			printf("Enter B:");
			scanf("%lf", &b);

			printf("Enter C:");
			scanf("%lf", &c);

			quadratic(a, b, c);
			break;

		case 'c':
			printf("Cubic equation solver");
			printf("Enter A:");
			scanf("%lf", &a);

			printf("Enter B:");
			scanf("%lf", &b);

			printf("Enter C:");
			scanf("%lf", &c);

			printf("Enter D:");
			scanf("%lf", &d);

			cubic(a, b, c, d);
			break;
		default:
			printf("ERROR: wrong input\n");
			menu();
	}
}


void linear(double a, double b) {

	double x1;

	//calculating x
	x1 = (((b * -1) / a) * -1);
	printf("x = %0.3f\n", x1);

}

void quadratic(double a, double b, double c) {

	double determinant, x1, x2;

	if(a == 0) {
		linear(b, c);
		return;
	}

	//calculating the determinant.
	determinant = ((pow(b, 2)) - (4 * a * c));

	//the equatoin is only solvable if the determinant is bigger than 0.
	if(determinant > 0) {

		//caluclating x1
		x1 = (((-b) + sqrt(determinant)) / (2 * a) * -1);
		printf("x1 = %0.3f\n", x1);

		//caluclating x2
		x2 = (((-b) - sqrt(determinant)) / (2 * a) * -1);
		printf("x2 = %0.3f\n", x2);
	} else if(determinant == 0) {

		x1 = ((b * -1) / (2 * a) * -1);
		printf("x1 = %0.3f\n", x1);


	} else {
		printf("ERROR: Determinant < 0 \n");
	}
}

void cubic(double a, double b, double c, double d) {

	if(a == 0) {
		quadratic(b, c, d);
		return;
	}

	if(d == 0) {
		quadratic(a, b, c);
		printf("x3 = 0\n");
		return;
	}

	double f, g, delimiter, h, i, j, k, l, m, n, p, x1, x2, x3;

	//To find the delimiter i divide the equation in two (f and g)
	f = (((3 * c / a) - ((pow(b, 2)) / (pow(a, 2)))) / 3);
	g = (((2 * (pow(b, 3)) / (pow(a, 3))) - (9 * b * c / (pow(a, 2))) + (27 * d / a)) / 27);

	delimiter = (((pow(g, 2)) / 4) + ((pow(f, 3)) / 27));

	//if delimiter <= 0 there are three roots
	if(delimiter <= 0) {

		i = pow(((pow(g, 2) / 4) - delimiter), 0.5);
		j = pow(i, (0.3333333));
		k = acos((g / (2 * i)) * -1);
		l = (j * -1);
		m = cos(k / 3);
		n = sqrt(3.0) * sin(k / 3);
		p = b / (3 * a) * -1;

		x1 = (2 * j) * cos(k / 3) - (b / (3 * a));
		x2 = l * (m + n) + p;
		x3 = l * (m - n) + p;

		printf("x1 = %f\n", x1);
		printf("x2 = %f\n", x2);
		printf("x3 = %f\n", x3);
	}
		//if delimiter > 0 there are just one root
	else if(delimiter > 0) {

		i = (((3 * c) / a) - ((pow(b, 2)) / (pow(a, 2)))) / 3;
		j = ((2 * (pow(b, 3)) / (pow(a, 3))) - ((9 * b * c) / (pow(a, 2))) + ((27 * d) / a)) / 27;
		k = (((pow(j, 2)) / 4) + ((pow(i, 3)) / 27));
		l = (((j / 2) * -1) + ((pow(k, 0.5))));
		m = pow(l, (1.0 / 3.0));
		n = (((j / 2) * -1) - ((pow(k, 0.5))));

		//Here i need to handle that T could be negative.
		//Since the pow(x,y) is only able to process positive numbers
		if(n < 0) {
			double posN = n * -1;
			p = (pow(posN, (1.0 / 3.0))) * -1;

		} else {
			p = (pow(n, (1.0 / 3.0)));
		}

		//calculating x1
		x1 = (m + p) - (b / (3 * a));
		printf("x1 = %f\n", x1);
	}
}

void printArray(int arr[], int elementsInArray) {

	for(int i = 0; i < elementsInArray; ++i) {
		printf("%d\n", arr[i]);
	}
}

