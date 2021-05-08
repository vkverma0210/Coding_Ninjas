/* Alice and Bob need to send secret messages to each other and are discussing ways to encode their messages:
Alice: “Let’s just use a very simple code: 
We’ll assign ‘A’ the code word 1, ‘B’ will be 2, and so on down to ‘Z’ being assigned 26.”

Bob: “That’s a stupid code, Alice. 
Suppose I send you the word ‘BEAN’ encoded as 25114. 
You could decode that in many different ways!”

Alice: “Sure you could, but what words would you get? 
Other than ‘BEAN’, you’d get ‘BEAAD’, ‘YAAD’, ‘YAN’, ‘YKD’ and ‘BEKD’. 
I think you would be able to figure out the correct decoding. 
And why would you send me the word ‘BEAN’ anyway?”

Bob: “OK, maybe that’s a bad example, 
but I bet you that if you got a string of length 5000 there would be tons of different decodings 
and with that many you would find at least two different ones that would make sense.”

Alice: “How many different decodings?”

Bob: “Jillions!”
For some reason, Alice is still unconvinced by Bob’s argument, 
so she requires a program that will determine how many decodings there can be for a given string using her code. */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll m = 1000000007;

ll alpha_code(ll num_arr[], ll size)
{
    ll *output = new ll[size + 1]{};

    output[0] = 1;

    if (num_arr[0] * 10 + num_arr[1] <= 26)
    {
        if (num_arr[1] == 0)
        {
            output[1] = 1;
        }
        else
        {
            output[1] = 2;
        }
    }
    else
    {
        if (num_arr[1] == 0)
        {
            output[1] = 0;
        }
        else
        {
            output[1] = 1;
        }
    }

    for (int i = 2; i < size; i++)
    {
        if (num_arr[i] != 0)
        {
            output[i] = output[i - 1] % m;
        }
        if (num_arr[i - 1] * 10 + num_arr[i] <= 26 && num_arr[i - 1] != 0)
        {
            output[i] = output[i] % m + output[i - 2] % m;
        }
    }

    ll ans = output[size - 1];
    delete output;
    return ans;
}

int main()
{

    while (1)
    {
        string n;
        cin >> n;

        if (n == "0")
        {
            return 0;
        }

        ll *num_arr = new ll[n.size() + 1];
        for (int i = 0; i < n.size(); i++)
        {
            num_arr[i] = n[i] - '0';
        }

        cout << alpha_code(num_arr, n.size()) % m << endl;
    }

    return 0;
}
