#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void countingSort(vector<unsigned char>& arr, int exp) {
    vector<unsigned char> output(arr.size());
    vector<int> count(2, 0);

    for (int i = 0; i < arr.size(); i++)
        count[(arr[i] >> exp) & 1]++;

    count[1] += count[0];

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[(arr[i] >> exp) & 1] - 1] = arr[i];
        count[(arr[i] >> exp) & 1]--;
    }

    for (int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}

void binaryRadixSort(vector<unsigned char>& arr) {
    unsigned char max = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    int bits = 8; 

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
