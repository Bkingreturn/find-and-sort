#pragma once
template<class T>
struct Node {
	T key;
	/*
	....根据需要添加。
	*/
};
template<class T>
class SSearch {
private:
	Node<T> *ST;//表首址；
	int len;//表长；
public:
	SSearch();//构造函数；
	~SSearch();//析构函数，删除表空间；
	void Create(int n);//创建时根据用户需求，再为相应的数据元素赋值；
	void Display();//输出静态表中的数据元素；
	int GetLen();
	int SeSearch(T key);//从表中最后一个元素开始顺序查找；
	void Ascendsort();//升序排列；
	int BiSearch_1(T key);//折半查找，非递归算法；
	int BiSearch_2(T key);//折半查找，递归算法；
	int BiSearch(int x, int y, T key);//折半查找递归；
	void BInsertSort();//折半插入排序；
	void QuitSort();//快速排序；
	void SelectSort();//简单选择排序；
	int SelectMinKey(int n);
	void HeapSort();//堆排序；
};
template<class T>
int SSearch<T>::GetLen() {
	return len;
}
template <class T>
SSearch<T>::SSearch() {
	ST = NULL;
	len = 0;
}
template<class T>
SSearch<T>::~SSearch() {
	delete ST;
	len = 0;
}
template<class T>
void SSearch<T>::Create(int n) {
	len = n;
	ST =  new Node<T>[len+1];
	Node<T>e;
	cout << "请输入" << len << "个数据元素：";
	for (int i = 1; i < len+1; i++) {
		cin >> e.key;
		ST[i] = e;
	}
}
template<class T>
void SSearch<T>::Display() {
	int i;
	cout << "静态表中的数据元素为：";
	for (i = 1; i < len ; i++) {
		cout << ST[i].key << ",";
		
	}
	if (i = len) cout << ST[i].key << endl;
}
template<class T>
int SSearch<T>::SeSearch(T key) {
	int i;
	ST[0].key = key;
	for (i = len; (ST[i].key<key)||(ST[i].key>key); i--);
	if (i == 0) cout << "查找不成功！" << endl;
	return i;
}
template<class T>
int SSearch<T>::BiSearch_1(T key) {
	if (len == 0 && ST == NULL) {
		cout << "静态表不存在，请重新建立表\n";
		return -1;
	}
	else {
		int low = 1, high = len, mid;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (key == ST[mid].key) { 
				return mid;
				break;
			}
			else if (key < ST[mid].key) high = mid - 1;
			else if (key > ST[mid].key) low = mid + 1;
		}
		return -1;
	}
}
template<class T>
int SSearch<T>::BiSearch(int x, int y, T key) {
	int mid = (x + y) / 2;
	if (ST[mid].key == key) {
		return mid;
	}
	else if (x > y)
		return -1;
	else if (key < ST[mid].key) return BiSearch(x, mid - 1, key);
	else
		return BiSearch(mid + 1, y, key);
}
template<class T>
int SSearch<T>::BiSearch_2(T key) {
	int k;
	k = BiSearch(1, len, key);
	return k;
}


/************折半插入排序************/
template<class T>
void SSearch<T>::BInsertSort() {
	int high, low, mid;
	for (int i = 2; i <=len; i++) {
		ST[0].key = ST[i].key;
		low = 1;
		high = i - 1;
		while (low <= high) {
			mid = (low + high) / 2;
			if (ST[0].key <= ST[mid].key)
				high = mid - 1;
			else
				low = mid + 1;
		}
		for (int j = i - 1; j >= high + 1; --j)
			ST[j + 1].key = ST[j].key;
		ST[high + 1].key = ST[0].key;
	}
}
/************折半插入排序************/



/************快速排序************/
template<class T>
int Partition(Node<T> *ST,int low,int high) {
	T pivotkey;
	ST[0].key = ST[low].key;
	pivotkey = ST[low].key;
	while (low < high) {
		while (low < high&&ST[high].key >= pivotkey) --high;
		ST[low].key = ST[high].key;
		while (low < high&&ST[low].key <= pivotkey) ++low;
		ST[high].key = ST[low].key;
	}
	ST[low].key = ST[0].key;
	return low;
}

template<class T>
void Qsort(Node<T> *ST, int low, int high) {
	int mid;
	if (low < high) {
		mid = Partition(ST, low, high);
		Qsort(ST, low, mid-1);//对低子表进行排序；
		Qsort(ST, mid+1, high);//对高子表进行排序；

	}
}

template<class T>
void SSearch<T>::QuitSort() {
	Qsort(ST, 1, len);
}
/************快速排序************/


/************简单选择排序************/
template<class T>
int SSearch<T>:: SelectMinKey(int n){
	int min = n;
	T minkey;
	minkey = ST[n].key;
	for (int i = n + 1; i <= len; i++) {
		if (ST[i].key < minkey) {
			minkey = ST[i].key;
			min = i;
		}
	}
	return min;
}

template<class T>
void SSearch<T>::SelectSort() {
	int j;
	T t;
	for (int i = 1; i <= len; i++) {
		j = SelectMinKey(i);
		if (i != j) {
			t = ST[i].key;
			ST[i].key = ST[j].key;
			ST[j].key = t;
		}
	}
}
/************简单选择排序************/


/************堆排序************/
template<class T>
void HeapAdjust(Node<T> *ST, int s, int m) {
	T rc = ST[s].key;
	for (int j = 2 * s; j <= m; j *= 2) {
		if (j < m&&ST[j].key <= ST[j + 1].key) j++;
		if (rc > ST[j].key) break;
		ST[s].key = ST[j].key;
		s = j;
	}
	ST[s].key = rc;
}

template<class T>
void SSearch<T>::HeapSort() {
	T value;
	for (int i = len / 2; i > 0; i--) {
		HeapAdjust(ST, i, len);
	}
	for (int i = len; i > 1; --i) {
		value = ST[1].key;
		ST[1].key = ST[i].key;
		ST[i].key = value;
		HeapAdjust(ST, 1, i - 1);
	}
}
/************堆排序************/

