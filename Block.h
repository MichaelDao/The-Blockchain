//
// Created by salad on 9/23/18.
//

#ifndef BLOCKCHAIN_BLOCK_H
#define BLOCKCHAIN_BLOCK_H

#include <cstdint>
#include <iostream>
#include <sstream>


using namespace std;

class Block
{
public:
    string sPreviousHash;

    // constructor takes paremeters index and data
    Block(uint32_t nIndexIn, const string &sDataIn);

    // method signature specified
    string GetHash();

    // take in paremeter difficulty
    void MineBlock(uint32_t nDifficulty);

private:
    // all my private declarations
    uint32_t _nIndex;
    int64_t _nNonce;
    string _sData;
    string _sHash;
    time_t _tTime;

    // ensure hash cant be changed
    string _CalculateHash() const;

};


#endif //BLOCKCHAIN_BLOCK_H
