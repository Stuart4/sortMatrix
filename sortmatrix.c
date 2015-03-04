#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int m, n;
	printf("Input Matrix:\n");
	scanf("%d %d", &m, &n);
	getchar();
	double mat[m][n];
	char line[500];
	for (int row = 0; row < m; row++) {
		scanf("%[^\n]", line);
		getchar();
		mat[row][0] = atof(strtok(line, " "));
		for (int col = 1; col < n; col++) {
			mat[row][col] = atof(strtok(NULL, " "));
		}
	}

	printf("Original Matrix:\n%d %d\n", m, n);
	for (int row = 0; row < m; row++) {
		for (int col = 0; col < n; col++) {
			printf("%1f ", mat[row][col]);
		}
		printf("\n");
	}

	printf("Sorted Matrix\n %d %d\n", m, n);
	int order[m];
	for (int i = 0; i < m; i++) order[i] = i;
	for (int i = 0; i < m - 1; i++) {
		double sum1 = 0, sum2 = 0;
		for (int j = 0; j < n; j++) {
			sum1 += mat[order[i]][j];
			sum2 += mat[order[i+1]][j];
		}
		if (sum1 > sum2) {
			int tmp = order[i];
			order[i] = order[i+1];
			order[i+1] = tmp;
			i = -1;
		}
	}
	for (int p = 0; p < m; p++) {
		for (int s = 0; s < n; s++) {
			printf("%1f ", mat[order[p]][s]);
		}
		printf("\n");
	}
}
