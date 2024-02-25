#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> parts(n);

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        istringstream iss(s);
        string part;

        while (getline(iss, part, '.'))
        {
            parts[i].push_back(stoi(part));
        }
    }

    if (n == 1)
    {
        cout << parts[0][0] << "." << parts[0][1] << "." << parts[0][2] << "." << parts[0][3];
        cout << "\n255.255.255.255";
    }
    else
    {
        int pos = 4;
        int index;

        for (int i = 0; i < 4; i++)
        {
            bool find_pos = false;
            for (int j = 0; j < n - 1; j++)
            {
                if (parts[j][i] != parts[j + 1][i])
                {
                    find_pos = true;
                    break;
                }
            }

            if (find_pos)
            {
                pos = i;
                break;
            }
        }

        if (pos == 4)
        {
            cout << parts[0][0] << "." << parts[0][1] << "." << parts[0][2] << "." << parts[0][3];
            cout << "\n255.255.255.255";
        }
        else
        {
            for (int j = 7; j >= 0; j--)
            {
                bool find_index = false;

                for (int i = 0; i < n - 1; i++)
                {
                    if ((parts[i][pos] & (1 << j)) != (parts[i + 1][pos] & (1 << j)))
                    {
                        find_index = true;
                        break;
                    }
                }
                if (find_index)
                {
                    index = j;
                    break;
                }
            }

            for (int i = 0; i < pos; i++)
            {
                cout << parts[0][i] << ".";
            }

            bitset<8> num(parts[0][pos]);

            for (int i = index; i >= 0; i--)
            {
                num[i] = 0;
            }

            cout << num.to_ulong();

            if (pos != 3)
            {
                cout << ".";
            }

            for (int i = pos + 1; i < 4; i++)
            {
                cout << 0;

                if (i != 3)
                {
                    cout << ".";
                }
            }

            cout << "\n";

            for (int i = 0; i < pos; i++)
            {
                cout << 255 << ".";
            }

            bitset<8> num2(parts[0][pos]);
            num2.set();

            for (int i = index; i >= 0; i--)
            {
                num2[i] = 0;
            }

            cout << num2.to_ulong();

            if (pos != 3)
            {
                cout << ".";
            }

            for (int i = pos + 1; i < 4; i++)
            {
                cout << 0;
                if (i != 3)
                {
                    cout << ".";
                }
            }
        }
    }

    return 0;
}
