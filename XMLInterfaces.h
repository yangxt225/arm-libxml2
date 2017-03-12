/** @brief   ���ĵ�����libxml2���ýӿ�
 *  @file    XMLInterfaces.h
 *  @author  ������
 *  @version 1.0.0
 *  @date    2017/03/10
 *  @note    ע��. �μ���http://xmlsoft.org/html/index.html
 *  @since   �Դ�...
 */

///////////////////////////////////////////////////////////////////
/**  ���ڴ��д���һ���µ�XML�ĵ������������ĵ���Ҫʹ��xmlFreeDoc()���ͷ���Դ
 @param[in]  version 	XML��׼�İ汾��Ŀǰֻ��ָ��Ϊ��1.0��
 @return     			����һ���µ�XML�ĵ��ṹָ��
 @warning    ����
 @note       ע��,ʾ��: xmlNewDoc(BAD_CAST"1.0")
 @see        xmlFreeDoc()
*/
xmlDocPtr xmlNewDoc(const xmlChar * version)

/**  ����һ���µĽڵ�Ԫ��
 @param[in]  ns 	 namespace if any��ͨ��ΪNULL
 @param[in]  name 	 �ڵ�����
 @return    		 ����һ���µĽڵ�Ԫ��ָ��
 @warning    ����
 @note       ע��
 @see        
*/
xmlNodePtr xmlNewNode(xmlNsPtr ns, const xmlChar * name)

/**  ��ָ���ڵ�����ӽڵ㣬Add a new node to @parent
 @param[in]  parent  ���ڵ�ָ��
 @param[in]  cur 	 �ӽڵ�ָ��
 @return    		 the child or NULL in case of error.
 @warning    ����
 @note       ע��
 @see        
*/
xmlNodePtr xmlAddChild(xmlNodePtr parent, xmlNodePtr cur)

/**  ��ָ���ڵ�����ӽڵ㣬Creation of a new child element, added at the end of @parent children list
 @param[in]  parent  	 ���ڵ�ָ��
 @param[in]  ns 		 namespace if any��ͨ��ΪNULL
 @param[in]  name  		 �ӽڵ�����
 @param[in]  content 	 �ӽڵ����ݣ�the XML content of the child if any
 @return    		 	 ����ָ���ӽڵ��ָ�룬a pointer to the new node object.
 @warning    ����
 @note       ע��
 @see        
*/
xmlNodePtr xmlNewChild(xmlNodePtr parent, xmlNsPtr ns, const xmlChar * name, const xmlChar * content)

/**  �����½ڵ�����
 @param[in]  node 	 ���Թ����Ľڵ�ָ��
 @param[in]  name 	 ��������
 @param[in]  value 	 ����ֵ
 @return    		 a pointer to the attribute
 @warning    ����
 @note       ע��
 @see        
*/
xmlAttrPtr xmlNewProp(xmlNodePtr node, const xmlChar * name, const xmlChar * value)

/**  ��ȡ�ڵ�����
 @param[in]  node 	 	 ��Ҫ��ȡ���ԵĽڵ�����
 @param[in]  name 	 	 ��������
 @return    		     the attribute value or NULL if not found. It's up to the caller to free the memory with xmlFree().
 @warning    ����
 @note       ע��		 xmlGetPropΪ�����ص��ַ��������ڴ�,ʹ����֮����Ҫ�����ߵ���xmlFree()���ͷ��ڴ�
 @see        
*/
xmlChar* xmlGetProp(const xmlNode * node, const xmlChar * name)

/**  ���ýڵ�����
 @param[in]  node 	 	 ��Ҫ�������ԵĽڵ�����
 @param[in]  name 	 	 ��������
 @param[in]  value 	 	 ����ֵ
 @return    		     the attribute pointer
 @warning    ����
 @note       ע��		 
 @see        
*/
xmlAttrPtr xmlSetProp(xmlNodePtr node, const xmlChar * name, const xmlChar * value)

/**  �����ĵ��ĸ��ڵ�
 @param[in]  doc 	�ĵ�ָ��
 @param[in]  root 	the new document root element, if root is NULL no action is taken
 @return     		the old root element if any was found, NULL if root was NULL
 @warning    ����
 @note       ע��
 @see        
*/
xmlNodePtr xmlDocSetRootElement(xmlDocPtr doc, xmlNodePtr root)

/**  ��ȡ�ĵ��ĸ��ڵ�
 @param[in]  doc 	�ĵ�ָ��
 @return     		���ظ��ڵ�ָ�룬��NULL��the #xmlNodePtr for the root or NULL
 @warning    ����
 @note       ע��
 @see        
*/
xmlNodePtr xmlDocGetRootElement(const xmlDoc * doc)

/**  �����ĵ��ĸ��ڵ�
 @param[in]  filename 	��Ҫ�����xml�ļ�����
 @param[in]  cur 		׼�������xml�ĵ��ṹָ��
 @param[in]  encoding 	�����ļ��ı������ͣ���"UTF-8"
 @param[in]  format 	�Ƿ��ʽ����0��ʾ����ʽ����1��ʾ��Ҫ��ʽ����һ��Ϊ1��
 @return    			д���ļ��е��ֽ�������-1��ʾ����
 @warning    ����
 @note       ע�⣺ֻ�е�xmlIndentTreeOutput����Ϊ1������xmlKeepBlanksDefault(0)ʱ��format����Ϊ1������Ч
 @see        
*/
int xmlSaveFormatFileEnc(const char * filename, xmlDocPtr cur, const char * encoding, int format)

/**  �ͷ����б��ĵ����õĽṹ��
 @param[in]  cur 	 xml�ĵ��ṹָ��
 @return    		 
 @warning    ����
 @note       ע��
 @see        
*/
void xmlFreeDoc(xmlDocPtr cur)

/**  ��XML�ļ���Ӳ�������뵽�ڴ��У���������DOM����ʹ�����֮����Ҫ��xmlFreeDoc()���ͷ���Դ, parse an XML file and build a tree
 @param[in]  filename 	 ��Ҫ�����xml�ļ�����
 @return    		     �������ɹ����򷵻�����ĵ�ָ�롣���򷵻�NULL
 @warning    ����
 @note       ע��
 @see        
*/
xmlDocPtr xmlParseFile(const char * filename)

/**  �Ƚ�����xml�ַ����Ƿ����
 @param[in]  str1 	 	 ��һ�����Ƚ�xml�ַ���
 @param[in]  str2 	 	 �ڶ������Ƚ�xml�ַ���
 @return    		     ����ַ�����ȣ�����0��
 @warning    ����
 @note       ע��
 @see        
*/
int xmlStrcmp (const xmlChar * str1, const xmlChar * str2)

/**  ��ȡ�ڵ�Ԫ�ؼ�¼������
 @param[in]  doc 	 		 �ĵ��ṹָ��
 @param[in]  list 	 		 a Node list
 @param[in]  inLine	 		 should we replace entity contents or show their external form
 @return    		    	 a pointer to the string copy, the caller must free it with xmlFree().
 @warning    ����		 	 ��Ϊ xmlNodeListGetString Ϊ�����ص��ַ��������ڴ棬�����ʹ��xmlFree�ͷ���
 @note       ע�⣬�磺		 xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
 @see        				 �μ� createblacklist.c ʾ���ļ�
*/
xmlChar * xmlNodeListGetString(xmlDocPtr doc, const xmlNode * list, int inLine)