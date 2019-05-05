template<typename T>
class my_vector {
    T* _b;
    int _size;

    public:
        my_vector(): _b(nullptr), _size(0) {

        };

        my_vector(const int& i): _size(i){
            if(i != 0) {
                _b = new T[i];
            }
        }

        my_vector(const int& i, const T& v): _size(i) {
            if(i != 0) {
                _b = new T[i];
            }
            fill(_b, _b + _size, v);
        }

        my_vector(const initializer_list<T>& list) : _size(list.size()) {
          if (list.size() != 0) {
            _b = new T[list.size()];
          }
          copy(list.begin(), list.end(), _b);
        }
        T& operator [] (int i) const {
            return _b[i];
        }
        T* begin() const {
            return _b;
        }
        T* end () const {
            return _b + _size;
        }
        int size() const {
            return _size;
        }
};
