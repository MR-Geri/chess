#include <QtTest>
#include "../src/figure/figure.h"


// add necessary includes here

class tests : public QObject
{
    Q_OBJECT

public:
    tests();
    ~tests();

private slots:
    void test_case1();

};

tests::tests()
{

}

tests::~tests()
{

}

void tests::test_case1()
{
    King h;
}

QTEST_APPLESS_MAIN(tests)

#include "tst_tests.moc"
