#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input_scores(int, int scores[][3]);
void calculate_student_stats(int totals[100], int scores[][3], int N, double avg[100]);
void calculate_subject_stats(int subject_total[3], int subject_max[3], int subject_min[3], int N, int scores[][3], double subject_avg[3]);
void prn_avg_best(double avg[100], int N);

int main()
{
	while (1) {
		int scores[100][3] = {0};
		int totals[100] = {0};
		double avg[100] = {0};
		int subject_total[3] = {0}, subject_max[3], subject_min[3];
		double subject_avg[3];
		int N;

		printf("¸î¸íÀÇ ÇÐ»ýÀÌ ½ÃÇèÀ» º½?(1<=N<=100)");
		scanf("%d", &N);

		if (N < 1 || N > 99)    break;

		input_scores(N, scores);
		calculate_student_stats(totals, scores, N, avg);
		calculate_subject_stats(subject_total, subject_max, subject_min, N, scores, subject_avg);
		prn_avg_best(avg, N);
	}

	return 0;
}
void input_scores(int N, int scores[][3])
{
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < 3; j++) {
			scanf("%d", &scores[i][j]);
		}
		printf("\n");
	}
}
void calculate_student_stats(int totals[100], int scores[][3], int N, double avg[100])
{
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < 3; j++) {
			totals[i] += scores[i][j];
		}
		avg[i] = totals[i] / 3.0;
	}
	
	for (i = 0; i < N; i++) {
		printf("ÇÐ»ý%d - ÃÑÁ¡: %d, Æò±Õ: %lf\n", i + 1, totals[i], avg[i]);
	}
}
void calculate_subject_stats(int subject_total[3], int subject_max[3], int subject_min[3], int N, int scores[][3], double subject_avg[3])
{
	int i, j;

	for (j = 0; j < 3; j++) {
		for (i = 0; i < N; i++) {
			subject_total[j] += scores[i][j];
		}
		subject_avg[j] = subject_total[j] / (double)N;

		subject_max[j] = scores[0][j];
		subject_min[j] = scores[0][j];
		
		for (i = 0; i < N; i++) {
			if (subject_max[j] <= scores[i][j])     subject_max[j] = scores[i][j];
			if (subject_min[j] >= scores[i][j])     subject_min[j] = scores[i][j];
		}
	}
	printf("\n[±¹¾î] ÃÑÁ¡: %d, Æò±Õ: %lf, ÃÖ°íÁ¡: %d, ÃÖÀúÁ¡: %d\n", subject_total[0], subject_avg[0], subject_max[0], subject_min[0]);
	printf("\n[¿µ¾î] ÃÑÁ¡: %d, Æò±Õ: %lf, ÃÖ°íÁ¡: %d, ÃÖÀúÁ¡: %d\n", subject_total[1], subject_avg[1], subject_max[1], subject_min[1]);
	printf("\n[¼öÇÐ] ÃÑÁ¡: %d, Æò±Õ: %lf, ÃÖ°íÁ¡: %d, ÃÖÀúÁ¡: %d\n", subject_total[2], subject_avg[2], subject_max[2], subject_min[2]);
}
void prn_avg_best(double avg[100], int N)
{
	int i;
	double best_avg;

	best_avg = avg[0];

	for (i = 0; i < N; i++) {
		if (avg[i] >= best_avg)       best_avg = avg[i];
	}
	for (i = 0; i < N; i++) {
		if (best_avg == avg[i]) {
			printf("\n°¡Àå Æò±ÕÀÌ ³ôÀº ÇÐ»ý: %d¹ø (Æò±Õ: %lf)\n\n", i + 1, best_avg);
		}
	}
	
	
}