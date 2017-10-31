#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>

#include <assert.h>

using namespace std;

void print(const vector<int> &vec)
{
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
}

vector<int> selectBySorting(const vector<int>& input, int from, int to)
{
    assert(0 <= from && from < input.size());
    assert(0 <= to && to < input.size());
    assert(from <= to);

    vector<int> tmp(input);
    sort(tmp.begin(), tmp.end());
    return vector<int>(tmp.begin() + from, tmp.begin() + to + 1);
}

vector<int> selectNthElement(const vector<int>& input, int from, int to)
{
    assert(0 <= from && from < input.size());
    assert(0 <= to && to < input.size());
    assert(from <= to);

    vector<int> tmp(input);
    nth_element(tmp.begin(), tmp.begin() + to + 1, tmp.end());
    nth_element(tmp.begin(), tmp.begin() + from, tmp.begin() + to + 1);
    sort(tmp.begin() + from, tmp.begin() + to + 1);
    return vector<int>(tmp.begin() + from, tmp.begin() + to + 1);
}


vector<int> selectByPartialSort(const vector<int>& input, int from, int to)
{
    assert(0 <= from && from < input.size());
    assert(0 <= to && to < input.size());
    assert(from <= to);
    
    vector<int> temp(input);
    nth_element(temp.begin(), temp.begin() + from, temp.end());
    partial_sort(temp.begin() + from, temp.begin() + to + 1, temp.end());
    return vector<int>(temp.begin() + from, temp.begin() + to + 1);
}


int main()
{
    vector<int> input;
    for (int i = 0; i < 100; i++)
        input.push_back(i);

    random_shuffle(input.begin(), input.end());
    print(input);
    print(selectBySorting(input, 5, 10));
    print(selectNthElement(input, 5, 10));
    print(selectByPartialSort(input, 5, 10));

    return 0;
}
