#include"main.h"

bool letter(char C)
{
	return (C >= 'a' && C <= 'z') || (C >= 'A' && C <= 'Z');
}

bool digit(char C)
{
	return C >= '0' && C <= '9';
}

bool IsKey(string str)
{
	string key[32] = {"do","double", "auto","break","case","char","const","continue","default",
						"else","enum","extern","float","for","goto","if","int","long","register",
						"return","struct","switch","typedef","short","signed","sizeof","static",
						"union","unsigned","void","volatile","while" };
	vector<string> test(key, key + 32);
	for (int i = 0; i < test.size(); i++)
		if (!str.compare(test[i]))
			return true;
	return false;
}

string GetWord(string str,int i,int& j)
{
    string symbol("\\%#:,^~{}[]() \'\";\n\t?");
    j=str.find_first_of(symbol,i);
    if(j==-1)
       return " ";
    if(i!=j)
       j--;
    return str.substr(i,j-i+1);
}

int get_nbc(string str,int i)
{
    for(;;i++)
      if(str[i]!=' '&&str[i]!='\n' && str[i] != '\t')
      {
         return i;
      }
}

bool Output(vector<pair<string,string> > v)
{
    cout<<"请输入输出文件路径（包括后缀名）：";
    cin>>file_name;
	ofstream outfile(file_name.c_str(), ios::out);
    if (!outfile)
    {
		cout << "无法打开目标文件 " << file_name.c_str()<< endl;
		return false;
    }
    cout<<endl;
	int i, j;
	outfile << "类型" << "\t\t\t" << "表达式" << endl;
    for(i=0;i<v.size();i++)
	{
		outfile << v[i].first << "\t\t\t" << v[i].second << endl;
		letters += v[i].second.size();
    }
	vector<bool> key;
	for (int i = 0; i < v.size(); i++)
	{
		key.push_back(false);
	}
	outfile <<"---------------------------------------------------------------------" << endl;
	outfile << "表达式" << "\t\t\t" << "个数" << endl;
	for (i = 0;i < v.size();i++)
	{
		if (key[i] == false)
		{
			int sum = 0;
			for (j = 0; j < v.size(); j++)
			{
				if (v[j].second == v[i].second)
				{
					key[j] = true;
					sum++;
				}
			}
			outfile << v[i].second << "\t\t\t" << sum << endl;
		}
	}
	vector<bool> key1;
	for (int i = 0; i < v.size(); i++)
	{
		key1.push_back(false);
	}
	outfile << "---------------------------------------------------------------------" << endl;
	outfile << "类型" << "\t\t\t" << "个数" << endl;
	for (i = 0;i < v.size();i++)
	{
		if (key1[i] == false)
		{
			int sum = 0;
			for (j = 0; j < v.size(); j++)
			{
				if (v[j].first == v[i].first)
				{
					key1[j] = true;
					sum++;
				}
			}
			outfile << v[i].first << "\t\t\t" << sum << endl;
		}
	}
	outfile << "---------------------------------------------------------------------" << endl;
	outfile << "源程序共有" << lines << "行。" << endl;
	outfile << "源程序共有" << words << "个单词。" << endl;
	outfile << "源程序共有" << letters << "个字符。" << endl;
	outfile.close();
	return true;
}

