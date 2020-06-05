//Отсортировать строки по количеству слов, содержащих цифры
#include <iostream>
#include <cmath>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
int main()
{
	char s[20];

	std::ifstream ifs("test_numbers.txt");
	std::ofstream ofs("2.txt");
	if (ifs && ofs)
	{
		for (std::size_t i = 0; std::getline(s, 20, " "); ++i)
		{
			if (i % 2 == 0) {
				ofs << atoi(s) / 2 << '\n';
			}
			else {
				ofs << atoi(s) * 3 + 1 << '\n';
			}

		}
	}
	else std::cerr << "Can't open file\n";
	ifs.close();
	ofs.close();
	return 0;

}
