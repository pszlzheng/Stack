#include<stdlib.h>
#include<stdio.h>
#include"variable.h"

int classSub = 0;

PSeqList createNullSeqList(int num)
{
	PSeqList palist = (PSeqList)malloc(length_Seq);//malloc�����Զ�����ָ�����ȵĿռ��˳���
	if (palist != NULL)
	{
		palist->next = NULL;
		palist->elements = (DataType*)malloc(length_Stu*num);//˳����е�element�а�����Ԫ�ظ����ɴ�����������
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

PSeqList createClass(int num ,int code)//��һ��������ʾ�˽ڵ�Ԥ�ư������ٸ�ѧ�����ڶ���������ʾ�˰༶��ѧ��
{
	PSeqList Node = (PSeqList)malloc(length_Seq);//malloc�����Զ�����ָ�����ȵĿռ��˳���
	if (Node != NULL)
	{
		Node->next = NULL;
		Node->elements = (DataType*)malloc(length_Stu * num);//˳����е�element�а�����Ԫ�ظ����ɴ�����������
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
	PSeqList Cache = createClass(5, classSub);//���ýڵ����ɺ���������������ɽڵ�
	while (palist->next != NULL)//��������������ָ��ָ�����һ���ڵ�
	{
		palist = palist->next;
	}
	palist->next = Cache;//�������β�����������ӵĽڵ�
}