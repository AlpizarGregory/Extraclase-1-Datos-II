#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>

using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::ostringstream;
using std::istringstream;

string readFileIntoString(const string& path) {
    auto ss = ostringstream{};
    ifstream input_file(path);
    if (!input_file.is_open()) {
        cerr << "Could not open files - '"
             << path << "'" << endl;
        exit(EXIT_FAILURE);
    }
    ss << input_file.rdbuf();
    return ss.str();
}

int main() {
    string filename("D:\\OneDrive - Estudiantes ITCR\\TEC\\2021 II Semestre\\Algoritmos y Estructuras de Datos II\\Extraclase 1\\Extraclase-1-Datos-II\\enteros.csv");
    string file_contents;
    std::map<int, std::vector<string>> csv_contents;
    char delimiter = ',';

    file_contents = readFileIntoString(filename);

    istringstream sstream(file_contents);
    std::vector<string> items;
    string record;

    int counter = 0;
    while (std::getline(sstream, record)) {
        istringstream line(record);
        cout << record << endl;

        csv_contents[counter] = items;
        items.clear();
        counter += 1;
    }

    exit(EXIT_SUCCESS);
}
