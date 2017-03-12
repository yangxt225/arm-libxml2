/** BlackList201703100001.xml文件格式范例：

<?xml version="1.0" encoding="UTF-8"?>
<SimpleBlack>
  <!--版本信息-->
  <Version VersionId="201004260001" VersionDate="20100426131336"/>
  <CardType>
    <CardTypeInfo CardType="01" CardTypeName="01羊城通"/>
	<CardTypeInfo CardType="02" CardTypeName="02一卡通">yangxt<CardTypeInfo/>
  </CardType>
</SimpleBlack>

*/  
#include <stdio.h>  
#include <string.h>  
#include <unistd.h>  
#include <assert.h>  
  
#include <libxml/parser.h>  
#include <libxml/tree.h>  
#include <libxml/xmlmemory.h>  
  
#define BLACK_LIST_FILE     "BlackList201703100001.xml"  


int createFile(const char *fileName)
{
	int retval=0;
	// 文档结构指针
	xmlDocPtr doc = NULL;
	// 节点结构指针
	xmlNodePtr rootNode = NULL;
	// 创建新xml文档
	doc = xmlNewDoc(BAD_CAST"1.0");  
    if (doc == NULL) {  
		printf("Failed to new doc.\n");  
		return -1;  
    } 
	
	do{
		// 创建根节点
		rootNode = xmlNewNode(NULL, BAD_CAST"SimpleBlack");  
		if (rootNode == NULL) {  
			printf("Failed to new root node.\n");  
			retval = -1;  
			break;
		}

		//将根节点添加到文档中  
		xmlDocSetRootElement(doc, rootNode); 	
		
		//将文档保存到文件中，按照utf-8编码格式保存  
		xmlSaveFormatFileEnc(fileName, doc, "UTF-8", 1);
	}while(0);
	
	if(doc){
		// 释放文档结构内存
		xmlFreeDoc(doc);  
    }
	
	return retval;
}

int addNodeToRoot(const char *fileName)
{
	int retval=0;
	xmlDocPtr doc = NULL;
	xmlNodePtr rootNode = NULL;
	xmlNodePtr newNode = NULL;
	xmlNodePtr childNode = NULL;
	
	do{		
		// 分析xml文档
		doc = xmlParseFile(fileName);  
		if(doc == NULL){  
			printf("Failed to parser xml file:%s\n", fileName);  
			retval = -2;
			break;  
		}
		// 获取根节点
		rootNode = xmlDocGetRootElement(doc);  
		if(rootNode == NULL){  
			printf("Failed to get root node.\n");  
			retval = -3;
			break;
		}
		
		// 检查文档类型
		if((xmlStrcmp(rootNode->name, (const xmlChar *)"SimpleBlack"))){  
			printf("The root is not SimpleBlack.\n");  
			retval = -4;
			break;
		}
		
		/*******************************************
		 * 创建 <!--版本信息--> 节点
		 *******************************************/
		newNode = xmlNewNode(NULL, BAD_CAST"Version");
		if (newNode == NULL){  
			printf("Failed to create new node.\n");  
			retval = -5;
			break;
		} 
		// 设置节点属性
		xmlNewProp(newNode, BAD_CAST"VersionId", (xmlChar*)"201004260001"); 
		xmlNewProp(newNode, BAD_CAST"VersionDate", (xmlChar*)"20100426131336"); 
		//根节点添加一个子节点 
		xmlAddChild(rootNode, newNode); 
		
		/*******************************************
		 * 创建 <!--卡类型--> 节点
		 *******************************************/
		newNode = xmlNewNode(NULL, BAD_CAST"CardType");
		if (newNode == NULL){  
			printf("Failed to create new node.\n");  
			retval = -6;
			break;
		}
		//根节点添加一个子节点  
		xmlAddChild(rootNode, newNode);  
		
		//==================================================
		/*******************************************
		 * 创建 <!--卡片信息--> 节点
		 *******************************************/
		childNode = xmlNewChild(newNode, NULL, BAD_CAST"CardTypeInfo", NULL);
		if (childNode == NULL){  
			printf("Failed to create new node.\n");  
			retval = -4;
			break;
		} 
		// 设置节点属性
		xmlNewProp(childNode, BAD_CAST"CardType", (xmlChar*)"01"); 
		xmlNewProp(childNode, BAD_CAST"CardTypeName", (xmlChar*)"01羊城通");
		
		childNode = xmlNewChild(newNode, NULL, BAD_CAST"CardTypeInfo", "yangxt");
		if (childNode == NULL){  
			printf("Failed to create new node.\n");  
			retval = -4;
			break;
		} 
		// 设置节点属性
		xmlNewProp(childNode, BAD_CAST"CardType", (xmlChar*)"02"); 
		xmlNewProp(childNode, BAD_CAST"CardTypeName", (xmlChar*)"02一卡通"); 
		//==================================================
		
		//将文档保存到文件中，按照utf-8编码格式保存  
		xmlSaveFormatFileEnc(fileName, doc, "UTF-8", 1);
		
	}while(0);
	
	if(doc){  
		// 释放文档结构内存
		xmlFreeDoc(doc);  
	}
	return retval;
}

