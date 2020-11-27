#ifndef sample_array_h
#define sample_array_h

class SampleArray {
public:
    SampleArray(int size) {
        _size = size;
        _buffer = (int16_t *)malloc(size * sizeof(int16_t));
    }

    SampleArray(SampleArray &&array) {
        _size = array._size;
        _buffer = array._buffer;
    }

    SampleArray(SampleArray &array) = delete;

    ~SampleArray() {
        free(_buffer);
    }

    int size() {
        return _size;
    }

    int16_t *buffer() {
        return _buffer;
    }

private:
    int _size;
    int16_t *_buffer;
};

#endif
