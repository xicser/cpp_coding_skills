#define _CRT_SECRUE_NO_WARINGS
#include <iostream>
#include <string>

using namespace std;


/* 共有接口 */
class AbstractCommonInterface {
public:
    virtual void run() = 0;
};

/* 真正的服务器 */
class MySystem : public AbstractCommonInterface {
public:
    virtual void run() {
        cout << "系统启动..." << endl;
    }
};

/* 
   服务器的代理
   必须有要权限验证，不是所有人都能来启动我的启动，提供用户名和密码
   通过这个MySystemProxy代理，控制对MySystem的访问（提供一种代理来控制对其他对象的访问）
   MySystem有的行为，MySystemProxy也必须要有。
*/
class MySystemProxy : public AbstractCommonInterface {
public:
    MySystemProxy(string username, string passwd) {
        this->username = username;
        this->passwd = passwd;
        pSystem = new MySystem();
    }
    virtual void run() {
        if (check() == true) {
            cout << "验证成功..." << endl;
        }
        else {
            cout << "验证失败..." << endl;
        }
    }

    bool check() {
        if (this->username == "admin" && this->passwd == "admin") {
            return true;
        }

        return false;
    }

    ~MySystemProxy() {
        if (pSystem != nullptr) {
            delete pSystem;
        }
    }

private:
    MySystem* pSystem;      //服务器
    string username;
    string passwd;
};


int main()
{
    MySystemProxy proxy("admin", "admin");
    proxy.run();


}
