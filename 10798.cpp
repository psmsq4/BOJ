#include <iostream>

using namespace std;

int main(void)  {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);

	char M[5][15] = {0, };

	for (int i = 0; i < 5; ++i) {	
        	cin >> M[i];
   	}

	int col = 0;
	int eof = 0;
	int row = 0;

	for (col = 0; col < 15; ++col)	{
		for (row = 0; row < 5; ++row)	{
			if (M[row][col] == '\0')	{
				eof++;
				continue;
			}
			cout << M[row][col];
		}	
		if (eof == 5)
			break;
		eof = 0;
   	}

    return 0;
}
