#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <random>
#include <conio.h>
using namespace std;
#pragma once

namespace lib
{
	string Convert2To16(short hash[8][32]);
	short* Convert10To2(int number);
	int Pow(int x, int y);
	short* StringToBit(string str, int lengthToBit);
	string BitToString(short* arr);
	string Convert2To16(short* arr);
	short* Convert16To2(string number, int length);
	short** Convert16To2(string* number, int length);
	void ConvertTextToHash(string* text, int length);
	string* SplittingByNByte(string* text, int& length, int countByte);
	short* Convert10To2(int number, int length);
	short* Copy(short* arr);
	int FindLastChar(string text, char x);
	void ConvertHashToText(string* text, int length);
	string HMACSHA256(string* text, int length, string key);
	string HashUI(string way);
	string CopyLastPartString(string* text, int length, int lengthpart);
	void DeleteGarbage(short*** arr);
	void DeleteLastChars(string* text, int &length, int countChar);
	bool CheckHashValue(string hash);
	void CheckCorrectWayLengthKey(string& way, int& lengthKey);

	// Массивы необходимых констант

	short K[64][32] =  // огромный набор необходимых для вычисления хэша констант
	{
		{0,1,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,1,1,1,1,0,0,1,1,0,0,0},
		{0,1,1,1,0,0,0,1,0,0,1,1,0,1,1,1,0,1,0,0,0,1,0,0,1,0,0,1,0,0,0,1},
		{1,0,1,1,0,1,0,1,1,1,0,0,0,0,0,0,1,1,1,1,1,0,1,1,1,1,0,0,1,1,1,1},
		{1,1,1,0,1,0,0,1,1,0,1,1,0,1,0,1,1,1,0,1,1,0,1,1,1,0,1,0,0,1,0,1},
		{0,0,1,1,1,0,0,1,0,1,0,1,0,1,1,0,1,1,0,0,0,0,1,0,0,1,0,1,1,0,1,1},
		{0,1,0,1,1,0,0,1,1,1,1,1,0,0,0,1,0,0,0,1,0,0,0,1,1,1,1,1,0,0,0,1},
		{1,0,0,1,0,0,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,0,1,0,1,0,0,1,0,0},
		{1,0,1,0,1,0,1,1,0,0,0,1,1,1,0,0,0,1,0,1,1,1,1,0,1,1,0,1,0,1,0,1},
		{1,1,0,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,1,0,1,0,1,0,1,0,0,1,1,0,0,0},
		{0,0,0,1,0,0,1,0,1,0,0,0,0,0,1,1,0,1,0,1,1,0,1,1,0,0,0,0,0,0,0,1},
		{0,0,1,0,0,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,1,0,1,1,0,1,1,1,1,1,0},
		{0,1,0,1,0,1,0,1,0,0,0,0,1,1,0,0,0,1,1,1,1,1,0,1,1,1,0,0,0,0,1,1},
		{0,1,1,1,0,0,1,0,1,0,1,1,1,1,1,0,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0,0},
		{1,0,0,0,0,0,0,0,1,1,0,1,1,1,1,0,1,0,1,1,0,0,0,1,1,1,1,1,1,1,1,0},
		{1,0,0,1,1,0,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,1,1,0,1,0,1,0,0,1,1,1},
		{1,1,0,0,0,0,0,1,1,0,0,1,1,0,1,1,1,1,1,1,0,0,0,1,0,1,1,1,0,1,0,0},
		{1,1,1,0,0,1,0,0,1,0,0,1,1,0,1,1,0,1,1,0,1,0,0,1,1,1,0,0,0,0,0,1},
		{1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,0,1,0,0,0,1,1,1,1,0,0,0,0,1,1,0},
		{0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,1,1,1,0,1,1,1,0,0,0,1,1,0},
		{0,0,1,0,0,1,0,0,0,0,0,0,1,1,0,0,1,0,1,0,0,0,0,1,1,1,0,0,1,1,0,0},
		{0,0,1,0,1,1,0,1,1,1,1,0,1,0,0,1,0,0,1,0,1,1,0,0,0,1,1,0,1,1,1,1},
		{0,1,0,0,1,0,1,0,0,1,1,1,0,1,0,0,1,0,0,0,0,1,0,0,1,0,1,0,1,0,1,0},
		{0,1,0,1,1,1,0,0,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,1,1,1,0,1,1,1,0,0},
		{0,1,1,1,0,1,1,0,1,1,1,1,1,0,0,1,1,0,0,0,1,0,0,0,1,1,0,1,1,0,1,0},
		{1,0,0,1,1,0,0,0,0,0,1,1,1,1,1,0,0,1,0,1,0,0,0,1,0,1,0,1,0,0,1,0},
		{1,0,1,0,1,0,0,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,0,0,1,1,0,1,1,0,1},
		{1,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,1,1,1,1,1,0,0,1,0,0,0},
		{1,0,1,1,1,1,1,1,0,1,0,1,1,0,0,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1},
		{1,1,0,0,0,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,0,0,1,1},
		{1,1,0,1,0,1,0,1,1,0,1,0,0,1,1,1,1,0,0,1,0,0,0,1,0,1,0,0,0,1,1,1},
		{0,0,0,0,0,1,1,0,1,1,0,0,1,0,1,0,0,1,1,0,0,0,1,1,0,1,0,1,0,0,0,1},
		{0,0,0,1,0,1,0,0,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,1,0,1,1,0,0,1,1,1},
		{0,0,1,0,0,1,1,1,1,0,1,1,0,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,0,1,0,1},
		{0,0,1,0,1,1,1,0,0,0,0,1,1,0,1,1,0,0,1,0,0,0,0,1,0,0,1,1,1,0,0,0},
		{0,1,0,0,1,1,0,1,0,0,1,0,1,1,0,0,0,1,1,0,1,1,0,1,1,1,1,1,1,1,0,0},
		{0,1,0,1,0,0,1,1,0,0,1,1,1,0,0,0,0,0,0,0,1,1,0,1,0,0,0,1,0,0,1,1},
		{0,1,1,0,0,1,0,1,0,0,0,0,1,0,1,0,0,1,1,1,0,0,1,1,0,1,0,1,0,1,0,0},
		{0,1,1,1,0,1,1,0,0,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,1,1,0,1,1},
		{1,0,0,0,0,0,0,1,1,1,0,0,0,0,1,0,1,1,0,0,1,0,0,1,0,0,1,0,1,1,1,0},
		{1,0,0,1,0,0,1,0,0,1,1,1,0,0,1,0,0,0,1,0,1,1,0,0,1,0,0,0,0,1,0,1},
		{1,0,1,0,0,0,1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,0,0,0,1,0,1,0,0,0,0,1},
		{1,0,1,0,1,0,0,0,0,0,0,1,1,0,1,0,0,1,1,0,0,1,1,0,0,1,0,0,1,0,1,1},
		{1,1,0,0,0,0,1,0,0,1,0,0,1,0,1,1,1,0,0,0,1,0,1,1,0,1,1,1,0,0,0,0},
		{1,1,0,0,0,1,1,1,0,1,1,0,1,1,0,0,0,1,0,1,0,0,0,1,1,0,1,0,0,0,1,1},
		{1,1,0,1,0,0,0,1,1,0,0,1,0,0,1,0,1,1,1,0,1,0,0,0,0,0,0,1,1,0,0,1},
		{1,1,0,1,0,1,1,0,1,0,0,1,1,0,0,1,0,0,0,0,0,1,1,0,0,0,1,0,0,1,0,0},
		{1,1,1,1,0,1,0,0,0,0,0,0,1,1,1,0,0,0,1,1,0,1,0,1,1,0,0,0,0,1,0,1},
		{0,0,0,1,0,0,0,0,0,1,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,1,1,1,0,0,0,0},
		{0,0,0,1,1,0,0,1,1,0,1,0,0,1,0,0,1,1,0,0,0,0,0,1,0,0,0,1,0,1,1,0},
		{0,0,0,1,1,1,1,0,0,0,1,1,0,1,1,1,0,1,1,0,1,1,0,0,0,0,0,0,1,0,0,0},
		{0,0,1,0,0,1,1,1,0,1,0,0,1,0,0,0,0,1,1,1,0,1,1,1,0,1,0,0,1,1,0,0},
		{0,0,1,1,0,1,0,0,1,0,1,1,0,0,0,0,1,0,1,1,1,1,0,0,1,0,1,1,0,1,0,1},
		{0,0,1,1,1,0,0,1,0,0,0,1,1,1,0,0,0,0,0,0,1,1,0,0,1,0,1,1,0,0,1,1},
		{0,1,0,0,1,1,1,0,1,1,0,1,1,0,0,0,1,0,1,0,1,0,1,0,0,1,0,0,1,0,1,0},
		{0,1,0,1,1,0,1,1,1,0,0,1,1,1,0,0,1,1,0,0,1,0,1,0,0,1,0,0,1,1,1,1},
		{0,1,1,0,1,0,0,0,0,0,1,0,1,1,1,0,0,1,1,0,1,1,1,1,1,1,1,1,0,0,1,1},
		{0,1,1,1,0,1,0,0,1,0,0,0,1,1,1,1,1,0,0,0,0,0,1,0,1,1,1,0,1,1,1,0},
		{0,1,1,1,1,0,0,0,1,0,1,0,0,1,0,1,0,1,1,0,0,0,1,1,0,1,1,0,1,1,1,1},
		{1,0,0,0,0,1,0,0,1,1,0,0,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,0,1,0,0},
		{1,0,0,0,1,1,0,0,1,1,0,0,0,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0},
		{1,0,0,1,0,0,0,0,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0},
		{1,0,1,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,1,0,1,1,0,0,1,1,1,0,1,0,1,1},
		{1,0,1,1,1,1,1,0,1,1,1,1,1,0,0,1,1,0,1,0,0,0,1,1,1,1,1,1,0,1,1,1},
		{1,1,0,0,0,1,1,0,0,1,1,1,0,0,0,1,0,1,1,1,1,0,0,0,1,1,1,1,0,0,1,0}
	};