vector<pair<string,string> > analyse(vector<str>& vec)
{
    vector<pair<string,string> > temp;
	state = 0;
	string word;
	int j = -1;
	bool flag = true, dot_flag = true;
	for (int i = 0; i < vec.size(); i++)
	{
		j = -1;
		do
		{
			switch (state)
			{
			case 0://初始状态
				word = "";
				j++;
				switch (vec[i].Str[j])
				{
				case 'a':
				case 'b':
				case 'c':
				case 'd':
				case 'e':
				case 'f':
				case 'g':
				case 'h':
				case 'i':
				case 'j':
				case 'k':
				case 'l':
				case 'm':
				case 'n':
				case 'o':
				case 'p':
				case 'q':
				case 'r':
				case 's':
				case 't':
				case 'u':
				case 'v':
				case 'w':
				case 'x':
				case 'y':
				case 'z':
				case 'A':
				case 'B':
				case 'C':
				case 'D':
				case 'E':
				case 'F':
				case 'G':
				case 'H':
				case 'I':
				case 'J':
				case 'K':
				case 'L':
				case 'M':
				case 'N':
				case 'O':
				case 'P':
				case 'Q':
				case 'R':
				case 'S':
				case 'T':
				case 'U':
				case 'V':
				case 'W':
				case 'X':
				case 'Y':
				case 'Z':
				case '_':
					state = 1;
					break;
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					state = 2;
					break;
				case '<':
					state = 8;
					break;
				case '>':
					state = 9;
					break;
				case '=':
					state = 10;
					break;
				case '/':
					state = 11;
					break;
				case '!':
					state = 13;
					break;
				case '&':
					state = 15;
					break;
				case '|':
					state = 16;
					break;
				case '+':
					if (vec[i].Str[j + 1] == '\0')
					{
						j++;
					}
					state = 0;
					words++;
					temp.push_back(pair<string, string>("运算符", "+"));
					break;
				case '-':
					state = 17;
					break;
				case '*':
					if (vec[i].Str[j + 1] == '\0')
					{
						j++;
					}
					state = 0;
					words++;
					temp.push_back(pair<string, string>("运算符", "*"));
					break;
				case '.':
					if (vec[i].Str[j + 1] == '\0')
					{
						j++;
					}
					state = 0;
					words++;
					temp.push_back(pair<string, string>("运算符", "."));
					break;
				case '(':
					j++;
					state = 0;
					words++;
					temp.push_back(pair<string, string>("运算符", "("));
					break;
				case ')':
					j++;
					state = 0;
					words++;
					temp.push_back(pair<string, string>("运算符", ")"));
					break;
				case ';':
					j++;
					state = 0;
					words++;
					temp.push_back(pair<string, string>("分隔符", ";"));
					break;
				case '#':
					j++;
					state = 0;
					words++;
					temp.push_back(pair<string, string>("分隔符", "#"));
					break;
				case '\\':
					j++;
					state = 0;
					words++;
					temp.push_back(pair<string, string>("转义符", "\\"));
					break;
				case '\'':
					j++;
					state = 0;
					words++;
					temp.push_back(pair<string, string>("分隔符", "\'"));
					break;
				case '\"':
					j++;
					state = 0;
					words++;
					temp.push_back(pair<string, string>("分隔符", "\""));
					break;
				case '[':
					j++;
					state = 0;
					words++;
					temp.push_back(pair<string, string>("分隔符", "["));
					break;
				case ']':
					j++;
					state = 0;
					words++;
					temp.push_back(pair<string, string>("分隔符", "]"));
					break;
				case '{':
					j++;
					state = 0;
					words++;
					temp.push_back(pair<string, string>("分隔符", "{"));
					break;
				case '}':
					j++;
					state = 0;
					words++;
					temp.push_back(pair<string, string>("分隔符", "}"));
					break;
				case ',':
					j++;
					state = 0;
					words++;
					temp.push_back(pair<string, string>("分隔符", ","));
					break;
				case '~':
					j++;
					state = 0;
					words++;
					temp.push_back(pair<string, string>("运算符", "~"));
					break;
				case '^':
					j++;
					state = 0;
					words++;
					temp.push_back(pair<string, string>("运算符", "^"));
					break;
				case '%':
					j++;
					state = 0;
					words++;
					temp.push_back(pair<string, string>("运算符", "%"));
					break;
				case '?':
					j++;
					state = 0;
					words++;
					temp.push_back(pair<string, string>("运算符", "?"));
					break;
				case ':':
					j++;
					state = 0;
					words++;
					temp.push_back(pair<string, string>("运算符", ":"));
					break;
				default:
					word += vec[i].Str[j];
					state = 0;
					if (vec[i].Str[j + 1] == '\0')
					{
						j++;
					}
					cout << "第" << vec[i].linenum << "行有非法字符：" << word << endl;
					break;
				}
				break;
			case 1://标识符状态
				word += vec[i].Str[j];
				j++;
				if (digit(vec[i].Str[j])||letter(vec[i].Str[j])|| vec[i].Str[j]=='_');
				else
				{
					if (vec[i].Str[j] != '\0')
					{
						j--;
					}
					state = 0;
					if (IsKey(word))
					{
						words++;
						temp.push_back(pair<string, string>("关键字", word));
					}
					else
					{
						words++;
						temp.push_back(pair<string, string>("标识符", word));
					}	
				}
				break;
			case 2://常数状态
				word += vec[i].Str[j];
				j++;
				switch (vec[i].Str[j])
				{
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					state = 2;
					break;
				case '.':
					state = 3;
					break;
				case 'E':
				case 'e':
					state = 5;
					break;
				default:
					if (vec[i].Str[j] != '\0')
					{
						j--;
					}
					state = 0;
					words++;
					temp.push_back(pair<string, string>("数字", word));
					break;
				}
				break;
			case 3://小数点状态
				word += vec[i].Str[j];
				j++;
				if (digit(vec[i].Str[j]))
				{
					state = 4;
				}
				else
				{
					cout << "第" << vec[i].linenum << "行有词法错误：" << word + vec[i].Str[j] << endl;
					if (vec[i].Str[j] != '\0' && vec[i].Str[j + 1] == '\0')
					{
						j++;
					}
					state = 0;
				}
				break;
			case 4://小数状态
				word += vec[i].Str[j];
				j++;
				switch (vec[i].Str[j])
				{
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					state = 4;
					break;
				case 'E':
				case 'e':
					state = 5;
					break;
				default:
					if (vec[i].Str[j]!='\0')
					{
						j--;
					}
					state = 0;
					words++;
					temp.push_back(pair<string, string>("数字", word));
					break;
				}
				break;
			case 5://指数状态
				word += vec[i].Str[j];
				j++;
				switch (vec[i].Str[j])
				{
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					state = 7;
					break;
				case '+':
				case '-':
					state = 6;
					break;
				default:
					cout << "第" << vec[i].linenum << "行有词法错误：" << word + vec[i].Str[j] << endl;
					if (vec[i].Str[j] != '\0' && vec[i].Str[j + 1] == '\0')
					{
						j++;
					}
					state = 0;
					break;
				}
				break;
			case 6://指数2状态
				word += vec[i].Str[j];
				j++;
				if (digit(vec[i].Str[j]))
				{
					state = 7;
				}
				else
				{
					cout << "第" << vec[i].linenum << "行有词法错误：" << word + vec[i].Str[j] << endl;
					if (vec[i].Str[j] != '\0' && vec[i].Str[j + 1] == '\0')
					{
						j++;
					}
					state = 0;
				}
				break;
			case 7://无符号数状态
				word += vec[i].Str[j];
				j++;
				if (digit(vec[i].Str[j]))
				{
					state = 7;
				}
				else
				{
					if (vec[i].Str[j] != '\0')
					{
						j--;
					}
					state = 0;
					words++;
					temp.push_back(pair<string, string>("数字", word));
				}
				break;
			case 8://'<'状态
				word += vec[i].Str[j];
				j++;
				switch (vec[i].Str[j])
				{
				case '=':
					if (vec[i].Str[j + 1] == '\0')
					{
						j++;
					}
					word += vec[i].Str[j];
					state = 0;
					words++;
					temp.push_back(pair<string, string>("运算符", "<="));
					break;
				case '<':
					if (vec[i].Str[j + 1] == '\0')
					{
						j++;
					}
					word += vec[i].Str[j];
					state = 0;
					words++;
					temp.push_back(pair<string, string>("运算符", "<<"));
					break;
				default:
					if (vec[i].Str[j] != '\0')
					{
						j--;
					}
					state = 0;
					words++;
					temp.push_back(pair<string, string>("运算符", "<"));
					break;
				}
				break;
			case 9://'>'状态
				word += vec[i].Str[j];
				j++;
				switch (vec[i].Str[j])
				{
				case '=':
					if (vec[i].Str[j + 1] == '\0')
					{
						j++;
					}
					word += vec[i].Str[j];
					state = 0;
					words++;
					temp.push_back(pair<string, string>("运算符", ">="));
					break;
				case '>':
					if (vec[i].Str[j + 1] == '\0')
					{
						j++;
					}
					word += vec[i].Str[j];
					state = 0;
					words++;
					temp.push_back(pair<string, string>("运算符", ">>"));
					break;
				default:
					if (vec[i].Str[j] != '\0')
					{
						j--;
					}
					state = 0;
					words++;
					temp.push_back(pair<string, string>("运算符", ">"));
					break;
				}
				break;
			case 10://'='状态
				word += vec[i].Str[j];
				j++;
				if (vec[i].Str[j] == '=')
				{
					if (vec[i].Str[j + 1] == '\0')
					{
						j++;
					}
					word += vec[i].Str[j];
					state = 0;
					words++;
					temp.push_back(pair<string, string>("运算符", "=="));
				}
				else
				{
					if (vec[i].Str[j] != '\0')
					{
						j--;
					}
					state = 0;
					words++;
					temp.push_back(pair<string, string>("运算符", "="));
				}
				break;
			case 11://'/'状态
				word += vec[i].Str[j];
				j++;
				if (vec[i].Str[j] == '*')
				{
					state = 12;
					flag = true;
				}
				else if (vec[i].Str[j] == '/')
				{
					state = 14;
				}
				else
				{
					if (vec[i].Str[j] != '\0')
					{
						j--;
					}
					state = 0;
					words++;
					temp.push_back(pair<string, string>("运算符", "/"));
				}
				break;
			case 12://'/*'注释状态
				j++;
				while (vec[i].Str[j] != '*')
				{
					j++;
					if (j >= vec[i].Str.size())
					{
						if (i == vec.size() - 1)
						{
							flag = false;
							state = 0;
							break;
						}
						i++;
						j = 0;
					}
				}
				if (flag)
				{
					j++;
					if (vec[i].Str[j] == '/')
					{
						state = 0;
						if (vec[i].Str[j + 1] == '\0')
						{
							j++;
						}
					}
					else
					{
						if (vec[i].Str[j] != '\0')
						{
							j--;
						}
						state = 12;
						if (j == vec[i].Str.size() && i == vec.size() - 1)
						{
							state = 0;
						}
					}
				}
				break;
			case 13://'!'状态
				word += vec[i].Str[j];
				j++;
				if (vec[i].Str[j] == '=')
				{
					if (vec[i].Str[j + 1] == '\0')
					{
						j++;
					}
					word += vec[i].Str[j];
					state = 0;
					words++;
					temp.push_back(pair<string, string>("运算符", "!="));
				}
				else
				{
					if (vec[i].Str[j] != '\0')
					{
						j--;
					}
					state = 0;
					words++;
					temp.push_back(pair<string, string>("运算符", "!"));
				}
				break;
			case 14://'//'注释状态
			{
				int line_temp = i;
				while (i < vec.size() && vec[i].linenum == vec[line_temp].linenum)
					i++;
				i--;
				j = vec[i].Str.size();
				state = 0;
				break;
			}
			case 15://'&'状态
				word += vec[i].Str[j];
				j++;
				switch (vec[i].Str[j])
				{
				case '&':
					if (vec[i].Str[j + 1] == '\0')
					{
						j++;
					}
					word += vec[i].Str[j];
					state = 0;
					words++;
					temp.push_back(pair<string, string>("运算符", "&&"));
					break;
				default:
					if (vec[i].Str[j] != '\0')
					{
						j--;
					}
					state = 0;
					words++;
					temp.push_back(pair<string, string>("运算符", "&"));
					break;
				}
				break;
			case 16://'|'状态
				word += vec[i].Str[j];
				j++;
				switch (vec[i].Str[j])
				{
				case '|':
					if (vec[i].Str[j + 1] == '\0')
					{
						j++;
					}
					word += vec[i].Str[j];
					state = 0;
					words++;
					temp.push_back(pair<string, string>("运算符", "||"));
					break;
				default:
					if (vec[i].Str[j] != '\0')
					{
						j--;
					}
					state = 0;
					words++;
					temp.push_back(pair<string, string>("运算符", "|"));
					break;
				}
				break;
			case 17://'-'状态
				word += vec[i].Str[j];
				j++;
				switch (vec[i].Str[j])
				{
				case '>':
					if (vec[i].Str[j + 1] == '\0')
					{
						j++;
					}
					word += vec[i].Str[j];
					state = 0;
					words++;
					temp.push_back(pair<string, string>("运算符", "->"));
					break;
				default:
					if (vec[i].Str[j] != '\0')
					{
						j--;
					}
					state = 0;
					words++;
					temp.push_back(pair<string, string>("运算符", "-"));
					break;
				}
				break;
			}
		} while (vec[i].Str[j]!='\0');
	}
   return temp;
}

