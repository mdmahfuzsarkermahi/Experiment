#include <cmath>      
#include <iostream>   
#include <stdexcept>  

class Vector3 {
public:
    
    double x, y, z;


    Vector3() : x(0.0), y(0.0), z(0.0) {}


    Vector3(double x, double y, double z) : x(x), y(y), z(z) {}

    Vector3(const Vector3& other) : x(other.x), y(other.y), z(other.z) {}

    Vector3& operator=(const Vector3& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
            z = other.z;
        }
        return *this;
    }


    Vector3& operator+=(const Vector3& other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }


    Vector3& operator-=(const Vector3& other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }


    Vector3& operator*=(double scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }


    Vector3& operator/=(double scalar) {
        if (scalar == 0.0) {
            throw std::invalid_argument("Division by zero in Vector3::operator/=");
        }
        x /= scalar;
        y /= scalar;
        z /= scalar;
        return *this;
    }


    Vector3 operator-() const {
        return Vector3(-x, -y, -z);
    }


    friend Vector3 operator+(const Vector3& a, const Vector3& b) {
        Vector3 result(a);
        result += b;
        return result;
    }


    friend Vector3 operator-(const Vector3& a, const Vector3& b) {
        Vector3 result(a);
        result -= b;
        return result;
    }


    friend Vector3 operator*(const Vector3& v, double s) {
        Vector3 result(v);
        result *= s;
        return result;
    }


    friend Vector3 operator*(double s, const Vector3& v) {
        return v * s;
    }


    friend Vector3 operator/(const Vector3& v, double s) {
        Vector3 result(v);
        result /= s;
        return result;
    }


    bool operator==(const Vector3& other) const {
        const double eps = 1e-9;
        return (std::abs(x - other.x) < eps) &&
               (std::abs(y - other.y) < eps) &&
               (std::abs(z - other.z) < eps);
    }


    bool operator!=(const Vector3& other) const {
        return !(*this == other);
    }


    double dot(const Vector3& other) const {
        return x * other.x + y * other.y + z * other.z;
    }


    Vector3 cross(const Vector3& other) const {
        return Vector3(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }


    double lengthSquared() const {
        return x*x + y*y + z*z;
    }


    double length() const {
        return std::sqrt(lengthSquared());
    }


    Vector3& normalize() {
        double len = length();
        if (len == 0.0) {
            throw std::invalid_argument("Cannot normalize zero vector in Vector3::normalize");
        }
        x /= len;
        y /= len;
        z /= len;
        return *this;
    }


    Vector3 normalized() const {
        Vector3 result(*this);
        result.normalize();
        return result;
    }


    static double dot(const Vector3& a, const Vector3& b) {
        return a.dot(b);
    }


    static Vector3 cross(const Vector3& a, const Vector3& b) {
        return a.cross(b);
    }


    static double distance(const Vector3& a, const Vector3& b) {
        return (a - b).length();
    }


    static double angle(const Vector3& a, const Vector3& b) {
        double lenA = a.length();
        double lenB = b.length();
        if (lenA == 0.0 || lenB == 0.0) {
            throw std::invalid_argument("Cannot compute angle with zero vector in Vector3::angle");
        }
        double cosTheta = a.dot(b) / (lenA * lenB);
        
        cosTheta = std::max(-1.0, std::min(1.0, cosTheta));
        return std::acos(cosTheta);
    }


    friend std::ostream& operator<<(std::ostream& os, const Vector3& v) {
        os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
        return os;
    }
};

// ==================== Example Usage ====================

int main() {
    using namespace std;

    // Create vectors
    Vector3 v1(10.0, 20.0, 30.0);
    Vector3 v2(40.0, 50.0, 60.0);

    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;

    // Addition
    Vector3 sum = v1 + v2;
    cout << "v1 + v2 = " << sum << endl;

    // Subtraction
    Vector3 diff = v1 - v2;
    cout << "v1 - v2 = " << diff << endl;

    // Scalar multiplication
    Vector3 scaled = v1 * 2.5;
    cout << "v1 * 2.5 = " << scaled << endl;

    // Dot product
    double dot = v1.dot(v2);
    cout << "v1 · v2 = " << dot << endl;

    // Cross product
    Vector3 cross = v1.cross(v2);
    cout << "v1 × v2 = " << cross << endl;

    // Length
    cout << "|v1| = " << v1.length() << endl;
    cout << "|v2| = " << v2.length() << endl;

    // Normalization
    try {
        Vector3 unit = v1.normalized();
        cout << "Unit vector of v1 = " << unit << ", length = " << unit.length() << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    // Distance
    double dist = Vector3::distance(v1, v2);
    cout << "Distance between v1 and v2 = " << dist << endl;

    // Angle
    double ang = Vector3::angle(v1, v2);
    cout << "Angle between v1 and v2 = " << ang << " radians (" << ang * 180.0 / M_PI << "°)" << endl;

    // Using static methods
    Vector3 v3(2, 0, 0);
    Vector3 v4(0, 3, 0);
    cout << "v3 = " << v3 << ", v4 = " << v4 << endl;
    cout << "Dot (static) = " << Vector3::dot(v3, v4) << endl;
    cout << "Cross (static) = " << Vector3::cross(v3, v4) << endl;

    return 0;
}