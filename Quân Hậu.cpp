//Ý tưởng: Xếp theo từng cột
#include <iostream>
#include <vector>

using namespace std;

void In(vector<vector<int>>& a, int &n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
bool AnToan(vector<vector<int>>& a, int &n, int hang, int cot) 
//Duyệt xem hậu đặt đây có bị chiếu không (so với các hậu ở hàng trước) Do đó chỉ duyệt về phía bên trái
{
	int i, j;
	for (i = cot; i >= 0; i--) //Duyệt trên hàng
	{
		if (a[hang][i]) return false;
	}
	for (i = hang, j = cot; i >= 0 && j >= 0; i--, j--) //Duyệt đường chéo trên bên trái
	{
		if (a[i][j]) return false;
	}
	for (i = hang, j = cot; i < n && j >= 0; i++, j--) //Duyệt đường chéo dưới bên trái
	{
		if (a[i][j]) return false;
	}
	return true;
}
bool DatHau(vector<vector<int>>& a, int &n, int cot)
{
	if (cot == n) return true; //Hậu đặt xong hết thì kết thúc
	for (int i = 0; i < n; i++)
	{
		if (AnToan(a, n, i, cot) == true)
		{
			a[i][cot] = 7;
			if (DatHau(a, n, cot + 1) == true) return true;
			a[i][cot] = 0; //Không đặt được thì quay trở lại bước liền trước rồi đặt chỗ khác - Đây chính là Backtracking
		}
	}
	return false;
}
bool GiaiHau(vector<vector<int>>& a, int &n)
{
	if (DatHau(a, n, 0) == false)
	{
		cout << "Khong the dat duoc het cac quan hau!";
		return false;
	}
	In(a, n);
	return true;
}

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n, 0));
	GiaiHau(a, n);
	return 0;
}