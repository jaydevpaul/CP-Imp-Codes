
//-------------------------------------********X********------------------------------------------------

struct Node
{
    int childReferences[26];
    int stringEndingHere;
    int stringEndingBelow;

    Node()
    {
        for (int i = 0; i < 26; i++)
        {
            childReferences[i] = -1;
        }

        stringEndingHere = 0;
        stringEndingBelow = 0;
    }

    bool canDeleteNode()
    {
        if (stringEndingHere > 0)
        {
            return false;
        }
        for (int i = 0; i < 26; i++)
        {
            if (childReferences[i] != -1)
            {
                return false;
            }
        }
        return true;
    }
};

struct Trie
{
    int root;
    vector<Node> nodes;

    Trie()
    {
        root = 0;
        nodes.push_back(Node());
    }

    void precomputeSpecialStringsBelow(int current)
    {
        nodes[current].stringEndingBelow = nodes[current].stringEndingHere;

        for (int i = 0; i < 26; i++)
        {
            if (nodes[current].childReferences[i] != -1)
            {
                nodes[current].stringEndingBelow += nodes[nodes[current].childReferences[i]].stringEndingBelow;
            }
        }
    }

    void addRecursively(string &a, int currentNode, int index)
    {
        if (index == a.size())
        {
            nodes[currentNode].stringEndingHere++;
            precomputeSpecialStringsBelow(currentNode);
            return;
        }

        int child=nodes[currentNode].childReferences[a[index]-'a'];

        if (child==-1)
        {
            nodes[currentNode].childReferences[a[index]-'a']=nodes.size();
            nodes.push_back(Node());
            child=nodes[currentNode].childReferences[a[index]-'a'];
        }
        addRecursively(a,child,index+1);
        precomputeSpecialStringsBelow(currentNode);
        
    }

    void addString(string a)
    {
        addRecursively(a, root, 0);
    }

    int searchString(string a)
    {
        int currentNode = root;

        for (auto ch : a)
        {
            if (nodes[currentNode].childReferences[ch - 'a'] == -1)
            {
                return 0;
            }
            currentNode = nodes[currentNode].childReferences[ch - 'a'];
        }

        return nodes[currentNode].stringEndingHere ;
    }


    int commonPrefixes(string a)
    {
        int currentNode = root;

        for (auto ch : a)
        {
            if (nodes[currentNode].childReferences[ch - 'a'] == -1)
            {
                return 0;
            }
            currentNode = nodes[currentNode].childReferences[ch - 'a'];
        }
        return nodes[currentNode].stringEndingBelow;
    }


};

