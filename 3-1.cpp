//Определить, сколько слов в строке начинается с прописной буквы. Вывести их на экран.
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	char str[] = "There are,Five Words/with !Capital letter ?in this Sentence.";
	char key[] = " .,!?/";
	int n = 0;

	for (int i = 0; i < strlen(str); i++)
	{
		for (int j = 0; j < strlen(key); j++)
		{
			if (str[i - 1] == key[j - 1])
				if ((str[i] >= 65) && (str[i] <= 90))
					n++;
		}
	}
	cout << n << endl;
}