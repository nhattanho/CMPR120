#include"Shapes.h"
#include<iostream>
#include<string>
using namespace std;

namespace shapes
{
	void printSquare(int size, bool shapeSolid)
	{
		int row, column;
		for (row = 0; row < size; row++)
		{
			for (column = 0; column < size; column++)
			{
				if (!shapeSolid && row != 0 && row != size - 1)
				{
					if (column != 0 && column != size - 1)
					{
						cout << " ";
						continue;
					}
				}
				cout << "*";
			}
			cout << endl;
		}
		cout << endl;
	}

	void triangleRightAngle_Southwest(int size, bool shapeSolid)
	{
		int row, column;
		for (row = 1; row <= size; row++)
		{
			for (column = 1; column <= row; column++)
			{
				if (!shapeSolid && column != 1
					&& column != row && row != size)
				{
					cout << " ";
					continue;
				}
				cout << "*";
			}
			cout << endl;
		}
		cout << endl;
	}

	void triangleRightAngle_Southeast(int size, bool shapeSolid)
	{
		int row, column;
		for (row = size; row >= 1; row--)
		{
			for (column = 1; column <= row; column++)
			{
				if (!shapeSolid && column != 1
					&& column != row && row != size)
				{
					cout << " ";
					continue;
				}
				cout << "*";
			}
			cout << endl;
		}
		cout << endl;
	}
	
	void triangleRightAngle_Northwest(int size, bool shapeSolid)
	{
		int row, column;
		for (row = size; row >= 1; row--)
		{
			for (column = 1; column < row; column++)
			{
				cout << " ";
			}
			for (column = row; column <= size; column++)
			{
				if (!shapeSolid && column != row && column != size && row != 1)
				{
					cout << " ";
					continue;
				}
				cout << "*";
			}
			cout << endl;
		}
		cout << endl;
	}

	void triangleRightAngle_Northeast(int size, bool shapeSolid)
	{
		int row, column;
		for (row = 1; row <= size; row++)
		{
			for (column = 1; column < row; column++)
			{
				cout << " ";
			}
			for (column = row; column <= size; column++)
			{
				if (!shapeSolid && row != 1 && column != row && column != size)
				{
					cout << " ";
					continue;
				}
				cout << "*";
			}
			cout << endl;
		}
		cout << endl;
	}

	void triangleRightAngle_North(int size, bool shapeSolid)
	{
		int row, column, i;
		for (row = size, i = 1; row >= 1; row--, i++)
		{
			for (column = 1; column < row; column++)
			{
				cout << " ";
			}
			for (column = 1; column < 2 * i; column++)
			{
				if (!shapeSolid && i != size
					&& column != 1 && column != 2 * i - 1)
				{
					cout << " ";
					continue;
				}
				cout << "*";
			}
			cout << endl;
		}
		cout << endl;
	}

	void triangleRightAngle_East(int size, bool shapeSolid)
	{
		int row, column;
		for (row = 1; row <= size; row++)
		{
			for (column = 1; column <= row; column++)
			{
				if (!shapeSolid && column != 1 && column != row)
				{
					cout << " ";
					continue;
				}
				cout << "*";
			}
			cout << endl;
		}
		for (row = 1; row < size; row++)
		{
			for (column = 1; column <= size - row; column++)
			{
				if (!shapeSolid && column != 1 && column != size - row)
				{
					cout << " ";
					continue;
				}
				cout << "*";
			}
			cout << endl;
		}
		cout << endl;
	}

	void triangleRightAngle_West(int size, bool shapeSolid)
	{
		int row, column;
		for (row = size; row >= 1; row--)
		{
			for (column = 1; column < row; column++)
			{
				cout << " ";
			}
			for (; column <= size; column++)
			{
				if (!shapeSolid && column != row && column != size)
				{
					cout << " ";
					continue;
				}
				cout << "*";
			}
			cout << endl;
		}
		for (row = 1; row < size; row++)
		{
			for (column = 1; column <= row; column++)
			{
				cout << " ";
			}
			for (; column <= size; column++)
			{
				if (!shapeSolid && column != (row + 1) && column != size)
				{
					cout << " ";
					continue;
				}
				cout << "*";
			}
			cout << endl;
		}
		cout << endl;
	}

	void triangleRightAngle_South(int size, bool shapeSolid)
	{
		int row, column, i;
		for (row = 1, i = size; row <= size; row++, i--)
		{
			for (column = 1; column < row; column++)
			{
				cout << " ";
			}
			for (column = 1; column < 2 * i; column++)
			{
				if (!shapeSolid && row != 1 && column != 1 && column != 2 * i - 1)
				{
					cout << " ";
					continue;
				}
				cout << "*";
			}
			cout << endl;
		}
		cout << endl;
	}

	void printCircle(int size, bool shapeSolid)
	{

	}
}