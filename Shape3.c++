class AbstractShape {
    friend bool operator == (const AbstractShape& lhs, const AbstractShape& rhs) {
        return lhs.equals(rhs);}

    friend istream& operator >> (istream& lhs, AbstractShape& rhs) {
        return rhs.read(lhs);}

    friend ostream& operator << (ostream& lhs, const AbstractShape& rhs) {
        return rhs.write(lhs);}

    private:
        int _x;
        int _y;

    protected:
        virtual bool equals (const AbstractShape& rhs) const {
            return (_x == rhs._x) && (_y == rhs._y);}

        virtual istream& read (istream& in) {
            return in >> _x >> _y;}

        virtual ostream& write (ostream& out) const {
            return out << _x << " " << _y;}

    public:
        AbstractShape (int x, int y) :
                _x (x),
                _y (y)
            {}

        AbstractShape             (const AbstractShape&) = default;
        virtual ~AbstractShape    ()             = default;
        AbstractShape& operator = (const AbstractShape&) = default;

        virtual double area () const = 0;
        virtual AbstractShape* clone() const = 0;
        void move (int x, int y) {
            _x = x;
            _y = y;}};

class Circle : public AbstractShape {
    friend bool operator == (const Circle& lhs, const Circle& rhs) {
        return lhs.AbstractShape::equals(rhs) && (lhs._r == rhs._r);}

    friend istream& operator >> (istream& lhs, Circle& rhs) {
        return rhs.read(lhs);}

    friend ostream& operator << (ostream& lhs, const Circle& rhs) {
        return rhs.write(lhs);}

    private:
        int _r;

    protected:
        bool equals (const AbstractShape& rhs) const override {
            if (const Circle* const p = dynamic_cast<const Circle*>(&rhs))
                return AbstractShape::equals(*p) && (_r == p->_r);
            return false;}

        istream& read (istream& in) override {
            return AbstractShape::read(in) >> _r;}

        ostream& write (ostream& out) const override {
            return AbstractShape::write(out) << " " << _r;}

    public:
        Circle (int x, int y, int r) :
                AbstractShape (x, y),
                _r    (r)
            {}

        Circle             (const Circle&) = default;
        ~Circle            ()              = default;
        Circle& operator = (const Circle&) = default;

        Circle * clone () const {
            Circle* ret = new Circle(*this);
            return ret;
        }
        double area () const override {
            return 3.14 * _r * _r;}

        int radius () const {
            return _r;}};
