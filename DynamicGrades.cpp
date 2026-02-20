#include <iostream>
#include <iomanip>


using namespace std;

void getScores(double* arr, int size)
{
    for (int i = 0; i < size; i++)
       {  cout << "Enter score " << i + 1 << ": ";
        cin >> arr[i];

        while (arr[i] < 0)
        {
        cout << "Score cannot be negative. Enter again: ";
            cin >> arr[i];
        }
    }
}

void sortScores(double* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

double calculateAverage(const double* arr, int size)
   {
    double sum = 0;

    for (int i = 0; i < size; i++)
      {
        sum += arr[i];
    }

    return sum / size;
}

int main()
{
    int size;

    cout << "How many test scores would you like to enter? ";
    cin >> size;

    if (size <= 0)
    {
        cout << "Invalid number of scores." << endl;
        return 0;
    }

    double* scores = new double[size];

    getScores(scores, size);

    sortScores(scores, size);

    double average = calculateAverage(scores, size);

    cout << fixed << setprecision(2);

    cout << "\nThe sorted scores are: ";
    for (int i = 0; i < size; i++)
    {
        cout << scores[i] << " ";
    }

    cout << "\nThe average score is: " << average << endl;

    delete [] scores;
    scores = nullptr;

    return 0;
}