//解析每一个Card，提取出 CardType、CardTypeName属性
static int parseCard(xmlDocPtr doc, xmlNodePtr currNode)  
{  
    xmlChar *tmpProp, *tmpNodeText;  
  
    currNode = currNode->xmlChildrenNode;  
    while (currNode != NULL) {  
		if ((!xmlStrcmp(currNode->name, (const xmlChar *)"CardTypeInfo"))) {  
			tmpProp = xmlGetProp(currNode, "CardType");  
			printf("VersionId:%s\t", tmpProp); 
			tmpProp = xmlGetProp(currNode, "CardTypeName");
			printf("VersionDate:%s\t\n", tmpProp); 
			tmpNodeText = xmlNodeListGetString(doc, currNode->xmlChildrenNode, 1);  
			if(tmpNodeText){
				printf("myName: %s\n", tmpNodeText);  
				xmlFree(tmpNodeText);  
			}
		}
		currNode = currNode->next;  
    }  
    return 0;  
} 

int parseBlackList(const char *fileName)
{
	int retval=0;
	xmlDocPtr doc = NULL;
	xmlNodePtr currNode = NULL;
	xmlChar *tmpProp, *tmpNodeText;
	
	do{		
		// 分析xml文档，获取树形结构
		doc = xmlParseFile(fileName);  
		if(doc == NULL){  
			printf("Failed to parser xml file:%s\n", fileName);  
			retval = -1;
			break;  
		}
		// 获取根节点
		currNode = xmlDocGetRootElement(doc);  
		if(currNode == NULL){  
			printf("Failed to get root node.\n");  
			retval = -2;
			break;
		}
		
		// 检查文档类型
		if((xmlStrcmp(currNode->name, (const xmlChar *)"SimpleBlack"))){  
			printf("The root is not SimpleBlack.\n");  
			retval = -3;
			break;
		}
		
		//遍历处理根节点的每一个子节点  
		currNode = currNode->xmlChildrenNode;  
		while(currNode != NULL){  

			//创建 <!--版本信息--> 节点
			if ((!xmlStrcmp(currNode->name, (const xmlChar *)"Version"))) {  
				tmpProp = xmlGetProp(currNode, "VersionId");  
				printf("VersionId:%s\t", tmpProp); 
				tmpProp = xmlGetProp(currNode, "VersionDate");
				printf("VersionDate:%s\t\n", tmpProp);  				 
			}
			
			//创建 <!--卡类型--> 节点
			if ((!xmlStrcmp(currNode->name, (const xmlChar *)"CardType"))) {  
				parseCard(doc, currNode);  
			}	
			
			currNode = currNode->next;  
		}  
		retval = 0; 
		
	}while(0);
	
	if(doc){  
		// 释放文档结构内存
		xmlFreeDoc(doc);  
	}
	return retval;
}

int main()
{
	char *black_file_name = BLACK_LIST_FILE;
	
	// 创建xml文档
	createFile(black_file_name);
	
	if (access(black_file_name, F_OK) == 0){  
		//文件存在，在根节点下添加 新节点
		addNodeToRoot(black_file_name);
    }
	
	if (access(black_file_name, F_OK) == 0){  
		//文件存在，打印xml文档
		parseBlackList(black_file_name);
    }
	
	return 0;
}

