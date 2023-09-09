#include <iostream>
#include<string>

using namespace std;

class StringNode {
private:
	string elem; //������ ��
	StringNode* next; // ���� ��带 ����Ű�� ������
	friend class StringLinkedList; //StringLinkedList�� private ���ҷ��� ���� ���
};

class StringLinkedList {
public:
	StringLinkedList(); // �� ����Ʈ ����
	~StringLinkedList();
	bool empty()const; // ����Ʈ empty ����
	const string& front()const; // ù��° ���� return
	void addFront(const string& e); // �� �տ� ���� �߰�
	void removeFront(); // �� �� ���� ����
private:
	StringNode* head;
};

StringLinkedList::StringLinkedList() //������
	:head(NULL) {} // head==NULL�̸� �� ����Ʈ

StringLinkedList::~StringLinkedList() { while (!(empty())) removeFront(); }
// empty�Լ��� true�� ������ ������ removeFront �Լ� ����

bool StringLinkedList::empty()const {
	return head == NULL;
}

const string& StringLinkedList::front()const { return head->elem; }

void StringLinkedList::addFront(const string& e) { //e�� ���� ���� ��
	StringNode* v = new StringNode; // 1. ���ο� ��� ���� �Ҵ�
	v->elem = e; // ���ο� ��忡 �� �ֱ�
	v->next = head; // 2. ���ο� ��尡 head �� ����Ű���� ��
	head = v; // 3. head�� ���ο� ��� ����Ű�⵵�� ��.
}

void StringLinkedList::removeFront() {
	StringNode* old = head; // 1. head ���� �ӽ� ������ ����
	head = old->next; // 2. head ���� old�� ���� ���� ���� 
	delete old; //3. old ����
}