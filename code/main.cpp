#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream myFile;
    myFile.open("D:\\\\OneDrive - Estudiantes ITCR\\\\TEC\\\\2021 II Semestre\\\\Algoritmos y Estructuras de Datos II\\\\Extraclase 1\\\\Extraclase-1-Datos-II\\data\\enteros.csv");

    while (myFile.good()) {
        string line;
        getline(myFile, line, ',');
        int intNum = atoi(line.c_str());
        cout << intNum << endl;
    }

    myFile.close();
}

// The working code is below

//#include <iostream>
//#include <sstream>
//#include <fstream>
//#include <vector>
//#include <map>
//
//using std::cout; using std::cerr;
//using std::endl; using std::string;
//using std::ifstream; using std::ostringstream;
//using std::istringstream;
//
//string readFileIntoString(const string& path) {
//    auto ss = ostringstream{};
//    ifstream input_file(path);
//    if (!input_file.is_open()) {
//        cerr << "Could not open file - '"
//             << path << "'" << endl;
//        exit(EXIT_FAILURE);
//    }
//    ss << input_file.rdbuf();
//    return ss.str();
//}
//
//int main() {
//    string filename("D:\\OneDrive - Estudiantes ITCR\\TEC\\2021 II Semestre\\Algoritmos y Estructuras de Datos II\\Extraclase 1\\Extraclase-1-Datos-II\\data\\enteros.csv");
//    string file_contents;
//    std::map<int, std::vector<string>> csv_contents;
//    char delimiter = ',';
//
//    file_contents = readFileIntoString(filename);
//
//    istringstream sstream(file_contents);
//    std::vector<string> items;
//    string record;
//
//    int counter = 0;
//    int index = 0;
//    int arr[256];
//    string num1;
//    //string num1, num2, num3, num4, num5, num6, num7;
//    while (std::getline(sstream, record)) {
//        istringstream line(record);
//
//        for (int i = 0; i < 7; ++i) {
//            std::getline(line, num1, delimiter);
//            int numb1 = atoi(num1.c_str());
//            arr[index] = numb1;
//            index++;
//        }
//
//
//       while(std::getline(line, record, delimiter)) {
//
//           items.push_back(record);
//
//       }
//
//
//        csv_contents[counter] = items;
//        items.clear();
//        counter += 1;
//    }
//
//    for (int i = 0; i < 28; ++i) {
//        cout << arr[i] << endl;
//    }
//
//    exit(EXIT_SUCCESS);
//}
