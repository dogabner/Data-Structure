#include <iostream>
#include <cstring>
 
using namespace std;
 
int ans, column[10][10], row[10][10], squre[10][10], a[10][10];
void DFS(int i, int j);
int cal(int i, int j);
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		ans = 0;
		memset(column, 1, sizeof column);
		memset(row, 1, sizeof row);
		memset(squre, 1, sizeof squre);
 
		for (int i = 1; i <= 9; i++)
			for (int j = 1; j <= 9; j++)
			{
				cin >> a[i][j];
				int k = a[i][j];
				if (k && (!row[i][k] || !column[j][k] || !squre[cal(i, j)][k]))
					ans = 2;
				row[i][k] = 0;
				column[j][k] = 0;
				squre[cal(i, j)][k] = 0;
			}
		DFS(1, 1);
		if (ans == 1)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}
 
int cal(int i, int j)
{
 
	return (i - 1) / 3 * 3 + (j - 1) / 3 + 1;
}
void DFS(int i, int j)
{
	if (ans >= 2)
		return;
	if (j == 10)
	{
		i++;
		j = 1;
	}
	if (i == 10)
	{
		ans++;
		return;
	}
	if (a[i][j])
		DFS(i, j + 1);
	else
		for (int k = 1; k <= 9; k++)
			if(row[i][k] && column[j][k] && squre[cal(i, j)][k])
			{
				row[i][k] = column[j][k] = squre[cal(i, j)][k] = 0;
				DFS(i, j + 1);
				row[i][k] = column[j][k] = squre[cal(i, j)][k] = 1;
			}
}