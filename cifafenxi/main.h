#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

int start = 0, over = 0, first = 0;//指针
int letters = 0, lines = 0, words = 0;//统计单词数，行数和字符数的变量
int state;//状态变量

class str//单词类
{
public:
	int linenum;//行号
	string Str;//单词       
};

//输出文件名
string file_name;

//返回单词或符号,从位置i开始查找，引用参数j返回这个单词最后一个字符在str的位置。
string GetWord(string str, int i, int& j);

//除去字符串中连续的空格和换行。第一个参数为目标字符串，第二个参数为开始位置。返回值为第一个有效字符在字符串的位置
int get_nbc(string str, int i);

//文件输出函数，成功输出返回true，失败返回false
bool Output(vector<pair<string, string> > v);

//词法分析主要算法函数，返回一个pair型数组
vector<pair<string, string> > analyse(vector<str>& vec);

//此函数判断str是否为关键字，是的话，返回真，反之返回假
bool IsKey(string str);

//此函数判断C是否为字母，是的话，返回真，反之返回假
bool letter(char C);

//此函数判断C是否为数字，是的话，返回真，反之返回假
bool digit(char C);