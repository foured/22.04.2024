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
void z7();

int main() {
	z7();	
	return 0;
}

void z1() {
	std::cout << "z1: " << std::endl;
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
	std::cout << std::endl;
}
void z6() {
	std::cout << "z6: " << std::endl;
	int res = 0;
	for (int i = 2; i <= 300; i++) {
		int dels = 0;
		for (int j = 1; j < i; j++) {
			if (i % j == 0) dels++;
		}
		if (dels == 5) res++;
	}
	std::cout << res << std::endl;
	std::cout << std::endl;
}
void z5() {
	std::cout << "z5: " << std::endl;

	std::vector<int> marks;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(2, 5);
	std::cout << "(note: used random to generate marks)" << std::endl;

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
	std::cout << std::endl;

}
void z8() {
	std::cout << "z8: " << std::endl;

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
	std::cout << std::endl;
}
void z4() {
	std::cout << "z4: " << std::endl;

	std::vector<std::string> cards = { "6", "7", "8", "9", "10", "valet", "dama", "korol", "tyz" };

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, cards.size() - 1);
	
	std::cout << "(note: used random to choose card)" << std::endl;
	std::cout << cards[dis(gen)] << std::endl;
	std::cout << std::endl;
}
void z9() {
	std::cout << "z9: " << std::endl;
	std::string link;
	std::cout << "Enter link: " << std::endl;
	std::cin >> link;

	//https://ya.ru/maps?x=0.0001&y=51.77&city=Moscow

	std::string protocol, host, end_point, args;
	bool has_found_host = false, is_first_arg = true;
	std::string current_part = "";
	for (int i = 0; i < link.size(); i++) {
		char c = link[i];
		if (c == ':') {
			protocol = current_part;
			current_part = "";
			i += 2;
		}
		else if (c == '/' && !has_found_host) {
			host = current_part;
			current_part = "/";
			has_found_host = true;
		}
		else if (c == '?') {
			end_point = current_part;
			current_part = "";
		}
		else if (c == '&') {
			args += current_part + "; ";
			current_part = "";

			if (is_first_arg) {
				is_first_arg = false;
				link += '&';
			}
		}
		else {
			current_part += c;
		}
	}

	if (protocol.back() == 's') protocol += " (secure)";

	std::cout << "Protocol: " << protocol << std::endl;
	std::cout << "Host: " << host << std::endl;
	std::cout << "End point: " << end_point << std::endl;
	std::cout << "Args: " << args << std::endl;
	std::cout << std::endl;
}
void z7() {
	std::cout << "z7: " << std::endl;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 5);

	std::vector<std::pair<int, int>> data = {
		{dis(gen), dis(gen)},
		{dis(gen), dis(gen)},
		{dis(gen), dis(gen)},
		{dis(gen), dis(gen)},
		{dis(gen), dis(gen)},
		{dis(gen), dis(gen)},
		{dis(gen), dis(gen)},
		{dis(gen), dis(gen)},
		{dis(gen), dis(gen)},
		{dis(gen), dis(gen)}
	};

	std::cout << "(note: used random to gen data in z7)" << std::endl;
	int sum = 0, gectars = 0;
	for (int i = 0; i < data.size(); i++) {
		std::pair<int, int> p = data[i];
		sum += p.first * p.second;
		gectars += p.first;
		std::cout << "Area_" << i << ": amount of harvest: " << p.first * p.second << " hundredweight (" << 
			p.first << " hectares, " << p.second << " hundredweight per hectare)" << std::endl;
	}

	std::cout << "Average amount of harvest: " << sum  << " hundredweight" << std::endl;
	std::cout << "Average yield: " << sum / (float)gectars << " hundredweight per hectare" << std::endl;

	std::cout << std::endl;
}
