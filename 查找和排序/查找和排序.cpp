// 查找和排序.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include "SSearch.h"
using namespace std;

int main()
{
	SSearch<int> s[4];
	int n, k; int m;
	
	cout << "请输入数据元素的个数：";
	cin >> n;
	for (int i = 0; i < 4; i++) {
		s[i].Create(n);
	}
	cout << endl;
	for (int i = 0; i < 4; i++) {
		cout << "选择排序方式【折半插入排序（1），快速排序（2），简单选择排序（3），堆排序（4）】：";
			cin >> k;
			
			if (k == 1) {
				cout << "请输入想要查找的值：";
				cin >> m;
				cout << "顺序查找结果为：" << s[k - 1].SeSearch(m) << endl;
				cout << "折半插入排序后";
				s[k - 1].BInsertSort();
				s[k - 1].Display();
				cout << "请输入想要查找的值：";
				cin >> m;
				cout << "折半查找(非递归)结果为：" << s[k - 1].BiSearch_1(m) << endl;
				cout << "折半查找(递归)结果为：" << s[k - 1].BiSearch_2(m) << endl;
				cout << endl;
			}
			else if (k == 2) {
				cout << "请输入想要查找的值：";
				cin >> m;
				cout << "顺序查找结果为：" << s[k - 1].SeSearch(m) << endl;
				cout << "快速排序后";
				s[k - 1].QuitSort();
				s[k - 1].Display();
				cout << "请输入想要查找的值：";
				cin >> m;
				cout << "折半查找(非递归)结果为：" << s[k - 1].BiSearch_1(m) << endl;
				cout << "折半查找(递归)结果为：" << s[k - 1].BiSearch_2(m) << endl;
				cout << endl;
			}
			else if (k == 3) {
				cout << "请输入想要查找的值：";
				cin >> m;
				cout << "顺序查找结果为：" << s[k - 1].SeSearch(m) << endl;
				cout << "简单选择排序后";
				s[k - 1].SelectSort();
				s[k - 1].Display();
				cout << "请输入想要查找的值：";
				cin >> m;
				cout << "折半查找(非递归)结果为：" << s[k - 1].BiSearch_1(m) << endl;
				cout << "折半查找(递归)结果为：" << s[k - 1].BiSearch_2(m) << endl;
				cout << endl;
			}
			else if (k == 4) {
				cout << "请输入想要查找的值：";
				cin >> m;
				cout << "顺序查找结果为：" << s[k - 1].SeSearch(m) << endl;
				cout << "堆排序后";
				s[k - 1].HeapSort();
				s[k - 1].Display();
				cout << "请输入想要查找的值：";
				cin >> m;
				cout << "折半查找(非递归)结果为：" << s[k - 1].BiSearch_1(m) << endl;
				cout << "折半查找(递归)结果为：" << s[k - 1].BiSearch_2(m) << endl;
				cout << endl;
			}
	}

	
	return 0;
}

