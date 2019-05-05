class Shape {
    int x;
    int y;
    friend void operator >> (istream& i, Shape& lhs) {
        i >> lhs.x;
        i >> lhs.y;
    }

    friend ostream& operator << (ostream& o, Shape& lhs) {
        o << lhs.x << " " << lhs.y;
        return o;
    }
    friend bool operator == (const Shape& lhs, const Shape& rhs) {
        return lhs.x == rhs.x && lhs.y && rhs.y;
    }
    friend bool operator!=(const Shape &lhs, const Shape &rhs) {
      return !(lhs == rhs);
    }

  public:
    Shape(const int &_x, const int &_y) : x(_x), y(_y) {}

    void move(const int &_x, const int &_y) {
      x = _x;
      y = _y;
        }

        int area() const {
            return 0;
        }
};

class Circle: public Shape {
    int _radius;
    friend bool operator == (const Circle& lhs, const Circle& rhs) {
      return lhs._radius == rhs._radius &&
             static_cast<const Shape &>(lhs) == static_cast<const Shape &>(rhs);
    }
    friend bool operator!=(const Circle &lhs, const Circle &rhs) {
        return !(lhs == rhs);
    }

  public:
    Circle(const int &_x, const int &_y, const int &rad)
        : Shape(_x, _y), _radius(rad) {}

    double area() const { return 3.14 * _radius * _radius; }

    int radius() const { return _radius; }
};
