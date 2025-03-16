// ========================= Start ========================= //
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
// ========================= Datas ========================= //
int side1[3][3] = { {1,1,1}, {1,1,1}, {1,1,1} };
int side2[3][3] = { {2,2,2}, {2,2,2}, {2,2,2} };
int side3[3][3] = { {3,3,3}, {3,3,3}, {3,3,3} };
int side4[3][3] = { {4,4,4}, {4,4,4}, {4,4,4} };
int side5[3][3] = { {5,5,5}, {5,5,5}, {5,5,5} };
int side6[3][3] = { {6,6,6}, {6,6,6}, {6,6,6} };
const int Max = 3;
// ========================= Rubik Functions ========================= //
// =============== Rotate clockwise =============== //
void Rotateclockwise(int side[3][3])
{
	for (int i = 0; i < 3 / 2; i++)
	{
		for (int j = i; j < 3 - i - 1; j++)
		{
			int temp = side[i][j];

			side[i][j] = side[3 - j - 1][i];
			side[3 - j - 1][i] = side[3 - i - 1][3 - j - 1];
			side[3 - i - 1][3 - j - 1] = side[j][3 - i - 1];
			side[j][3 - i - 1] = temp;
		}
	}
}
// =============== Rotate Anticlockwise =============== //
void Rotateanticlockwise(int side[3][3])
{
	for (int i = 0; i < 3 / 2; i++)
	{
		for (int j = i; j < 3 - i - 1; j++)
		{
			int temp = side[i][j];

			side[i][j] = side[j][3 - i - 1];
			side[j][3 - i - 1] = side[3 - i - 1][3 - j - 1];
			side[3 - i - 1][3 - j - 1] = side[3 - j - 1][i];
			side[3 - j - 1][i] = temp;
		}
	}
}
// _________________________ Case Side _________________________ //
// _______________ Help Copy Case Side _______________ //
void CopyCaseSide(int side[3][3], int temp[3])
{
	for (int j = 0; j < Max; j++)
	{
		temp[j] = side[2][j];
	}
}
// _______________ Swap Case Side _______________ //
void SwapCaseSide(int side[3][3], int temp[3])
{
	for (int j = 0; j < Max; j++)
	{
		side[2][j] = temp[j];
	}
}

