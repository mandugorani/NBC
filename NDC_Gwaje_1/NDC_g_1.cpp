//	���� 01
//	����ڷκ��� 5���� ���ڸ� �Է¹޾� �迭�� �����ϰ� �̵��� �հ�� ����� ����ؼ� ����� ��
//	5���� ���ڸ� �Է¹޴� ������ �迭�� Ȱ���� ��
//	�հ� ����� ���ϴ� ������ main�Լ��� �ѹ��� �ۼ����� �� �� (���� �����Ұ�)
//	--------
//	������ �������� ���İ� �������� ������ �����ϵ��� �� ��
//	���� 1�� �Է¹����� ��������, 2�� �Է¹����� �������� ������ �ϵ��� ������ ��
//	algorithm ����� sort �Լ��� ������� �ʰ� ���� ������ ��
//	���� 12/27
//


#include <iostream>
#include <numbers>
using namespace std;

int sum(int arr[], int size) {
	int total = 0;
	for (int i = 0; i < size; i++) {
		total += arr[i];
	}
	return total;
}

double avg(int total, int size) {
	return total / (double)size;
}

// size�� double ���·� ��ȯ�ϱ� => (double)size
// ���࿡ sum�� double�� ��ȯ�Ѵٸ�
// return (double)sum / size
// int�� ������
// 
// ���� ������� ���������� �������� ������ ������

void sort_orumcha(int arr[], int size) {
	for (int i = 0;i < size;i++) {
		for (int n = i + 1; n < size; n++) {
			if (arr[i] > arr[n]) {
				int temp = arr[i]; // ���� �ӽ÷� �����ϴ� ����� temp ������ ���°�. ������ �ڷ����� int
				arr[i] = arr[n]; // arr[i]�� �迭(arr)���� i ��ġ�� �ִ� ������ ���� �������� �� ���� arr[n]�� ��ȯ�� ����.
				arr[n] = temp; // �տ��� ������ arr[i]�� ���� ���� temp���� �ٽ� �������� temp���� arr[i]�� �ִ� ���� ����Ǿ� �ִ�?
			}
		}
	}
}
// temp�� arr[i]�� ���� �����ϰ�->
// arr[i]�� arr[n] ���� ����� arr[n]�� temp���� ������ָ� arr[j](arr�� j��° ��)�� arr[i] �� ���� ��ȯ�Ǵ� ����� �ȴ�?

void sort_naerimcha(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		for (int n = i + 1; n < size; n++) {
			if (arr[i] < arr[n]) {
				int temp = arr[i];
				arr[i] = arr[n];
				arr[n] = temp;
			}
		}
	}
}

int main() {
	const int size = 5; // const int size=5�� �迭 ũ�⸦ ����� ������Ŵ
	int num[size];
	int choice;
	cout << "choose 5 numbers:" << endl; // ����ڷκ��� 5���� ���ڸ� �Է¹ޱ�
	for (int i = 0; i < size; i++) {
		cout << "num" << (i + 1) << ":"; // cout<< "num"...~~ => ���° ���ڸ� �Է��ϴ��� �˷���
		cin >> num[i];
	}
	int total = sum(num, size);
	double avg = total/static_cast<double>(size);
	cout << "SUM:" << total << endl;
	cout << "average:" << avg << endl;
	cout << "enter 1 for Ascending / 2 for Descending order";
	cin >> choice;

	if (choice == 1) { // 1 ������ ������������ �Լ��� ȣ��
		sort_orumcha(num, size);
		cout << "Ascending:";
	}
	else if (choice == 2) { // 2 ������ ������������ �Լ��� ȣ��
		sort_naerimcha(num, size);
		cout << "Descending:";
	}
	else { // 1 �Ǵ� 2 ���� �ٸ� ������ ���� ���?
		cout << "enter 1 for Ascending / 2 for Descending order.." << endl;
		return 1; // return 1
	}

	for (int i = 0; i < size; i++) {
		cout << num[i]; //cout << num[i] << ","; ������ �� ��� �� ������ ���ڿ����� ,�� ��µǼ� �����ϴ�?
		if (i < size - 1) { //if���� Ȱ���ؼ� �� ������ ���� �ڿ� ,�� ���� �ʰ� �Ѵ�
			cout << ",";
		}
		cout << endl;
	}
	return 0;
}


//	���� ����
//	choose 5 numbers:
//	num1:5
//	num2 : 321
//	num3 : 74
//	num4 : 124
//	num5 : 285
//	SUM : 809
//	average : 161.8
//	enter 1 for Ascending / 2 for Descending order1
//	Ascending : 5,
//	74,
//	124,
//	285,
//	321
// 
