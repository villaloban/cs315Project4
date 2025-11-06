//
// Created by Anthony Villalobos on 11/3/25.
//

#ifndef HUFFMANTREE_HPP
#define HUFFMANTREE_HPP
#include "TreeNode.hpp"
#include <vector>
#include <string>
#include <iostream>
class HuffmanTree {
public:
    HuffmanTree() = default;
    ~HuffmanTree();
    bool buildFromHeader(const std::vector<std::pair<std::string, std::string>>& header);
    bool decode(std::istream& codeBits, std::ostream& os);



private:
    TreeNode* root_ = nullptr;


    static void destroy(TreeNode* node) noexcept;


};


#endif //HUFFMANTREE_HPP
