#include <QCoreApplication>
#include <QTest>

#include "pointmassif.h"
#include "lienressort.h"

class TestPointMateriel : public QObject
{
	Q_OBJECT

public:
	TestPointMateriel();
	~TestPointMateriel();

private slots:
	void initTestCase();
	void init();
	void cleanupTestCase();
	void cleanup();
	void test_Creation();
	void test_Modification();
	void test_LienRessort();
};

TestPointMateriel::TestPointMateriel() {}

TestPointMateriel::~TestPointMateriel() {}

void TestPointMateriel::initTestCase()
{
	// code to be executed before the first test function
}

void TestPointMateriel::init()
{
	// code to be executed before each test function
}

void TestPointMateriel::cleanupTestCase()
{
	// code to be executed after the last test function
}

void TestPointMateriel::cleanup()
{
	// code to be executed after each test function
}

void TestPointMateriel::test_Creation()
{
	PointMateriel crash;
	QVERIFY_THROWS_EXCEPTION(std::bad_weak_ptr, crash.points());
	auto p = std::make_shared<PointMateriel>();
	QVERIFY(!p->masse());
	QVERIFY(p->points().size() == 1);
	QVERIFY(p->points().first()==p);
	QVERIFY(p->nom().isEmpty());
	QVERIFY(p->force().isNull());
	QVERIFY(p->liens().isEmpty());
	QVERIFY(!p->parent());
	QVERIFY(p->frames().isEmpty());
	QVERIFY(p->vit().isNull());
	QVERIFY(p->pos().isNull());
}

void TestPointMateriel::test_Modification()
{
	auto p = std::make_shared<PointMateriel>();
	auto masse = 10.;
	QString nom = "toto";
	p->setMasse(masse);
	p->setNom(nom);
	QVector3D position(1, 2, 3);
	QVector3D vitesse(10, 11, 12);
	p->setPos(position);
	p->setVit(vitesse);
	QVERIFY(p->masse() == masse);
	QVERIFY(p->nom() == nom);
	QVERIFY(p->force().isNull());
	QVERIFY(p->liens().isEmpty());
	QVERIFY(!p->parent());
	QVERIFY(p->frames().size() == 1);
	QVERIFY(p->vit() == vitesse);
	QVERIFY(p->pos() == position);
	p->tick(2);
	QVERIFY(p->vit() == vitesse);
	QVERIFY(p->pos() == (position + vitesse * 2));
	QVERIFY(p->frames().size() == 2);
	p->tick(2);
	QVERIFY(p->frames().size() == 2);
}

void TestPointMateriel::test_LienRessort()
{
	auto a = std::make_shared<PointMateriel>();
	auto b = std::make_shared<PointMateriel>();
	auto masse = 10.;
	QString nom = "toto";
	a->setMasse(masse);
	b->setMasse(masse);
	a->setNom(nom);
	b->setNom(nom);
	QVector3D positionA(1, 2, 3);
	QVector3D positionB(11, 12, 13);
	QVector3D vitesseA(10, 11, 12);
	a->setPos(positionA);
	b->setPos(positionB);
	a->setVit(vitesseA);
	b->setVit(vitesseA);
	a->addLien(b, 100);
	QVERIFY(b->liens().size() == 1);
	QVERIFY(a->liens().size() == 1);
	a->tick(2);
	QVERIFY(a->force().isNull());
	QVERIFY(a->frames().size() == 2);
	QVERIFY(b->frames().size() == 1);
	b->tick(2);
	b->setVit(QVector3D(0, 0, 0));
	a->tick(1);
	b->tick(1);
	QVERIFY(!a->force().isNull());
	QVERIFY((a->force() - b->force()).isNull());
}

QTEST_MAIN(TestPointMateriel)

#include "tst_testpointmateriel.moc"
