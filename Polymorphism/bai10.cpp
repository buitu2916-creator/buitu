#include <iostream>
#include <string>
using namespace std;

// ===== Abstract base class =====
class Notifier {
public:
    virtual void sendAlert(string message) = 0;   // pure virtual
    virtual string getChannel() const = 0;         // pure virtual
    virtual ~Notifier() {}                           // virtual destructor - bat buoc
};

// ===== 4 lop con =====
class SMSNotifier : public Notifier {
    string phoneNumber;
public:
    SMSNotifier(string phone) : phoneNumber(phone) {}
    void sendAlert(string message) override {
        cout << "[SMS -> " << phoneNumber << "] " << message << "\n";
    }
    string getChannel() const override { return "SMS"; }
    ~SMSNotifier() override { cout << "[Destructor] Huy SMSNotifier\n"; }
};

class EmailNotifier : public Notifier {
    string email;
public:
    EmailNotifier(string mail) : email(mail) {}
    void sendAlert(string message) override {
        cout << "[Email -> " << email << "] " << message << "\n";
    }
    string getChannel() const override { return "Email"; }
    ~EmailNotifier() override { cout << "[Destructor] Huy EmailNotifier\n"; }
};

class PushNotifier : public Notifier {
    string deviceId;
public:
    PushNotifier(string device) : deviceId(device) {}
    void sendAlert(string message) override {
        cout << "[Push -> device " << deviceId << "] " << message << "\n";
    }
    string getChannel() const override { return "Push"; }
    ~PushNotifier() override { cout << "[Destructor] Huy PushNotifier\n"; }
};

class SlackNotifier : public Notifier {
    string channel;
public:
    SlackNotifier(string ch) : channel(ch) {}
    void sendAlert(string message) override {
        cout << "[Slack -> #" << channel << "] " << message << "\n";
    }
    string getChannel() const override { return "Slack"; }
    ~SlackNotifier() override { cout << "[Destructor] Huy SlackNotifier\n"; }
};

// ===== AlertSystem: quan ly mang con tro da hinh =====
class AlertSystem {
private:
    Notifier** notifiers;   // mang con tro da hinh (Notifier*[])
    int count;              // so luong hien tai
    int capacity;           // suc chua toi da

public:
    AlertSystem(int cap = 10) : count(0), capacity(cap) {
        notifiers = new Notifier*[capacity];
    }

    void addNotifier(Notifier* n) {
        if (count >= capacity) {
            cout << "AlertSystem da day, khong the them notifier!\n";
            return;
        }
        notifiers[count] = n;
        count++;
    }

    void triggerAll(string message) {
        cout << "\n===== TRIGGER ALERT: \"" << message << "\" =====\n";
        for (int i = 0; i < count; i++) {
            // goi qua con tro base -> dynamic dispatch chay dung ham cua lop con
            notifiers[i]->sendAlert(message);
        }
        cout << "===============================================\n";
    }

    void removeNotifier(int index) {
        if (index < 0 || index >= count) {
            cout << "Index khong hop le, khong the xoa!\n";
            return;
        }
        cout << "-> Dang xoa notifier kenh: " << notifiers[index]->getChannel() << "\n";
        delete notifiers[index];   // giai phong doi tuong (goi dung destructor nho virtual)

        // don mang: doi vi tri phan tu cuoi len chinh vi tri vua xoa
        for (int i = index; i < count - 1; i++) {
            notifiers[i] = notifiers[i + 1];
        }
        count--;
    }

    // Destructor: don dep toan bo bo nho
    ~AlertSystem() {
        cout << "\n[AlertSystem] Dang don dep toan bo notifiers con lai...\n";
        for (int i = 0; i < count; i++) {
            delete notifiers[i];
        }
        delete[] notifiers;
        cout << "[AlertSystem] Da giai phong xong.\n";
    }
};

int main() {
    AlertSystem system;

    // Tao 4 notifier khac loai
    system.addNotifier(new SMSNotifier("0987654321"));
    system.addNotifier(new EmailNotifier("owner@smarthome.com"));
    system.addNotifier(new PushNotifier("device_iphone_01"));
    system.addNotifier(new SlackNotifier("home-alerts"));

    // Trigger canh bao lan 1 - ca 4 kenh deu nhan duoc
    system.triggerAll("Motion detected at front door!");

    // Xoa 1 notifier (vi du xoa notifier o vi tri 1 - Email)
    system.removeNotifier(1);

    // Trigger lai - dam bao khong crash, chi con 3 kenh nhan duoc
    system.triggerAll("Motion detected at back yard!");

    // Destructor cua AlertSystem se tu dong don dep khi ra khoi scope
    return 0;
}
