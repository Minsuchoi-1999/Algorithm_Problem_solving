#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

unordered_map<string, bool> visited;

struct node
{
    string first;
    string second;
    string third;
    int count;
};

bool check_hanoi(string &hanoi, char target)
{
    if (hanoi.empty())
        return true;

    for (auto e : hanoi)
    {
        if (e != target)
        {
            return false;
        }
    }

    return true;
}

string hashing(string &first, string &second, string &third)
{
    return first + " " + second + " " + third;
}

int brute_force(struct node start)
{
    queue<struct node> q;

    q.push(start);

    while (q.size())
    {
        string first = q.front().first;
        string second = q.front().second;
        string third = q.front().third;
        int count = q.front().count;
        visited[hashing(first, second, third)] = 1;

        // cout << first << " " << second << " " << third << " " << count << "\n";

        q.pop();

        bool checkA = check_hanoi(first, 'A');
        bool checkB = check_hanoi(second, 'B');
        bool checkC = check_hanoi(third, 'C');

        if (checkA && checkB && checkC)
        {
            return count;
        }

        if (!checkA)
        {
            char last = first.back();

            string src = first;
            src.pop_back();

            string dest1 = second + last;
            string dest2 = third + last;

            if (!visited[hashing(src, dest1, third)])
            {
                visited[hashing(src, dest1, third)] = 1;
                q.push({src, dest1, third, count + 1});
            }
            if (!visited[hashing(src, second, dest2)])
            {
                visited[hashing(src, second, dest2)] = 1;
                q.push({src, second, dest2, count + 1});
            }
        }

        if (!checkB)
        {
            char last = second.back();

            string src = second;
            src.pop_back();

            string dest1 = first + last;
            string dest2 = third + last;

            if (!visited[hashing(dest1, src, third)])
            {
                visited[hashing(dest1, src, third)] = 1;
                q.push({dest1, src, third, count + 1});
            }
            if (!visited[hashing(first, src, dest2)])
            {
                visited[hashing(first, src, dest2)] = 1;
                q.push({first, src, dest2, count + 1});
            }
        }

        if (!checkC)
        {
            char last = third.back();

            string src = third;
            src.pop_back();

            string dest1 = first + last;
            string dest2 = second + last;

            if (!visited[hashing(dest1, second, src)])
            {
                visited[hashing(dest1, second, src)] =1;
                q.push({dest1, second, src, count + 1});
            }
            if (!visited[hashing(first, dest2, src)])
            {
                visited[hashing(first, dest2, src)] = 1;
                q.push({first, dest2, src, count + 1});
            }
        }
    }

    return -1;
}

int main()
{
    vector<string> hanoi(3);

    for (int i = 0; i < 3; i++)
    {
        int num;
        cin >> num;

        if (num == 0)
        {
            hanoi[i] = "";
        }
        else
        {
            string tower;
            cin >> tower;

            hanoi[i] = tower;
        }
    }

    cout << brute_force({hanoi[0], hanoi[1], hanoi[2], 0});
}
