# Embedded-System-2024
부경대 2024 IoT 개발자과정 임베디드시스템 학습 리포지토리

## 1일차

- 개발환경 설치
	- 라즈베리파이 설치 : https://www.raspberrypi.com/software/
	- sd card formatter 설치 : https://www.sdcard.org/downloads/formatter/sd-memory-card-formatter-for-windows-download/
		- sd카드 리더기를 usb포트에 삽입 후 포맷작업
		
	- putty 설치 : https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html

	- <업데이트>
		- sudo apt update
		- sudo apt upgrade -y
		- clear

	- 환경설정
		- 편집기 : 코드 작업할 때 사용하는 프로그램(nano)
		- 한글
			- 기존 PC와 같이 사용해서는 안된다.
			- 순서에 맞춰서 사용 (동작중 다른 명령어 처리 X)
			
- 기본 명령어
	- <흰색은 파일 , 파란색은 폴더>
	- ls : 현재 위치의 디렉토리 안의 내용(디렉토리, 파일 등)목록을 보여줌
		- -a : 숨겨진 파일을 모두 보여줌
		- -l : 상세하게 보여줌
		- /etc : 환경(기본 설정)에 관련된 디렉토리
		
	- pwd : 현재 내 위치
	- mkdir : 새로운 디렉토리 생성
	- rm -fr : 디렉토리 삭제
	- clear : 화면 초기화
	- cd : 해당 위치로 이동
	- cd .. : 상위 디렉토리로 빠져나옴
	- ctrl + c : 실행취소
	- ctrl + x : 종료(빠져나옴)
	
- sudo nano /etc/nanorc -> 관리자 권한(sudo)으로 실행
	- 주석제거
		- autoindent 
		- linenumbers
		- tabsize 8 -> tabsize 2

## 2일차
- VNC Viewer 설치 : https://www.realvnc.com/en/connect/download/viewer/
	- putty -> vncserver-virtual
	
- 기본 명령어(추가)
	- <초록색은 실행파일>
	- gcc : 컴파일
		-> 형식 : gcc -o 만들실행파일명 소스파일명
		-> (ex) gcc -o test01 test01.c => 소스파일 test01.c의 실행파일을 test01 이라는 이름으로 생성
		- gcc test01.c => a.out 이라는 기본적인 실행파일 생성(출력(./a.out)은 동일하게 됨)
	- ./ : 출력
	
	- mv : 파일이동, 수정
		-> (ex) mv test01.c test02.c => test01.c를 test02.c로 수정(변경)
	- cp : 파일 복사
		-> (ex) cp test03.c test.c => test.c를 복사하여 test03.c를 생성
		
- 입력과 출력 
// 파일: printf01.c/ printf02.c/ prinf03.c/ func01.c/ func02.c / tri01.c
	- printf : 출력
	- scanf : 입력
		-> 
		```C
		void main()
		{
			int a;
			printf("정수 하나를 입력하세요 >> ");
			scanf("%d", &a);
		}
		```
		
