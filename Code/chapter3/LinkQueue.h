//
// Created by ���Ľ� on 2023-10-10.
//

#include "../chapter2/Node.h"


#ifndef INC_3__DATASTRUCTURES_LINKQUEUE_H
#define INC_3__DATASTRUCTURES_LINKQUEUE_H

// ��ͷ�����ֻ��һ��βָ���ѭ����ʽ����
template<class T>
class LinkQueue {
private:
	Node<T>* rear;

public:
	LinkQueue();
	~LinkQueue();
	void Clear();
	void Push(T x);
	T Pop();
};

template<class T>
LinkQueue<T>::LinkQueue() {
	Node<T>* hh = new Node<T>();
	rear = hh;
}

template<class T>
LinkQueue<T>::~LinkQueue() {
	// 0�����
	if (!rear->next) {
		cerr << "�ն��У��޷����" << "\n";
		exit(1);
	}
	// �ͷų���β�����������еĽ��
	Node<T>* hh = rear->next;
	while (hh->next != rear) {
		Node<T>* front = hh->next;
		hh = front->next;
		delete front;
	}
	// �ͷ����һ�����
	Node<T>* last = rear;
	rear = hh;
	hh->next = nullptr;
	delete last;
}

template<class T>
void LinkQueue<T>::Clear() {
	// 0�����
	if (!rear->next) {
		cerr << "�ն��У��޷����" << "\n";
		exit(1);
	}
	// �ͷų���β�����������еĽ��
	Node<T>* hh = rear->next;
	while (hh->next != rear) {
		Node<T>* front = hh->next;
		hh = front->next;
		delete front;
	}
	// �ͷ����һ�����
	Node<T>* last = rear;
	rear = hh;
	hh->next = nullptr;
	delete last;
}

template<class T>
void LinkQueue<T>::Push(T x) {
	Node<T>* now = new Node<T>(x);
	// �����״����
	Node<T>* hh = nullptr;
	if (!rear->next) {
		hh = rear;
	} else {
		hh = rear->next;
	}
	rear->next = now;
	rear = now;
	now->next = hh;
}

template<class T>
T LinkQueue<T>::Pop() {
	if (!rear->next) {
		cerr << "����" << "\n";
		exit(1);
	}
	Node<T>* hh = rear->next;
	Node<T>* front = hh->next;
	T res = front->data;
	if (front->next == hh) { // �������һ������������ÿ��������н�׳�Ա�д
		rear = hh;
		hh->next = nullptr;
	} else {
		hh->next = front->next;
		delete front;
	}
	return res;
}

#endif //INC_3__DATASTRUCTURES_LINKQUEUE_H
















