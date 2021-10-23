#include <iostream>
#define N 100

bool prostoe(int x)
{
	if (x < 2)
		return false;
	for (int d = 2; d <= sqrt(x); d++)
		if (x % d == 0)
			return false;
	return true;
}
int main()
{
	setlocale(0, "RUS");
	int n;
	std::cin>> n;
	int k = 0, matrix[N][N], f, d, b, sum, p = 0, s;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			std::cin>> matrix[i][j];
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		for (int j = 0; j < n; j++)
		{
			sum = sum + matrix[i][j];
			if (matrix[i][j] < 2)
				f = 0;
			else 
			{
				f = 1;
				d = 2;
				while (f == 1 && d * d <= matrix[i][j]) 
				{
					if (matrix[i][j] % d == 0)
						f = 0;
					else
						d = d + 1;
				}
				if (f == 1)
					p = 1;
			}
			if (p == 1 && sum == 0) 
			{
				k = 1;
			}
		}
	}
	if (k == 1) 
	{
		std::cout<< "Новая матрица:"<<std::endl;
		for (int j = 0; j < n; j++)
			for (int i = 0; i < n - 1; i++)
				for (k = i + 1; k < n; k++)
					if (matrix[i][j] < matrix[k][j]) 
					{
						s = matrix[i][j];
						matrix[i][j] = matrix[k][j];
						matrix[k][j] = s;
					}
	}
	else
		std::cout<< "Матрица не изменилась:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			std::cout<< matrix[i][j]<< " ";
		std::cout<< std::endl;
	}
}