// =============== clockwise Front =============== //
void clockWiseF(int side2[3][3], int side1[3][3], int side3[3][3], int side4[3][3], int side5[3][3])
{
	int temp1[3], temp3[3], temp4[3], temp5[3];

	CopyCaseSide(side1, temp1);
	CopyCaseSide(side3, temp3);
	CopyCaseSide(side4, temp4);
	CopyCaseSide(side5, temp5);

	SwapCaseSide(side1, temp3);
	SwapCaseSide(side3, temp5);
	SwapCaseSide(side4, temp1);
	SwapCaseSide(side5, temp4);

	Rotateclockwise(side2);
}
// =============== Anticlockwise Front =============== //
void AntiClockWiseF(int side2[3][3], int side1[3][3], int side3[3][3], int side4[3][3], int side5[3][3])
{
	int temp1[3], temp3[3], temp4[3], temp5[3];

	CopyCaseSide(side1, temp1);
	CopyCaseSide(side3, temp3);
	CopyCaseSide(side4, temp4);
	CopyCaseSide(side5, temp5);

	SwapCaseSide(side1, temp4);
	SwapCaseSide(side3, temp1);
	SwapCaseSide(side4, temp5);
	SwapCaseSide(side5, temp3);

	Rotateanticlockwise(side2);
}
// =============== clockwise Back =============== //
void ClockWiseB(int side6[3][3], int side1[3][3], int side3[3][3], int side4[3][3], int side5[3][3])
{
	int temp1[3], temp3[3], temp4[3], temp5[3];

	CopyCaseSide(side1, temp1);
	CopyCaseSide(side3, temp3);
	CopyCaseSide(side4, temp4);
	CopyCaseSide(side5, temp5);

	SwapCaseSide(side1, temp3);
	SwapCaseSide(side3, temp5);
	SwapCaseSide(side4, temp1);
	SwapCaseSide(side5, temp4);

	Rotateclockwise(side6);
}
// =============== Anticlockwise Back =============== //
void AntiClockWiseB(int side6[3][3], int side1[3][3], int side3[3][3], int side4[3][3], int side5[3][3])
{
	int temp1[3], temp3[3], temp4[3], temp5[3];

	CopyCaseSide(side1, temp1);
	CopyCaseSide(side3, temp3);
	CopyCaseSide(side4, temp4);
	CopyCaseSide(side5, temp5);

	SwapCaseSide(side1, temp4);
	SwapCaseSide(side3, temp1);
	SwapCaseSide(side4, temp5);
	SwapCaseSide(side5, temp3);

	Rotateanticlockwise(side6);
}
// _________________________ Right Side _________________________ //
// _______________ Help Copy Right _______________ //
void CopyData_Right(int side[3][3], int temp[3])
{
	for (int i = 0; i < Max; i++)
	{
		temp[i] = side[i][2];
	}
}
// _______________ Help swap Right _______________ //
void Swap_Right(int side[3][3], int temp[3])
{
	for (int i = 0; i < Max; i++)
	{
		side[i][2] = temp[i];
	}
}
// =============== Up =============== //
void RightUp(int side2[3][3], int side1[3][3], int side5[3][3], int side6[3][3], int side4[3][3])
{
	int temp1[3], temp2[3], temp5[3], temp6[3];

	CopyData_Right(side2, temp2);
	CopyData_Right(side1, temp1);
	CopyData_Right(side5, temp5);
	CopyData_Right(side6, temp6);

	Swap_Right(side2, temp5);
	Swap_Right(side1, temp2);
	Swap_Right(side5, temp6);
	Swap_Right(side6, temp1);

	Rotateclockwise(side4);
}
// =============== Down =============== //
void RightDown(int side2[3][3], int side1[3][3], int side5[3][3], int side6[3][3], int side4[3][3])
{
	int temp1[3], temp2[3], temp5[3], temp6[3];

	CopyData_Right(side2, temp2);
	CopyData_Right(side1, temp1);
	CopyData_Right(side5, temp5);
	CopyData_Right(side6, temp6);

	Swap_Right(side2, temp1);
	Swap_Right(side1, temp6);
	Swap_Right(side5, temp2);
	Swap_Right(side6, temp5);

	Rotateanticlockwise(side4);
}
// _________________________ Left Side _________________________ //
// _______________ Help Copy Left _______________ //
void CopyData_Left(int side[3][3], int temp[3])
{
	for (int i = 0; i < Max; i++)
	{
		temp[i] = side[i][0];
	}
}
// _______________ Help swap Right _______________ //
void Swap_Left(int side[3][3], int temp[3])
{
	for (int i = 0; i < Max; i++)
	{
		side[i][0] = temp[i];
	}
}
// =============== Up =============== //
void LeftUp(int side2[3][3], int side1[3][3], int side5[3][3], int side6[3][3], int side3[3][3])
{
	int temp1[3], temp2[3], temp5[3], temp6[3];

	CopyData_Left(side2, temp2);
	CopyData_Left(side1, temp1);
	CopyData_Left(side5, temp5);
	CopyData_Left(side6, temp6);

	Swap_Left(side2, temp5);
	Swap_Left(side1, temp2);
	Swap_Left(side5, temp6);
	Swap_Left(side6, temp1);

	Rotateclockwise(side3);
}
// =============== Down =============== //
void LeftDown(int side2[3][3], int side1[3][3], int side5[3][3], int side6[3][3], int side3[3][3])
{
	int temp1[3], temp2[3], temp5[3], temp6[3];

	CopyData_Left(side2, temp2);
	CopyData_Left(side1, temp1);
	CopyData_Left(side5, temp5);
	CopyData_Left(side6, temp6);

	Swap_Left(side2, temp1);
	Swap_Left(side1, temp6);
	Swap_Left(side5, temp2);
	Swap_Left(side6, temp5);

	Rotateanticlockwise(side3);
}
// _________________________ Up Side _________________________ //
// _______________ Help Copy Up _______________ //
void CopyData_Up(int side[3][3], int temp[3])
{
	for (int j = 0; j < Max; j++)
	{
		temp[j] = side[0][j];
	}
}
// _______________ Help swap Up _______________ //
void Swap_Up(int side[3][3], int temp[3])
{
	for (int j = 0; j < Max; j++)
	{
		side[0][j] = temp[j];
	}
}
// =============== Right =============== //
void UpRight(int side2[3][3], int side3[3][3], int side4[3][3], int side6[3][3], int side1[3][3])
{
	int temp2[3], temp3[3], temp4[3], temp6[3];

	CopyData_Up(side2, temp2);
	CopyData_Up(side3, temp3);
	CopyData_Up(side4, temp4);
	CopyData_Up(side6, temp6);

	Swap_Up(side2, temp3);
	Swap_Up(side3, temp6);
	Swap_Up(side4, temp2);
	Swap_Up(side6, temp4);

	Rotateanticlockwise(side1);
}
// =============== Left =============== //
void UpLeft(int side2[3][3], int side3[3][3], int side4[3][3], int side6[3][3], int side1[3][3])
{
	int temp2[3], temp3[3], temp4[3], temp6[3];

	CopyData_Up(side2, temp2);
	CopyData_Up(side3, temp3);
	CopyData_Up(side4, temp4);
	CopyData_Up(side6, temp6);

	Swap_Up(side2, temp4);
	Swap_Up(side3, temp2);
	Swap_Up(side4, temp6);
	Swap_Up(side6, temp3);

	Rotateclockwise(side1);
}
// _________________________ Down Side _________________________ //
// _______________ Help Copy Down _______________ //
void CopyData_Down(int side[3][3], int temp[3])
{
	for (int j = 0; j < Max; j++)
	{
		temp[j] = side[2][j];
	}
}
// _______________ Help swap Down _______________ //
void Swap_Down(int side[3][3], int temp[3])
{
	for (int j = 0; j < Max; j++)
	{
		side[2][j] = temp[j];
	}
}
// =============== Right =============== //
void DownRight(int side2[3][3], int side3[3][3], int side4[3][3], int side6[3][3], int side5[3][3])
{
	int temp2[3], temp3[3], temp4[3], temp6[3];

	CopyData_Down(side2, temp2);
	CopyData_Down(side3, temp3);
	CopyData_Down(side4, temp4);
	CopyData_Down(side6, temp6);

	Swap_Down(side2, temp3);
	Swap_Down(side3, temp6);
	Swap_Down(side4, temp2);
	Swap_Down(side6, temp4);

	Rotateclockwise(side5);
}