	// Набор констант необходимых для функции Mix
	const int constMix4[8][2] =
	{
		{14,16},
		{52,57},
		{23,40},
		{5,37},
		{25,33},
		{46,12},
		{58,22},
		{32,32}
	};
	const int constMix8[8][4] =
	{
		{46,36,19,37},
		{33,27,14,42},
		{17,49,36,39},
		{44,9,54,56},
		{39,30,34,24},
		{13,50,10,17},
		{25,29,39,43},
		{8,35,56,22},
	};
	const int constMix16[8][8] =
	{
		{24,13,8,47,8,17,22,37},
		{38,19,10,55,49,18,23,52},
		{33,4,51,13,34,41,59,17},
		{5,20,48,41,47,28,16,25},
		{41,9,37,31,12,47,44,30},
		{16,34,56,51,4,53,42,41},
		{31,44,47,46,19,42,44,25},
		{9,48,35,52,23,31,37,20},
	};

	const int constSwap4[4] =
	{0,3,2,1};
	const int constDeSwap4[4] =
	{ 0,3,2,1 };

	const int constSwap8[8] =
	{ 2,1,4,7,6,5,0,3 };
	const int constDeSwap8[8] =
	{6,1,0,7,2,5,4,3};

	const int constSwap16[16] =
	{ 0,9,2,13,6,11,4,15,10,7,12,3,14,5,8,1 };
	const int constDeSwap16[16] =
	{ 0,15,2,11,6,13,4,9,14,1,8,5,10,3,12,7 };


	//ФУНКЦИИ ДЛЯ ВВОДА / ВЫВОДА ТЕКСТА
	/// <summary>
	///  Считывает текст с файла и возвращает массив строк. При указании неверного пути возвращает null и выводит ошибку в консоли
	/// </summary>
	/// <param name="way"></param>
	/// <param name="length"></param>
	/// <returns></returns>
	string* TextReader(string way, int &length)
	{
		ifstream in(way);
		length = 0;

		if (in.is_open())
		{
			string* result;
			string word;

			int counter = 0;
			while (getline(in, word))
			{
				length++;
				counter = word == "" ? counter + 1 : 0;
			}
			length -= counter;
			in.close();
			in.open(way);

			result = new string[length];


			for (int i = 0; i < length; ++i)
			{
				getline(in, result[i]);
				if (i < length - 1)
					result[i].insert(result[i].size(), "\n");
			}
			in.close();
			return result;
		}
		else
		{
			cout << "Error: not the right way" << endl;
			return NULL;
		}
	}
	string* EncryptedTextReader(string way, int& length)
	{
		ifstream in(way);
		length = 0;

		if (in.is_open())
		{
			string* result;
			string word;

			int counter = 0;
			while (getline(in, word))
			{
				length++;
				counter = word == "" ? counter + 1 : 0;
			}
			length -= counter;
			in.close();
			in.open(way);

			result = new string[length];


			for (int i = 0; i < length; ++i)
			{
				getline(in, result[i]);
			}
			in.close();
			return result;
		}
		else
		{
			cout << "Error: not the right way" << endl;
			return NULL;
		}
	}
	/// <summary>
	/// Выводит массив строк в консоль
	/// </summary>
	/// <param name="Text"></param>
	/// <param name="length"></param>
	void OutTextInConsole(string* Text, int length)
	{
		for (int i = 0; i < length ; ++i)
		{
			cout << Text[i];
		}
	}
	/// <summary>
	/// Создает файл по пути way с содержанием Text
	/// </summary>
	/// <param name="way"></param>
	/// <param name="Text"></param>
	/// <param name="length"></param>
	void CreatFileSiph(string way, string* Text, int length)
	{
		ofstream out(way);

		if(out.is_open())
		for (int i = 0; i < length; ++i)
		{
			out << Text[i] << endl;
		}
		out.close();
	}
	void CreatFileText(string way, string* Text, int length)
	{
		ofstream out(way);

		if (out.is_open())
			for (int i = 0; i < length; ++i)
			{
				out << Text[i];
			}
		out.close();
	}


