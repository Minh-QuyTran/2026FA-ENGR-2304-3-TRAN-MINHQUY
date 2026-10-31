/*2026FA-ENGR-2304-3-TRAN-MINHQUY-P03*/
#include <stdio.h>
int main() {
	int choice, again;
	double a1, b1, c1, d1;
	double a2, b2, c2, d2;
	double a3, b3, c3, d3;
	double D, Dx, Dy, Dz;
	double x, y, z;
	while (1) {
		printf("\n/*** Menu ***/\n");
		printf("1. Solve two equations\n");
		printf("2. Solve three equations\n");
		printf("3. Exit\n");
		printf("Choice: ");
		scanf("%d", &choice);

		if (choice == 1) {
			while (1) {
				printf("\n-- Solve two equations --\n");
				printf("Do you want to solve the equations? (1 = Yes, 0 = Back): ");
				scanf("%d", &again);

				if (again == 0) {
					break;
				}
				printf("\nEnter coefficients for equation 1 (a1 b1 c1): \n");
				scanf("%lf %lf %lf", &a1, &b1, &c1);
				printf("Enter coefficients for equation 2 (a2 b2 c2): \n");
				scanf("%lf %lf %lf", &a2, &b2, &c2);
				D = a1 * b2 - a2 * b1;
				Dx = c1 * b2 - c2 * b1;
				Dy = a1 * c2 - a2 * c1;
				printf("\nD = %.2lf\n", D);
				printf(" Dx = %.2lf\n", Dx);
				printf(" Dy = %.2lf\n", Dy);

				if (D == 0 && Dx == 0 && Dy == 0) {
					printf("Infinitive solution.\n");
				}

				else if (D == 0 && (Dx != 0 || Dy != 0)) {
					printf("No unique solution.\n");
				}

				else {
					x = Dx / D;
					y = Dy / D;
					printf("\nUsing Cramer's Rule:\n");
					printf("x = Dx/D = %.2lf\n", x);
					printf("y = Dy/D = %.2lf\n", y);
				}
			}
		}

		else if (choice == 2) {
			while (1) {
				printf("\n-- Solve three equations --\n");
				printf("Do you want to solve the equations? (1 = Yes, 0 = Back): ");
				scanf("%d", &again);

				if (again == 0) {
					break;
				}
				printf("\nEnter coefficients for equation 1 (a1 b1 c1 d1): \n");
				scanf("%lf %lf %lf %lf", &a1, &b1, &c1, &d1);
				printf("Enter coefficients for equation 2 (a2 b2 c2 d2): \n");
				scanf("%lf %lf %lf %lf", &a2, &b2, &c2, &d2);
				printf("Enter coefficients for equation 3 (a3 b3 c3 d3): \n");
				scanf("%lf %lf %lf %lf", &a3, &b3, &c3, &d3);
				D = a1 * (b2 * c3 - b3 * c2) - b1 * (a2 * c3 - a3 * c2) + c1 * (a2 * b3 - a3 * b2);
				Dx = d1 * (b2 * c3 - b3 * c2) - b1 * (d2 * c3 - d3 * c2) + c1 * (d2 * b3 - d3 * b2);
				Dy = a1 * (d2 * c3 - d3 * c2) - d1 * (a2 * c3 - a3 * c2) + c1 * (a2 * d3 - a3 * d2);
				Dz = a1 * (b2 * d3 - b3 * d2) - b1 * (a2 * d3 - a3 * d2) + d1 * (a2 * b3 - a3 * b2);
				printf("\nD = %.2lf\n", D);
				printf(" Dx = %.2lf\n", Dx);
				printf(" Dy = %.2lf\n", Dy);
				printf(" Dz = %.2lf\n", Dz);

				if (D == 0) {
					printf("Need to check further.\n");
				}
				else {
					x = Dx / D;
					y = Dy / D;
					z = Dz / D;
					printf("\nUsing Cramer's Rule:\n");
					printf("x = Dx/D = %.2lf\n", x);
					printf("y = Dy/D = %.2lf\n", y);
					printf("z = Dz/D = %.2lf\n", z);
				}
			}
		}

		else if (choice == 3) {
			break;
		}
	}
	return 0;
}
