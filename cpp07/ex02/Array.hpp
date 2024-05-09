#pragma once

#include <iostream>
#include <stdexcept>


template <typename T>
class Array {
private:
  unsigned int size_;
  T *array_;
  void swap(Array &first, Array &second) {
    std::swap(first.size_, second.size_);
	std::swap(first.array_, second.array_);
}
public:
  Array() {
	size_ = 0;
    array_ = NULL;
}

  Array(unsigned int size) {
    this->size_ = size;
    this->array_ = new T[size];
}

  Array(const Array &copy) {
	if (copy.size() > 0) {
		this->size_ = copy.size_;
		this->array_ = new T[copy.size_];
		for (unsigned int i = 0; i < copy.size_; i++)
			this->array_[i] = copy.array_[i];
		} 
		else {
			size_ = 0;
			array_ = NULL;
    	}
}

  ~Array() {
	if (this->size_ != 0) delete[] array_;
  }

  Array &operator=(Array other) {
	this->swap(*this, other);
    return *this;
  }


  T &operator[](unsigned int i) {
    if (i >= this->size_)
      throw std::out_of_range("Index out of range");
    return this->array_[i];
  }

  const T &operator[](unsigned int i) const {
    if (i >= this->size_)
      throw std::out_of_range("Index out of range");
    return this->array_[i];
  }

  unsigned int size(void) const { return this->size_; }
};