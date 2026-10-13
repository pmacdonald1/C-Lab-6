/**
 * @file Lab6_pmacdonald1.cpp
 * @author Phillip Macdonald
 * @date 2026-12-10
 * @brief Compare static arrays and vectors for processing student scores
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

float calculateAverage(const int arr[], int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return static_cast<float>(sum) / size;
}


int findMax(const int arr[], int size)
{
    int highest = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > highest)
        {
            highest = arr[i];
        }
    }

    return highest;
}

int findMin(const int arr[], int size)
{
    int lowest = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] < lowest)
        {
            lowest = arr[i];
        }
    }

    return lowest;
}

float calculateAverage(const vector<int>& vec)
{
    int sum = 0;

    for (int score: vec)
    {
        sum += score;
    }

    return static_cast<float>(sum) / vec.size();
}

int findMax(const vector<int>& vec)
{
    return *max_element(vec.begin(), vec.end());
}

int findMin(const vector<int>& vec)
{
    return *min_element(vec.begin(), vec.end());
}

void arraySolution()
{
    const int SIZE = 10;
    int scores[SIZE];
    int count = 0;
    int score;

    cout << "=== Static Array Solution ===" << endl;
    cout << "Enter 10 test scores between 0 and 100." << endl;

    while (count < SIZE)
    {
        cout << "Enter score " << count + 1 << ": ";

        while (!(cin >> score))
        {
            cout << "Invalid input. Please enter an integer." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Enter score " << count + 1 << ": ";
            
        }

        while (score < 0 || score > 100)
        {
            cout << "Score must be between 0 and 100." << endl;
            cout << "Enter score " << count + 1 << ": ";
            cin >> score;
        }

        scores[count] = score;
        count++;
    }

    cout << endl << "Array Statistics:" << endl;
    cout << "Average score: " << calculateAverage(scores, count) << endl;
    cout << "Highest score: " << findMax(scores, count) << endl;
    cout << "Lowest score: " << findMin(scores, count) << endl;
}

void vectorSolution()
{
    vector<int> scores;
    int score;

    cout << endl << "=== Dynamic Vector Solution ===" << endl;
    cout << "Enter test scores between 0 and 100." << endl;
    cout << "Enter -1 when you are finished." << endl;

    while (true)
    {
        cout << "Enter a score: ";

        while (!(cin >> score))
        {
            cout << "Invalid input. Please enter an integer." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Enter a score: ";
        }

        if (score == -1)
        {
            break;
        }

        if (score < 0 || score > 100)
        {
            cout << "Score must be between 0 and 100, or -1 to finish." << endl;
            cout << "Enter a score: ";
            cin >> score;
        }

        scores.push_back(score);
    }

    if (scores.empty())
    {
        cout << endl << "No scores were entered." << endl;
        return;
    }

    cout << endl << "Vector Statistics:" << endl;
    cout << "Average score: " << calculateAverage(scores) << endl;
    cout << "Highest score: " << findMax(scores) << endl;
    cout << "Lowest score: " << findMin(scores) << endl;

    sort(scores.begin(), scores.end());

    cout << "Sorted scores: ";

    for (int s: scores)
    {
        cout << s << " ";
    }

    cout << endl;
}

int main()
{
    arraySolution();
    vectorSolution();

    return 0;
}