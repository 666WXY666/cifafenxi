#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

int start = 0, over = 0, first = 0;//ָ��
int letters = 0, lines = 0, words = 0;//ͳ�Ƶ��������������ַ����ı���
int state;//״̬����

class str//������
{
public:
	int linenum;//�к�
	string Str;//����       
};

//����ļ���
string file_name;

//���ص��ʻ����,��λ��i��ʼ���ң����ò���j��������������һ���ַ���str��λ�á�
string GetWord(string str, int i, int& j);

//��ȥ�ַ����������Ŀո�ͻ��С���һ������ΪĿ���ַ������ڶ�������Ϊ��ʼλ�á�����ֵΪ��һ����Ч�ַ����ַ�����λ��
int get_nbc(string str, int i);

//�ļ�����������ɹ��������true��ʧ�ܷ���false
bool Output(vector<pair<string, string> > v);

//�ʷ�������Ҫ�㷨����������һ��pair������
vector<pair<string, string> > analyse(vector<str>& vec);

//�˺����ж�str�Ƿ�Ϊ�ؼ��֣��ǵĻ��������棬��֮���ؼ�
bool IsKey(string str);

//�˺����ж�C�Ƿ�Ϊ��ĸ���ǵĻ��������棬��֮���ؼ�
bool letter(char C);

//�˺����ж�C�Ƿ�Ϊ���֣��ǵĻ��������棬��֮���ؼ�
bool digit(char C);