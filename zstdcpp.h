#ifndef ZSTD_CPP_ZSTDCPP_H
#define ZSTD_CPP_ZSTDCPP_H
#include <zstd.h>
#include <vector>
#include <cstdint>

template <typename T>
class zstd {
private:
    std::vector<T> buffer_;
public:
    std::vector<T> compress(const std::vector<T>& data, int compress_level) {
        size_t estimated = ZSTD_compressBound(data.size());

        buffer_.resize(estimated);

        auto compressed_size =
                ZSTD_compress((void*)buffer_.data(), estimated,
                              data.data(), data.size(), compress_level);

        buffer_.resize(compressed_size);
        buffer_.shrink_to_fit();

        return buffer_;
    }

    std::vector<T> decompress(const std::vector<T>& data) {
        auto const estimated =
                ZSTD_getDecompressedSize(data.data(), data.size());

        buffer_.resize(estimated);

        size_t const decompressed_size = ZSTD_decompress(
                (void*)buffer_.data(), estimated, data.data(), data.size());

        buffer_.resize(decompressed_size);
        buffer_.shrink_to_fit();
        return buffer_;
    }
};

#endif //ZSTD_CPP_ZSTDCPP_H
