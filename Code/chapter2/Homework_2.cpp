//
// Created by ���Ľ� on 2023-10-10.
//

#include "SeqList.h"
#include "LinkList.h"
#include "CircleList.h"

using namespace std;

class Homework_2 {
public:
	// T 1.1 ɾ����Сֵ���ҷ�����Сֵ
	void TestDeleteMin() {
		int arr1[] = {2, 4, 1, 5}, n1 = 4;
		SeqList<int> a(arr1, n1);

		a.Output();
		cout << a.DeleteMin() << endl;
		a.Output();

		int arr2[] = {}, n2 = 0;
		SeqList<int> b(arr2, n2);

		// ���Կձ�
//		b.Output();
//		b.DeleteMin();
//		b.Output();
	}


	// T 1.2 ɾ�����и���ֵx������Ԫ��
	void TestDeleteAllX() {
		int arr[] = {2, 4, 1, 2, 5, 2}, n = 6;
		SeqList<int> a(arr, n);

		a.Output();
		a.DeleteAllX(2);
		a.Output();
	}


	// T 1.3 ɾ����ֵ�ڸ���ֵs��t(Ҫ��sС��t)֮�������Ԫ��
	void TestDeleteRange() {
		int arr[] = {1, 3, 4, 5, 7, 8, 10}, n = 7;
		SeqList<int> a(arr, n);

		a.Output();
		a.DeleteRange(3, 7);
		a.Output();
	}


	// T 1.4 ȥ��
	void TestUnique() {
		int arr[] = {3, 2, 5, 4, 2, 3, 9}, n = 7;
		SeqList<int> a(arr, n);

		a.Output();
		a.Unique();
		a.Output();
	}


	// T 1.5 �����Ĳ���
	void TestInsert() {
		int arr[] = {2, 3, 5, 7, 10}, n = 5;
		SeqList<int> a(arr, n);

		a.Output();
		a.IncreaseInsert(30);
		a.Output();
	}


	// T 1.6 ������
	void TestDecompose() {
		int arr[] = {1, 2, 3, 4}, n = 4;
		LinkList<int> a(arr, n);
		LinkList<int> odd, even;
		a.Split(odd, even);
		odd.Output();
		even.Output();
	}


	// T 1.7 ������
	void TestCopy() {
		int arr[] = {1, 2, 3, 4}, n = 4;
		LinkList<int> a(arr, n);
		LinkList<int> b(a);
		b.Output();
	}


	// T 1.8 �������
	void TestSortAndOutput() {
		int arr[] = {3, 2, 1, 4}, n = 4;
		LinkList<int> a(arr, n);
		a.SortAndOutput();
	}


	// T 1.9 ����һ��
	void TestSortOnce() {
		int arr[] = {4, 2, 1, 9}, n = 4;
		SeqList<int> a(arr, n);
		// 2 1 3 4
		a.Output();
		a.SortOnce();
		a.Output();
	}


	// T 1.10 ����ѭ������Ľ�����
	void TestCircleList() {
		int arr[] = {4, 2, 1, 9}, n = 4;
		CircleList<int> a(arr, n);
		cout << a.CountNode();
	}
};