	// Логические операци над массивами битовых значений
	short* NOT(short* arr)
	{
		int length = _msize(arr) / sizeof(arr[0]);

		short* result = new short[length] {0};

		for (int i = 0; i < length; ++i)
		{
			result[i] = (arr[i] + 1) % 2;
		}

		return result;
	}
	short* AND(short* arr, short* arr2)
	{
		int length = _msize(arr) / sizeof(arr[0]);

		short* result = new short[length] {0};

		for (int i = 0; i < length; ++i)
		{
			result[i] = arr[i] & arr2[i];
		}

		return result;
	}
	short* XOR(short* arr, short* arr2)
	{
		int length = _msize(arr) / sizeof(arr[0]);

		short* result = new short[length] {0};

		for (int i = 0; i < length; ++i)
		{
			result[i] = arr[i] ^ arr2[i];
		}

		return result;
	}
	short** XOR(short** arr, short** arr2)
	{
		int length0 = _msize(arr) / sizeof(arr[0]);
		int length1 = _msize(arr[0]) / sizeof(arr[0][0]);

		short** result = new short* [length0];

		for (int i = 0; i < length0; ++i)
		{
			result[i] = new short[length1];
			for (int j = 0; j < length1; ++j)
			{
				result[i][j] = arr[i][j] ^ arr2[i][j];
			}
		}

		return result;

	}
	short* PLUS(short* arr, short* arr2)
	{
		int length = _msize(arr) / sizeof(arr[0]);

		short* result = new short[length] {0};

		for (int i = 0; i < length; ++i)
		{
			result[i] = arr[i] + arr2[i];
		}

		for (int i = length - 1; i > 0; --i)
		{
			if (result[i] < 2)
				continue;
			else if (result[i] == 2)
			{
				result[i] = 0;
				result[i - 1]++;
			}
			else
			{
				result[i] = 1;
				result[i - 1]++;
			}
		}

		if (result[0] == 2)
		{
			result[0] = 0;
		}
		else if (result[0] == 3)
		{
			result[0] = 1;
		}

		return result;
	}
	short* MINUS(short* educat, short* deducation)
	{
		int length = _msize(educat) / sizeof(educat[0]);
		short* result = new short[length];
		short* _educat = Copy(educat);

		for (int i = length - 1; i > 0; --i)
		{
			if (_educat[i] >= deducation[i])
			{
				result[i] = _educat[i] - deducation[i];
			}
			else
			{
				_educat[i - 1]--;
				_educat[i] += 2;
				result[i] = _educat[i] - deducation[i];
			}
		}

		if (_educat[0] >= deducation[0])
		{
			result[0] = _educat[0] - deducation[0];
		}
		else
		{
			_educat[0] += 2;
			result[0] = _educat[0] - deducation[0];
		}

		delete[] _educat;
		return result;
	}
	/// <summary>
	/// сдвиг массива. НЕ ЗАБЫВАЙ УДАЛЯТЬ НЕ НУЖНЫЕ ДИНАМИЧЕСКИЕ МАССИВЫ ПОСЛЕ ЭТОЙ ФУНКЦИИ
	/// </summary>
	/// <param name="arr"></param>
	/// <param name="countShift"></param>
	/// <returns></returns>
	short* ShiftArr(short* arr, int countShift)
	{
		int length = _msize(arr) / sizeof(arr[0]);

		short* result = new short[length] {0};

		for (int i = 0; i < length - countShift; ++i)
		{
			result[i + countShift] = arr[i];
		}

		return result;
	}
	/// <summary>
	/// циклическая прокрутка массива. НЕ ЗАБЫВАЙ УДАЛЯТЬ НЕ НУЖНЫЕ ДИНАМИЧЕСКИЕ МАССИВЫ ПОСЛЕ ЭТОЙ ФУНКЦИИ
	/// </summary>
	/// <param name="arr"></param>
	/// <param name="countRotate"></param>
	/// <returns></returns>
	short* RotateArrRight(short* arr, int countRotate)
	{
		int length = _msize(arr) / sizeof(arr[0]);

		short* result = new short[length] {0};

		for (int i = 0; i < length; ++i)
		{
			result[(i + countRotate) % length] = arr[i];
		}

		return result;
	}
	short* RotateArrLeft(short* arr, int countRotate)
	{
		int length = _msize(arr) / sizeof(arr[0]);
		countRotate %= length;

		short* result = new short[length] {0};

		for (int i = 0; i < length; ++i)
		{
			result[(i - countRotate + length) % length] = arr[i];
		}

		return result;
	}
	short* Copy(short* arr)
	{
		int length = _msize(arr) / sizeof(arr[0]);

		short* result = new short[length] {0};

		for (int i = 0; i < length; ++i)
		{
			result[i] = arr[i];
		}

		return result;
	}

	// Логические операции над статическими массивами битовых значений
	void NOT(short arr[], short result[], int length = 32)
	{
		for (int i = 0; i < length; ++i)
		{
			result[i] = (arr[i] + 1) % 2;
		}
	}
	void AND(short arr[], short arr2[], short result[], int length = 32)
	{
		for (int i = 0; i < length; ++i)
		{
			result[i] = arr[i] & arr2[i];
		}
	}
	void XOR(short arr[], short arr2[], short result[], int length = 32)
	{
		for (int i = 0; i < length; ++i)
		{
			result[i] = arr[i] ^ arr2[i];
		}
	}
	void PLUS(short arr[], short arr2[], short result[], int length = 32)
	{
		for (int i = 0; i < length; ++i)
		{
			result[i] = arr[i] + arr2[i];
		}

		for (int i = length - 1; i > 0; --i)
		{
			if (result[i] < 2)
				continue;
			else if (result[i] == 2)
			{
				result[i] = 0;
				result[i - 1]++;
			}
			else
			{
				result[i] = 1;
				result[i - 1]++;
			}
		}

		if (result[0] == 2)
		{
			result[0] = 0;
		}
		else if (result[0] == 3)
		{
			result[0] = 1;
		}
	}
	void ShiftArr(short arr[], short result[], int countShift, int length = 32)
	{

		for (int i = length - countShift - 1; i > -1; --i)
		{
			result[i + countShift] = arr[i];
		}

		for (int i = 0; i < countShift; ++i)
		{
			result[i] = 0;
		}
	}
	void RotateArr(short arr[], short result[], int countRotate, int length = 32)
	{
		for (int i = 0; i < length; ++i)
		{
			result[(i + countRotate) % length] = arr[i];
		}
	}
	void Equating(short result[], short arr[], int length = 32)
	{
		for (int i = 0; i < length; ++i)
		{
			result[i] = arr[i];
		}
	}

	//ОБЩИЕ ФУНКЦИЯ КОДИРОВКИ
	
	string* SplittingByNByte(string text, int countByte)
	{
		string* buf = new string[1]{ text };
		int bufL = 1;
		return SplittingByNByte(buf, bufL, countByte);
	}
	string* SplittingByNByte(string* text, int& length, int countByte)
	{
		string* result;
		int sizeArr = 0;

		for (int i = 0; i < length; ++i)
		{
			sizeArr += text[i].size();
		}

		bool dividedByCountByte = sizeArr % countByte == 0;

		int newLength = sizeArr % countByte == 0 ? sizeArr / countByte : sizeArr / countByte + 1;

		if (sizeArr > 0)
		{
			result = new string[newLength];
			for (int i = 0; i < newLength; ++i)
			{
				result[i].resize(countByte, 'F');
			}

			int i = 0, I = 0, j = 0, J = 0;

			while (J != length)
			{
				result[I][i++] = text[J][j++];

				if (i == countByte)
				{
					I++;
					i = 0;
				}
				if (j == text[J].size())
				{
					J++;
					j = 0;
				}
			}

			if (!dividedByCountByte)
				result[newLength - 1].resize(sizeArr % countByte);

			delete[] text;
			length = newLength;
			return result;
		}
		else
		{
			cout << "Error: too small size Arr" << endl;
		}

		return NULL;
	}
	string KeyGenerate(int lengthByte)
	{
		string result;
		char symbol[16] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };
		random_device rd;   // non-deterministic generator
		mt19937 gen(rd());

		for (int i = 0; i < lengthByte * 2; ++i)
		{
			result += symbol[gen() % 16];
		}

