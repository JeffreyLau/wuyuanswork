//LIB_XML.H

/*##############################################################################
#��������:
#       �����ͽ���XML�ļ�
#
#�ļ�����:
# 
#������Ϣ:
#       1215343312@qq.com                                   2012-05-25   ����
#��Ȩ��Ϣ:
#       Copyright(c) 2008~201x at TJ
#  	    1215343312@qq.com All rights reserved.
###############################################################################*/

#ifndef LIB_XML_H
#define LIB_XML_H
#ifdef WIN32
#if defined(LIB_XML_EXPORTS)
#define TJXML_API  extern "C" __declspec(dllexport) 
#else 
#define TJXML_API  extern "C" __declspec(dllimport) 
#endif
#else//LINUX
#define TJXML_API  //extern "C" 
#endif//WIN32


#ifndef HNODE   //���
#define HNODE void *
#endif//HNODE

#ifndef HXMLFILE   //�ĵ����
#define HXMLFILE void *
#endif//HXMLFILE

#ifndef HXMLELEMENT //�ڵ�Ԫ��
#define HXMLELEMENT void *
#endif//HXMLFILE

#ifndef HXMLTEXT    //�ڵ��ĵ�
#define HXMLTEXT    void *
#endif//HXMLTEXT

#ifndef HXMLATTRB   //�ڵ�����
#define HXMLATTRB   void *
#endif//HXMLATTRB

#ifndef CHAR 
#define CHAR  char
#endif//CHAR

#ifndef INT
#define INT  int
#endif//INT

#ifndef VOID
#define VOID void
#endif//VOID

#ifndef BOOL
#define BOOL int
#endif//BOOL

#ifndef TRUE
#define TRUE 1
#endif//TRUE

#ifndef FALSE
#define FALSE 0
#endif//FALSE

#ifndef FLOAT
#define FLOAT float
#endif//FLOAT

#ifndef USHORT
#define USHORT unsigned short
#endif//USHORT

#ifndef DOUBLE
#define DOUBLE double
#endif//DOUBLE


typedef enum{
	VALTYPE_CHAR    =  1,
	VALTYPE_INT     =  2,
	VALTYPE_FLOAT   =  3,
	VALTYPE_BOOL    =  4,
	VALTYPE_BOOLSTR =  5,
}ENU_VALUETYPE;

TJXML_API   HXMLFILE       XML_CreateFile             (CHAR *lpszFileName,CHAR*lpszRoot,BOOL  bIsRead);
TJXML_API   VOID           XML_CloseFile              (HXMLFILE hXmlFile);

TJXML_API   HXMLELEMENT    XML_GetRootElement         (HXMLFILE hXmlFile);
TJXML_API   HXMLELEMENT    XML_GetChildElement        (HXMLELEMENT Element);
TJXML_API   HXMLELEMENT    XML_GetNextElement         (HXMLELEMENT Element);
TJXML_API   HXMLELEMENT    XML_CreateElement          (HXMLFILE hXmlFile,HXMLELEMENT ParentElement,CHAR *lpszElement);
TJXML_API   HXMLELEMENT    XML_LinkElement            (HXMLELEMENT ParentElement,HXMLELEMENT hElement);

TJXML_API   HXMLATTRB      XML_ElementGetAttrb        (HXMLELEMENT hElement,CHAR** lpVal);
TJXML_API   BOOL           XML_ElementGetValue        (HXMLELEMENT hElement,CHAR *ElementName,VOID * lpVal,USHORT nValSize,ENU_VALUETYPE ValType);
TJXML_API   BOOL           XML_ElementSetValue        (HXMLELEMENT hElement,CHAR *ElementName,VOID * lpVal,USHORT nValSize,ENU_VALUETYPE ValType);
TJXML_API   CHAR*          XML_ElementGetLabel        (HXMLELEMENT hElement);

TJXML_API   HXMLTEXT       XML_CreateText             (HXMLFILE hXmlFile,HXMLELEMENT ParentElement,CHAR *lpszElement);
TJXML_API   HXMLTEXT       XML_LinkText               (HXMLELEMENT ParentElement,HXMLTEXT hText);
//                         XML_FirstChild(HXMLElement ,....);

