#ifndef XML_OPERATION_HPP
#define XML_OPERATION_HPP
#include "tinyxml/tinyxml.h"
#include "tinyxml/tinystr.h"

TiXmlElement *ReadXML(const char *filename);
TiXmlElement *ReadXML(const char *filename)
{
	TiXmlDocument *doc = new TiXmlDocument(filename);
	TiXmlElement *root;
	bool loadOK = doc->LoadFile();	/*ŒÓÔØxmlÎÄŒþ*/
	if (!loadOK)
	{
		return NULL;
	}
	root= doc->RootElement();
	return root;
}

#endif

