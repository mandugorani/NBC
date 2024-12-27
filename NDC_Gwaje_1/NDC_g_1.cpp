//	과제 01
//	사용자로부터 5개의 숫자를 입력받아 배열에 저장하고 이들의 합계와 평균을 계산해서 출력할 것
//	5개의 숫자를 입력받는 공간은 배열을 활용할 것
//	합과 평균을 구하는 동작은 main함수에 한번에 작성하지 말 것 (각각 구현할것)
//	--------
//	정렬은 오름차순 정렬과 내림차순 정렬이 가능하도록 할 것
//	숫자 1을 입력받으면 오름차순, 2를 입력받으면 내림차순 정렬을 하도록 구현할 것
//	algorithm 헤더의 sort 함수를 사용하지 않고 각각 구현할 것
//	제출 12/27
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

// size를 double 형태로 변환하기 => (double)size
// 만약에 sum을 double로 변환한다면
// return (double)sum / size
// int는 정수임
// 
// 도전 기능으로 오름차순과 내림차순 정렬을 구현↓

void sort_orumcha(int arr[], int size) {
	for (int i = 0;i < size;i++) {
		for (int n = i + 1; n < size; n++) {
			if (arr[i] > arr[n]) {
				int temp = arr[i]; // 값을 임시로 저장하는 방법은 temp 변수를 쓰는것. 변수의 자료형은 int
				arr[i] = arr[n]; // arr[i]는 배열(arr)에서 i 위치에 있는 원래의 값을 가져오고 이 값은 arr[n]과 교환될 값임.
				arr[n] = temp; // 앞에서 저장한 arr[i]의 원래 값을 temp에서 다시 가져오면 temp에는 arr[i]에 있던 값이 저장되어 있다?
			}
		}
	}
}
// temp에 arr[i]의 값을 저장하고->
// arr[i]에 arr[n] 값을 덮어쓰고 arr[n]에 temp값을 덮어씌워주면 arr[j](arr의 j번째 값)과 arr[i] 가 서로 교환되는 계산이 된다?

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
	const int size = 5; // const int size=5로 배열 크기를 상수로 고정시킴
	int num[size];
	int choice;
	cout << "choose 5 numbers:" << endl; // 사용자로부터 5개의 숫자를 입력받기
	for (int i = 0; i < size; i++) {
		cout << "num" << (i + 1) << ":"; // cout<< "num"...~~ => 몇번째 숫자를 입력하는지 알려줌
		cin >> num[i];
	}
	int total = sum(num, size);
	double avg = total/static_cast<double>(size);
	cout << "SUM:" << total << endl;
	cout << "average:" << avg << endl;
	cout << "enter 1 for Ascending / 2 for Descending order";
	cin >> choice;

	if (choice == 1) { // 1 누르면 오름차순정렬 함수를 호출
		sort_orumcha(num, size);
		cout << "Ascending:";
	}
	else if (choice == 2) { // 2 누를시 내림차순정렬 함수를 호출
		sort_naerimcha(num, size);
		cout << "Descending:";
	}
	else { // 1 또는 2 말고 다른 선택을 했을 경우?
		cout << "enter 1 for Ascending / 2 for Descending order.." << endl;
		return 1; // return 1
	}

	for (int i = 0; i < size; i++) {
		cout << num[i]; //cout << num[i] << ","; 식으로 할 경우 맨 마지막 숫자에서도 ,가 출력되서 불편하다?
		if (i < size - 1) { //if문을 활용해서 맨 마지막 숫자 뒤에 ,가 붙지 않게 한다
			cout << ",";
		}
		cout << endl;
	}
	return 0;
}


//	실행 예시
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
