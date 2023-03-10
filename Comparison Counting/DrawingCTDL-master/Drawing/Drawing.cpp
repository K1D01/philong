#include "graphics.h"
#include<conio.h>
#include<sstream>
#include<iostream>
#include<string.h>

using namespace std;

int A[10];
int n;

void DrawBox(int x1, int y1) {
	line(x1, y1, x1, y1 + 50);
	line(x1, y1, x1 + 70, y1);
	line(x1 + 70, y1, x1 + 70, y1 + 50);
	line(x1, y1 + 50, x1 + 70, y1 + 50);

}

void InsertRectangle(int A[], int n) {
	char text1[] = "Array";
	outtextxy(70, 100, text1);
	int x1 = 183, y1 = 150;
	for (int i = 0; i < n; i++) {
		string s = to_string(A[i]);
		char const* pchar = s.c_str();
		drawText(x1 + 25, y1 + 15, pchar);
		DrawBox(x1, y1);
		x1 += 120;
	}

}

void Cout(int A[], int n) {
	char text2[] = "Count";
	outtextxy(70, 190, text2);
	char text4[] = "0";
	outtextxy(190, 210, text4);
	char text5[] = "1";
	outtextxy(300, 210, text5);
	char text6[] = "2";
	outtextxy(400, 210, text6);
	char text7[] = "3";
	outtextxy(505, 210, text7);
	char text8[] = "4";
	outtextxy(610, 210, text8);
	char text9[] = "5";
	outtextxy(720, 210, text9);
	char text10[] = "6";
	outtextxy(825, 210, text10);
	char text11[] = "7";
	outtextxy(950, 210, text11);
	char text12[] = "8";
	outtextxy(1045, 210, text12);
	char text13[] = "9";
	outtextxy(1140, 210, text13);
	int x2 = 183, y2 = 255;
	for (int i = 0; i < 10; i++) {
		string s = to_string(0);
		char const* pchar = s.c_str();
		drawText(x2 + 25, y2 + 10, pchar);
		DrawBox(x2, y2);
		x2 += 120;
	}
	
 
}

void countSort(int array[], int size) {
	int output[10];
	int count[10];
	int max = array[0];

	for (int i = 1; i < size; i++) {
		if (array[i] > max)
			max = array[i];
	}


	for (int i = 0; i <= max; ++i) {
		count[i] = 0;
	}


	for (int i = 0; i < size; i++) {
		count[array[i]]++;
	}

	for (int i = 1; i <= max; i++) {
		count[i] += count[i - 1];
	}

	for (int i = size - 1; i >= 0; i--) {
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (int i = 0; i < size; i++) {
		array[i] = output[i];
	}
}

void printArray(int array[], int size) {
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}
void Output(int array[], int n) {
	char text3[] = "Output";
	outtextxy(70, 250, text3);
	int x3 = 183, y3 = 400;
	for (int i = 0; i < n; i++) {
		string s = to_string(array[i]);
		char const* pchar = s.c_str();
		drawText(x3 + 25, y3 + 15, pchar);
		DrawBox(x3, y3);
		x3 += 120;
	}
}
int main() 
{
	initgraph();
	setfontcolor(9);
	char string1[] = "Mo phong cach hoat dong cua CountingSort";
	outtextxy(500, 0, string1);
	cout << endl;
	cout << "Nhap so phan tu cua chuong trinh:";
	cin >> n;
	do {
		if (n <= 1) {
			cout << "Vui long nhap lai n:";
			cin >> n;
		}
	} while (n <= 1);
	for (int i = 0; i < n; i++) {
		cout << "A[" << i << "]=";
		cin >> A[i];
	}


	InsertRectangle(A, n);
	Sleep(1000);
	
	setfontcolor(8);
	Cout(A, n);
	Sleep(1000);

	setfontcolor(7);
	countSort(A, n);
	Output(A, n);

	Sleep(5000);
	system("cls");


	return 0;
}