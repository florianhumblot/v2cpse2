#include "iostream"
#include "fstream"
#include "iterator"
#include "vector"
#include "algorithm"
#include "cctype"
#include "map"
#include "set"
#include <functional>
#include <cstring>


int main() {
	printf("\nStarting Week 4\n");
	auto filename = "bible.txt";
	std::ifstream in(filename, std::ios::in | std::ios::binary);
	if (!in) {
		std::cerr << "Couldn't open " << filename << std::endl;
		return -1;
	}
	std::vector<char> characters(std::istreambuf_iterator<char>(in), (std::istreambuf_iterator<char>()));
	printf("The bible contains %lu characters.\n", characters.size());
	printf("The bible has %li lines.\n", std::count(characters.begin(), characters.end(), '\n'));
	printf("The bible contains %li alphanumeric characters.\n", std::count_if(
			characters.begin(),
			characters.end(),
			isalnum
	));
	std::transform(characters.begin(), characters.end(), characters.begin(), ::tolower);

	std::map<char, int> letter_count;
	for (auto &c : characters) {
		if (isalnum(c)) {
			if (letter_count.count(c) == 0) {
				letter_count[c] = 0;
			}
			letter_count[c] += 1;
		}
	}
	printf("Occurences of letters alphabetically: \n");
	for (auto element : letter_count) {
		printf("%c occured %d times\n", element.first, element.second);
	}
	typedef std::function<bool(std::pair<char, int>, std::pair<char, int>)> Comparator;
	Comparator compare = [](std::pair<char, int> elem1, std::pair<char, int> elem2) {
		return elem1.second > elem2.second;
	};
	std::set<std::pair<char, int>, Comparator> sorted_letter_count(letter_count.begin(), letter_count.end(), compare);
	printf("\n\n\n");
	printf("Occurences of letters in descending order: \n");
	for (auto element : sorted_letter_count) {
		printf("%c occured %d times\n", element.first, element.second);
	}

	std::string s;
	std::map<std::string, int> wordOccurences;
	for (auto c: characters) {
		if (c == ' ') {
			if (wordOccurences.count(s) == 0) {
				wordOccurences[s] = 0;
			}
			wordOccurences[s] += 1;
			s = "";
		} else if(isalnum(c)){
			s += c;
		}
	}
	printf("%lu words", wordOccurences.size());
	printf("%lu characters",characters.size());

	std::vector<std::pair<std::string, int>> top_ten_words(10);
	std::partial_sort_copy(wordOccurences.begin(),
						   wordOccurences.end(),
						   top_ten_words.begin(),
						   top_ten_words.end(),
						   [](std::pair<const std::string, int> const &l,
							  std::pair<const std::string, int> const &r) {
							   return l.second > r.second;
						   });

	printf("\n\n\nTop 10 words: \n");
	int i = 0;
	for (auto word : top_ten_words) {
		i++;
		printf("%d. '%s' appeared %d times\n", i, word.first.c_str(), word.second);
	}

}