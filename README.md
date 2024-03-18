# Embedded-System-2024
# embedded-system-2024
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
		-> ex) gcc -o test01 test01.c => 소스파일 test01.c의 실행파일을 test01 이라는 이름으로 생성
		- gcc test01.c => a.out 이라는 기본적인 실행파일 생성(출력(./a.out)은 동일하게 됨)
	- ./ : 출력
	
	- mv : 파일이동, 수정
		-> ex) mv test01.c test02.c => test01.c를 test02.c로 수정(변경)
	- cp : 파일 복사
		-> ex) cp test03.c test.c => test.c를 복사하여 test03.c를 생성
		
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
- 연결리스트 : 하나의 노드가 값과 다음 노드를 가리키는 노드로 이루어진 자료구조
    - head 포인터 : 연결리스트에서 첫 번째 노드의 주소를 가지는 포인터
    - 노드 : 연결 리스트의 아이템
        - 데이터 필드 : 연결 리스트의 각 노드에 저장된 데이터
        - 링크 필드 : 다른 노드의 주소를 저장하는 부분
    ``` 노드 구조
    typedef struct NODE{
        int data;            // 노드의 데이터를 담고 있는 데이터 필드
        struct NODE* nexct;  // 자기자신을 가리키는 링크 필드
    }node;
    ```
    - 노드 생성 : 동적메모리 할당을 통해 노드를 생성, malloc()함수를 이용하여 노드 크기만큼 동적 메모리를 할당받아 헤드 포인터에 저장
	 ![list](https://raw.githubusercontent.com/Juhyi/Embedded-System-2024/main/images/linked_list_image.png)
    ```노드 생성
    node* newnode = (node*)malloc(sizeof(node)); // 헤드 포인터에 동적 메모리 주소 저장
    ```
    - 노드의 필드에 값 저장
    '''노드 필드 값 저장
    newnode->data = 1;
    newnode->next = LULL;  // 마지막 노드의 링크 필드는 NULL을 가짐.
    ```
    -노드 생성과 연결
    ```C
    node * head = (node*)malloc(sizeof(node)); // 헤드(시작)노드 생성
    node1->next = head->next;
    node * node1 = (node*)malloc(sizeof(node));
    head->next = NULL;
    node1->data = 10;
    head->next = node1;
    

    node* node2 = (node*)malloc(sizeof(node));
    node2->next = node1->next;
    node2->data = 20;
    node1->next = node2;
    ```
    ![list](https://raw.githubusercontent.com/Juhyi/Embedded-System-2024/main/images/linked_list_1.png)