#include <stdio.h>
#include <stdlib.h>

long long rep1[15] = { 1234320, 2343210, 3432120, 4321230 , 3212340 , 1234320 , 4321230 , 2123430 , 4321230 , 1234320 , 3212340 , 4321230 , 3432120 , 2343210  , 1234320 }; //16��°���ʹ� 15���� �������� �պκ��� �ݺ���
long long int result = 0; //������ ������
long long int arr[15] = { 1, 2, 3, 4, 32, 123, 43, 2123, 432, 1234, 32123, 43212, 34321, 23432, 123432 }; //1~15��°�� �ݺ��Ǵ� �� ����
long long int tmp[15]; //^7�� ���ٶ� �ӽ������� �������� ����

int main() {
	int checknum = 15; //������ ��������Ҵ���(�����ʿ���)
	const int mod = 123454321; //��������� ��
	int i, j;
	int r = 1; //�ѹ��� ���� ������ ���� ã���� ����
	int id; //������ ������ ���� ��ȣ
	for (i = 0; i <= 14; i++) {
		result += arr[i]; //�ݺ� ���������� �����༭ ������ ���ð� �����
	}

	for (j = 1; j <= 15; j++) {
		id = j;
		tmp[id] = (rep1[id - 1]) % mod; //15��°���� �ݺ��Ǵ� ������ ������� %mod ���ش�. * 15
		if ((j == 5) || (j == 7)) {
			result = ((arr[j - 1] + tmp[id] * 10) + result) % mod; //�� ��쿡�� �����ڸ��� ���Ѵ�.
		}
		else if ((j == 6) || (j == 9)) {
			result = ((arr[j - 1] + tmp[id] * 100) + result) % mod; //�� ��쿡�� �����ڸ��� ���Ѵ�.
		}
		else if ((j == 8) || (j == 10)) {
			result = ((arr[j - 1] + tmp[id] * 1000) + result) % mod; //�� ��쿡�� õ���ڸ��� ���Ѵ�.
		}
		else if ((j >= 11) && (j <= 14)) {
			result = ((arr[j - 1] + tmp[id] * 10000) + result) % mod; //�� ��쿡�� �����ڸ��� ���Ѵ�.
		}
		else if (j == 15) {
			result = ((arr[j - 1] + tmp[id] * 100000) + result) % mod; //�� ��쿡�� �ʸ��ڸ��� ���Ѵ�.
		}
		else {
			result = (arr[j - 1] + tmp[id] + result) % mod; //arr + rep + ������ ������
		}
		checknum++;
	}
	for (j = 16; j <= 985; j++) {
		id = j;
		tmp[id - (r * 15)] = (((tmp[id - (r * 15)] * 1000000) % mod + (rep1[j - (r * 15) - 1] % mod))) % mod; //30��°���ʹ� �տ��� �������� ���� ������ͼ� long long int �ȿ� �����Ѵ�.
		if (((j % 15) == 5) || ((j % 15) == 7)) {
			result = ((arr[j - 1 - (r * 15)] + tmp[id - (r * 15)] * 10) + result) % mod; //�� ��쿡�� �����ڸ��� ���Ѵ�.
		}
		else if (((j % 15) == 6) || ((j % 15) == 9)) {
			result = ((arr[j - 1 - (r * 15)] + tmp[id - (r * 15)] * 100) + result) % mod; //�� ��쿡�� �����ڸ��� ���Ѵ�.
		}
		else if (((j % 15) == 8) || ((j % 15) == 10)) {
			result = ((arr[j - 1 - (r * 15)] + tmp[id - (r * 15)] * 1000) + result) % mod; //�� ��쿡�� õ���ڸ��� ���Ѵ�.
		}
		else if (((j % 15) >= 11) && ((j % 15) <= 14)) {
			result = ((arr[j - 1 - (r * 15)] + tmp[id - (r * 15)] * 10000) + result) % mod; //�� ��쿡�� �����ڸ��� ���Ѵ�.
		}
		else if ((j % 15) == 0) {
			result = ((arr[j - 1 - (r * 15)] + tmp[id - (r * 15)] * 100000) + result) % mod; //�� ��쿡�� �ʸ��ڸ��� ���Ѵ�.
		}
		else {
			result = (arr[j - 1 - (r * 15)] + tmp[id - (r * 15)] + result) % mod; //arr + rep + ������ ������
		}
		checknum++;
		if (j % 15 == 0) {
			r++;
		}
	}
	printf("(%d, '=>', %lld)\n", checknum, result);
	return 0;
}