#pragma once
#include "HashTableClosed.hpp"

template <typename T>
class LinearProbing : public HashTableClosed<T> {
private:
    int skip; // skip factor
public:
    LinearProbing(int size = 101, int skipFactor = 3)
        : HashTableClosed<T>(size), skip(skipFactor) {}

    
    int probeIndex(const T& key, int i) const override {
        int base = this->hash1(key);
        return (base + (i*skip)) % this->M;
    }
};
