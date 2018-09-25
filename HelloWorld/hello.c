#include <stdio.h>
#include <mujs.h>

#ifdef _DEBUG
#pragma comment(lib,"../Debug/libmujs.lib")
#else
#pragma comment(lib,"../Release/libmujs.lib")
#endif // _DEBUG

static void hello(js_State *J)
{
	const char *name = js_tostring(J, 1);
	printf("Hello, %s!\n", name);
	js_pushundefined(J);
}

static void hello2(js_State *J)
{
	const char *name = js_tostring(J, 1);
	int num = js_tonumber(J, 2);	// ��ȡ�ڶ�������
	printf("Hello2,%s! num:%d\n", name, num);
	js_pushundefined(J);
}


int main(int argc, char **argv)
{
	js_State *J = js_newstate(NULL, NULL, JS_STRICT);

	js_newcfunction(J, hello, "hello", 1);
	js_setglobal(J, "hello");	//����Ϊȫ�ֱ���,���룡

	js_dostring(J, "hello('world');");	// ����javascript

	// �½���ע�Ტ����hello2
	js_newcfunction(J, hello2, "hello2", 2);
	js_setglobal(J, "hello2");	//����Ϊȫ�ֱ���,���룡
	js_dostring(J, "hello2('world',100);");

	js_freestate(J);	// �ͷ�J
}