## 3일차
- 연결리스트 : 하나의 노드가 값과 다음 노드를 가리키는 노드로 이루어진 자료구조, 배열의 단점 보완 (배열은 칸 자체를 삭제할 수 없지만 연결리스트는 노드 자체를 삭제할 수 있음.)
    - head 포인터 : 연결리스트에서 첫 번째 노드의 주소를 가지는 포인터
	- 노드 : 연결 리스트의 아이템
        - 데이터 필드 : 연결 리스트의 각 노드에 저장된 데이터
        - 링크 필드 : 다른 노드의 주소를 저장하는 부분
	- 노드의 구조체 
	  ```C
	   typedef struct NODE{
        int data;            // 저장할 데이터
        struct NODE* next;  // 다음 노드를 가리킬 포인터
    	}node;
	  void main()
	  {
		node* head = (node*) malloc(sizeof(node));  // head 노드 동적할당
		head->next = NULL;  // head는 데이터를 가질 필요X, 첫번째 노드를 가리킴.
	  }
	  ```

	![list](https://raw.githubusercontent.com/Juhyi/Embedded-System-2024/main/images/linked_list_1.png)
    
    - 노드 생성 : 동적메모리 할당을 통해 노드를 생성, malloc()함수를 이용하여 노드 크기만큼 동적 메모리를 할당받아 헤드 포인터에 저장
    ```C
    node* newnode = (node*)malloc(sizeof(node)); // newnode 동적할당, 생성
    ```
    - 노드의 필드에 값 저장
    ```C
    newnode->data = 1;
    newnode->next = NULL;  // 마지막 노드의 링크 필드는 NULL을 가짐.
    ```
    -노드 생성과 연결
	
    ```C
    node * head = (node*)malloc(sizeof(node)); // 헤드(시작)노드 생성
    head->next = NULL;
    
	node * node1 = (node*)malloc(sizeof(node)); // 첫번째 노드
    node1->data = 10; 
	node1->next = NULL;	   		// 다음 노드에 NULL로 초기화							
    head->next = node1;
    
    node* node2 = (node*)malloc(sizeof(node)); // 두번째 노드
    node2->data = 20;
    node2->next = NULL;   
    node1->next = node2;                       // 연결리스트의 핵심 :  두번째 노드를 연결
    ```

	![list](https://raw.githubusercontent.com/Juhyi/Embedded-System-2024/main/images/linked_list_image.png)
	- while문을 이용한 노드 출력
	```C
	void showNode(node* pnode)
	{
		node* curr  = head ->next;	     // 임시 포인터 객체 curr이 head->next, 첫번째 노드를 가리키게 함.
		while(curr != NULL)			     // 횟수가 정해져 있지 않은 상황 ->while문 이용
		{
			printf("%d\n", curr->data);	 // 첫번째 노드 데이터 출력	
			curr = curr->next;		     // node2(주소값이 들어감) 가리키게 함.
		}
	} 
	// curr의 next를 curr에 집어 넣으므로 curr이 NULL일때 마지막 노드.
	```
	- 노드의 삽입
		1. 삽입할 노드를 생성
		2. 삽입할 노드의 링크가 삽입될 위치의 후행 노드를 가리키게 한다.
		3. 삽입될 위치의 선행노드의 링크가 삽입할 노드를 가리키게 한다.
		- 전위 삽입 : 새로 만든 노드를 연결리스트 맨 앞에 삽입
     ```C
	 void preAddNode(node* pnode, int data)
	 {
		node* newnode = (node*)malloc(sizeof(node));
		newnode->data = data;
		newnode->next = pnode->next;	// 새로운 노드가 현재 노드의 다음을 가리키게 함.
		pnode->next = newnode;			// 노드가 새로 생성될때 마다 첫번째 노드로 삽입, (현재 노드가 새로운 노드를 가리키게 함.)
	 }   
	 ``` 
		- 후위 삽입 : 새로 만든 노드를 연결리스트 맨 마지막에 삽입
	 ```C
	 void rear_addNode(node* pnode, int _data)
	 {
		node* newnode = (node*)malloc(sizeof(node));  // 새로운 노드추가
		newnode->data = _data;
		newnode->next = NULL;

		while(pnode->next != NULL)	//연결리스트의 마지막 노드의 next가 NULL이므로 끝이 될때까지 순회.
		{
			pnode = pnode->next;	//pnode가 다음 노드를 가리킴.
		}
		pnode->next = newnode;		// 마지막 노드 뒤에 새로만든 노드를 삽입
	}
	 ```
    - 노드 삭제 
		1. 삭제할 노드찾기 : 삭제할 노드의 이전 노드를 알고 있어야함. 연결리스트의 특성 상 직전노드의 링크를 수정해줘야하기 때문에.
		2. 이전노드의 링크 수정 : 삭제할 노드의 이전 노드가 가리키는 링크를 삭제할 노드의 다음 노드로 변경.
		3. 메모리 해제 : 메모리 누수 방지를 위해 free() 수행.
	```C
	// 메인함수에서 구현 (4일차에서 삭제함수 생성 후 메인에서 호출)
	void main()
	{
		// 초기화를 하지 않으면 마지막 노드 삭제 후 이전 노드가 가리키는 것이 없음.
		curr = head->next;  // 첫번째 노드를 가리키는 curr을 head로 초기화.
		while(curr != NULL){
			head->next = curr->next;	// 메모리 반환전  head가 curr이 가리키는 두번째 노드룰 가리키게 함.
			free(curr);			// 첫번째 노드 반환		
			curr = head->next;	// curr값이 두번째 노드를 가리키게 함.
		}
		printf("%d, %d\n", head->next, curr);
		free(head);  // 헤드도 잊지말고 반환할 것!!
	}
	```
## 4일차
- 연결리스트 구현 다르게 해보기 : headNode 포인터 타입의 head 노드를 생성하여 연결리스트 구현
	- 구조체 선언 
	```C
	typedef struct NODE{      // node 구조체
		int data;			
		struct NODE* next;	  // 다음 노드를 가리키는 포인터	
	}node;

	typedef struct{			  // headNode 구조체
		node *head;			  // 연결리스트의 첫번째 노드를 가리키는 포인터. 연결리스트의 시작점	  
	}headNode;
	```
	- head함수 정의 : node* 타입의 head를 선언하지 않고 headNode* 타입의 head를 생성.
	
	 ```C
	headNode* createHeadNode(void)
	{	
		headNode *newhead = (headNode*)malloc(sizeof(headNode));
   		return newhead;
     }
	void main()
	{
	 headNode* newhead =createHeadNode();
	}
	// newhead : headNode의 구조체 포인터 => 이 구조체는 'node'의 구조체 포인터인 head를 멤버로 가짐.
	// newhead-> head가 node를 가리키는 포인터. 즉, newhead->head->data는 node 구조체의 data 멤버에 접근.
	```
	- 삽입 함수 정의
		- 전위 삽입 
		1. 삽입할 노드를 생성 
		: node* 타입의 newnode 동적할당해주기- 프로그램 실행 중에 메모리 공간을 할당을 해주는 것! (힙 영역에)
		<정적할당 - 프로그램 실행전에 미리 메모리공간을 할당>
		```C
		void preAddNode(headNode* pnode, int data)
		{
			node* newnode = (node*)malloc(sizeof(node)); //힙영역 메모리 공간에 node사이즈만큼 할당 받고, 할당받은 주소값을 newnode node포인터변수에 저장.	
			newnode->data = data; 					// 입력받은 데이터 값을 새 node의 데이터 필드에 저장.
			newnode->next = pnode->head; 			// headnode 포인터 변수가 head필드를 참조한 값을 새노드의 next필드에 대입. 
			pnode->head = newnode;					// 새노드를 pnode의 헤드필드에 집어넣는다. == pnode의 헤드필드가 새노드를 가리킨다.
		}
		```
		
		- 후위 삽입
		1. 삽입할 노드를 생성
		2. 마지막 노드 뒤에 새로 만든 노드를 삽입하기 위해=> 연결리스트의 마지막 노드의 next가 NULL이 될때까지 현재 노드가 다음 노드를 가리키는 것을 순회함.
		3. 마지막 노드 뒤에 새로 만든 노드를 삽입
		```c
		void rear_addNode(headNode* pnode, int _data)
		{
			node* newnode = (node*)malloc(sizeof(node));  // 힙영역 메모리 공간에 node사이즈만큼 할당받고 할당받은 주소값을 newnode 노드포인터 변수에 저장.
			newnode-> data = _data;		// 입력받은 data값을 새노드의 데이터필드에 저장
			newnode->next = NULL;		// 후위 삽입이므로 새 노드는 마지막 노드가 됨.  마지막 노드의 링크필드는 NULL을 가리킴

			node* curr = pnode-> head;	// headNode 포인터변수가 head필드를 참조한 값을 node포인터변수 curr에 저장한다.

			while( curr->next != NULL)  // curr의 next필드가 NULL이 되면 순회를 멈춤. 
			{
				curr = curr->next;      // 노드포인터변수 curr이 next필드를 참조한 값을 curr에 집어넣는다. 반복문을 순회하고나면 curr이 마지막 노드, next필드는 NULL을 가짐
			}	
			curr->next = newnode;		// 새노드를 curr 노드 포인터변수 next필드에 집어 넣는다. == curr의 next필드가 새노드를 가리킨다.
		}		
		```
		- 전위삽입이 이루어지지 않은 상태에서 후위삽입 바로 실행할 수 있는 후위삽입 함수
		: pnode의 head가 NULL인 경우의 상황을 if문으로 구현 => 연결리스트가 비어있는 경우 새 노드를 헤드 노드로 설정.
		```C
		void proAddNode(headNode* pnode, int data)
		{
			node* newnode = (node*)malloc(sizeof(node));  // 힙영역 메모리 공간에 node 사이즈만큼의 동적할당을 받은 후 node 포인터 변수 타입의 newnode에 저장
			if(newnode != NULL){		// 동적할당을 제대로 받았다면 밑의 코드를 실행, 프로그램의 안정성을 높이고 메모리 오류를 방지하기 위해 검사하는 것
				newnode->data = data;	// 입력받은 data값을 새노드의 데이터 필드에 저장
				newnode->next = NULL;	//  새노드의 링크필드는 NULL을 가짐.
				if(pnode->head == NULL)		pnode->head = newnode;		// headnode 포인터변수의 head필드 값이 NULL 즉, 연결리스트가 비어있다면 새노드를 headnode 포인터변수의 head필드에 집어넣는다 == pnode의 head필드가 새노드를 가리킴.
				else	// 비어있지 않다면, 위에 코드와 동일
				{
					node* curr = pnode->head;
					while(curr->next != NULL)
					{
						curr = curr->next;
					}
						curr->next = newnode;
				}
			}
		}

	- 삭제 함수 정의 : 삭제할 노드 찾기 -> 이전 노드의 링크 수정 -> 메모리 해제
	```c
	void allFreeNode(headnode *pnode){
		node* curr = pnode->head;   // headNode 포인터변수가 head 필드를 참조한 값을 node포인터변수 curr에 저장
		while(curr != NULL)			// curr이 NULL이 되면 순회를 멈춤 
		{
			printf("%d 노드 삭제\n", curr->data);
			node* temp = curr;		// head 필드 참조값을 가지는 변수 curr 값을 node포인터변수 temp에 저장
			curr = curr ->next;		// curr 노드 포인터변수 next필드를 참조한 값을 curr에 저장
			free(temp)				// 동적할당 해제				
		}
		printf("헤드 삭제");
		free(pnode);				// 헤드노드 동적할당 해제
	}
	```
## 5일차
- 스택(Stack) : "쌓다"의 의미로 데이터를 차곡차곡 쌓아올린 형태의 자료구조
	![stack](https://raw.githubusercontent.com/Juhyi/Embedded-System-2024/main/images/stack.png)

	- LIFO(Last In First Out) : 후입선출, 가장 마지막에 삽입된 자료가 가장 먼저 삭제되는 구조
	- Top으로 정한 곳을 통해서만 접근할 수 있으면 top을 통해 자료가 쌓이고 삭재된다.
	- 연산 : 삽입연산(push), 삭제연산(pop)
	- 사용사례 : 웹 브라우저 방문기록(뒤로가기), 실행취소(undo), 역순 문자열 만들기, 후위 표기법 계산
		
	
	- 배열로 stack 구현하기
		- 배열, 배열의 크기, TOP 위치 정의
		```C
		#define STACK_SZ 10
		#define TRUE 1
		#define FLASE 0

		int stack[STACK_SZ];
		int top = -1;
		```
		- 스택이 가득 찼는지 확인하는 함수 정의
		```C
		int isFull(void)
		{
			if(top == STACK_SZ - 1) return TRUE;	// 가득차면 1 반환 
			else	return FALSE;					// 아니면 0 반환
		}
		```
		- 스택이 비었는지 확인하는 함수 정의
		```C
		int isEmpty(void)
		{
			if(top <= -1)	return TRUE;	// 사용환경에서 일시적 오류가 발생할 수 있으므로 == 말고 <=을 사용
		  	else	return FALSE;
		}
		```
		- 삽입연산 함수 정의 : 스택은 차곡차곡 자료가 쌓이는 형태 
		```C
		void push(int data)
		{
			if(isFull()){
				printf("stack overflow\n");
				return;
			}
			stack[++top] = data; 	// 오버플로때문에 ++전위로 사용 
			// 데이터를 추가하기 전에 top을 증가시키고 증가된 top에 데이터를 할당.
		}
		```
		- 삭제연산 함수 정의 : LIFO, 마지막에 넣은 데이터가 삭제.
		```C
		int pop(void)
		{
			if(isEmpty())
			{
				printf("stack underflow\n");
				return -1;
			}
			return stack[top--]; // 스택에서 데이터를 제거하고 반환
			// 현재 top에 있는 데이터를 추출하고 난 후 top 1 감소
		}
		```
	- 연결리스트로 stack 구현하기
		- 구조체 stack 선언 
		```C
		#define STACK_SZ 10
		typedef struct STACK{
			int buf[STACK_SZ];	// satck의 요소를 저장하는 배열
			int top;			// stackd의 맨 위에 있는 요소를 가리키는 인덱스
		}stack;

		- 삽입연산 함수 정의
		```C 
		void push(stack* st, int value)		// 출력은 없고 입력으로 매개변수 stack포인터 변수 타입의 st와 int타입의 value를 가짐.
			{
			if(st->top == STACK_SZ -1){	// 배열의 마지막 인덱스의 값과 st 포인터변수 top 필드를 참조할 값이 같으면
				printf("stack overflow\n");	// stack이 가득차서 더 값을 넣을 수 없다.
				return;	
			}
			st->top++;	// st의 top 필드를 참조한 값을 +1 해줌
			st->buf[st->top] = value;	// 입력받은 값을  st포인터 변수의 buf 필드를 참조한 값에 저장. (buf의 인덱스는 st포인터 변수가 top필드를 참조한 값)
			
			// 위의 두줄을 한줄로 표현하면 => st->buf[++(st->top)] = value;  
			printf("%d\n", value);
		}
		
		- 삭제연산 함수 정의
		```C
		int pop(stack* st, int value)	// 실제로 삭제하는 것이 아니라 배열의 출력에서 나타나지 않게 해주는 함수 구현
		{
			if(stack->top == -1)
			{
				printf("stack underflow\n");
				return;
			}

			int delete = st->buf[st->top];	// int형 변수에 stack의 최상위 요소의 값을 저장. 
			st->top--;	// top 값을 -1 해줌
			return delete;	// 삭제할 요소의 값을 반환.
			//return st->buf[(st->top)--];  

		}

- 큐(Queue) : 한쪽 끝에서만 삽입이 이루어지고, 다른 한쪽 끝에서는 삭제 연산이 이루어지는 자료구조.
	![queue](https://raw.githubusercontent.com/Juhyi/Embedded-System-2024/main/images/queue.png)
	
	- FIFO(First In First Out) : 먼저 들어간 것이 먼저 나가는 형식
	- 전단(front) : 데이터 삭제연산 (가장 먼저 들어왔던 데이터가 쌓이는쪽) -> dequeue () 연산
	- 후단(rear) : 데이터의 삽입 연산 (가장 나중에, 최근에 삽입된 데이터가 쌓여있는 쪽) -> enqueue() 연산
	- 예시 : 한줄로 나가야하는 차들, 컴퓨터 운영체제의 테스크 스케쥴링


	- 배열로 queue 구현하기 : 실제로 삭제하지는 않고 FIFO 로 입력되고 출력되는 것을 보이는 것을 구현하였음.
		- 연산기능 함수 구현전 전역변수 선언
		```C
		int queue[10];	
		int rear = 0;
		int front = 0;
		```
		- 삽입연산 함수 정의
		```C
		void enqueue(int data)	// 입력으로 배열의 요소값 넣음
		{
			if(rear >= Q_SIZE -1)	// 배열이 가득 차 있으면
			{
				printf("queue overflow\n");	 // queue가 가득 찼다는 문자열 출력
				return;	 // 함수를 즉시 종료. 함수를 호출하는 곳으로 제어를 반환	
			}

			queue[++rear] = data;  // rear이 -1으로 초기화되어 있으므로 data 값을 삽입하기 전에 증가를 시켜준 후 요소값 저장. 
		}
		```
		- 삭제연산 함수 정의
		```C
		int dequeue()
		{
			if(front == rear)  // 입력이 없었다면 front와 rear값 변화 X
			{
				printf("queue underflow\n");	
				return -1;	// 함수 즉시 종료, 함수를 호출하는 곳에서 -1 반환
			}
			
			return queue[++front]; 	// front가 -1이므로 인덱스를 1증가시켜 준 후 배열의 요소 값 반환 
		}

## 6일차
- QUEUE 구현 계속
	- 순차 자료구조를 이용한 큐 자료구조                                      : 동적할당을 받아 순차 자료구조를 표현하고 있지만 메모리 해제를 하지 않고 구현하였음. 배열의 인덱스를 사용하여 큐 자료 구조를 나타냄 
		- 구조체 선언
		```C
		typedef struct{
			int front;	// 삭제연산을 하는 front 필드 
			int rear;	// 삽입연산을 하는 rear 필드
			char queue[Q_SIZE]; // queue 배열
		}queue;
		```
		- malloc() 함수를 이용하여 동적할당 해주기
		```C
		queue* create()
		{
			queue* q = malloc(sizeof(queue)); // 힙영역 메모리 공간에 queue 사이즈만큼의 동적할당을 받은 후 queue 포인터 변수 타입의 q에 저장
			if(q == NULL) exit(!);	// q가 비어있으면 프로그램 종료
			q->front = -1;	// q의 front 필드의 값 -1로 초기화
			q->rear =-1;	// q의 rear 필드이 값 -1로 초기화
			return q;       // 생성한 queue 포인터 변수 타입의 q를 반환함.
		}
		```
		- 삽입연산 함수 정의하기
		```C
		void enqueue(queue* qNew, char a) //매개변수로 queue 포인터 변수 타입,char 타입을 가짐
		{
			if(qNew->rear >= Q_SIZE -1){ // 새노드의 rear 필드를 참조한 값이 배열의 마지막 인덱스 보다 크다면
				printf(" QUEUE Overflow!\n");	// queue 배열이 가득찼다는 문자열 출력
					return;
			}
			qNew->queue[++(qNew->rear)] = a; // 새노드의 배열 queue 필드의 인덱스를 초기화 시킨 rear필드의 값에서 1 증가시킨 후 그 인덱스에 배열의 요소 저장
			printf("ENQUEUE: %c", qNew->queue[qnew->raer]); // queue 배열은 queue 구조체의 필드의 값이므로 qNew -> queue[] 로 참조해야 배열의 요소 값에 접근 가능.
		}
		```

		- 삭제연산 함수 정의하기
		```C
		char dequeue(queue* qNew, char a)	
		{
			if(q->front == q->real)		// q 포인터 변수가 front필드를 참조한 값과 real을 참조한 값이 동일하다면
			{	
				printf("QUEUEU Underflow\n");	// queue 가 비었다는 문자열 출력
				return -1;
			}
			else{	
				char dequeueQ = q->queue[++(q->front)];	// 포인터 변수 q가 배열 queue를 참조하는데 인덱스는 q가 front필드를 참조한 값 +1인 요소값을 dequeueQ에 저장 
				printf("DEQUEUE: %s\n", deqqueueQ);		// dequeue 출력
				return dequeue;
			}
		}
		```
		- 출력함수 정의하기
		```C
		void printQ(queue* pq)
		{
			if(pq->front == pq->rear) // queue 포인터 변수가 front 필드를 참조한 값과 rear을 참조한 값이 같을 때 == enqueue 함수 호출과 dequeue 함수 호출 수가 같을때
			{
				printf("QUEUE Emtry!\n");	// queue 가 비었다는 문자열 출력
			}
			else  // 빈칸 출력을 피하기 위해 else 사용
			{
				printf("QUEUE: ");	
				int i = pq->front;	// pd 포인터 변수가 front 필드를 참조한 값을 정수형 변수 i에 저장
				while(i <= (pq->rear)) //i가 pd포인터 변수가 rear을 참조한 값보다 작거나 같을때까지
				{
					printf("%c ",pq->queue[++i]);	// 인덱스를 1씩 증가시키고 그 value를 출력함.
					// 만약 enqueue가 2번 호출되고 dequeue는 호출이 한번도 되지 않았다면 => i =-1부터 0 될때까지 2번 반복하고 queue[0]과 queue[1]이 출력됨.
				}
				printf("\n");
			}
		}
		```
	- 연결리스트를 이용한 큐 구현하기
		- 구조체 선언하기
		```C
		// 연결리스트 사용을 위한 노드 구조체 선언
		typedef struct NODE{  
			int data;		  // 큐의 각 요소의 값이 돠는 data필드	
			struct NODE* link; // 다음노드를 가리킬 link 필드
		}node;	
		// 큐 구조체 선언
		typedef struct{		
			node* rear;		// 삽입연산을 하는 부분을 node 포인터 변수 타입 rear 선언 
			node* front;	// 삭제연산을 하는 부분을 node 포인터변수 타입 front 선언
		}linkQ;
		```
		- 큐 생성함수 구현하기
		```C
		linkQ createLinkQ()
		{
			linkQ* linkedQ = (linkQ*)malloc(sizeof(linkQ));	////힙영역 메모리 공간에  linkQ사이즈만큼 할당 받고, 할당받은 주소값을 linkedQ linkQ포인터변수에 저장.	
			linkedQ->rear = NULL;	// 새노드의 rear 필드 값을 NULL로 초기화
			linkedQ->front = NULL; 	// 새노드이 fronbt 필드 값을 NULL로 초기화
			printf("linkQ* 타입의 노드 생성 완료");
			return linkedQ;
		} 
		```
		- 삽입연산 함수 구현하기
		```C
		void enQueue(linkQ* newQ, int _data)
		{
			node* newnode = (node*)malloc(sizeof(node));
			newnode->data = _data;
			newnode->link = NULL;

			if(linkedQ->rear == NULL)
			{
				newQ->rear = newnode;
				newQ->front = newnode;
			}
			else{
				newQ->rear->link = newnode;
				newQ->rear = newnode;
			}
		}
		```
		- 삭제연산 함수 구현하기
		```C
		int deqQueue(linkQ* deletQ)
		{
			if(deldeQ->front == NULL){
				printf("Queue is Empty, Dequeue Fail\n")
			}
			else{
				node* temp = deletQ->front;
				int data = temp->data;
				
				deletQ->front = temp ->link;
				printf("Dequeue %d 추출\n", data);
				free(temp);
				return data;
			}
		}
		```
		- 출력함수 구현하기
		```C
		void printQ(linkQ* pq)
		{
			if(pq->front== NULL && pq->rear == NULL)
			{
				printf("Queue is Em)
			}




		}































