#ifndef ZSTD_CPP_ZSTDCPP_H
#define ZSTD_CPP_ZSTDCPP_H
#include <zstd.h>
#include <vector>
#include <cstdint>

class zstd {
private:
    std::vector<uint8_t> buffer_;
public:
    std::vector<uint8_t> compress(const std::vector<uint8_t>& data, int compress_level) {
        auto const bound = ZSTD_compressBound(data.size());

        buffer_.resize(bound);

        auto compressed_size =
                ZSTD_compress(reinterpret_cast<void *>(buffer_.data()), bound,
                              data.data(), data.size(), compress_level);

        buffer_.resize(compressed_size);
        buffer_.shrink_to_fit();

        return buffer_;
    }

    std::vector<uint8_t> decompress(const std::vector<uint8_t>& data) {
        auto const estimated =
                ZSTD_getFrameContentSize(data.data(), data.size());

        if (estimated == ZSTD_CONTENTSIZE_UNKNOWN || estimated == ZSTD_CONTENTSIZE_ERROR)
            return {};

        buffer_.resize(estimated);

        size_t const decompressed_size = ZSTD_decompress(
                reinterpret_cast<void *>(buffer_.data()), estimated, data.data(), data.size());

        buffer_.resize(decompressed_size);
        buffer_.shrink_to_fit();
        return buffer_;
    }
};

#endif //ZSTD_CPP_ZSTDCPP_H
