/*
	JS�ṹ��ת��ΪC��ͷ��
*/

#include <stdio.h>
#include <mujs.h>

#ifdef _DEBUG
#pragma comment(lib,"../Debug/libmujs.lib")
#else
#pragma comment(lib,"../Release/libmujs.lib")
#endif // _DEBUG


struct T
{
	int foo;
	unsigned char bar;
};

int main(void)
{
	js_State *J = js_newstate(NULL, NULL, JS_STRICT);
	// t = {foo:42, bar:12};
	js_newobject(J);
	{
		js_pushnumber(J, 42);
		js_setproperty(J, -2, "foo");
		js_pushnumber(J, 12);
		js_setproperty(J, -2, "bar");
	}
	js_setglobal(J, "t");

	struct T t;
	js_getglobal(J, "t"); // �ҵ�t����objectѹջ
	js_getproperty(J, -1, "foo"); // ��ʱt��ջ�����õ�foo���ٽ�foo��ֵѹջ
	js_getproperty(J, -2, "bar"); // ��ʱt�Ѿ��³�һ�Σ�����idxΪ-2
	t.foo = js_tonumber(J, -2);
	t.bar = js_tonumber(J, -1);

	t.foo = 0;
	t.bar = 0;

	t.foo = js_tonumber(J, -2);
	t.bar = js_tonumber(J, -1);

	printf("t.foo:%d, t.bar:%d\n", t.foo, t.bar);
	return 0;
}