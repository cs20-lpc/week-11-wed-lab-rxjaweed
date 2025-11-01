template <typename T>
int HashTableClosed<T>::insert(const T& key)
{
    int probes = 0;

    for (int i = 0; i < M; ++i)
    {
        int index = probeIndex(key,i);
        probes++;

        if (!occupied[index])
        {
            table[index] = key;
            occupied[index] = true;
            N++;
            return probes;
        }

        if (table[index] == key)
        {
            return probes;
        }
        return probes;
    }
    return probes;
}

template <typename T>
pair<bool, int> HashTableClosed<T>::search(const T& key) const
{
   int probes = 0;

    for (int i = 0; i < M; ++i) {
        int index = probeIndex(key, i);
        probes++;

        // Empty slot = key not found
        if (!occupied[index])
            return {false, probes};

        // Found the key
        if (table[index] == key)
            return {true, probes};
    }

    // Not found after full table scan
    return {false, probes};
}
