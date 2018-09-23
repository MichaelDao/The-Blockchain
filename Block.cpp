//
// Created by salad on 9/23/18.
//

#include "Block.h"
#include "sha256.h"

Block::Block(uint32_t nIndexIn, const string &sDataIn) : _nIndex(nIndexIn)
                                                         , _sData(sDataIn)
{
    _nNonce = -1;
    //set to current time
    _tTime = time(nullptr);
}

string Block::GetHash()
{
    return _sHash;
}

// lets make this rewarding for miners
void Block::MineBlock(uint32_t nDifficulty)
{
    // create array of characters with length greater than nDifficulty
    char cstr[nDifficulty + 1];

    // fill array with 0's
    for (uint32_t i = 0; i < nDifficulty; i++)
    {
        cstr[i] = '0';
    }

    // yeet on a terminator
    cstr[nDifficulty] = '\0';

    string str(cstr);

    // keep looping until a match is found when the hash is calculated
    do
    {
        _nNonce++;
        _sHash = _CalculateHash();

    } while (_sHash.substr(0, nDifficulty) != str);

    // send message to output buffer that block has been mined
    cout << "Block mined: " << _sHash << endl;
}

inline string Block::_CalculateHash() const
{
    stringstream ss;
    ss << _nIndex << sPreviousHash << _tTime << _sData << _nNonce;

    return sha256(ss.str());
}