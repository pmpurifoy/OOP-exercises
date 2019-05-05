template <typename T> class my_vector {
  friend bool operator==(const my_vector &lhs, const my_vector &rhs) {
    return (lhs.size() == rhs.size()) &&
           equal(lhs.begin(), lhs.end(), rhs.begin());
  }

  friend bool operator<(const my_vector &lhs, const my_vector &rhs) {
    return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
                                   rhs.end());
  }

public:
  using pointer = T *;
  using iterator = pointer;
private:
  pointer _b = nullptr;
  pointer _e = nullptr;

public:
  my_vector() = default;

  explicit my_vector(int s) {
    if (s != 0)
      _b = new T[s];
    _e = _b + s;
    fill(begin(), end(), T());
  }

  my_vector(int s, const T &v) {
    if (s != 0)
      _b = new T[s];
    _e = _b + s;
    fill(begin(), end(), v);
  }

  my_vector(initializer_list<T> rhs) {
    if (rhs.size() != 0)
      _b = new T[rhs.size()];
    _e = _b + rhs.size();
    copy(rhs.begin(), rhs.end(), begin());
  }

  my_vector(const my_vector &rhs) {
    if (rhs.size() != 0)
      _b = new T[rhs.size()];
    _e = _b + rhs.size();
    copy(rhs.begin(), rhs.end(), begin());
  }

  my_vector(my_vector &&rhs) {
    std::swap(_b, rhs._b);
    std::swap(_e, rhs._e);
   }

  my_vector &operator=(const my_vector &rhs) {
    my_vector t(rhs);
    std::swap(_b, t._b);
    std::swap(_e, t._e);
    return *this;
  }

  my_vector &operator=(my_vector &&rhs) {
    my_vector t(move(rhs));
    std::swap(_b, t._b);
    std::swap(_e, t._e);
    return *this;
  }

  //~my_vector() { delete[] _b; }

  T &operator[](int i) const {
    return _b[i];
  } //  warning: Returning null reference

  iterator begin() const { return _b; }

  iterator end() const { return _e; }

  int size() const { return _e - _b; }

};
