//
// Created by ���Ľ� on 2023-10-10.
//

#include <bits/stdc++.h>
#include "SeqStack.h"
#include "SeqDoubleStack.h"
#include "LinkQueue.h"
#include "SeqQueueFlag.h"
#include "SeqQueueNum.h"
#include "Dstack2Queue.h"
#include "Trail_3.cpp"

using namespace std;

class Homework_3 {
public:
	// T 3.1 ��ӡ��ջ˳��
	void TestCatlan() {
		SeqStack<int, 100> station;
		vector<int> out;
		int n = 5;
		get_train_seq(station, out, n);
	}


	// T 3.1 �����ݹ麯��
	void get_train_seq(SeqStack<int, 100>& station, vector<int>& out, int n) {
		/**
		 * @note ��õ�ǰ��վ״���Լ��г���վ����µ����г�ջ����
		 * @param station ��վ
		 * @param out ��ǰ��ջ����
		 * @param n ��ǰ�г����
		 */

		if (out.size() == 5) {
			// �ݹ��յ㣺�����г����ѳ�վ
			for (int i = 0; i < out.size(); i++) {
				cout << out[i] << " \n"[i == out.size() - 1];
			}
			return;
		}

		if (n > 0) {
			// ״̬1�����г�δ��վ����վ
			station.Push(n);
			get_train_seq(station, out, n - 1);
			station.Pop();
		}

		if (!station.Empty()) {
			// ״̬2��վ�㲻Ϊ�գ���վ
			int train = station.Top();
			station.Pop();
			out.push_back(train);
			get_train_seq(station, out, n);
			out.pop_back();
			station.Push(train);
		}
	}


	// T 3.2 ʮ����ת��Ϊ�������
	void TestTransfor() {
		int num, scale;
		cin >> num >> scale;

		SeqStack<int, 100> a;
		while (num >= scale) {
			int ys = num % scale;
			a.Push(ys);
			num = (num - ys) / scale;
		}
		a.Push(num);

		while (!a.Empty()) {
			int t = a.Top();
			a.Pop();
			if (t >= 10) {
				cout << char(t - 10 + 'A');
			} else {
				cout << t;
			}
		}
	}


	// T 3.3 ����ƥ��
	bool TestMatch() {
		string s;
		cin >> s;
		//	s = "{10+9*12+[10/(2+90)+1]*(1+2)}";
		SeqStack<char, 100> a;

		string op = "{[()]}";
		for (int i = 0; i < s.size();) {
			if (isdigit(s[i])) {
				i++;
			} else if (op.find(s[i]) != string::npos) {
				if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
					a.Push(s[i]);
				} else {
					if (a.Empty()) { // �����Ŷ���
						return false;
					} else {
						if (s[i] == '}' && a.Top() == '{' ||
							s[i] == ']' && a.Top() == '[' ||
							s[i] == ')' && a.Top() == '(') {
							a.Pop();
						} else { // ��ƥ��
							return false;
						}
					}
				}
				i++;
			} else {
				i++;
			}
		}

		if (!a.Empty()) { // �����Ŷ���
			return false;
		}

		return true;
	}


	// T 3.4 ��ջ����һ�����Կռ�
	void TestDStack() {
		SeqDoubleStack<int, 10> a;
//		a.Output();
		a.Push_front(12);
		a.Push_front(35);
		a.Pop_front();
//		a.Output();
	}


	// T 3.5 ��׺ת��׺
	void TestMid2Post() {
		string s;
		cout << "��������׺���ʽ��";
		cin >> s;

		Trail_3 t3;
		string post = t3.Mid2Post(s);
		cout << "��׺���ʽΪ��" << post << "\n";
	}


	// T 3.6 ѭ����ʽ����
	void TestCircleLinkQueue() {
		LinkQueue<int> lq;
		lq.Push(1);
		lq.Push(2);
		lq.Push(3);
		lq.Push(4);
		cout << lq.Pop() << "\n";
		cout << lq.Pop() << "\n";
		cout << lq.Pop() << "\n";
		cout << lq.Pop() << "\n";
	}


	// T 3.7 ѭ��˳����� flag
	void TestSeqQueueFlag() {
		SeqQueueFlag<int, 10> sqf;
		sqf.Push(2);
		sqf.Push(8);
		sqf.Push(1);
		cout << sqf.Front() << "\n";
	}


	// T 3.8 ѭ��˳����� num
	void TestSeqQueueNum() {
		SeqQueueNum<int, 3> sqn;
		cout << sqn.Empty() << "\n";
	}


	// T 3.9 ˫ջʵ�ֶ���
	void TestDstack2Queue() {
		int cnt = 0;
		Dstack2Queue<int, 10> dst2q;
		dst2q.Push(4);
		dst2q.Push(7);
		cout << dst2q.Empty() << "\n";
		cout << dst2q.Front() << "\n";
		dst2q.Pop();
		cout << dst2q.Front() << "\n";
	}
};











