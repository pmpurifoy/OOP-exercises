template <typename T, typename A = allocator<T>> class my_vector {
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
  A a;
  pointer _b = nullptr;
  pointer _e = nullptr;

public:
  my_vector() = default;

  explicit my_vector(int s) {
    if (s != 0)
      _b = a.allocate(s);
    _e = _b + s;
    my_uninitialized_fill(a, _b, _e, T());
  }

  my_vector(int s, const T &v) {
    if (s != 0)
      _b = a.allocate(s);
    _e = _b + s;
    my_uninitialized_fill(a, _b, _e, v);
  }

  my_vector(int s, const T &v, allocator<T> t) : a(t) {
    if (s != 0)
      _b = a.allocate(s);
    _e = _b + s;
    my_uninitialized_fill(a, _b, _e, v);
  }
  my_vector(initializer_list<T> rhs) {
    if (rhs.size() != 0)
      _b = a.allocate(rhs.size());
    _e = _b + rhs.size();
    my_uninitialized_copy(a, rhs.begin(), rhs.end(), _b);
  }

  my_vector(const my_vector &rhs) {
    if (rhs.size() != 0)
      _b = a.allocate(rhs.size());
    _e = _b + rhs.size();
    my_uninitialized_copy(a, rhs.begin(), rhs.end(), _b);
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

  ~my_vector() { my_destroy(a, _b, _e); }

  T &operator[](int i) const {
    return _b[i];
  } //  warning: Returning null reference

  iterator begin() const { return _b; }

  iterator end() const { return _e; }

  int size() const { return _e - _b; }
};
