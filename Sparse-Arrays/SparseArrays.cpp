/*
    Author: CBOMBS
    Date: July 17th, 2022

    HackerRank: Sparse Arrays

    match queries with strings

    string strings[n] - an array of strings to search
    string queries[q] - an array of query strings

    Example:

    Input:
    4       strings[n]
    aba
    baba
    aba
    xzxb
    3       queries[n]
    aba
    xzxb
    ab

    Output:
    2
    1
    0

    There are 2 instances of 'ab', 1 of 'abc' and 0 of 'bc'
    For each query, add an element to the return array, .
*/
#include <bits/stdc++.h>
#include <string.h>
#include <iostream>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

/*
 * Complete the 'matchingStrings' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY strings
 *  2. STRING_ARRAY queries
 */

vector<int> matchingStrings(vector<string> strings, vector<string> queries) {

    int count = 0;
    vector<int> matches;

    for (int q = 0; q < queries.size(); q++) {

        for (int s = 0; s < strings.size(); s++) {

            if (queries[q] == strings[s]) {

                count++;
            }
        }

        matches.push_back(count);
        count = 0;
    }

    return matches;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string strings_count_temp;
    getline(cin, strings_count_temp);

    int strings_count = stoi(ltrim(rtrim(strings_count_temp)));

    vector<string> strings(strings_count);

    for (int i = 0; i < strings_count; i++) {
        string strings_item;
        getline(cin, strings_item);

        strings[i] = strings_item;
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<string> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item;
        getline(cin, queries_item);

        queries[i] = queries_item;
    }

    vector<int> res = matchingStrings(strings, queries);

    for (size_t i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
