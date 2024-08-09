struct Hash
{

    const int Base1 = 5689;
    const int Base2 = 8861;

    vector<pair<int, int>> hashValue, Pow;

    Hash(string s)
    {
        hashValue.assign(s.size() + 1, {0, 0});
        Pow.assign(s.size() + 1, {1, 1});

        for (int i = 0; i < s.size(); i++)
        {
            hashValue[i + 1] = {
                (hashValue[i].first * Base1 + (s[i] - 'a' + 1)) % MOD,
                (hashValue[i].second * Base2 + (s[i] - 'a' + 1)) % MOD};

            Pow[i + 1] = {
                (Pow[i].first * Base1) % MOD,
                (Pow[i].second * Base2) % MOD};
        }
    }

    pair<int, int> get(int l, int r)
    {
        l++;
        r++;
        int hash1 = (hashValue[r].first - (hashValue[l - 1].first * Pow[r - l + 1].first) % MOD + MOD) % MOD;
        int hash2 = (hashValue[r].second - (hashValue[l - 1].second * Pow[r - l + 1].second) % MOD + MOD) % MOD;

        return {hash1, hash2};
    }
};
