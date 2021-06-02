#include <iostream>
#include "zstdcpp.h"

int main() {
    std::string raw = "Hello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello Worldabcdefghijklmnopqrstuvwxyz";

    zstd zstd_compressor;
    std::vector<uint8_t> bin(raw.size());
    std::memcpy(bin.data(), raw.data(), raw.size());
    std::cout << "Uncompressed size: " << bin.size() << "B" << std::endl;

    auto compressed = zstd_compressor.compress(bin, -1);
    std::cout << "Compressed size: " << compressed.size() << "B" << std::endl;
    auto decompressed = zstd_compressor.decompress(compressed);
    std::cout << reinterpret_cast<const char *>(decompressed.data()) << std::endl;

    return 0;
}
