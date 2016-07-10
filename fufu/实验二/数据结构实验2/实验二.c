#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	NUM 100

typedef struct {
	int weight; char ch;
	int lchild, rchild, parent;
} TNode, *PHT;

typedef struct {
	char ch;
	char *pcode;
} TCode, *PCode;

int calc_freq(char text[], int **freq, char **dict, int n);

void huffman(PHT *pht, int *freq, char *dict, int n);

void get_code(PCode *pcode, PHT p, int n);

void show_result(PCode pcode, int n);

int main(int argc, char *argv[])
{
	int n, m, *freq;
	char text[NUM], *dict;
	PHT p = NULL;
	PCode pc = NULL;
	scanf("%s", &text);
	n = strlen(text);

	m = calc_freq(text, &freq, &dict, n);

	huffman(&p, freq, dict, m);

	get_code(&pc, p, m);

	show_result(pc, m);

	return 0;
}

// 统计字符串text中字符出现的频率，参数n为字符串长度
// 返回值为：text中出现的不同种类的字符个数
// 副作用：通过指针参数间接返回两个数组，其中：
//		dict：字符数组，存放 text中出现的不同种类的字符
//		freq：整型数组，存放 text中出现的不同种类的字符的出现频率 
int calc_freq(char text[], int **freq, char **dict, int n)
{
	int i, k, nchar = 0;
	int * pwght;
	char * pch;
	int tokens[256] = {0};

	// 根据输入的文本字符串逐一统计字符出现的频率 
	for(i = 0; i < n; ++i){
		tokens[text[i]]++;
	}
	
	// 统计共有多少个相异的字符出现在文本串中 
	for(i = 0; i < 256; i++){
		if( tokens[i] > 0 ){
			nchar++;
		}
	}

	// 为权重数组分配空间 
	pwght = (int*)malloc(sizeof(int)*nchar);
	if( !pwght ){
		printf("为权重数组分配空间失败！\n");
		exit(0);
	}
	
	// 为字符数组（字典）分配空间 
	pch = (char *)malloc(sizeof(char)*nchar);
	if( !pch ){
		printf("为字符数组（字典）分配空间失败！\n");
		exit(0);
	}
	
	k = 0;
	for(i = 0; i < 256; ++i){
		if( tokens[i] > 0 ){
			pwght[k] = tokens[i];
			pch[k] = (char)i;  //强制类型转换 
			k++;
		}
	}
	
	*freq = pwght;
	*dict = pch;
	
	return nchar;
}

void huffman(PHT *pht, int *freq, char *dict, int n)
{
	PHT p = *pht = (PHT)malloc((n * 2 - 1) * sizeof(TNode));
	int i, j, min1, min2;
	for (i = 0; i < n; ++i)
	{
		p[i].weight = freq[i];
		p[i].ch = dict[i];
		p[i].lchild = p[i].rchild = p[i].parent = -1;
	}
	for (i = n; i < n + n - 1; ++i)
	{
		min1 = min2 = -1;
		for (j = 0; j < i; ++j)
		{
			if (p[j].parent == -1)
			{
				if (min1 == -1 || p[min1].weight > p[j].weight)
					min2 = min1, min1 = j;
				else if (min2 == -1 || p[min2].weight > p[j].weight)
					min2 = j;
			}
		}
		p[i].weight = p[min1].weight + p[min2].weight;
		p[i].lchild = min1;
		p[i].rchild = min2;
		p[i].parent = -1;
		p[min1].parent = i;
		p[min2].parent = i;
	}
}

void get_code(PCode *pcode, PHT pht, int n)
{
	PCode p = *pcode = (PCode)malloc(n * sizeof(TNode));
	int i, j, k, len;
	for (i = 0; i < n; ++i)
	{
		len = 0;
		j = i;
		while (j != -1)
		{
			j = pht[j].parent;
			len++;
		}
		p[i].ch = pht[i].ch;
		p[i].pcode = (char*)malloc(len * sizeof(char));
		j = i;
		for (k = len - 2; k >= 0; --k)
		{
			if (pht[pht[j].parent].lchild == j)
				p[i].pcode[k] = '0';
			else
				p[i].pcode[k] = '1';
			j = pht[j].parent;
		}
		p[i].pcode[len - 1] = 0;
	}
}

void show_result(PCode pcode, int n)
{
	int i;
	for (i = 0; i < n; ++i)
	{
		printf("%c %s\n", pcode[i].ch, pcode[i].pcode);
	}
}
