#include <iostream>
using namespace std;

// Lớp cha thứ nhất
class Artist {
protected:
    int creativity;

public:
    Artist(int c = 100) : creativity(c) {}

    void draw() {
        cout << "[Artist] Đang vẽ đồ họa với mức sáng tạo: " << creativity << endl;
    }
    
    // Hàm work() giả định để giải thích câu hỏi lý thuyết
    void work() {
        cout << "Artist đang làm việc..." << endl;
    }
};

// Lớp cha thứ hai
class Coder {
protected:
    int logic;

public:
    Coder(int l = 100) : logic(l) {}

    void code() {
        cout << "[Coder] Đang viết code với mức logic: " << logic << endl;
    }
    
    // Hàm work() giả định để giải thích câu hỏi lý thuyết
    void work() {
        cout << "Coder đang làm việc..." << endl;
    }
};

// Lớp con kế thừa từ cả Artist và Coder
class GameDev : public Artist, public Coder {
public:
    // Constructor gọi initializer list cho cả 2 lớp cha
    GameDev(int c, int l) : Artist(c), Coder(l) {}

    // Phương thức riêng của lớp con
    void develop() {
        cout << "--- GameDev đang phát triển game ---" << endl;
        draw(); // Gọi hàm từ lớp Artist
        code(); // Gọi hàm từ lớp Coder
    }
};

int main() {
    // Tạo đối tượng GameDev với creativity = 90 và logic = 95
    GameDev myDev(90, 95);
    
    // Gọi phương thức tổng hợp
    myDev.develop();

    return 0;
}
