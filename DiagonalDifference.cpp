#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'diagonalDifference' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

int diagonalDifference(vector<vector<int>> arr)
{
    size_t arr_size = arr.size() - 1;
    
    int left_diagonal_sum = 0;
    int right_diagonal_sum = 0;
    
    for (size_t i = 0; i <= arr_size; ++i)
    {
        left_diagonal_sum += arr[i][i];
        right_diagonal_sum += arr[i][arr_size-i];
    }
    
    return std::abs(left_diagonal_sum - right_diagonal_sum);
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i].resize(n);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int arr_row_item = stoi(arr_row_temp[j]);

            arr[i][j] = arr_row_item;
        }
    }

    int result = diagonalDifference(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);
    s.erase(
        s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) { return !isspace(ch); })
    );
    return s;
}

string rtrim(const string &str)
{
    string s(str);
    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !isspace(ch); }).base(), s.end()
    );
    return s;
}

std::vector<string> split(const string &str) {
    vector<string> tokens;
    string_view str_view(str);

    size_t start = 0;
    size_t end = 0;

    while ((end = str_view.find(' ', start)) != string_view::npos) {
        if (end > start) {
            tokens.emplace_back(str_view.substr(start, end - start));
        }
        start = end + 1;
    }

    if (start < str_view.size()) {
        tokens.emplace_back(str_view.substr(start));
    }

    return tokens;
}