int main()
{
	string com1 = " ";
	string com2 = "\n";
	string fileline;
	int i = 1;
	vector<str>array(0);
	string file_name1;
	cout<<"请输入源文件路径（包括后缀名）：";
	cin>>file_name1;
	ifstream infile(file_name1.c_str(), ios::in);
	if (!infile)
	{
		cerr << "无法打开源文件 " << file_name1.c_str() << endl;
	}
	else
	{
		cout << endl;
		while (!infile.eof())
		{
			getline(infile, fileline, '\n');
			fileline += "\n";
			lines++;
			str nowString;
			start = 0;
			over = 0;
			for (int j = 0;fileline[j] != '\0' && over != -1;j++)
			{
				start = get_nbc(fileline, start);
				nowString.Str = GetWord(fileline, start, over);
				nowString.linenum = lines;
				if (nowString.Str.compare(com1) && nowString.Str.compare(com2))
				{
					array.push_back(nowString);
				}
				start = over + 1;
			}
		}
		vector<pair<string, string> > result;
		result = analyse(array);
		bool out_flag = Output(result);
		if (out_flag)
		{
			cout << "----------------------------------------------------------------------\n";
			cout << "词法分析完成，分析结果已经存储在文件" << file_name << "中\n";
			cout << "----------------------------------------------------------------------\n";
		}
	}
	system("pause");
	return 0;
}