/////////////////////////////////////////////////////////////////////////////////

//�ڵ���TiXmlNode
TJXML_API const CHAR* XML_GetValue(HNODE hNode);//�õ��ڵ���hNode��ֵ
TJXML_API VOID  XML_SetValue(HNODE hNode, const CHAR *pszValue);//���ýڵ���hNode��ֵΪpszValue
TJXML_API VOID  XML_Clear(HNODE hNode);//ɾ�����ڵ�������ӽڵ㣨�����ӽڵ㺬�Ĵ��ӽڵ㣩�������޸ı��ڵ�
TJXML_API HNODE XML_Parent(HNODE hNode);//�õ����ڵ�
//�ӽڵ�
TJXML_API HNODE XML_FirstChild(HNODE hNode);//���ص�һ���ӽڵ�����ָ��
TJXML_API HNODE XML_FirstChildByValue(HNODE hNode, const CHAR *pszValue);
TJXML_API HNODE XML_LastChild(HNODE hNode);//�������һ���ӽڵ�����ָ��
TJXML_API HNODE XML_LastChildByValue(HNODE hNode, const CHAR *pszValue);
//�༭�ӽڵ�
TJXML_API HNODE XML_LinkEndChild(HNODE hNode, HNODE hAddThis);//�����½ڵ�hAddThis��hNode����
TJXML_API HNODE XML_InsertEndChild(HNODE hNode, const HNODE hAddThis);//�����½ڵ㵽ĩβ
TJXML_API HNODE XML_InsertBeforeChild(HNODE hNode, HNODE *phBeforeThis, const HNODE hAddThis);//��ָ���ڵ�λ��ǰ�����½ڵ�
TJXML_API HNODE XML_InsertAfterChild (HNODE hNode, HNODE *phAfterThis, const HNODE hAddThis);//��ָ���ڵ�λ�ú�����½ڵ�
TJXML_API HNODE XML_ReplaceChild(HNODE hNode, HNODE *phReplaceThis, const HNODE hWithThis);//�滻ָ���Ľڵ�
TJXML_API BOOL  XML_RemoveChild(HNODE hNode, HNODE hRemoveThis);//ɾ��ָ���Ľڵ�
//ͬ���ڵ�
TJXML_API HNODE XML_PreviousSibling(HNODE hNode);//���ݵ�ǰ�ڵ㣬������һ���ڵ��ָ��
TJXML_API HNODE XML_PreviousSiblingByValue(HNODE hNode, const CHAR *pszValue);
TJXML_API HNODE XML_NextSibling(HNODE hNode);//���ݵ�ǰ�ڵ㣬������һ���ڵ��ָ��
TJXML_API HNODE XML_NextSiblingByValue(HNODE hNode, const CHAR *pszValue);
//����Ԫ��
TJXML_API HNODE XML_NextSiblingElement(HNODE hNode);//������һ��ͬ��Ԫ�ض������������͵Ľڵ�
TJXML_API HNODE XML_NextSiblingElementByValue(HNODE hNode, const CHAR *pszValue);//������һ����ΪpszValue��ͬ��Ԫ��
TJXML_API HNODE XML_FirstChildElement(HNODE hNode);//������һ��ͬ��Ԫ�ض������������͵Ľڵ�
TJXML_API HNODE XML_FirstChildElementByValue(HNODE hNode, const CHAR *pszValue);//������һ����ΪpszValue����Ԫ��

TJXML_API BOOL  XML_NoChildren(HNODE hNode);//�ýڵ�û���ӽڵ㷵��true

