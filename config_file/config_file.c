#include <stdio.h>
#include <mujs.h>

#ifdef _DEBUG
#pragma comment(lib,"../Debug/libmujs.lib")
#else
#pragma comment(lib,"../Release/libmujs.lib")
#endif // _DEBUG


char* pJsData = "var foo=2;\
var coo = \"string\";\
function afunc()\
{\
	var boo = 100;\
}";


void Object_manipulation(js_State *J)
{
	// t = { foo: 42, bar: true }
	js_newobject(J);
	{
		js_pushnumber(J, 42);
		js_setproperty(J, -2, "foo");
		js_pushboolean(J, 1);
		js_setproperty(J, -2, "bar");
	}
	js_setglobal(J, "t");
}


int main(int argc, char **argv)
{
	js_State *J = js_newstate(NULL, NULL, JS_STRICT);
	//js_dofile(J, "config.js"); // ����js�ļ�
	js_dostring(J, pJsData);

	js_getglobal(J, "foo");    // ��ȡjs�е�ȫ�ֱ���foo
	int foo = js_tonumber(J, -1);
	printf("foo: %d\n", foo);
	js_pop(J, 1);               // ����ջ��1��Ԫ�أ���foo
	foo = 0;
	//  js_getglobal(J, "foo"); // ��ſ�ע�ͣ�foo�����ٴλ�ȡ
	foo = js_tonumber(J, -1); // ��ʱ�ٻ�ȡfoo�����Ѿ�û����
	printf("foo: 0x%x\n", foo);
	return 0;
}
