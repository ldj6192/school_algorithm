#include <stdio.h>

int main() {
	int checknum = 0; //������ ��������Ҵ���(�����ʿ���)
	const int mod = 123454321; //��������� ��
	long long int result = 0; //������ ������
	long long int arr[15] = { 1, 2, 3, 4, 32, 123, 43, 2123, 432, 1234, 32123, 43212, 34321, 23432, 123432 };
	long long int rep1[15] = { 1234320, 2343210, 3432120, 4321230 , 3212340 , 1234320 , 4321230 , 2123430 , 4321230 , 1234320 , 3212340 , 4321230 , 3432120 , 2343210  , 1234320 };
	long long int tmp[15]; //^7�� ���ٶ� �ӽ������� �������� ����
	int i, j;
	int id; //������ ������ ���� ��ȣ
	for (i = 0; i <= 14; i++) {
		result += arr[i]; //�ݺ� ���������� �����༭ ������ �����
	}
	//for (i = 1;i <= 65;i++) {
		for (j = 1; j <= 30; j++) {
			id = j;
			tmp[id] = (rep1[id - 1]) % mod;
			if ((j == 5) || (j == 7)) {
				result = ((arr[j - 1] + tmp[id] * 10) + result) % mod; //�� ��쿡�� �����ڸ��� ���Ѵ�.
			}
			else if ((j == 6) || (j == 9)) {
				result = ((arr[j - 1] + tmp[id] * 100)  + result) % mod; //�� ��쿡�� �����ڸ��� ���Ѵ�.
			}
			else if ((j == 8) || (j == 10)) {
				result = ((arr[j - 1] + tmp[id] * 1000)  + result) % mod; //�� ��쿡�� õ���ڸ��� ���Ѵ�.
			}
			else if ((j >= 11) && (j <= 14)) {
				result = ((arr[j - 1] + tmp[id] * 10000)  + result) % mod; //�� ��쿡�� �����ڸ��� ���Ѵ�.
			}
			else if (j == 15) {
				result = ((arr[j - 1] + tmp[id] * 100000)  + result) % mod; //�� ��쿡�� �ʸ��ڸ��� ���Ѵ�.
			}
			else {
				result = (arr[j - 1] + tmp[id] + result) % mod; //arr + rep + ������ ������
			}
			printf("%d\n", result);
		}
		/*for (j = 1; j <= 15; j++) {
			id = j;
			tmp[id] = (rep1[id-1] * 1000000) % mod;
			result = (arr[j - 1] + tmp[id] + result) % mod; //arr + rep + ������ ������	
			printf("%d\n", result);
		}*/
	//}
	return 0;
}	