/////////////////////////////////////////////////////////////////////////////////
//XML�ĵ���TiXmlDocument
TJXML_API HNODE XML_DocNew(VOID);//����һ�����ĵ�
TJXML_API VOID  XML_DocDelete(HNODE hDoc);//ɾ���ĵ�
TJXML_API BOOL  XML_DocFromFile(HNODE hDoc, const CHAR *pszFileName);//����xml�ĵ�
TJXML_API BOOL  XML_DocToFile(HNODE hDoc, const CHAR *pszFileName);//�����ĵ����󣬱���Ϊ��ΪpszFileName���ļ�
TJXML_API const CHAR* XML_DocFromString(HNODE hDoc, const CHAR *pszString);//���ַ���ת�����ĵ�
TJXML_API const CHAR* XML_DocToString(HNODE hDoc);//�õ��ĵ����ݲ������ַ���
TJXML_API HNODE XML_DocRootElement(HNODE hDoc);//�õ��ĵ���Ԫ��
TJXML_API BOOL  XML_DocError(HNODE hDoc);//����ĵ�������true
TJXML_API VOID  XML_DocPrint(HNODE hDoc);//��ӡ�ĵ�����
//Ԫ������TiXmlElement
TJXML_API HNODE XML_ElementNew(const CHAR *pszValue);//����һ����ΪpszValue��Ԫ��
TJXML_API HNODE XML_ElementWithStringNew(const CHAR *pszValue, const CHAR *pszText);//����һ����ΪpszValue�ģ��ַ���ֵΪpszText����Ԫ��
TJXML_API HNODE XML_ElementWithIntNew(const CHAR *pszValue, int nText);//����һ����ΪpszValue�ģ�����ֵΪpszText����Ԫ��
TJXML_API HNODE XML_ElementWithDoubleNew(const CHAR *pszValue, double dText);//����һ����ΪpszValue�ģ�����ֵΪpszText����Ԫ��
TJXML_API HNODE XML_ElementWithStrBoolNew(const CHAR *pszValue, BOOL bText);//����һ����ΪpszValue�ģ����ֵΪpszText:=true?false����Ԫ��
TJXML_API VOID  XML_ElementDelete(HNODE hElement);
TJXML_API const CHAR* XML_ElementGetStrAttribute(HNODE hElement, const CHAR *pszName);//�õ��ڵ�Ԫ��hElement���ַ�����ֵ
TJXML_API int   XML_ElementGetIntAttribute(HNODE hElement, const CHAR *pszName);//�õ��ڵ�Ԫ��hElement������ֵ
TJXML_API BOOL  XML_ElementGetBoolAttribute(HNODE hElement, const CHAR *pszName);//�õ��ڵ�Ԫ��hElement�������ֵ
TJXML_API VOID  XML_ElementSetStrAttribute(HNODE hElement, const CHAR *pszName, const CHAR *pszValue);//���ýڵ�Ԫ��hElement���ַ�����ֵ
TJXML_API VOID  XML_ElementSetIntAttribute(HNODE hElement, const CHAR *pszName, int nValue);//���ýڵ�Ԫ��hElement������ֵ
TJXML_API VOID  XML_ElementSetDoubleAttribute(HNODE hElement, const CHAR *pszName, double dValue);//���ýڵ�Ԫ��hElement�ĸ�����ֵ
TJXML_API VOID  XML_ElementSetStrBoolAttribute(HNODE hElement, const CHAR *pszName, BOOL bValue);//���ýڵ�Ԫ��hElement�������ֵ
TJXML_API VOID  XML_ElementRemoveAttribute(HNODE hElement, const CHAR *pszName);//ɾ��ָ�����Ƶ�����
TJXML_API const CHAR* XML_ElementGetText(HNODE hElement);
TJXML_API int   XML_ElementGetTextToInt(HNODE hElement);
TJXML_API BOOL  XML_ElementGetTextToBool(HNODE hElement);

TJXML_API HNODE XML_TextNew(const CHAR *pszValue);
TJXML_API VOID  XML_TextDelete(HNODE hText);
//ע����TiXmlComment
TJXML_API HNODE XML_CommentNew(const CHAR *pszValue);
TJXML_API VOID  XML_CommentDelete(HNODE hComment);
//������TiXmlDeclaration
TJXML_API HNODE XML_DeclarationNew(const CHAR *pszVersion, const CHAR *pszEncoding, const CHAR *pszStandalone);
TJXML_API VOID  XML_DeclarationDelete(HNODE hDeclaration);
/////////////////////////////////////////////////////////////////////////////////

#endif//LIB_XML_H