		return result;
	}


	//ФУНКЦИИ ДЛЯ ШИФРОВКИ / ДЕШИФРОВКИ
	string** PrepairText(string* text, int &lengthText, int lengthBlock)
	{
		text = SplittingByNByte(text, lengthText, lengthBlock);
		int len = text[lengthText - 1].length();
		if (len != lengthBlock)
		{
			text[lengthText - 1].resize(lengthBlock, '0');
			text[lengthText - 1][len] = (char)128;
		}
		

		string** result = new string * [lengthText];

		for (int i = 0; i < lengthText; ++i)
		{
			result[i] = SplittingByNByte(text[i], 8);
		}

		return result;
	}
	short*** GenerateTurnKey(short** SplitHashKey, short** SplitHashTweak,
		int countRound, int count64Part)
	{
		int countTurnKey = countRound / 4 + 1;
		short C240[64] = { 0,0,0,1,1,0,1,1,1,1,0,1,0,0,0,1,0,0,0,1,1,0,1,1,1,1,0,1,1,0,1,0,1,0,1,0,1,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,0,1,0,0,0,1,0,0,0,1,0 };

		delete[] SplitHashTweak[2];
		SplitHashTweak[2] = XOR(SplitHashTweak[0], SplitHashTweak[1]);

		for (int i = 0; i < 64; ++i)
		{
			int symbol = 0;
			for (int j = 0; j < count64Part; ++j)
				symbol ^= SplitHashKey[j][i];

			SplitHashKey[count64Part][i] = symbol ^ C240[i];
		}
		// Подготовили t2 и KnW

		short*** resultTurnKey = new short** [countTurnKey];
		for (int i = 0; i < countTurnKey; ++i)
			resultTurnKey[i] = new short* [count64Part];

		for (int s = 0; s < countTurnKey;++s)
		{
			for (int k = 0; k < count64Part; ++k)
			{
				if (k < count64Part - 3)
					resultTurnKey[s][k] = Copy(SplitHashKey[(s + k) % (count64Part + 1)]);
				if(k == count64Part-3) 
					resultTurnKey[s][k] = PLUS(SplitHashKey[(s + k) % (count64Part + 1)], SplitHashTweak[s%3]);
				if (k == count64Part - 2)
					resultTurnKey[s][k] = PLUS(SplitHashKey[(s + k) % (count64Part + 1)], SplitHashTweak[(s+1) % 3]);
				if (k == count64Part - 1)
				{
					short* sToBit = Convert10To2(s, 64);
					resultTurnKey[s][k] = PLUS(SplitHashKey[(s + k) % (count64Part + 1)], sToBit);
					delete[] sToBit;
				}

			}
		}

		for (int i = 0; i < count64Part + 1; ++i)
			delete[] SplitHashKey[i];
		delete[] SplitHashKey;

		for (int i = 0; i < 3; ++i)
			delete[] SplitHashTweak[i];
		delete[] SplitHashTweak;

		return resultTurnKey;
	}
	short*** PrepairNewTurnKey(int sizeKeyByte)
	{
		if (sizeKeyByte == 128 || sizeKeyByte == 64 || sizeKeyByte == 32)
		{
			int countRound = sizeKeyByte == 128 ? 80 : 72;
			int count64Part = sizeKeyByte / 8;
			string key = KeyGenerate(sizeKeyByte);  //1024 bit 512 bit or 256 bit
			cout << key << endl << "Это ключ шифрования, сохраните его в надежном месте." << endl;
			key.resize(sizeKeyByte * 2 + 16, '0');
			string tweak = KeyGenerate(16); //128 bit always
			cout << tweak << endl << "Это tweak значение, сохраните его в надежном месте." << endl;
			cout << "ВВедите Enter для продолжения" << endl;
			_getch();
			tweak.resize(48, '0');
			string* SplitKey = SplittingByNByte(key, 16);
			string* SplitTweak = SplittingByNByte(tweak, 16);
			short** SplitHashKey = Convert16To2(SplitKey, count64Part + 1);
			short** SplitHashTweak = Convert16To2(SplitTweak, 3);
			short*** turnKey = GenerateTurnKey(SplitHashKey, SplitHashTweak, countRound, count64Part);
			delete[] SplitKey;
			delete[] SplitTweak;

			return turnKey;
		}
		else
		{
			cout << "Error: Incorect Length key" << endl;
			return NULL;
		}
		
	}
	short*** PrepairOldTurnKey(string key, string tweak)
	{
		int sizeKeyByte = key.length() / 2;

		if ((sizeKeyByte == 128 || sizeKeyByte == 64 || sizeKeyByte == 32)
			&& tweak.length() == 32)
		{
			int countRound = sizeKeyByte == 128 ? 80 : 72;
			int count64Part = sizeKeyByte / 8;
			key.resize(sizeKeyByte * 2 + 16, '0');
			tweak.resize(48, '0');
			string* SplitKey = SplittingByNByte(key, 16);
			string* SplitTweak = SplittingByNByte(tweak, 16);
			short** SplitHashKey = Convert16To2(SplitKey, count64Part + 1);
			short** SplitHashTweak = Convert16To2(SplitTweak, 3);
			short*** turnKey = GenerateTurnKey(SplitHashKey, SplitHashTweak, countRound, count64Part);
			delete[] SplitKey;
			delete[] SplitTweak;

			return turnKey;
		}
		else
		{
			cout << "Error: Incorect Length key" << endl;
			return NULL;
		}

	}
	void Mix(short* &x0, short* &x1, int cons)
	{
		short* buf = PLUS(x0, x1);
		delete[] x0;
		x0 = buf;
		short* _buf = RotateArrLeft(x1, cons);
		delete[] x1;
		x1 = _buf;
		short* __buf = XOR(x1, x0);
		delete[] x1;
		x1 = __buf;
	}
	void deMix(short* &x0, short* &x1, int cons)
	{
		short* buf = XOR(x0, x1);
		delete[] x1;
		x1 = buf;
		short* _buf = RotateArrRight(x1, cons);
		delete[] x1;
		x1 = _buf;
		short* __buf = MINUS(x0, x1);
		delete[] x0;
		x0 = __buf;
	}
	void encoderThreeFish(short** &text, short*** key, int countRound, int count64Part)
	{
		for (int i = 0; i < countRound; ++i)
		{
			// вставка ключа на каждую четвертую итерацию
			if (i % 4 == 0) 
			{
				for (int j = 0; j < count64Part; ++j)
				{
					short* _buf = PLUS(text[j], key[i / 4][j]);
					delete[] text[j];
					text[j] = _buf;
				}
			}

			//// использование функции микс
			for (int j = 0; j < count64Part / 2; ++j)
			{
				int cons;

				switch (count64Part)
				{
				case 4:
					cons = constMix4[i % 8][j];
					break;
				case 8:
					cons = constMix8[i % 8][j];
					break;
				case 16:
					cons = constMix16[i % 8][j];
					break;
				default:
					cout << "Error in encoder func (mix)" << endl;
					break;
				}

				Mix(text[2*j], text[2*j + 1], cons);
			}

			//применение перестановки
			short** buf = new short* [count64Part];
			for (int j = 0; j < count64Part; ++j)
			{
				int cons;

				switch (count64Part)
				{
				case 4:
					cons = constSwap4[j];
					break;
				case 8:
					cons = constSwap8[j];
					break;
				case 16:
					cons = constSwap16[j];
					break;
				default:
					cout << "Error in encoder func (permotion)" << endl;
					break;
				}

				buf[cons] = Copy(text[j]);
			}

			for (int j = 0; j < count64Part; ++j)
			{
				delete[] text[j];
				text[j] = buf[j];
			}
			delete[] buf;
		}

		//использование последнего ключа после всех раундов
		for (int j = 0; j < count64Part; ++j)
		{
			short* _buf = PLUS(text[j], key[countRound / 4][j]);
			delete[] text[j];
			text[j] = _buf;
		}
	}
	void decoderThreeFish(short** text, short*** key, int countRound, int count64Part)
	{
		//использование последнего ключа перед началом шифрования
		for (int j = 0; j < count64Part; ++j)
		{
			short* _buf = MINUS(text[j], key[countRound / 4][j]);
			delete[] text[j];
			text[j] = _buf;
		}

		for (int i = countRound - 1; i > -1; --i)
		{
			//применение перестановки
			short** buf = new short* [count64Part];
			for (int j = count64Part-1; j > -1; --j)
			{
				int cons;

				switch (count64Part)
				{
				case 4:
					cons = constDeSwap4[j];
					break;
				case 8:
					cons = constDeSwap8[j];
					break;
				case 16:
					cons = constDeSwap16[j];
					break;
				default:
					cout << "Error in encoder func (permotion)" << endl;
					break;
				}

				buf[cons] = Copy(text[j]);
			}

			for (int j = 0; j < count64Part; ++j)
			{
				delete[] text[j];
				text[j] = buf[j];
			}
			delete[] buf;

			for (int j = count64Part / 2 - 1; j > -1; --j)
			{
				int cons;

				switch (count64Part)
				{
				case 4:
					cons = constMix4[i  % 8][j];
					break;
				case 8:
					cons = constMix8[i % 8][j];
					break;
				case 16:
					cons = constMix16[i % 8][j];
					break;
				default:
					cout << "Error in encoder func (demix)" << endl;
					break;
				}

				deMix(text[2 * j], text[2 * j + 1], cons);
			}

			if (i % 4 == 0)
			{
				for (int j = 0; j < count64Part; ++j)
				{
					short* _buf = MINUS(text[j], key[i / 4][j]);
					delete[] text[j];
					text[j] = _buf;
				}
			}
		}
	}
	// ЭТА ФУНКЦИЯ НЕ УДАЛЯЕТ ВХОДЯЩИЕ ДИНАМИЧЕСКИЕ ПАРАМЕТРЫ. ЛИБО ДОБАВИТЬ ИХ УДАЛЕНИЕ ЛИБО УДАЛЯТЬ ИХ ПОСЛЕ ИСПОЛЬЗОВАНИЯ
	string* CBCEncoderThreeFish(short*** BitText, short*** turnKey, int countRound, int count64Part)
	{
		string IV = KeyGenerate(count64Part * 8); //sizeKey
		string* SplitIV = SplittingByNByte(IV, 16);
		short** SplitBitIV = Convert16To2(SplitIV, count64Part);
		int length = _msize(BitText) / sizeof(BitText[0]);
		//cipher
		for (int i = 0; i < length; ++i)
		{
			short** _buf;
			if (i == 0)
				_buf = XOR(SplitBitIV, BitText[i]);
			else
				_buf = XOR(BitText[i], BitText[i - 1]);


			encoderThreeFish(_buf, turnKey, countRound, count64Part);

			for (int j = 0; j < count64Part; ++j)
				delete BitText[i][j];
			delete BitText[i];

			BitText[i] = _buf;
		}

		string* result = new string[length + 1];

		for (int j = 0; j < count64Part; ++j)
		{
			result[0] += Convert2To16(SplitBitIV[j]);
		}
		for (int i = 0; i < length; ++i)
		{
			for (int j = 0; j < count64Part; ++j)
			{
				result[i + 1] += Convert2To16(BitText[i][j]);
			}
		}

		return result;
	}
	string* CBCDecoderThreeFish(short*** BitText, short*** turnKey, int countRound, int count64Part)
	{
		int length = _msize(BitText) / sizeof(BitText[0]);
		for (int i = length - 1; i > 0; --i)
		{
			decoderThreeFish(BitText[i], turnKey, countRound, count64Part);
			short** _buf = XOR(BitText[i], BitText[i - 1]);

			for (int j = 0; j < count64Part; ++j)
				delete BitText[i][j];
			delete BitText[i];

			BitText[i] = _buf;
		}

		string* result = new string[length - 1];


		for (int i = 1; i < length; ++i)
		{
			for (int j = 0; j < count64Part; ++j)
			{
				result[i-1] += BitToString(BitText[i][j]);
			}
		}

		return result;
	}
	void EncoderUI(string way, int sizeKeyByte)
	{
		int length = 1;
		string* check = TextReader(way, length);
		string hash = HashUI(way);
		check[length - 1] += hash;
		int countRound = sizeKeyByte == 128 ? 80 : 72;
		int count64Part = sizeKeyByte / 8;

		string** test = PrepairText(check, length, sizeKeyByte);
		short*** BitText = new short** [length];
		for (int i = 0; i < length; ++i)
		{
			BitText[i] = new short* [count64Part];
			for (int j = 0; j < count64Part; ++j)
			{
				BitText[i][j] = StringToBit(test[i][j], test[i][j].length() * 8);
			}
			delete[] test[i];
		}
		delete[] test;
		cout << "1. Использовать существующий ключ шифрования" << endl << "2. Создать новый ключ шифрования" << endl;
		string checkKey;
		short*** turnKey;
		while (true)
		{
			cin >> checkKey;
			if (checkKey == "1")
			{
				string key, tweak;
				while (true)
				{

					cout << "Введите ключ" << endl;
					cin >> key;

					if (CheckHashValue(key) && key.length() / 2 == sizeKeyByte)
						break;
					else
						cout << "Неверное значение ключа" << endl;
				}
				while (true)
				{

					cout << "Введите tweak значение" << endl;
					cin >> tweak;

					if (CheckHashValue(tweak) && tweak.length()  == 32)
						break;
					else
						cout << "Неверное tweak значение" << endl;
				}				
				
				turnKey = PrepairOldTurnKey(key, tweak);
			}
			else if(checkKey == "2")
			{
				turnKey = PrepairNewTurnKey(sizeKeyByte);
				break;
			}
			else
			{
				cout << "Неверное значение. Введите нужный вам вариант еще раз." << endl;
			}
		}

		string* result = CBCEncoderThreeFish(BitText, turnKey, countRound, count64Part);
		string waySave;
		while (true)
		{
			cout << "Введите путь сохранения шифрованого текста и нзвание .txt файла" << endl;
			cin >> waySave;
			ofstream file(waySave);
			if (file.is_open())
			{
				file.close();
				break;
			}
			else
			{
				cout << "Неверный путь к файлу, введите заново. Пример правильного пути файла: C:\\Users\\Users\\Desktop\\text.txt" << endl;
			}
		}
		CreatFileSiph(waySave, result, _msize(BitText) / sizeof(BitText[0]) + 1);

		delete[] result;
		DeleteGarbage(turnKey);
	}
	void DecoderUI(string way, int sizeKeyByte)
	{
		int length = 1;
		string* check = EncryptedTextReader(way, length);
		ConvertHashToText(check, length);

		int countRound = sizeKeyByte == 128 ? 80 : 72;
		int count64Part = sizeKeyByte / 8;

		string** test = PrepairText(check, length, sizeKeyByte);
		short*** BitText = new short** [length];
		for (int i = 0; i < length; ++i)
		{
			BitText[i] = new short* [count64Part];
			for (int j = 0; j < count64Part; ++j)
			{
				BitText[i][j] = StringToBit(test[i][j], test[i][j].length() * 8);
			}
			delete[] test[i];
		}
		delete[] test;

		short*** turnKey;
		string key, tweak;
		while (true)
		{

			cout << "Введите ключ" << endl;
			cin >> key;

			if (CheckHashValue(key) && key.length() / 2 == sizeKeyByte)
				break;
			else
				cout << "Неверное значение ключа" << endl;
		}
		while (true)
		{

			cout << "Введите tweak значение" << endl;
			cin >> tweak;

			if (CheckHashValue(tweak) && tweak.length() == 32)
				break;
			else
				cout << "Неверное tweak значение" << endl;
		}
		turnKey = PrepairOldTurnKey(key, tweak);
		
		string* result = CBCDecoderThreeFish(BitText, turnKey, countRound, count64Part);
		int lengthResult = _msize(BitText) / sizeof(BitText[0]) - 1;
		result[lengthResult-1].resize(FindLastChar(result[lengthResult-1], (char)128));
		string hash = CopyLastPartString(result,lengthResult,64);
		DeleteLastChars(result, lengthResult, 64);
		string waySave;
		while (true)
		{
			cout << "Введите путь сохранения шифрованого текста и нзвание .txt файла" << endl;
			cin >> waySave;
			ofstream file(waySave);
			if (file.is_open())
			{
				file.close();
				break;
			}
			else
			{
				cout << "Неверный путь к файлу, введите заново. Пример правильного пути файла: C:\\Users\\Users\\Desktop\\text.txt" << endl;
			}
		}
		CreatFileText(waySave, result, lengthResult);

		string keyHash;
		while (true)
		{
			cout << "Введите ключ цифровой подписи" << endl;
			cin >> keyHash;

			if (CheckHashValue(keyHash))
				break;
			else
				cout << "Неверное значение цифровой подписи" << endl;
		}


		if (hash == HMACSHA256(result, lengthResult, keyHash))
		{
			cout << "Данные не изменены" << endl;
		}
		else
		{
			cout << "Внимание, данные подверглись изменением, их корректность не является достоверной" << endl;
		}

		DeleteGarbage(BitText);
		DeleteGarbage(turnKey);
	}

	//функции для хэширования
	short** ParityCheckOn512(string* text, int& length)
	{
		int lengthRes = text[length - 1].size() < 112 ? length : length + 1;
		short* sizeText = Convert10To2((length - 1) * 512 + text[length - 1].size()* 4);
		int lenText = _msize(sizeText) / sizeof(sizeText[0]);
		short** result = new  short*[lengthRes];

		for (int i = 0; i < length - 1; ++i)
		{
			result[i] = Convert16To2(text[i], text[i].size() * 4);
		}

		if (text[length - 1].size() == 128)
		{
			result[length - 1] = Convert16To2(text[length - 1], text[length - 1].size() * 4);
			result[length] = new short[512]{0};
			result[length][0] = 1;
			for (int i = 0; i < lenText; ++i)
			{
				result[length][512 - lenText + i] = sizeText[i];
			}
		}
		else if (text[length - 1].size() < 112)
		{
			short* buf = Convert16To2(text[length - 1], text[length-1].size() * 4);
			int lenBuf = _msize(buf) / sizeof(buf[0]);
			result[length - 1] = new short[512]{ 0 };

			for (int i = 0; i < lenBuf; ++i)
			{
				result[length - 1][i] = buf[i];
			}

			delete[] buf;

			result[length - 1][lenBuf] = 1;

			for (int i = 0; i < lenText; ++i)
			{
				result[length - 1][512 - lenText + i] = sizeText[i];
			}
		}
		else if(text[length - 1].size() >= 112)
		{
			short* buf = Convert16To2(text[length - 1], text[length - 1].size() * 4);
			int lenBuf = _msize(buf) / sizeof(buf[0]);
			result[length - 1] = new short[512]{ 0 };

			for (int i = 0; i < lenBuf; ++i)
			{
				result[length - 1][i] = buf[i];
			}
			delete[] buf;
			result[length - 1][lenBuf] = 1;
			result[length] = new short[512]{ 0 };
			for (int i = 0; i < lenText; ++i)
			{
				result[length][512 - lenText + i] = sizeText[i];
			}
		}

		delete[] text;
		length = lengthRes;

		return result;
	}
	void CreateMessageSchedule(short* arr, short result[64][32])
	{
		for (int i = 0; i < _msize(arr) / sizeof(arr[0]); ++i)
		{
			result[i / 32][i % 32] = arr[i];
		}
		//s0 = (w[i - 15] rightrotate 7) xor (w[i - 15] rightrotate 18) xor (w[i - 15] rightshift 3)
		//s1 = (w[i - 2] rightrotate 17) xor (w[i - 2] rightrotate 19) xor (w[i - 2] rightshift 10)
		//w[i] = w[i - 16] + s0 + w[i - 7] + s1
		short calculations[6][32]{ 0 };
		for (int i = 16; i < 64; ++i)
		{
			RotateArr(result[i - 15], calculations[0], 7);
			RotateArr(result[i - 15], calculations[1], 18);
			ShiftArr(result[i - 15], calculations[2], 3);
			XOR(calculations[0], calculations[1], calculations[1]);
			XOR(calculations[1], calculations[2], calculations[2]); //calculation[2] = s0

			RotateArr(result[i - 2], calculations[3], 17);
			RotateArr(result[i - 2], calculations[4], 19);
			ShiftArr(result[i - 2], calculations[5], 10);
			XOR(calculations[3], calculations[4], calculations[4]);
			XOR(calculations[4], calculations[5], calculations[5]); //calculation[5] = s1

			PLUS(result[i - 16], calculations[2], calculations[2]);
			PLUS(result[i - 7], calculations[5], calculations[5]);
			PLUS(calculations[2], calculations[5], result[i]);
		}

		delete[] arr;
	}
	void Compression(short MessageSchedule[64][32], short HASH[8][32])
	{
		/*S1 = (e rightrotate 6) xor (e rightrotate 11) xor (e rightrotate 25) //3
		ch = (e and f) xor ((not e) and g)									   //2
		temp1 = h + S1 + ch + k[i] + w[i]									   //1
		S0 = (a rightrotate 2) xor (a rightrotate 13) xor (a rightrotate 22)   //3
		maj = (a and b) xor (a and c) xor (b and c)							   //3
		temp2 : = S0 + maj                                                     //1
		h = g
		g = f
		f = e
		e = d + temp1
		d = c
		c = b
		b = a
		a = temp1 + temp2*/

		short calculations[13][32]{0};
		short ConstantVariables[8][32]{0};
		

		for (int i = 0; i < 8; ++i)
		{
			Equating(ConstantVariables[i], HASH[i]);
		}

		for (int i = 0; i < 64; ++i)
		{
			//S1 = (e rightrotate 6) xor (e rightrotate 11) xor (e rightrotate 25) 3
			RotateArr(ConstantVariables[4], calculations[0], 6);
			RotateArr(ConstantVariables[4], calculations[1], 11);
			RotateArr(ConstantVariables[4], calculations[2], 25);
			XOR(calculations[0], calculations[1], calculations[1]);
			XOR(calculations[1], calculations[2], calculations[2]); // Calculations[2] = S1

			//ch = (e and f) xor ((not e) and g) 2
			AND(ConstantVariables[4], ConstantVariables[5], calculations[3]);
			NOT(ConstantVariables[4], calculations[4]);
			AND(calculations[4], ConstantVariables[6], calculations[4]);
			XOR(calculations[3], calculations[4], calculations[4]); // Calculations[4] = ch

			//temp1 = h + S1 + ch + k[i] + w[i] 1
			PLUS(ConstantVariables[7], calculations[2], calculations[5]);
			PLUS(calculations[5], calculations[4], calculations[5]);
			PLUS(calculations[5], K[i],calculations[5]);
			PLUS(calculations[5], MessageSchedule[i],calculations[5]); //Calculations[5] = temp1

			//S0 = (a rightrotate 2) xor (a rightrotate 13) xor (a rightrotate 22) 3
			RotateArr(ConstantVariables[0], calculations[6], 2);
			RotateArr(ConstantVariables[0], calculations[7], 13);
			RotateArr(ConstantVariables[0], calculations[8], 22);
			XOR(calculations[6], calculations[7], calculations[7]);
			XOR(calculations[7], calculations[8], calculations[8]); // Calculations[8] = S0

			//maj = (a and b) xor (a and c) xor (b and c) 3
			AND(ConstantVariables[0],ConstantVariables[1],calculations[9]);
			AND(ConstantVariables[0], ConstantVariables[2], calculations[10]);
			AND(ConstantVariables[1],ConstantVariables[2],calculations[11]);
			XOR(calculations[9],calculations[10],calculations[10]);
			XOR(calculations[10],calculations[11],calculations[11]); //Calculations[11] = maj

			//temp2: = S0 + maj  1
			PLUS(calculations[11], calculations[8], calculations[12]); //Calculations[12] = temp2

			/*h = g
			g = f
			f = e
			e = d + temp1
			d = c
			c = b
			b = a
			a = temp1 + temp2*/

			Equating(ConstantVariables[7], ConstantVariables[6]); //h = g
			Equating(ConstantVariables[6], ConstantVariables[5]); //g = f
			Equating(ConstantVariables[5], ConstantVariables[4]); //f = e
			PLUS(ConstantVariables[3], calculations[5], ConstantVariables[4]); //e = d + temp1
			Equating(ConstantVariables[3], ConstantVariables[2]); //d = c
			Equating(ConstantVariables[2], ConstantVariables[1]); //c = b
			Equating(ConstantVariables[1], ConstantVariables[0]); //b = a
			PLUS(calculations[5], calculations[12], ConstantVariables[0]);
		}
		
		for (int i = 0; i < 8; ++i)
		{
			PLUS(ConstantVariables[i], HASH[i], HASH[i]);
		}
	}
	string HashSha256(string* text, int length, bool texthash = true) // готовая хэш функция
	{
		if (texthash)
		{
			ConvertTextToHash(text, length);
		}
		short HASH[8][32] = // набор значений, которые будут изменятся походу хэширования и обьединение которых будет результатом хэширования
		{
			{0,1,1,0,1,0,1,0,0,0,0,0,1,0,0,1,1,1,1,0,0,1,1,0,0,1,1,0,0,1,1,1}, //a
			{1,0,1,1,1,0,1,1,0,1,1,0,0,1,1,1,1,0,1,0,1,1,1,0,1,0,0,0,0,1,0,1}, //b
			{0,0,1,1,1,1,0,0,0,1,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,1,1,1,0,0,1,0}, //c
			{1,0,1,0,0,1,0,1,0,1,0,0,1,1,1,1,1,1,1,1,0,1,0,1,0,0,1,1,1,0,1,0}, //d
			{0,1,0,1,0,0,0,1,0,0,0,0,1,1,1,0,0,1,0,1,0,0,1,0,0,1,1,1,1,1,1,1}, //e
			{1,0,0,1,1,0,1,1,0,0,0,0,0,1,0,1,0,1,1,0,1,0,0,0,1,0,0,0,1,1,0,0}, //f
			{0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,0,1,1,0,0,1,1,0,1,0,1,0,1,1}, //g
			{0,1,0,1,1,0,1,1,1,1,1,0,0,0,0,0,1,1,0,0,1,1,0,1,0,0,0,1,1,0,0,1}  //h
		};
		string* splittingText = SplittingByNByte(text, length,128);
		short** splittingBit = ParityCheckOn512(splittingText,length);
		
		for (int i = 0; i < length; ++i)
		{
			short messageSchedule[64][32]{0};
			CreateMessageSchedule(splittingBit[i], messageSchedule);
			Compression(messageSchedule, HASH);
		}

		delete[] splittingBit;
		return Convert2To16(HASH);
	}
	string HMACSHA256(string* text, int length, string key)
	{
		short* constX36 = new short[512]{0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0 };
		short* constX5C = new short[512]{0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0};
		short* keyBit;

		int lenKey = key.length() / 2;

		if (lenKey < 64)
		{
			keyBit = Convert16To2(key, 512);
		}
		else if (lenKey > 64)
		{
			string* _Key = new string[1];
			_Key[0] = key;
			key = HashSha256(_Key,1);
			keyBit = Convert16To2(key, 512);
		}
		else
			keyBit = Convert16To2(key, 512);


		short* constX36XORKey = XOR(constX36, keyBit);
		delete[] constX36;
		short* constX5CXORKey = XOR(constX5C, keyBit);
		delete[] constX5C;
		delete[] keyBit;

		string x36 = Convert2To16(constX36XORKey);
		string x5c = Convert2To16(constX5CXORKey);

		ConvertTextToHash(text, length);

		string* preRes = new string[1];
		text[0] = x36 + text[0];
		preRes[0] = HashSha256(text, length, false);
		preRes[0] = x5c + preRes[0];
		
		// HMAC = HASH(X5c || HMAC(x36 || text));
		return HashSha256(preRes ,1, false);
	}
	string HashUI(string way)
	{
		cout << "1. Использовать существующий ключ цифровой подписи." << endl << "2. Создать новый ключ цифровой подписи." << endl;
		string checkKey;
		string Key;
		while (true)
		{
			cin >> checkKey;

			if (checkKey == "1")
			{
				while (true)
				{
					cout << "Введите существующий ключ. Ключ должен быть в виде хэш значения, то есть числа 16 формы!" << endl;
					cin >> Key;
					if (CheckHashValue(Key))
						break;
					else
						cout << "Неверное значение ключа." << endl;
				}
				break;

			}
			else if(checkKey == "2")
			{
				Key = KeyGenerate(64);
				cout << "Это ключ цифровой подписи. Сохраните его в надежном месте." << endl << Key << endl;
				break;
			}
			else
			{
				cout << "Введено неверное значение, введите его заново" << endl;
			}
		}

		int length = 1;
		string* text = TextReader(way, length);
		return HMACSHA256(text, length, Key);
	}

		// Функции конвертаций
	short* StringToBit(string str, int lengthToBit)
	{
		short* result = new short[lengthToBit]{0};

		for (int i = 0; i < str.length(); ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				result[i * 8 + j] = str[i] >> (7 - j) & 1;
			}
		}

		return result;
	}
	string BitToString(short* arr)
	{
		string result("0", _msize(arr) / sizeof(arr[0]) / 8);

		for (int i = 0; i < _msize(arr) / sizeof(arr[0]) / 8; ++i)
		{
			int number = 0;
			for (int j = 7; j > -1; --j)
			{
				number += pow(2, j) * arr[i * 8 + 7 - j];
			}
			result[i] = (char)number;
		}

		return result;
	}
	short* Convert10To2(int number)
	{
		int lenArr = 0;

		int counter = 1;

		do
		{
			lenArr++;
			counter *= 2;
		} while (counter <= number);

		short* result = new short[lenArr] {0};

		for (int i = 0; i < lenArr; ++i)
		{
			result[lenArr - 1 - i] = number % 2;
			number /= 2;
		}


		return result;
	}
	short* Convert10To2(int number, int length)
	{
		int lenArr = 0;

		int counter = 1;

		do
		{
			lenArr++;
			counter *= 2;
		} while (counter <= number);

		short* result = new short[length] {0};

		for (int i = 0; i < lenArr; ++i)
		{
			result[length - 1 - i] = number % 2;
			number /= 2;
		}


		return result;
	}
	string Convert2To16(short hash[8][32])
	{
		string result("F",64);

		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 32;)
			{
				int convert = 0;
				for (int k = 3; k > -1; k--)
				{
					convert += Pow(10, k) * hash[i][j + (3-k)];
				}
				
				switch (convert)
				{
				case 0: result[i * 8 + j / 4] = '0';
					break;
				case 1: result[i * 8 + j / 4] = '1';
					break;
				case 10: result[i * 8 + j / 4] = '2';
					break;
				case 11: result[i * 8 + j / 4] = '3';
					break;
				case 100: result[i * 8 + j / 4] = '4';
					break;
				case 101: result[i * 8 + j / 4] = '5';
					break;
				case 110: result[i * 8 + j / 4] = '6';
					break;
				case 111: result[i * 8 + j / 4] = '7';
					break;
				case 1000: result[i * 8 + j / 4] = '8';
					break;
				case 1001: result[i * 8 + j / 4] = '9';
					break;
				case 1010: result[i * 8 + j / 4] = 'a';
					break;
				case 1011: result[i * 8 + j / 4] = 'b';
					break;
				case 1100: result[i * 8 + j / 4] = 'c';
					break;
				case 1101: result[i * 8 + j / 4] = 'd';
					break;
				case 1110: result[i * 8 + j / 4] = 'e';
					break;
				case 1111: result[i * 8 + j / 4] = 'f';
					break;
				}
				j += 4;
			}
		}

		return result;
	}	
	string Convert2To16(short* arr)
	{
		int length = _msize(arr) / sizeof(arr[0]);
		string result;
		result.resize(length / 4);

			for (int i = 0; i < length;)
			{
				int convert = 0;
				for (int k = 3; k > -1; k--)
				{
					convert += Pow(10, k) * arr[i + (3 - k)];
				}

				switch (convert)
				{
				case 0: result[i / 4] = '0';
					break;
				case 1: result[i / 4] = '1';
					break;
				case 10: result[i / 4] = '2';
					break;
				case 11: result[i / 4] = '3';
					break;
				case 100: result[i / 4] = '4';
					break;
				case 101: result[i / 4] = '5';
					break;
				case 110: result[i / 4] = '6';
					break;
				case 111: result[i / 4] = '7';
					break;
				case 1000: result[i / 4] = '8';
					break;
				case 1001: result[i / 4] = '9';
					break;
				case 1010: result[i / 4] = 'a';
					break;
				case 1011: result[i / 4] = 'b';
					break;
				case 1100: result[i / 4] = 'c';
					break;
				case 1101: result[i / 4] = 'd';
					break;
				case 1110: result[i / 4] = 'e';
					break;
				case 1111: result[i / 4] = 'f';
					break;
				}
				i += 4;
			}

		delete[] arr;
		return result;
	}
	short* Convert16To2(string number, int length)
	{
		short* result = new short[length] {0};
	

		for (int i = 0; i < number.length(); ++i)
		{
			char buf = number[i];
			
			switch (buf)
			{
			case '0':
				break;
			case '1':
				result[i * 4 + 3] = 1;
				break;
			case '2':
				result[i * 4 + 2] = 1;
				break;
			case '3':
				result[i * 4 + 2] = 1;
				result[i * 4 + 3] = 1;
				break;
			case '4':
				result[i * 4 + 1] = 1;
				break;
			case '5':
				result[i * 4 + 1] = 1;
				result[i * 4 + 3] = 1;
				break;
			case '6':
				result[i * 4 + 1] = 1;
				result[i * 4 + 2] = 1;
				break;
			case '7':
				result[i * 4 + 1] = 1;
				result[i * 4 + 2] = 1;
				result[i * 4 + 3] = 1;
				break;
			case '8': 
				result[i * 4] = 1;
				break;
			case '9': 
				result[i * 4] = 1;
				result[i * 4 + 3] = 1;
				break;
			case 'a': 
				result[i * 4] = 1;
				result[i * 4 + 2] = 1;
				break;
			case 'b': 
				result[i * 4] = 1;
				result[i * 4 + 2] = 1;
				result[i * 4 + 3] = 1;
				break;
			case 'c': 
				result[i * 4] = 1;
				result[i * 4 + 1] = 1;
				break;
			case 'd': 
				result[i * 4] = 1;
				result[i * 4 + 1] = 1;
				result[i * 4 + 3] = 1;
				break;
			case 'e': 
				result[i * 4] = 1;
				result[i * 4 + 1] = 1;
				result[i * 4 + 2] = 1;
				break;
			case 'f': 
				result[i * 4] = 1;
				result[i * 4 + 1] = 1;
				result[i * 4 + 2] = 1;
				result[i * 4 + 3] = 1;
				break;
			default:
				result[i * 4] = rand()%2;
				result[i * 4 + 1] = rand() % 2;
				result[i * 4 + 2] = rand() % 2;
				result[i * 4 + 3] = rand() % 2;
			}
		}

		return result;
	}
	short** Convert16To2(string* number, int length)
	{
		short** result = new short*[length] {0};


		for (int i = 0; i < length; ++i)
		{
			result[i] = Convert16To2(number[i], number[i].length() * 4);
		}

		return result;
	}
	void ConvertTextToHash(string* text, int length)
	{
		for (int i = 0; i < length; ++i)
		{
			text[i] = Convert2To16(StringToBit(text[i], text[i].length() * 8));
		}
	}
	void ConvertHashToText(string* text, int length)
	{
		for (int i = 0; i < length; ++i)
		{
			text[i] = BitToString(Convert16To2(text[i], text[i].length() * 4));
		}
	}
	
		//второсортные вспомогательные функции
	int Pow(int x, int y)
	{
		if (y == 0)
			return 1;

		int result = 1;

		for (int i = 0; i < y; ++i)
		{
			result *= x;
		}

		return result;
	}
	int FindLastChar(string text, char x)
	{
		for (int i = text.length()-1; i > -1; --i)
		{
			if (text[i] == x)
				return i;
		}

		return 0;
	}
	string CopyLastPartString(string* text,int length, int lengthpart)
	{
		string Preresult;

		if (text[length - 1].length() >= 64)
			Preresult = text[length - 1];
		else if (text[length - 1].length() + text[length - 2].length() >= 64)
			Preresult = text[length - 2] + text[length - 1];
		else
			Preresult = text[length - 3] + text[length - 2] + text[length-1];

		string result;
		result.resize(64);

		for (int i = 0; i < 64; ++i)
		{
			result[i] = Preresult[Preresult.length() - 64 + i];
		}

		return result;
	}
	void DeleteLastChars(string* text, int &length, int countChar)
	{
		while (length > -1 && countChar > 0)
		{
			
			if (text[length - 1].length() >= countChar)
			{
				text[length - 1].resize(text[length - 1].length() - countChar);
				countChar = 0;
			}
			else
			{
				countChar -= text[length - 1].length();
				text[length - 1] = "";
				length--;
			}
		}
	}
	void DeleteGarbage(short*** arr)
	{
		for (int i = 0; i < _msize(arr) / sizeof(arr[0]); ++i)
		{
			for (int j = 0; j < _msize(arr[i]) / sizeof(arr[i][0]); ++j)
			{
				delete[] arr[i][j];
			}

			delete[] arr[i];
		}

		delete[] arr;
	}
	bool CheckHashValue(string hash)
	{
		for (int i = 0; i < hash.length(); ++i)
		{
			int _buf = (int)hash[i];
			if ((_buf > 47 && _buf < 58) || (_buf > 96 && _buf < 103))
				continue;
			else
				return false;
		}

		return true;
	}
	void CheckCorrectWayLengthKey(string &way, int &lengthKey)
	{
		while (true)
		{
			cout << "Введите путь нужного txt файла" << endl;
			cin >> way;
			ifstream file(way);
			if (file.is_open())
			{
				file.close();
				break;
			}
			else
			{
				cout << "Неверный путь к файлу, введите заново. Пример правильного пути файла: C:\\Users\\Users\\Desktop\\text.txt" << endl;
			}
		}

		string _buf;
		while (true)
		{
			cout << "Введите длину ключа шифрования 128, 64 или 32 байта соответсвенно." << endl;
			cin >> _buf;
			if (_buf == "128" || _buf == "64" || _buf == "32")
			{
				lengthKey = atoi(_buf.c_str());
				break;
			}
			else
			{
				cout << "Неверная длинна. Введите заново" << endl;
			}

		}
	}
}
