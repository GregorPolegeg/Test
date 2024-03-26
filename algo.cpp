#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Counting sort za sortiranje po bitih
void countingSort(vector<unsigned char>& arr, int exp) {

}

// Binarni Radix sort
void binaryRadixSort(vector<unsigned char>& arr) {

}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Uporaba: " << argv[0] << " <vhodna_datoteka>" << endl;
        return 1;
    }

    ifstream inputFile(argv[1]);
    if (!inputFile) {
        cerr << "Napaka pri odpiranju vhodne datoteke." << endl;
        return 1;
    }

}
