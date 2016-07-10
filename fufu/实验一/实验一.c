# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>
# include <string.h>

/********************************************************
 * �궨�壺˳��������ɵ����Ԫ�ظ���
 *******************************************************/
#define	NUM 50

/********************************************************
 * ���������ݽṹ���� 
 *******************************************************/
typedef struct stuInfo {
	char stuName[10];         /*ѧ������*/
	long Age;                 /*����*/
}ElemType;

typedef struct node{
	ElemType data;
	struct node *next;	
}ListNode, *ListPtr;

/********************************************************
 * �������� 
 *******************************************************/
 
// ���ı��ļ�fname�ж������ݵ���������Name��Age��
int read_file(char * fname, char Name[][11], long* Age);

// ��ʾ���ļ��ж�������ݣ����ڲ��ԣ� 
void show_list(char Name[][11], long* Age,  int num);

// ���ݶ�����������鴴�����Ա�
// �ر�˵�������������������Ϊʾ��Ŀ�� 
// �������������ͷ���ֵ�ɸ����Լ�����Ҫ��ϰ�������޸�
ListPtr list_create(char Name[][11], long * Age, int n); 

void list_sort(ListPtr plist);

ListPtr list_merge(ListPtr plistA, ListPtr plistB);

void list_print(ListPtr plist);

int data_cmp(const ElemType * A, const ElemType * B);


/********************************************************
 * ������
 ********************************************************/

int main(int argc, char *argv[])
{
	char *fnameA = "FileStuInfoA.txt";  // ��Ż�������ı��ļ� 
	char *fnameB = "FileStuInfoB.txt";  // ��Ż�������ı��ļ� 
	int num = 0;         // �������е�ѧ������ 
	char Name[NUM][11];  // ��ά���飬ÿ��Ϊһ���������ַ����� 
	long Age[NUM];       // һά���飬Ԫ��Ϊ������ֵ��long��
	
	ListPtr plistA, plistB, plist; 
	
	// ���ļ��ж��������������ŵ����������� 
	num = read_file(fnameA, Name, Age); 
	
	//show_list(Name, Age, num); // ��ʾ���뵽�����е���Ϣ�Ƿ���ȷ 
	
	// ��ĳ�������￪ʼ ����
	plistA =  list_create(Name, Age, num);
	list_sort(plistA);

	num = read_file(fnameB, Name, Age);
	plistB =  list_create(Name, Age, num);
	list_sort(plistB);

	plist = list_merge(plistA, plistB);

	list_print(plist);
	
	return 0;
}

/*********************************************************
 * read_file()�����ı��ļ�����ѧ����Ϣ���浽������ 
 ********************************************************/
int read_file(char * fname, char Name[NUM][11], long* Age)
{
	int scount = 0;
	char charAge[13 + 1];
	FILE * pFile = NULL;
	
	pFile = fopen(fname, "r");
	if(!pFile)	{
		printf("���ļ�ʧ��!\n");
		exit(0);
	}
	else{
		printf("���ļ��ɹ�!\n");
	}
	
	memset(Age, 0, NUM *4);
	memset(Name, 0, NUM * (10 + 1));
	
	while(!feof(pFile))	{		
		fscanf(pFile,"%s", charAge);
		fscanf(pFile,"\t%s\n",  Name[scount]);
		Age[scount] = (long)_atoi64(charAge);
		scount++;
	}
	
	fclose(pFile);
	return scount;
}

/*********************************************************
 * show_list()����ʾ���뵽�����е���Ϣ�Ƿ���ȷ
 ********************************************************/
void show_list(char Name[][11], long* Age,  int num)
{
	printf("����\t ����\n");
	int i;
	for(i = 0; i < num; i++){
		printf("%s\t %ld\n", Name[i], Age[i]);
	}
}

/*********************************************************
 * list_create()�����ݶ�����������鴴�����Ա�
 ********************************************************/
ListPtr list_create(char Name[][11],long * Age, int n)
{
	ListPtr p = (ListPtr)malloc(sizeof(ListNode));
	p->next = NULL;	ListPtr tail = p;
	for (int i = 0; i < n; i++) {
		ListPtr newNode = (ListPtr)malloc(sizeof(ListNode));
		strcpy(newNode->data.stuName, Name[i]);
		newNode->data.Age = Age[i];
		newNode->next = NULL;
		tail->next = newNode;
		tail = tail->next;
	}
	return p;
} 

void list_sort(ListPtr plist)
{
	if (plist == NULL || plist->next == NULL)
		return;
	while (1) {
		int flag = 0;
		ListPtr p = plist->next;
		while (p->next != NULL) {
			ListPtr q = p->next;
			if (data_cmp(&p->data, &q->data) > 0) {
				ElemType t = p->data;
				p->data = q->data;
				q->data = t;
				flag = 1;
			}
			p = q;
		}
		if (!flag)
			break;
	}
}

ListPtr list_merge(ListPtr plistA, ListPtr plistB)
{
	ListPtr plist = (ListPtr)malloc(sizeof(ListNode));
	plist->next = NULL;
	ListPtr iterA = plistA->next, iterB = plistB->next;
	while (iterA != NULL || iterB != NULL) {
		if (iterB == NULL || data_cmp(&iterA->data, &iterB->data) < 0)
			plist->data = iterA->data;
		else
			plist->data = iterB->data;
		while (iterA != NULL && data_cmp(&iterA->data, &plist->data) == 0)
			iterA = iterA->next;
		while (iterB != NULL && data_cmp(&iterB->data, &plist->data) == 0)
			iterB = iterB->next;
		ListPtr newNode = (ListPtr)malloc(sizeof(ListNode));
		newNode->next = plist;
		plist = newNode;
	}
	return plist;
}

void list_print(ListPtr plist)
{
	ListPtr p = plist->next;
	printf("����\t ����\n");
	while (p != NULL) {
		printf("%s\t %ld\n", p->data.stuName, p->data.Age);
		p = p->next;
	}
}

int data_cmp(const ElemType * A, const ElemType * B)
{
	if (A->Age < B->Age)
		return -1;
	if (A->Age > B->Age)
		return 1;
	return strcmp(A->stuName, B->stuName);
}
