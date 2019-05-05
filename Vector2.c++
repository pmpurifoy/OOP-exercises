template <typename T> class my_vector {
  T *_b;
  int _size;

friend bool operator == (const my_vector<T>& lhs, const my_vector& rhs) {
    return lhs.size() == rhs.size() && equal(lhs.begin(), lhs.end(), rhs.begin());
}
public:
  my_vector()
      : _b(nullptr), _size(0){

                     };

  my_vector(const int &i) : _size(i) {
    if (i != 0) {
      _b = new T[i];
    }
  }

my_vector(const my_vector<T>& rhs): _size(rhs.size()) {
    if(rhs.size() != 0) {
        _b = new T[rhs.size()];
    }
    copy(rhs.begin(), rhs.end(), _b);
}
  my_vector(const int &i, const T &v) : _size(i) {
    if (i != 0) {
      _b = new T[i];
    }
    fill(_b, _b + _size, v);
  }

  my_vector(const initializer_list<T> &list) : _size(list.size()) {
    if (list.size() != 0) {
      _b = new T[list.size()];
    }
    copy(list.begin(), list.end(), _b);
  }

  my_vector& operator = (const my_vector<T>& rhs) {
my_vector t(rhs);
      swap(_b, t._b);
      swap(_size, t._size);
      return *this;
  }

  T &operator[](int i) { return _b[i]; }
  const T& operator[](int i) const { return _b[i]; }
  T *begin() const { return _b; }
  T *end() const { return _b + _size; }
  int size() const { return _size; }
};
