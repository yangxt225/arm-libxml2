--------------------------------------------------------
1. ��libxml2-2.8.0.tar.gzΪ������ѹ��libxml2-2.8.0Ŀ¼;
2. ����libxml2-2.8.0Ŀ¼��ִ��"#./configure"������Makefile�ļ�;
3. ִ��"make" ����libxml2��̬�⣬ִ��"make install" ��װ��̬��;
4. ��gcc������Գ�����PC�ϲ���libxml2����.

--------------------------------------------------------
��armƽ̨��ʹ��libxml2�⡣ʹ�ý�����빤��arm-linux-gcc.
1. ��libxml2-2.8.0.tar.gzΪ������ѹ��libxml2-2.8.0Ŀ¼;
2. ����libxml2-2.8.0Ŀ¼��ִ��"#./configure -host=arm-linux"������Makefile�ļ�;
	-host : ָ��������빤�ߡ�һ��Ϊarm-linux��arm-linux-gnueabihf��arm-none-linux-gnueabi�ȣ�����Ҫ�Ͱ����õĽ�����빤�߶�Ӧ��
3. ִ��"make" ����libxml2��̬�⣬ִ��"make install" ��װ��̬��;
4. �ý�����빤��arm-linux-gcc������Գ���, ֻ��Ҫָ��"CC=arm-linux-gcc"����;
5. ��"/usr/local/include/libxml2"Ŀ¼�µ�libxml�ļ����������������ļ���Ϊlibxml2������ͷ�ļ�;
6. ��"/usr/local/lib"Ŀ¼��libxml2.a, libxml2.la, libxml2.so, libxml2.so.2, libxml2.so.2.8.0���ļ�����;
7. �����Գ��򣬿�ͷ�ļ������ļ�һ�𿽱���arm�������ϣ�����صĿ��ļ���������/usr/lib��Ŀ¼��ִ�в��Գ�����ɡ�
