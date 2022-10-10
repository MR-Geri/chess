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
    void test_king();

};

tests::tests()
{

}

tests::~tests()
{

}

void tests::test_king()
{
    King h;
    QCOMPARE(h.move(QPair<int, int>(0, 0)), 0);
    QCOMPARE(h.move(QPair<int, int>(1, 1)), 0);
    QCOMPARE(h.move(QPair<int, int>(2, 2)), 1);
}

QTEST_APPLESS_MAIN(tests)

#include "tst_figure.moc"
