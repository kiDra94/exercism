#pragma once
#include <vector>
#include <stdexcept>

namespace circular_buffer {

template <typename T>
class circular_buffer {
public:
    circular_buffer(std::size_t capacity)
        : data_(capacity), max_size_(capacity) {}
    T read() {
        if (isEmpty()) {
            throw std::domain_error("Buffer is empty");
        }
        T item = data_[read_pos_];
        read_pos_ = (read_pos_ + 1) % max_size_;
        full_ = false;
        return item;
    }
    void write(T item) {
        if(full_){
            throw std::domain_error("Buffer is full");
        }
        data_[write_pos_] = item;
        write_pos_ = (write_pos_ + 1) % max_size_;

        if(write_pos_ == read_pos_) {
            full_ = true;
        }
    }
    void clear() {
        read_pos_ = 0;
        write_pos_ = 0;
        full_ = false;
    }
    void overwrite(T item) {
        if(!full_) {
            write(item);
        }else{
            read_pos_ = (read_pos_ + 1) % max_size_;
            data_[write_pos_] = item;
            write_pos_ = (write_pos_ + 1) % max_size_;
        };
    };

private:
    bool isEmpty() const { return (!full_ && (read_pos_ == write_pos_)); }
    std::vector<T> data_;
    std::size_t max_size_;
    std::size_t read_pos_ = 0;
    std::size_t write_pos_ = 0;
    bool full_ = false;
};
}
