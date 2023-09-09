#include <iostream>
#include<string>

using namespace std;

class StringNode {
private:
	string elem; //원소의 값
	StringNode* next; // 다음 노드를 가리키는 포인터
	friend class StringLinkedList; //StringLinkedList의 private 원소로의 접근 허용
};

class StringLinkedList {
public:
	StringLinkedList(); // 빈 리스트 생성
	~StringLinkedList();
	bool empty()const; // 리스트 empty 여부
	const string& front()const; // 첫번째 원소 return
	void addFront(const string& e); // 맨 앞에 원소 추가
	void removeFront(); // 맨 앞 원소 제거
private:
	StringNode* head;
};

StringLinkedList::StringLinkedList() //생성자
	:head(NULL) {} // head==NULL이면 빈 리스트

StringLinkedList::~StringLinkedList() { while (!(empty())) removeFront(); }
// empty함수가 true를 리턴할 때까지 removeFront 함수 실행

bool StringLinkedList::empty()const {
	return head == NULL;
}

const string& StringLinkedList::front()const { return head->elem; }

void StringLinkedList::addFront(const string& e) { //e는 새로 넣을 값
	StringNode* v = new StringNode; // 1. 새로운 노드 동적 할당
	v->elem = e; // 새로운 노드에 값 넣기
	v->next = head; // 2. 새로운 노드가 head 값 가리키도록 함
	head = v; // 3. head가 새로운 노드 가리키기도록 함.
}

void StringLinkedList::removeFront() {
	StringNode* old = head; // 1. head 값을 임시 변수에 저장
	head = old->next; // 2. head 값을 old의 다음 노드로 변경 
	delete old; //3. old 삭제
}