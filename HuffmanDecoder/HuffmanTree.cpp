//
// Created by Anthony Villalobos on 11/3/25.
//

#include "HuffmanTree.hpp"

void HuffmanTree::destroy(TreeNode *node) noexcept {
    if (node == nullptr)
        return;
    destroy(node->leftSubtree());
    destroy(node->rightSubtree());
    delete node;
}

HuffmanTree::~HuffmanTree() {
    destroy(root_);
}

bool HuffmanTree::buildFromHeader(const std::vector<std::pair<std::string, std::string> > &header) {
    root_ = new TreeNode("");

    for (const auto & i : header) {
        std::string word = i.first;
        std::string code = i.second;

        TreeNode* curr = root_;

        for (char bits : code) {
            if (bits == '0') {
                if (curr->leftSubtree() == nullptr)
                    curr->leftSubtree(new TreeNode(""));
                curr = curr->leftSubtree();
            }
            else if (bits == '1') {
                if (curr->rightSubtree() == nullptr)
                    curr->rightSubtree(new TreeNode(""));
                curr = curr->rightSubtree();
            }
        }
        curr->value() = word;
    }
    return true;
}

bool HuffmanTree::decode(std::istream &codeBits, std::ostream &os) {
    TreeNode* curr = root_;
    char bits;

    while (codeBits >> bits){
        if (bits == '0')
            curr = curr->leftSubtree();

        else if (bits == '1')
            curr = curr->rightSubtree();

        if (curr->leftSubtree() == nullptr && curr->rightSubtree() == nullptr){
            os << curr->value() << '\n';
            curr = root_;
        }
    }
    return true;
}
