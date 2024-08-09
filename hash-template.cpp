struct Hash
{

    const int Base1 = 5689;
    const int Base2 = 8861;

    vector<pair<int, int>> hashValue, Pow;

    Hash(string s)
    {
        hashValue.assign(s.size(), {0, 0});
        Pow.assign(s.size(), {1, 1});

        hashValue[0] = {s[0] - 'a' + 1, s[0] - 'a' + 1};

        for (int i = 1; i < s.size(); i++)
        {
            hashValue[i] = {
                (hashValue[i - 1].first * Base1 + (s[i] - 'a' + 1)) % MOD,
                (hashValue[i - 1].second * Base2 + (s[i] - 'a' + 1)) % MOD};

            Pow[i] = {
                (Pow[i - 1].first * Base1) % MOD,
                (Pow[i - 1].second * Base2) % MOD};
        }
    }


    pair<int,int> get(int l,int r)
    {
        int hash1=(hashValue[r].first-(hashValue[l-1].first * Pow[r-l+1].first)%MOD + MOD)%MOD;
        int hash2=(hashValue[r].second-(hashValue[l-1].second * Pow[r-l+1].second)%MOD + MOD)%MOD;

        return {hash1,hash2};
    }
};


