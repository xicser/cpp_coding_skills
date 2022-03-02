
/* 迪米特法则：最少知识原则
迪米特法则可以简单说成：talk only to your immediate friends。 
对于OOD来说，又被解释为下面几种方式：一个软件实体应当尽可能少的与其他实体发生相互作用。每一个软件单位对其他的单位都只有最少的知识，而且局限于那些与本单位密切相关的软件单位。
迪米特法则的初衷在于降低类之间的耦合。由于每个类尽量减少对其他类的依赖，因此，很容易使得系统的功能模块功能独立，相互之间不存在（或很少有）依赖关系。
迪米特法则不希望类之间建立直接的联系。如果真的有需要建立联系，也希望能通过它的友元类来转达。
因此，应用迪米特法则有可能造成的一个后果就是：系统中存在大量的中介类，这些类之所以存在完全是为了传递类之间的相互调用关系——这在一定程度上增
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


/* 中介类 */
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

