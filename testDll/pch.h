// pch.h: 这是预编译标头文件。
// 下方列出的文件仅编译一次，提高了将来生成的生成性能。
// 这还将影响 IntelliSense 性能，包括代码完成和许多代码浏览功能。
// 但是，如果此处列出的文件中的任何一个在生成之间有更新，它们全部都将被重新编译。
// 请勿在此处添加要频繁更新的文件，这将使得性能优势无效。

//防止头文件重复包含
#ifndef PCH_H
//如果没有这个宏就定义这个宏
#define PCH_H

// 添加要在此处预编译的标头
#include "framework.h"

//条件编译指令,如果DLLAPI没有被定义
#ifdef _DLLAPI
	#define DLLAPI _declspec(dllexport)
#else
	#define DLLAPI _declspec(dllimport)
#endif // !_DLLAPI

//声明导出函数
//_declspec(dllexport) 表示导出这个函数的接口给外界用
extern "C" DLLAPI int add(int a, int b);

extern "C" DLLAPI int sub(int a, int b);

#endif //PCH_H
