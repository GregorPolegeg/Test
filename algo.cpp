#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Counting sort za sortiranje po bitih
void countingSort(vector<unsigned char>& arr, int exp) {

}

// Binarni Radix sort
void binaryRadixSort(vector<unsigned char>& arr) {
    // Največji element
    unsigned char max = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    // Število bitov za največji element
    int bits = 8; // Ker so števila 8-bitna

    // Izvajanje counting sorta za vsak bit
    for (int exp = 0; exp < bits; exp++)
        countingSort(arr, exp);
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

    vector<unsigned char> numbers;
    unsigned char num;
    while (inputFile >> num)
        numbers.push_back(num);
    
    inputFile.close();

    // Sortiranje
    binaryRadixSort(numbers);

    // Izpis sortiranih števil v izhodno datoteko out.txt
    ofstream outputFile("out.txt");
    if (!outputFile) {
        cerr << "Napaka pri ustvarjanju izhodne datoteke." << endl;
        return 1;
    }

    for (int i = 0; i < numbers.size(); i++)
        outputFile << static_cast<int>(numbers[i]) << " ";

    outputFile.close();

    cout << "Sortiranje uspešno zaključeno. Rezultat zapisan v out.txt." << endl;

    return 0;
}
