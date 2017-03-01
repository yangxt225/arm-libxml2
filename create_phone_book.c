/****************************************  
 *��ϰlibxml�⣬����ͨѶ¼xml�ĵ�������һ��ͨѶ¼��  
 *���xml�ļ����ڣ������һ���½ڵ�  
 *���xml�ļ������ڣ����½�һ��xml�ļ�  
 *  
 *@author: Anker  @date: 2014/02/09  
 * ***************************************/  
  
#include <stdio.h>  
#include <string.h>  
#include <unistd.h>  
#include <assert.h>  
  
#include <libxml/parser.h>  
#include <libxml/tree.h>  
#include <libxml/xmlmemory.h>  
  
#define PHONE_BOOK_FILE     "phone_book.xml"  
#define ID_STR_LEN        16  
#define NAME_STR_LEN         32  
#define TEL_STR_LEN         16  
#define ADDR_STR_LEN         128  
  
//�绰ͨѶ¼�ṹ��  
typedef struct phone_t {  
    int id;              //���  
    char name[NAME_STR_LEN];     //����  
    char tel[TEL_STR_LEN];       //�绰  
    char address[ADDR_STR_LEN];  //��ַ  
}phone;  
  
//����ͨѶ¼��  
static void set_phone_item(phone *phone_item)  
{  
    assert(phone_item);  
  
    phone_item->id = 10;  
    snprintf(phone_item->name, NAME_STR_LEN, "%s", "Anker");  
    snprintf(phone_item->tel, TEL_STR_LEN, "%s", "13223246599");  
    snprintf(phone_item->address, ADDR_STR_LEN, "%s", "Shenzheng");  
}  
  
//����phone�ڵ�  
static xmlNodePtr create_phone_node(const phone *phone_item)  
{  
    assert(phone_item);  
      
    char id[ID_STR_LEN] = {0};  
    xmlNodePtr phone_node = NULL;  
      
    phone_node = xmlNewNode(NULL, BAD_CAST"phone");  
    if (phone_node == NULL) {  
		fprintf(stderr, "Failed to create new node.\n");  
		return NULL;  
    }  
    //��������  
    snprintf(id, ID_STR_LEN, "%d", phone_item->id);  
    xmlNewProp(phone_node, BAD_CAST"id", (xmlChar*)id);  
  
    xmlNewChild(phone_node, NULL, BAD_CAST"name", (xmlChar *)phone_item->name);  
    xmlNewChild(phone_node, NULL, BAD_CAST"tel", (xmlChar *)phone_item->tel);  
    xmlNewChild(phone_node, NULL, BAD_CAST"address", (xmlChar *)phone_item->address);  
  
    return phone_node;  
}  
  
//����ڵ������һ��phone�ڵ�  
static int add_phone_node_to_root(xmlNodePtr root_node)  
{  
    xmlNodePtr phone_node = NULL;  
    phone *phone_item = NULL;  
	int retval=0;
  
    //����һ���µ�phone  
    phone_item = (phone *)malloc(sizeof(phone));  
    if (phone_item == NULL) {  
		fprintf(stderr, "Failed to malloc memory.\n");  
		return -1;  
    }  
    set_phone_item(phone_item);  
  
	do{
		//����һ��phone�ڵ�  
		phone_node = create_phone_node(phone_item);   
		if (phone_node == NULL) {  
			fprintf(stderr, "Failed to create phone node.\n");  
			retval = -1;
			break;  
		}  
		//���ڵ����һ���ӽڵ�  
		xmlAddChild(root_node, phone_node);  
		
		retval = 0;
	}while(0);  
	
    if (phone_item){  
		free(phone_item);  
    }  
    return retval;  
}  
  
//����phone_books  
static int create_phone_books(const char *phone_book_file)  
{  
    assert(phone_book_file);  
  
    xmlDocPtr doc = NULL;  
    xmlNodePtr root_node = NULL;  
	int retval=0;
  
    //����һ��xml �ĵ�  
    doc = xmlNewDoc(BAD_CAST"1.0");  
    if (doc == NULL) {  
		fprintf(stderr, "Failed to new doc.\n");  
		return -1;  
    }  
  
	do{
		//�������ڵ�  
		root_node = xmlNewNode(NULL, BAD_CAST"phone_books");  
		if (root_node == NULL) {  
			fprintf(stderr, "Failed to new root node.\n");  
			retval = -1;  
			break;
		}  
		//�����ڵ���ӵ��ĵ���  
		xmlDocSetRootElement(doc, root_node);  

		if (add_phone_node_to_root(root_node) != 0) {  
			fprintf(stderr, "Failed to add a new phone node.\n");  
			retval = -1;  
			break; 
		}  
		//���ĵ����浽�ļ��У�����utf-8�����ʽ����  
		xmlSaveFormatFileEnc(phone_book_file, doc, "UTF-8", 1);  
		//xmlSaveFile("test.xml", doc);  
		
		retval = 0;	
	}while(0);

    if (doc) {  
		xmlFreeDoc(doc);  
    }  
  
    return retval;  
}  
  
static int add_phone_node(const char *phone_book_file)  
{  
    assert(phone_book_file);  
  
    xmlDocPtr doc = NULL;  
    xmlNodePtr root_node = NULL;  
    xmlNodePtr phone_node = NULL;  
    phone *phone_item = NULL;  
	int retval=0;
      
    doc = xmlParseFile(phone_book_file);  
    if (doc == NULL) {  
		fprintf(stderr, "Failed to parser xml file:%s\n", phone_book_file);  
		return -1;  
    }  
  
	do{
		root_node = xmlDocGetRootElement(doc);  
		if (root_node == NULL) {  
			fprintf(stderr, "Failed to get root node.\n");  
			retval = -1;
			break;
		}  
		  
		if (add_phone_node_to_root(root_node) != 0) {  
			fprintf(stderr, "Failed to add a new phone node.\n");  
			retval = -1;
			break;  
		}  
		//���ĵ����浽�ļ��У�����utf-8�����ʽ����  
		xmlSaveFormatFileEnc(phone_book_file, doc, "UTF-8", 1);  
		retval = 0;  
	}while(0);

    if (doc) {  
		xmlFreeDoc(doc);  
    }  
  
    return retval;  
}  
  
int main(int argc, char *argv[])  
{  
    char *phone_book_file = PHONE_BOOK_FILE;  
  
    if (argc == 2) {  
		phone_book_file = argv[1];  
    }  
  
    if (access(phone_book_file, F_OK) == 0) {  
		//�ļ����ڣ����һ���µ�phone�ڵ�  
		add_phone_node(phone_book_file);  
    }  
    else {  
		//�ļ������ڣ�����һ����Ϣ��phone book  
		create_phone_books(phone_book_file);  
    }  
  
    return 0;  
}  