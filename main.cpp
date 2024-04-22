#include <iostream>
#include <string>
#include <vector>
#include <random>

void z1();
void z6();
void z5();
void z8();
void z4();
void z9();

int main() {
	z4();
	return 0;
}

void z1() {
	std::string full_fio;
	std::cout << "Enter fio: " << std::endl;
	std::cin >> full_fio;
	std::string res = "";
	int first_space = full_fio.size() - 1;
	for (int i = 0; i < full_fio.size(); i++) {
		char c = full_fio[i];
		if (c == ' ') {
			if (i != full_fio.size() - 1) {
				res.push_back(' ');
				res.push_back(full_fio[i + 1]);
				res.push_back('.');
				first_space = i;
			}
			break;
		}
		res += c;
	}
	for (int i = first_space + 1; i < full_fio.size(); i++) {
		char c = full_fio[i];
		if (c == ' ') {
			if (i != full_fio.size() - 1) {
				res.push_back(full_fio[i + 1]);
				res.push_back('.');
			}
			break;
		}
	}
	std::cout << res << std::endl;
}
void z6() {
	int res = 0;
	for (int i = 2; i <= 300; i++) {
		int dels = 0;
		for (int j = 1; j < i; j++) {
			if (i % j == 0) dels++;
		}
		if (dels == 5) res++;
	}
	std::cout << res << std::endl;
}
void z5() {
	std::vector<int> marks;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(2, 5);

	for (int i = 0; i < 23; i++) {
		marks.push_back(dis(gen));
	}

	int m5 = 0, m4 = 0, m3 = 0, m2 = 0;

	for (int i = 0; i < marks.size(); i++) {
		if (marks[i] == 5) m5++;
		if (marks[i] == 4) m4++;
		if (marks[i] == 3) m3++;
		if (marks[i] == 2) m2++;
	}

	std::cout << "5: " << m5 << std::endl;
	std::cout << "4: " << m4 << std::endl;
	std::cout << "3: " << m3 << std::endl;
	std::cout << "2: " << m2 << std::endl;
}
void z8() {
	int n;
	std::cout << "Enter number of monthes: " << std::endl;
	std::cin >> n;
	int monthes = n % 12;
	int years = (n - monthes) / 12;

	if (years == 0 && monthes > 0) {
		std::cout << "Monthes: " << monthes << std::endl;
	}
	else if (years > 0 && monthes == 0) {
		std::cout << "Years: " << years << std::endl;
	}
	else if (years > 0 && monthes > 0) {
		std::cout << "Years: " << years << " Monthes: " << monthes << std::endl;
	}
	void z4();
}
void z4() {
	std::vector<std::string> kards = { "6", "7", "8", "9", "10", "valet", "dama", "korol", "tyz" };

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, kards.size() - 1);

	std::cout << kards[dis(gen)] << std::endl;
}
void z9() {
	std::string link;
	std::cout << "Enter link: " << std::endl;
	std::cin >> link;

	for (int i = 0; i < link.size(); i++) {
		char c = link[i];
	}
}
