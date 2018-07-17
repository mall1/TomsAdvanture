#include <iostream>
#include <string>
#include "tinyxml.h"
#include "tinystr.h"
#define NAME_STR 20
#define ELEMENT_STR 20
using namespace std;

struct Element
{
	char f[ELEMENT_STR];/*记录元素名*/
	

};
struct Text
{
	void *text;
	void *Next;
};
class XML_DataTransfer
{
private:
	struct character c;/*放入XML文件中的信息*/
	struct map m; 
	char *filename;
	TiXmlDocument *doc;/*存放XML信息的树状结构*/
	bool OK;	/*打开或创建xml文件是否成功*/

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

	bool ReadXML();/*输入文件名,输出xml文件的信息，成功则返回TRUE*/
	bool WriteXML();/*将信息写入xml文件，写入成功返回TRUE*/

};

bool XML_DataTransfer::WriteXML()
{
	TiXmlText
}

bool XML_DataTransfer::ReadXML()
{
	bool loadOK = doc->LoadFile();	/*加载xml文件*/
	const char *value;
	if (!loadOK) 
	{
		return false;
	}

	TiXmlElement *root = doc->RootElement();	/*读入根节点*/
	for (TiXmlNode* ObjectItem = root->FirstChild(); ObjectItem;
		ObjectItem = ObjectItem->NextSibling())		/*遍历根节点下的所有子节点*/
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

