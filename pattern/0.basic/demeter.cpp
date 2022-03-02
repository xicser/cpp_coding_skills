
/* �����ط�������֪ʶԭ��
�����ط�����Լ�˵�ɣ�talk only to your immediate friends�� 
����OOD��˵���ֱ�����Ϊ���漸�ַ�ʽ��һ�����ʵ��Ӧ���������ٵ�������ʵ�巢���໥���á�ÿһ�������λ�������ĵ�λ��ֻ�����ٵ�֪ʶ�����Ҿ�������Щ�뱾��λ������ص������λ��
�����ط���ĳ������ڽ�����֮�����ϡ�����ÿ���ྡ�����ٶ����������������ˣ�������ʹ��ϵͳ�Ĺ���ģ�鹦�ܶ������໥֮�䲻���ڣ�������У�������ϵ��
�����ط���ϣ����֮�佨��ֱ�ӵ���ϵ������������Ҫ������ϵ��Ҳϣ����ͨ��������Ԫ����ת�
��ˣ�Ӧ�õ����ط����п�����ɵ�һ��������ǣ�ϵͳ�д��ڴ������н��࣬��Щ��֮���Դ�����ȫ��Ϊ�˴�����֮����໥���ù�ϵ��������һ���̶�����
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class AbstractBuilding {
public:
    virtual void sale() = 0;
    virtual string getQulity() = 0;
};


class BuildingA : public AbstractBuilding {
public:
    BuildingA() {
        mQulity = "Good";
    }
    virtual void sale() {
        cout << "Good !" << endl;
    }
    virtual string getQulity() {
        return mQulity;
    }

private:
    string mQulity;
};


class BuildingB : public AbstractBuilding {
public:
    BuildingB() {
        mQulity = "very good";
    }
    virtual void sale() {
        cout << "Very Good !" << endl;
    }
    virtual string getQulity() {
        return mQulity;
    }

private:
    string mQulity;
};


/* �н��� */
class Mediator {
public:
    Mediator() {
        AbstractBuilding* ba = new BuildingA();
        vBuilding.push_back(ba);

        AbstractBuilding* bb = new BuildingB();
        vBuilding.push_back(bb);
    }
    ~Mediator() {
        for (auto item : vBuilding) {
            if (item != nullptr) {
                delete item;
            }
        }
    }

    AbstractBuilding* findMyBuilding(string qulity) {
        for (auto item : vBuilding) {
            if (item->getQulity() == qulity) {
                return item;
            }
        }

        return nullptr;
    }
private:
    vector<AbstractBuilding*> vBuilding;
};


void test2()
{
    Mediator* mediator = new Mediator();

    AbstractBuilding* abstractBuilding = mediator->findMyBuilding("Good");
    abstractBuilding->sale();

    delete mediator;
}

