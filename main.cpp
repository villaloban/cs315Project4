#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "HuffmanTree.hpp"


bool readHeader(const std::string& filename, std::vector<std::pair<std::string, std::string>>& header_pairs) {
    std::ifstream in(filename);
    if (!in.is_open()) {
        std::cout << "Error oppening header file" << filename << '\n';
        return false;
    }
    std::string word, code;
    while (in >> word >> code) {
        header_pairs.emplace_back(word, code);
    }
    return true;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <filename.hdr> <filename.code> \n";
        return 1;
    }

    const std::string dirName = "input_output";
    const std::string headerFile = dirName + "/" + std::string(argv[1]);
    const std::string codeFile = dirName + "/" + std::string(argv[2]);

    std::string baseName = std::string(argv[2]);
    if (baseName.size() > 5)
        baseName = baseName.substr(0, baseName.size() - 5);


    const std::string outputFile = dirName + "/" + baseName + ".tokens_decoded";

    std::vector<std::pair<std::string, std::string>> header_pairs;
    auto header_status = readHeader(headerFile, header_pairs);
    if(!header_status){
        std::cout << "Error reading " << '\n';
        return 1;
    }

    HuffmanTree decoder;
    auto build_status = decoder.buildFromHeader(header_pairs);
    if(!build_status){
        std::cout << "Error reading " << '\n';
        return 1;
    }

    std::ifstream code_stream(codeFile);
    if(!code_stream){
        std::cout << "Error reading " << '\n';
        return 1;
    }

    std::ofstream out_stream(outputFile);
    if(!out_stream){
        std::cout << "Error reading " << '\n';
        return 1;
    }

    bool decode_status = decoder.decode(code_stream, out_stream);
    if(!decode_status){
        std::cout << "Error reading " << '\n';
        return 1;
    }
    std::cout << "Output written to " << outputFile << '\n';

    return 0;


}
