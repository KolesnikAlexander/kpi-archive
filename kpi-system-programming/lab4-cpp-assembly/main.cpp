// Program lab4.cpp
#include <stdio.h>
#define n 255 // ������� ����� � ����������� ����
typedef unsigned char byte; // ��� ������ � ������� ��������������� ��� char
extern "C" {
	void BigShowN(byte* p1, int p2); //������� ���������� ����� ���������
	bool biggReq(byte* p1, byte*p2, short len);
			}
int main()
{
	byte x[n], y[n]; //�������� �����
	for (int i = 0; i<n; i++)
	{
		x[i] = 6;
		y[i] = 2;
	}
	printf("x=");
	BigShowN(x, n);
	printf("y=");
	BigShowN(y, n);
	bool res = biggReq(x, y, n);
	if(res == true)
		printf("\nReturn value: TRUE\n",res);
	else
		printf("\nReturn value: FALSE\n", res);
	return 0;
}