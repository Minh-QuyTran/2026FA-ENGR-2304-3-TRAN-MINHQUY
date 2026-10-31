#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int main() {
	int choice;
	srand(time(NULL));
	while (1) {
		printf("Do you want to solve the problem ? (1 = Yes or 0 = No)\n");
		scanf("%d", &choice);
		if (choice == 1) {
			int Vs, R1, R2, R3;
			float i1, i2, V1, V2, V3;
			float D, Dx, Dy;
			float ci1, ci2, cV1, cV2, cV3;
			Vs = rand() % 10 + 1;
			R1 = rand() % 20 + 1;
			R2 = rand() % 20 + 1;
			R3 = rand() % 20 + 1;
			printf("Vs = %d\n", Vs);
			printf("R1 = %d\n", R1);
			printf("R2 = %d\n", R2);
			printf("R3 = %d\n", R3);
			D = (R1 + R2) * (R2 + R3) - R2 * R2;
			Dx = Vs * (R2 + R3);
			Dy = Vs * R2;
			i1 = Dx / D;
			i2 = Dy / D;
			V1 = i1 * R1;
			V2 = (i1 - i2) * R2;
			V3 = i2 * R3;
			printf("Enter i1 i2 V1 V2 V3 (Round to hundreth decimal): ");
			scanf("%f %f %f %f %f", &ci1, &ci2, &cV1, &cV2, &cV3);
			if (fabs(ci1 - i1) < 0.05 &&
				fabs(ci2 - i2) < 0.05 &&
				fabs(cV1 - V1) < 0.05 &&
				fabs(cV2 - V2) < 0.05 &&
				fabs(cV3 - V3) < 0.05) {
				printf("\nSUCCESS!\n");
			}
			else {
				printf("FAILURE!\n");
			}
		}
		else {
			break;
		}
	}
	return 0;
}