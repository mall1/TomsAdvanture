#include <iostream>
#include <string>
#include "tinyxml.h"
#include "tinystr.h"
#define NAME_STR 20
#define ELEMENT_STR 20
using namespace std;

struct Element
{
	char f[ELEMENT_STR];/*��¼Ԫ����*/
	

};
struct Text
{
	void *text;
	void *Next;
};
class XML_DataTransfer
{
private:
	struct character c;/*����XML�ļ��е���Ϣ*/
	struct map m; 
	char *filename;
	TiXmlDocument *doc;/*���XML��Ϣ����״�ṹ*/
	bool OK;	/*�򿪻򴴽�xml�ļ��Ƿ�ɹ�*/

public:
	XML_DataTransfer() 
	{
		filename = new char[NAME_STR];
		strcpy(filename, "G:\\C++");
		doc = new TiXmlDocument(filename);
	}
	XML_DataTransfer(char *f)
	{
		filename = f;
		doc = new TiXmlDocument(filename);
	}
	~XML_DataTransfer()
	{
		delete[]filename;
		delete doc;
	}

	int char2int(char *s)
	{ 
		int n; 
		sscanf(s, "%d", n);
		return n;
	}
	double char2double(char *s)
	{
		double n;
		sscanf(s, "%f", n);
		return n;
	}
	char *int2char(int n)
	{
		char s[10];
		sprintf(s, "%d", n);
		return s;
	}
	char *double2char(double n)
	{
		char s[10];
		sprintf(s, "%f", n);
		return s;
	}

	bool ReadXML();/*�����ļ���,���xml�ļ�����Ϣ���ɹ��򷵻�TRUE*/
	bool WriteXML();/*����Ϣд��xml�ļ���д��ɹ�����TRUE*/

};

bool XML_DataTransfer::WriteXML()
{
	TiXmlText
}

bool XML_DataTransfer::ReadXML()
{
	bool loadOK = doc->LoadFile();	/*����xml�ļ�*/
	const char *value;
	if (!loadOK) 
	{
		return false;
	}

	TiXmlElement *root = doc->RootElement();	/*������ڵ�*/
	for (TiXmlNode* ObjectItem = root->FirstChild(); ObjectItem;
		ObjectItem = ObjectItem->NextSibling())		/*�������ڵ��µ������ӽڵ�*/
	{
		TiXmlNode *msg = ObjectItem->FirstChild();
		
		while (msg)
		{
			printf("%s=", msg->Value());
			value = msg->FirstChild()->Value();
			puts(value);
			msg = msg->NextSiblingElement();
		}
		
	}
	return true;

}

