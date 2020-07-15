#include<stdlib.h>
#include<stdio.h>
#include"variable.h"

int classSub = 0;

PSeqList createNullSeqList(int num)
{
	PSeqList palist = (PSeqList)malloc(length_Seq);//malloc函数自动分配指定长度的空间给顺序表
	if (palist != NULL)
	{
		palist->next = NULL;
		palist->elements = (DataType*)malloc(length_Stu*num);//顺序表中的element中包含的元素个数由创建函数给出
		if (palist->elements)
		{
			palist->maximum = num;
			palist->subCode = 0;
			palist->classCode = 0;
			return palist;
		}
		else
		{
			free(palist);
		}
	}
	printf("failed to create a sqelist!");
	return NULL;
}

int isSeqlistEmpty(PSeqList palist)
{
	PSeqList temp = (PSeqList)malloc(length_Seq);
	temp = palist;
	if (temp->elements)
		return 1;
	return 0;
}

int getLength(PSeqList palist)
{
	int sub = 0;
	while (palist->elements[sub].StuID)
	{
		sub+=1;
		print("The ID and Name of the student is %d->%s",palist->elements[sub].StuID, palist->elements[sub].StuNam);
	}
	return sub;
}

PSeqList createClass(int num ,int code)//第一个参数表示此节点预计包含多少个学生，第二个参数表示此班级的学号
{
	PSeqList Node = (PSeqList)malloc(length_Seq);//malloc函数自动分配指定长度的空间给顺序表
	if (Node != NULL)
	{
		Node->next = NULL;
		Node->elements = (DataType*)malloc(length_Stu * num);//顺序表中的element中包含的元素个数由创建函数给出
		if (Node->elements)
		{
			Node->maximum = num;
			Node->subCode = 0;
			Node->classCode = code;
			classSub += 1;
			return Node;
		}
		else
		{
			free(Node);
		}
	}
	printf("failed to create a sqelist!");
	return NULL;
}

void addNodesToPalist(PSeqList palist,int Number)
{
	PSeqList Cache = createClass(5, classSub);//调用节点生成函数，输入参数生成节点
	while (palist->next != NULL)//遍历整个链表，将指针指向最后一个节点
	{
		palist = palist->next;
	}
	palist->next = Cache;//在链表的尾部加上新增加的节点
}