// =============== Left =============== //
void DownLeft(int side2[3][3], int side3[3][3], int side4[3][3], int side6[3][3], int side5[3][3])
{
	int temp2[3], temp3[3], temp4[3], temp6[3];

	CopyData_Down(side2, temp2);
	CopyData_Down(side3, temp3);
	CopyData_Down(side4, temp4);
	CopyData_Down(side6, temp6);

	Swap_Down(side2, temp4);
	Swap_Down(side3, temp2);
	Swap_Down(side4, temp6);
	Swap_Down(side6, temp3);

	Rotateanticlockwise(side5);
}
// _________________________ Center Side _________________________ //
// _______________ Help Copy Center UD _______________ //
void CopyData_CenterUD(int side[3][3], int temp[3])
{
	for (int i = 0; i < Max; i++)
	{
		temp[i] = side[i][1];
	}
}
// _______________ Help swap Center UD _______________ //
void Swap_CenterUD(int side[3][3], int temp[3])
{
	for (int i = 0; i < Max; i++)
	{
		side[i][1] = temp[i];
	}
}
// =============== Up =============== //
void CenterUp(int side2[3][3], int side1[3][3], int side5[3][3], int side6[3][3])
{
	int temp2[3], temp1[3], temp5[3], temp6[3];

	CopyData_CenterUD(side2, temp2);
	CopyData_CenterUD(side1, temp1);
	CopyData_CenterUD(side5, temp5);
	CopyData_CenterUD(side6, temp6);

	Swap_CenterUD(side2, temp5);
	Swap_CenterUD(side1, temp2);
	Swap_CenterUD(side5, temp6);
	Swap_CenterUD(side6, temp1);
}
// =============== Down =============== //
void CenterDown(int side2[3][3], int side1[3][3], int side5[3][3], int side6[3][3])
{
	int temp2[3], temp1[3], temp5[3], temp6[3];

	CopyData_CenterUD(side2, temp2);
	CopyData_CenterUD(side1, temp1);
	CopyData_CenterUD(side5, temp5);
	CopyData_CenterUD(side6, temp6);

	Swap_CenterUD(side2, temp1);
	Swap_CenterUD(side1, temp6);
	Swap_CenterUD(side5, temp2);
	Swap_CenterUD(side6, temp5);
}
// _______________ Help Copy Center RL _______________ //
void CopyData_CenterRL(int side[3][3], int temp[3])
{
	for (int j = 0; j < Max; j++)
	{
		temp[j] = side[1][j];
	}
}
// _______________ Help swap Center RL _______________ //
void Swap_CenterRL(int side[3][3], int temp[3])
{

	for (int j = 0; j < Max; j++)
	{
		side[1][j] = temp[j];
	}
}
// =============== Right =============== //
void CenterRight(int side2[3][3], int side3[3][3], int side4[3][3], int side6[3][3])
{
	int temp2[3], temp3[3], temp4[3], temp6[3];

	CopyData_CenterRL(side2, temp2);
	CopyData_CenterRL(side3, temp3);
	CopyData_CenterRL(side4, temp4);
	CopyData_CenterRL(side6, temp6);

	Swap_CenterRL(side2, temp3);
	Swap_CenterRL(side3, temp6);
	Swap_CenterRL(side4, temp2);
	Swap_CenterRL(side6, temp4);
}
// =============== Left =============== //
void CenterLeft(int side2[3][3], int side3[3][3], int side4[3][3], int side6[3][3])
{
	int temp2[3], temp3[3], temp4[3], temp6[3];

	CopyData_CenterRL(side2, temp2);
	CopyData_CenterRL(side3, temp3);
	CopyData_CenterRL(side4, temp4);
	CopyData_CenterRL(side6, temp6);

	Swap_CenterRL(side2, temp4);
	Swap_CenterRL(side3, temp2);
	Swap_CenterRL(side4, temp6);
	Swap_CenterRL(side6, temp3);
}
// ========================= Functions ========================= //
void Rubic()
{
	int seed = rand() % 150 + 50;
	for (int i = seed; i > 0; i--)
	{
		int move = rand() % 16 + 1;
		switch (move)
		{
		case 1:
			clockWiseF(side2, side1, side3, side4, side5);
			break;
		case 2:
			AntiClockWiseF(side2, side1, side3, side4, side5);
			break;
		case 3:
			ClockWiseB(side6, side1, side3, side4, side5);
			break;
		case 4:
			AntiClockWiseB(side6, side1, side3, side4, side5);
			break;
		case 5:
			RightUp(side2, side1, side5, side6, side4);
			break;
		case 6:
			RightDown(side2, side1, side5, side6, side4);
			break;
		case 7:
			LeftUp(side2, side1, side5, side6, side3);
			break;
		case 8:
			LeftDown(side2, side1, side5, side6, side3);
			break;
		case 9:
			UpRight(side2, side3, side4, side6, side1);
			break;
		case 10:
			UpLeft(side2, side3, side4, side6, side1);
			break;
		case 11:
			DownRight(side2, side3, side4, side6, side5);
			break;
		case 12:
			DownLeft(side2, side3, side4, side6, side5);
			break;
		case 13:
			CenterUp(side2, side1, side5, side6);
			break;
		case 14:
			CenterDown(side2, side1, side5, side6);
			break;
		case 15:
			CenterRight(side2, side3, side4, side6);
			break;
		case 16:
			CenterLeft(side2, side3, side4, side6);
			break;
		}
	}
}
// ========================= Print Rubic ========================= //
void printSide(int side[3][3], int offset = 0)
{
	if (offset > 0)
		cout << string(offset, ' ');
	cout << "+-----+-----+-----+" << endl;

	for (int i = 0; i < 3; i++)
	{
		if (offset > 0)
			cout << string(offset, ' ');
		cout << "|  " << side[i][0] << "  |  " << side[i][1] << "  |  " << side[i][2] << "  |" << endl;

		if (offset > 0)
			cout << string(offset, ' ');
		cout << "+-----+-----+-----+" << endl;
	}
}

