#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void random(double* mas, int size, double min, double max, int i) {
    if (i < size) {
        mas[i] = min + static_cast<double>(rand()) * (max - min) / RAND_MAX;
        random(mas, size, min, max, i + 1);
    }
}

void wivid(const double* mas, int size, int i) {
    if (i < size) {
        cout << setw(6) << mas[i];
        wivid(mas, size, i + 1);
    }
    else {
        cout << endl;
    }
}

int countPositive(const double* mas, int size, int i) {
    if (i >= size) return 0; 
    return (mas[i] > 0 ? 1 : 0) + countPositive(mas, size, i + 1); 
}

double sumAfterLastZero(const double* mas, int size, int i, bool& foundZero) {
    if (i >= size) return 0; 
    if (mas[i] == 0) foundZero = true; 

    if (foundZero) {
        return mas[i] + sumAfterLastZero(mas, size, i + 1, foundZero); 
    }

    return sumAfterLastZero(mas, size, i + 1, foundZero); 
}

void rearrange(double* mas, int size, int i, int& count) {
    if (i >= size) return; 

    if (static_cast<int>(mas[i]) <= 1) {
     
        swap(mas[i], mas[count]);
        count++;
    }
    rearrange(mas, size, i + 1, count); 
}

int main() {
    cout << fixed;
    cout.precision(2);
    srand(static_cast<unsigned>(time(NULL)));

    int n;
    cout << "n = ";
    cin >> n;

    double* b = new double[n];
    random(b, n, -5.0, 5.0, 0); 

    cout << "Massive :" << endl;
    wivid(b, n, 0); 

    int positiveCount = countPositive(b, n, 0);
    cout << "Count of positive elements = " << positiveCount << endl;

    bool foundZero = false;
    double sum = sumAfterLastZero(b, n, 0, foundZero);
    cout << "Sum after last zero = " << sum << endl;

    int count = 0; 
    rearrange(b, n, 0, count);

    cout << "Modified massive : " << endl;
    wivid(b, n, 0); 

    delete[] b; 
    return 0;
}
