//
// Created by salad on 9/23/18.
//

#include "Blockchain.h"

Blockchain::Blockchain() {
    // blocks gotta start somewhere
    vectorChain.emplace_back(Block(0, "Genesis Block"));

    // making this easy by changing its numbers
    difficulty = 5;
}

void Blockchain::AddBlock(Block bNew)
{
    // look at previous blocks hash
    bNew.prevHash = GetLastBlock().GetHash();

    // mine a block based on difficulty
    bNew.MineBlock(difficulty);

    // complete procees of adding block to blockchain
    vectorChain.push_back(bNew);
}

Block Blockchain::GetLastBlock() const
{
    return vectorChain.back();
}