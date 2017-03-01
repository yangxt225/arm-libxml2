--------------------------------------------------------
1. 以libxml2-2.8.0.tar.gz为例；解压到libxml2-2.8.0目录;
2. 进入libxml2-2.8.0目录，执行"#./configure"，生成Makefile文件;
3. 执行"make" 编译libxml2动态库，执行"make install" 安装动态库;
4. 用gcc编译测试程序，在PC上测试libxml2调用.

--------------------------------------------------------
在arm平台上使用libxml2库。使用交叉编译工具arm-linux-gcc.
1. 以libxml2-2.8.0.tar.gz为例；解压到libxml2-2.8.0目录;
2. 进入libxml2-2.8.0目录，执行"#./configure -host=arm-linux"，生成Makefile文件;
	-host : 指定交叉编译工具。一般为arm-linux、arm-linux-gnueabihf、arm-none-linux-gnueabi等，具体要和板子用的交叉编译工具对应。
3. 执行"make" 编译libxml2动态库，执行"make install" 安装动态库;
4. 用交叉编译工具arm-linux-gcc编译测试程序, 只需要指定"CC=arm-linux-gcc"变量;
5. 将"/usr/local/include/libxml2"目录下的libxml文件夹整个拷贝，此文件夹为libxml2库所需头文件;
6. 将"/usr/local/lib"目录下libxml2.a, libxml2.la, libxml2.so, libxml2.so.2, libxml2.so.2.8.0库文件拷贝;
7. 将测试程序，库头文件，库文件一起拷贝到arm开发板上，将相关的库文件拷贝到“/usr/lib”目录，执行测试程序。完成。
