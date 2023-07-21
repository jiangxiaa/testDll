// test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<Windows.h>
//调用动态库头文件，导入，不叫导出
#include "../testDll/pch.h"
/* 这个不是真正的静态库，只是提供一些导出函数,隐式调用动态库 */
#pragma comment(lib,"testdll.lib")

//typedef int(*PADD)(int a, int b);

int main()
{
	//加载动态库,显式调用动态库，需要时用，不需要时卸载
	/*HMODULE hDll = LoadLibrary(L"../Debug/testDll.dll");
	if (hDll == NULL) {
		std::cout << "加载DLL文件失败！" << std::endl;
		return 0;
	}*/

	int a, b;
	std::cout << "请输入两个整数：";
	std::cin >> a >> b;

	/* ?add@@YAHHH@Z 为什么要用这个，因为使用c++语法，c++语法会将我们导出的函数名称改变为动态库的名称
	使用c语言导出就是正确的
	为了防止编译器把导出的接口改名字，如果一定要使用c++，加个关键字extern */
	//PADD pAdd = (PADD)GetProcAddress(hDll, "add");  /*返回函数指针*/
	std::cout << "add(a,b)=" << add(a, b) << std::endl;

	//FreeLibrary(hDll);
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
