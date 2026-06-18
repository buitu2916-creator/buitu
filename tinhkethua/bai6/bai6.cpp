#include <iostream>
using namespace std;

class Base {
public:    int pub   = 1;
protected: int prot  = 2;
private:   int priv  = 3;
};

class DerivedPublic : public Base {
public:
    void test() {
        cout << pub;    // OK - vẫn là public
        cout << prot;   // OK - vẫn là protected
        // cout << priv; // LỖI - private không kế thừa
    }
};

class DerivedProtected : protected Base {
public:
    void test() {
        cout << pub;    // OK - trở thành protected
        cout << prot;   // OK - vẫn là protected
        // cout << priv; // LỖI
    }
};

class DerivedPrivate : private Base {
public:
    void test() {
        cout << pub;    // OK - trở thành private
        cout << prot;   // OK - trở thành private
        // cout << priv; // LỖI
    }
};

int main() {
    DerivedPublic dp;
    dp.pub;           // OK - pub vẫn là public
    // dp.prot;       // LỖI - prot là protected, không truy cập từ ngoài

    DerivedProtected dpr;
    // dpr.pub;       // LỖI - pub trở thành protected

    DerivedPrivate dpv;
    // dpv.pub;       // LỖI - pub trở thành private
}
