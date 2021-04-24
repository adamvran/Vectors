#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
void bubbleSort(vector<int> &vec, int N)
{
    for (int i = 0; i < N-1; i++)
        for (int j = 0; j < N-i-1; j++)
            if (vec[j] < vec[j+1])
            {
                auto tmp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = tmp;
            }
}
void print(const vector<int>& vec)
{
    for (auto element : vec)
    {
        cout << element << "\t";
    }
    cout <<endl;
    cout <<endl;
}
bool isSortedDesc(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        if (vec[i] < vec[i+1])
            return false;
    }
    return true;
}
int main()
{
    vector<int> vec;
    vector<int>origVec;
    int N = 50000;
    time_t startTime, endTime;

    srand(time(nullptr));

    for (int i = 0; i < N; ++i)
        vec.push_back(rand() % N);

    origVec = vec;
    startTime = time(nullptr);
    bubbleSort(vec, N);
    endTime = time(nullptr);
    cout << boolalpha << isSortedDesc(vec) << endl;
    cout << "Elapsed time: " << endTime - startTime << "s" << endl;

    vec = origVec;
    for (int i = 1; i < N; ++i)
    {
        int j = i;
        int tmp = vec[i];
        while (j > 0 && vec[j-1] > tmp)
        {
            vec[j] = vec[j-1];
            j--;
        }
        vec[j] = tmp;
    }
    return 0;
}