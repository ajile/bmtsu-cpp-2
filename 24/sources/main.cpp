#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

void replace(std::string& str,
               const std::string& oldStr,
               const std::string& newStr)
{
  std::string::size_type pos = 0u;
  while((pos = str.find(oldStr, pos)) != std::string::npos){
     str.replace(pos, oldStr.length(), newStr);
     pos += newStr.length();
  }
}

int main(void) {

	// const char *words[] = {
	// 	"the list of the word in accordance with exercise",
	// 	"the list of the word in accordance with exercise"
	// };

	string line;
	vector<string> lines;

	do {
		cout << "# Input line: ";
		getline(cin, line);
		if (line[0] != '\0') {
			lines.push_back(line);
		}
	} while (line[0] != '\0');

	cout << endl;

	cout << "# You input " << lines.size() << " elements" << endl;

	cout << endl;

  cout << "# Lines (before replacement):" << endl;
	for (int i = 0; i < lines.size(); ++i) {
		cout << "- " << lines[i] << endl;
		replace(lines[i], "ed", "ing");
	}

	cout << endl;

  cout << "# Lines (after replacement):" << endl;
	for (int i = 0; i < lines.size(); ++i) {
		cout << "- " << lines[i] << endl;
	}
  return 0;
}
