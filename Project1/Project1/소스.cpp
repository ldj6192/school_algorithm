/*#include <stdio.h>
#include <stdlib.h>

int main() {
	long long int *arr = (long long int*)malloc(sizeof(long long int) * 100000000); //��ü ���ڿ��� ���� �迭
	int repeat[6] = { 1,2,3,4,3,2 }; //���ڿ��� ���� ����ټ� ������ �ݺ��Ǵ� �κи� �迭�� ����
	long long int v[1000] = {}; //������ ���������� �����ִ� V�迭
	int i, j = 0;
	long long int sum = 0; //�迭�� ���� �Է��� �ӽú���
	int num = 1; //���°���� ǥ������ ����
	for (i = 0; i <= 999; i++) {
		v[i] = 0;
	}


	i = 1;
	while (i <= 100000000 - 1) { //arr���ۿ� ������ ���� ��´�.
		arr[i] = repeat[j];
		j++;
		if (j == 6) {
			j = 0;
		}
		i++;
	}
	j = 1;
	while (j <= 100000000 - 1) {
		for (; j <= 100000000 - 1;) {
			sum += arr[j];
			v[num] *= 10;
			v[num] += arr[j];
			j++;
			if (num == sum) {
				printf("%d", v[num]);
				num++;
				break;
			}
		}
		printf("\n");
		sum = 0;
	}
	free(arr); //�����Ҵ��� �������ش�.
}*/
#include <stdio.h>
#include <stdlib.h>

int main() {
	int tmp = 1;
	int *arr = (int*)malloc(sizeof(int) * 100000000); //��ü ���ڿ��� ���� �迭
	int repeat[6] = { 1,2,3,4,3,2 }; //���ڿ��� ���� ����ټ� ������ �ݺ��Ǵ� �κи� �迭�� ����
	int v[1000] = {}; //������ ���������� �����ִ� V�迭
	int i, j = 0;
	int number = 0;
	int sum = 0; //�迭�� ���� �Է��� �ӽú���
	int num = 1; //���°���� ǥ������ ����
	for (i = 0; i <= 999; i++) {
		v[i] = 0;
	}


	i = 1;
	while (i <= 100000000 - 1) { //arr���ۿ� ������ ���� ��´�.
		arr[i] = repeat[j];
		j++;
		if (j == 6) {
			j = 0;
		}
		i++;
	}
	j = 1;

	while (j <= 100000000 - 1) {
		for (; j <= 100000000 - 1;) {
			sum += arr[j];
			printf("%d", arr[j]);
			if (num == sum) {
				num++;
				j++;
				break;
			}
			j++;
		}
		number++;
		printf("\t\t\t\t%d", number);
		printf("\n");
		sum = 0;
	}
	free(arr); //�����Ҵ��� �������ش�.
}