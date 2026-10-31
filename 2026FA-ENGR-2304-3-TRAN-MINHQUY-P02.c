/*2026FA-ENGR-2304-3-TRAN-MINHQUY-P02*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
	int option;
	char choice;
	while (1) {
		printf("\n/Menu/\n");
		printf("1.  Decimal to binary or binary to decimal\n");
		printf("2. Hex to binary and binary to hex\n");
		printf("3. Exit\n");
		printf("Option: ");
		scanf("%d", &option);

		if (option == 1) {
			while (1) {
				int i, n, syn_bit, bit[7], magnitude;
				char decimal[20], binary[9];
				printf("\na. Decimal to binary\n");
				printf("b. Binary to decimal\n");
				printf("c. Exit\n");
				printf("Choice: ");
				scanf(" %c", &choice);

				if (choice == 'a') {
					while (1) {
						printf("Enter decimal number from -127 to 127 or exit: ");
						scanf("%s", decimal);
						if (strcmp(decimal, "exit") == 0) {
							break;
						}
						n = atoi(decimal);
						if (n < 0) {
							magnitude = -n;
							syn_bit = 1;
						}
						else {
							syn_bit = 0;
							magnitude = n;
						}
						for (i = 6; i >= 0; i--) {
							bit[i] = magnitude % 2;
							magnitude = magnitude / 2;
						}
						printf("Binary:%d", syn_bit);
						for (i = 0; i <= 6; i++) {
							printf("%d", bit[i]);
						}
						printf("\n");
					}
				}

				else if (choice == 'b') {
					while (1) {
						printf("Enter 8-bit binary number or exit: ");
						scanf("%s", binary);
						if (strcmp(binary, "exit") == 0) {
							break;
						}
						int decimal = 0;
						for (i = 1; i < 8; i++) {
							decimal = decimal * 2 + (binary[i] - '0');
						}
						if (binary[0] == '1') {
							decimal = -decimal;
						}
						printf("Decimal: %d\n", decimal);
					}
				}

				else if (choice == 'c') {
					break;
				}
			}
		}

		else if (option == 2) {
			while (1) {
				printf("\na. Binary to hex\n");
				printf("b. Hex to binary\n");
				printf("c. Exit\n");
				printf("Choice: ");
				scanf(" %c", &choice);
				char binary[65], add[65], full_binary[65], hex[65];
				int length, m, i, value;
				int j, g;

				if (choice == 'a') {
					while (1) {
						printf("Enter binary number or exit: ");
						scanf("%s", binary);
						if (strcmp(binary, "exit") == 0) {
							break;
						}
						length = strlen(binary);
						m = (4 - length % 4) % 4;
						for (i = 0;i < m;i++) {
							add[i] = '0';
						}
						add[m] = '\0';
						strcpy(full_binary, add);
						strcat(full_binary, binary);
						g = 0;
						for (i = 0; i < strlen(full_binary); i += 4) {
							value = 0;
							for (j = 0; j < 4; j++) {
								value = value * 2 + (full_binary[i + j] - '0');
							}
							if (value < 10) {
								hex[g++] = value + '0';
							}
							else {
								hex[g++] = value - 10 + 'A';
							}
						}
						hex[g] = '\0';
						printf("Hexadecimal: 0x%s\n", hex);
					}
				}

				else if (choice == 'b') {
					while (1) {
						char hex[100];
						int i, n;
						printf("Enter hexdeciaml number (0x...) or exit: ");
						scanf("%s", hex);
						if (strcmp(hex, "exit") == 0) {
							break;
						}
						for (i = 2;hex[i] != '\0';i++) {
							if (hex[i] >= '0' && hex[i] <= '9') {
								n = hex[i] - '0';
							}
							else if (hex[i] >= 'A' && hex[i] <= 'F') {
								n = hex[i] - 'A' + 10;
							}
							else if (hex[i] >= 'a' && hex[i] <= 'f') {
								n = hex[i] - 'a' + 10;
							}
							printf("%d%d%d%d",
								(n >> 3) & 1,
								(n >> 2) & 1,
								(n >> 1) & 1,
								n & 1);
						}
						printf("\n");
					}
				}

				else if (choice == 'c') {
					break;
				}
			}
			}

		else if (option == 3) {
			break;
		}
	}

	return 0;
}