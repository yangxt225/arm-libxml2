/** @brief   本文档描述libxml2常用接口
 *  @file    XMLInterfaces.h
 *  @author  杨晓添
 *  @version 1.0.0
 *  @date    2017/03/10
 *  @note    注解. 参见；http://xmlsoft.org/html/index.html
 *  @since   自从...
 */

///////////////////////////////////////////////////////////////////
/**  在内存中创建一个新的XML文档。所创建的文档需要使用xmlFreeDoc()来释放资源
 @param[in]  version 	XML标准的版本，目前只能指定为“1.0”
 @return     			返回一个新的XML文档结构指针
 @warning    警告
 @note       注解,示例: xmlNewDoc(BAD_CAST"1.0")
 @see        xmlFreeDoc()
*/
xmlDocPtr xmlNewDoc(const xmlChar * version)

/**  创建一个新的节点元素
 @param[in]  ns 	 namespace if any，通常为NULL
 @param[in]  name 	 节点名字
 @return    		 返回一个新的节点元素指针
 @warning    警告
 @note       注解
 @see        
*/
xmlNodePtr xmlNewNode(xmlNsPtr ns, const xmlChar * name)

/**  给指定节点添加子节点，Add a new node to @parent
 @param[in]  parent  父节点指针
 @param[in]  cur 	 子节点指针
 @return    		 the child or NULL in case of error.
 @warning    警告
 @note       注解
 @see        
*/
xmlNodePtr xmlAddChild(xmlNodePtr parent, xmlNodePtr cur)

/**  给指定节点添加子节点，Creation of a new child element, added at the end of @parent children list
 @param[in]  parent  	 父节点指针
 @param[in]  ns 		 namespace if any，通常为NULL
 @param[in]  name  		 子节点名称
 @param[in]  content 	 子节点内容，the XML content of the child if any
 @return    		 	 返回指向子节点的指针，a pointer to the new node object.
 @warning    警告
 @note       注解
 @see        
*/
xmlNodePtr xmlNewChild(xmlNodePtr parent, xmlNsPtr ns, const xmlChar * name, const xmlChar * content)

/**  创建新节点属性
 @param[in]  node 	 属性归属的节点指针
 @param[in]  name 	 属性名称
 @param[in]  value 	 属性值
 @return    		 a pointer to the attribute
 @warning    警告
 @note       注解
 @see        
*/
xmlAttrPtr xmlNewProp(xmlNodePtr node, const xmlChar * name, const xmlChar * value)

/**  读取节点属性
 @param[in]  node 	 	 需要读取属性的节点名称
 @param[in]  name 	 	 属性名称
 @return    		     the attribute value or NULL if not found. It's up to the caller to free the memory with xmlFree().
 @warning    警告
 @note       注解		 xmlGetProp为它返回的字符串分配内存,使用完之后需要调用者调用xmlFree()来释放内存
 @see        
*/
xmlChar* xmlGetProp(const xmlNode * node, const xmlChar * name)

/**  设置节点属性
 @param[in]  node 	 	 需要设置属性的节点名称
 @param[in]  name 	 	 属性名称
 @param[in]  value 	 	 属性值
 @return    		     the attribute pointer
 @warning    警告
 @note       注解		 
 @see        
*/
xmlAttrPtr xmlSetProp(xmlNodePtr node, const xmlChar * name, const xmlChar * value)

/**  设置文档的根节点
 @param[in]  doc 	文档指针
 @param[in]  root 	the new document root element, if root is NULL no action is taken
 @return     		the old root element if any was found, NULL if root was NULL
 @warning    警告
 @note       注解
 @see        
*/
xmlNodePtr xmlDocSetRootElement(xmlDocPtr doc, xmlNodePtr root)

/**  获取文档的根节点
 @param[in]  doc 	文档指针
 @return     		返回根节点指针，或NULL，the #xmlNodePtr for the root or NULL
 @warning    警告
 @note       注解
 @see        
*/
xmlNodePtr xmlDocGetRootElement(const xmlDoc * doc)

/**  设置文档的根节点
 @param[in]  filename 	需要保存的xml文件名称
 @param[in]  cur 		准备保存的xml文档结构指针
 @param[in]  encoding 	导出文件的编码类型，如"UTF-8"
 @param[in]  format 	是否格式化。0表示不格式化，1表示需要格式化，一般为1。
 @return    			写入文件中的字节数量，-1表示出错
 @warning    警告
 @note       注解：只有当xmlIndentTreeOutput设置为1，或者xmlKeepBlanksDefault(0)时，format设置为1才能生效
 @see        
*/
int xmlSaveFormatFileEnc(const char * filename, xmlDocPtr cur, const char * encoding, int format)

/**  释放所有被文档引用的结构体
 @param[in]  cur 	 xml文档结构指针
 @return    		 
 @warning    警告
 @note       注解
 @see        
*/
void xmlFreeDoc(xmlDocPtr cur)

/**  将XML文件从硬盘上载入到内存中，并且生成DOM树。使用完毕之后，需要用xmlFreeDoc()来释放资源, parse an XML file and build a tree
 @param[in]  filename 	 需要保存的xml文件名称
 @return    		     如果载入成功，则返回这个文档指针。否则返回NULL
 @warning    警告
 @note       注解
 @see        
*/
xmlDocPtr xmlParseFile(const char * filename)

/**  比较两个xml字符串是否相等
 @param[in]  str1 	 	 第一个待比较xml字符串
 @param[in]  str2 	 	 第二个待比较xml字符串
 @return    		     如果字符串相等，返回0；
 @warning    警告
 @note       注解
 @see        
*/
int xmlStrcmp (const xmlChar * str1, const xmlChar * str2)

/**  获取节点元素记录的内容
 @param[in]  doc 	 		 文档结构指针
 @param[in]  list 	 		 a Node list
 @param[in]  inLine	 		 should we replace entity contents or show their external form
 @return    		    	 a pointer to the string copy, the caller must free it with xmlFree().
 @warning    警告		 	 因为 xmlNodeListGetString 为它返回的字符串分配内存，你必须使用xmlFree释放它
 @note       注解，如：		 xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
 @see        				 参见 createblacklist.c 示例文件
*/
xmlChar * xmlNodeListGetString(xmlDocPtr doc, const xmlNode * list, int inLine)