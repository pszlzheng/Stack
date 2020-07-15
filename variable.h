#pragma once
#ifndef _VARIABLE_H_	//if not def=ifndef 
#define _VARIABLE_H_

#define length_Seq sizeof(struct Node)
#define length_Stu sizeof(struct Student)

struct Student
{
	char StuNam[10];
	int  StuAge;
	long StuID;
	char StuCla[10];
	char StuOrg[10];
};

typedef struct Student DataType;

struct Node
{
	int subCode;
	int maximum;
	int classCode;
	DataType* elements;
	PSeqList next;
};

typedef struct Node* PSeqList;

#endif
