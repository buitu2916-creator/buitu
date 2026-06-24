#include <iostream>
#include <string>
using namespace std;

// Abstract class 1 đóng vai trò như một Interface [cite: 171]
class Printable {
public:
    // Pure virtual function (hàm thuần ảo) [cite: 171]
    virtual void print() const = 0; 
};

// Abstract class 2 đóng vai trò như một Interface [cite: 172]
class Serializable {
public:
    // Pure virtual function [cite: 172]
    virtual string serialize() const = 0; 
};

// Lớp Document kế thừa đa lớp từ 2 interface [cite: 173]
class Document : public Printable, public Serializable {
private:
    string title;    // Thuộc tính title [cite: 174]
    string content;  // Thuộc tính content [cite: 174]

public:
    // Constructor
    Document(string t, string c) : title(t), content(c) {}

    // Implement phương thức print() của Printable [cite: 175]
    void print() const override {
        cout << "--- In Tai Lieu ---" << endl;
        cout << "Tieu de: " << title << endl;
        cout << "Noi dung: " << content << endl;
    }

    // Implement phương thức serialize() của Serializable [cite: 175]
    string serialize() const override {
        // Chuyển đổi dữ liệu thành một chuỗi định dạng (ví dụ định dạng JSON đơn giản)
        return "{\"title\": \"" + title + "\", \"content\": \"" + content + "\"}";
    }
};

int main() {
    // --- PHẦN KIỂM TRA LỖI ---
    // Yêu cầu: Thử tạo đối tượng Printable p trực tiếp 
    // Nếu bạn bỏ comment dòng dưới đây, trình biên dịch sẽ báo lỗi:
    // "Cannot declare variable 'p' to be of abstract type 'Printable'"
    
    // Printable p; 

    // --- PHẦN TẠO OBJECT ---
    // Tạo Document và gọi cả 2 phương thức [cite: 177]
    cout << "[Tao doi tuong Document]" << endl;
    Document myDoc("Huong dan C++", "Day la noi dung cua tai lieu huong dan C++ nang cao.");
    
    // Gọi hàm print()
    myDoc.print();
    
    cout << "\n[Goi ham serialize]" << endl;
    // Gọi hàm serialize()
    cout << "Chuoi Serialized: " << myDoc.serialize() << endl;

    return 0;
}
