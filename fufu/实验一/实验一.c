# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>
# include <string.h>

/********************************************************
 * 宏定义：顺序表能容纳的最大元素个数
 *******************************************************/
#define	NUM 50

/********************************************************
 * 基本的数据结构定义 
 *******************************************************/
typedef struct stuInfo {
	char stuName[10];         /*学生姓名*/
	long Age;                 /*年龄*/
}ElemType;

typedef struct node{
	ElemType data;
	struct node *next;	
}ListNode, *ListPtr;

/********************************************************
 * 函数声明 
 *******************************************************/
 
// 从文本文件fname中读入数据到两个数组Name和Age中
int read_file(char * fname, char Name[][11], long* Age);

// 显示从文件中读入的数据（用于测试） 
void show_list(char Name[][11], long* Age,  int num);

// 根据读入的两个数组创建线性表
// 特别说明：这个函数声明是作为示范目的 
// 函数名、参数和返回值可根据自己的需要和习惯自行修改
ListPtr list_create(char Name[][11], long * Age, int n); 

void list_sort(ListPtr plist);

ListPtr list_merge(ListPtr plistA, ListPtr plistB);

void list_print(ListPtr plist);

int data_cmp(const ElemType * A, const ElemType * B);


/********************************************************
 * 主程序
 ********************************************************/

int main(int argc, char *argv[])
{
	char *fnameA = "FileStuInfoA.txt";  // 存放花名册的文本文件 
	char *fnameB = "FileStuInfoB.txt";  // 存放花名册的文本文件 
	int num = 0;         // 花名册中的学生人数 
	char Name[NUM][11];  // 二维数组，每行为一个姓名（字符串） 
	long Age[NUM];       // 一维数组，元素为长整型值（long）
	
	ListPtr plistA, plistB, plist; 
	
	// 从文件中读入姓名和年龄存放到两个数组中 
	num = read_file(fnameA, Name, Age); 
	
	//show_list(Name, Age, num); // 显示读入到数组中的信息是否正确 
	
	// 你的程序从这里开始 ……
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
 * read_file()：从文本文件读入学生信息保存到数组中 
 ********************************************************/
int read_file(char * fname, char Name[NUM][11], long* Age)
{
	int scount = 0;
	char charAge[13 + 1];
	FILE * pFile = NULL;
	
	pFile = fopen(fname, "r");
	if(!pFile)	{
		printf("打开文件失败!\n");
		exit(0);
	}
	else{
		printf("打开文件成功!\n");
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
 * show_list()：显示读入到数组中的信息是否正确
 ********************************************************/
void show_list(char Name[][11], long* Age,  int num)
{
	printf("姓名\t 年龄\n");
	int i;
	for(i = 0; i < num; i++){
		printf("%s\t %ld\n", Name[i], Age[i]);
	}
}

/*********************************************************
 * list_create()：根据读入的两个数组创建线性表
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
	printf("姓名\t 年龄\n");
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