void printRubik()
{
	printSide(side4, 15);

	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			cout << "+-----+-----+-----+   +-----+-----+-----+   +-----+-----+-----+   +-----+-----+-----+" << endl;
		}

		cout << "|  " << side1[i][0] << "  |  " << side1[i][1] << "  |  " << side1[i][2] << "  |   ";
		cout << "|  " << side2[i][0] << "  |  " << side2[i][1] << "  |  " << side2[i][2] << "  |   ";
		cout << "|  " << side5[i][0] << "  |  " << side5[i][1] << "  |  " << side5[i][2] << "  |   ";
		cout << "|  " << side6[i][0] << "  |  " << side6[i][1] << "  |  " << side6[i][2] << "  |" << endl;

		cout << "+-----+-----+-----+   +-----+-----+-----+   +-----+-----+-----+   +-----+-----+-----+" << endl;
	}

	printSide(side3, 15);
}
// ========================= Color Guide ========================= //
void printColorGuide()
{
	cout << "\nColor Guide:\n";
	cout << "+-----------+-------+\n";
	cout << "| Number    | Color |\n";
	cout << "+-----------+-------+\n";
	cout << "| 1         | Green |\n";
	cout << "| 2         | White |\n";
	cout << "| 3         | Red   |\n";
	cout << "| 4         | Orange|\n";
	cout << "| 5         | Blue  |\n";
	cout << "| 6         | Yellow|\n";
	cout << "+-----------+-------+\n\n";
}
// ========================= Count Colors ========================= //
void countColors()
{
	int count[7] = { 0 };

	int* sides[6] = { &side1[0][0], &side2[0][0], &side3[0][0], &side4[0][0], &side5[0][0], &side6[0][0] };

	for (int s = 0; s < 6; s++)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				count[sides[s][i * 3 + j]]++;
			}
		}
	}

	cout << "Color Counts: ";
	for (int i = 1; i <= 6; i++)
	{
		cout << "Color " << i << ": " << count[i] << "  ";
	}
	cout << "\n\n";
}
// ========================= Main ========================= //
int main()
{
	srand(time(0));
	Rubic();
	system("color 0A");
	cout << "This is the Result:" << endl;
	printColorGuide();
	printRubik();
	countColors();
	system("pause");
	return 0;
}
// ========================= End ========================= //
// Dev: Mohammadreza