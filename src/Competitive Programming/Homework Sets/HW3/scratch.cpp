
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;

int main()  //移动的步数可以看出x坐标和y坐标移动的和（即向x方向移动步数并不影响y方向的移动步数）。
{
    int n;
    while (cin >> n) {
        int x[10005];
        int y[10005];
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &x[i], &y[i]);
        }
        sort(x, x + n);  //将x坐标进行排序
        sort(y, y + n);  //将y坐标进行排序
        for (int i = 0; i < n; i++) {
            x[i] -= i;
        } //如果x坐标是连续数（如1，2，3）减去其下标位置则全部相同
        sort(x, x + n);
        int midx = x[(n - 1) / 2];
        int midy = y[(n - 1) / 2];  //y坐标移动到mid[(n-1)/2]移动步数最少，这是中点坐标的性质
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += abs(x[i] - midx);//使x有序递增所需步数
            ans += abs(y[i] - midy); //将士兵移到同一水平所需步数
        }
        cout << ans << endl;
    }

    return 0;
}