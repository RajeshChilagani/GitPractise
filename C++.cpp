// C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Learnings/CPPLearnings.h"
#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>
#include "EngineTest/SmartPointers.h"
#include "EngineTest/WeakPtr.h"
#include <memory>
#include <string>
#include <string>
#include "EngineTest/EC.h"
class Transform : public Component
{
public:
	Transform(float i=0):m_position(i)
	{}
	inline float getPosition()
	{
		return m_position;
	}
	inline float& setPosition()
	{
		return m_position;
	}
	
	inline void init() override
	{

	}
	inline void update() override
	{

	}
private:
	float          m_position;
};
class TestComp : public Component
{

public:
	inline void init() override
	{

	}
	inline void update() override
	{

	}
	std::string m_Name;
};
class Dev_Array
{
public:
	Dev_Array(size_t i_size) :size(i_size),m_Data(new int[size]) {}
	Dev_Array() {}
	int* GetData()
	{
		return m_Data;
	}
	int* & SetData()
	{
		delete m_Data;
		return m_Data;
	}
	int& operator[](size_t index)
	{
		if (index >= size)
		{
			std::cout << "Index out of bound" << std::endl;
		}
		return m_Data[index];
	}
	~Dev_Array()
	{
		delete m_Data;
	}
private:
	size_t size;
	int* m_Data;
};
void Test();
class GameObject
{
public:
	GameObject() :m_GridPosition(nullptr) {}
	GameObject(int* i_position) :m_GridPosition(i_position) { *m_GridPosition = 1; }
	GameObject& operator=(const GameObject& i_Rhs)
	{
		if (!m_GridPosition)
			m_GridPosition = new int;
		*m_GridPosition = *(i_Rhs.m_GridPosition);
		return *this;
	}
	void update()
	{
		(*m_GridPosition)++;
	}
	int* GetGridPosition()
	{
		return m_GridPosition;
	}
	~GameObject()
	{
		delete m_GridPosition;
	}
private:
	int* m_GridPosition;
};
struct ent
{
private:
	int x;
public:
	ent(int a):x(a)
	{

	}
	void Print() const
	{
		std::cout << x<<std::endl;
	}
	ent(const ent& i_Other) :x(i_Other.x) {}
	ent& operator=(const ent& i_Other)
	{
		x = i_Other.x;
		return *this;
	}
	int* getmem() 
	{
		return reinterpret_cast<int*>(this);
	}
	~ent()
	{
		x = 0;
	}
};

//Perfecet Singelton
class Singleton
{
public:
	static void Func()
	{
		std::cout<<Get().GetMem();
	}
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	int  GetMem()
	{
		return a;
	}
	static Singleton& Get() { static Singleton Instance; ; return Instance; }
private:
	Singleton() {}
	int a;
};

//EntityGame& EGTes(EntityGame& E)
//{
//	std::cout << "test" << std::endl;
//	return E;
//}
#define BIT(x) (1<<x)

class Base
{
protected:
	
public:
	Base() {}
	//virtual void PrintName() const = 0;
	Base(int input) :a(input) { std::cout << "Base is called" << std::endl; }
	void PrintA()
	{
		std::cout << a;
	}
	virtual void Printname() const
	{
		std::cout << "Base" << std::endl;
	}
private:
	int a;
	static int ST;
};
int Base::ST;
class Dr: public Base
{

public:
	Dr() {}
	Dr(int i_a, int b) :Base(i_a),b{ b } 
	{ 
		
		std::cout << "Derived is called" << std::endl;
	}
	void GetData()
	{
		std::cin >> b;
	}
	void PrintV()
	{
	//	a = 2;
		//std::cout <<a<<" "<<b;
	}
	void Printname() const override
	{
		std::cout << "Derived" << std::endl;
	}
	int b;
};
class AD :public Dr
{
public:
	void Printname() const override
	{

	}
	AD(int a, int b, int i_c) :
		Dr(a, b), c(i_c) {}
	int c;
};
void CallBack(Func i_CallBack)
{
	i_CallBack();
}
class EntityGame
{
public:
	EntityGame() {}
	EntityGame(int i) :m_x(i) {}
	EntityGame(const EntityGame& i_Other) :m_x(i_Other.m_x) { std::cout << "Copy is called" << std::endl; }
	EntityGame(EntityGame&& i_Other) :m_x(i_Other.m_x) { std::cout << "Move is called" << std::endl; }
	EntityGame& operator=(const EntityGame& i_Other)
	{
		m_x = i_Other.m_x;
		return *this;
	}
	void Print() { std::cout << m_x; }
	bool operator==(const EntityGame& i_Other)
	{
		return this == &i_Other;
	}
	/*static EntityGame& getOne(EntityGame& i_Other)
	{
		return i_Other;
	}*/
	~EntityGame()
	{
		std::cout << "Destructor called " << std::endl;
	}
private:
	int m_x;
};
class Pointer
{
public:
	 Pointer(EntityGame i_Obj):Obj(i_Obj) {}
	~Pointer() {}
private:
	EntityGame Obj;
};
class GlobalSystem
{
public:
	inline static GlobalSystem& Get() { static GlobalSystem* Instance = new GlobalSystem(); return *Instance; }
	void AddGameObject(const char* name)
	{
		m_AllGameObjects.emplace(name, new Entity());
		m_AllGameObjects.insert(std::make_pair(name, SmartPtr<Entity>(new Entity())));
	}
	template<typename T, typename...Targs>
	static void AddComponent(const char* name, Targs&&...mArgs)
	{

		Get().m_AllGameObjects[name]->AddComponent(new T(std::forward<Targs>(mArgs)...));
	}
	SmartPtr<Entity>& GetObject(const char* i_name)
	{
		return m_AllGameObjects[i_name];
	}
	static void  ShutDown()
	{
		delete &Get();
	}
	GlobalSystem() {}
	std::unordered_map<const char*, SmartPtr<Entity>> m_AllGameObjects;
};
#define CALLBACK(x) int ype(){return 1##x;}
CALLBACK(1)
#include "set"
#include <unordered_set>
void RemoveDupliactesWithSet(int a[],int size)
{
	std::unordered_set<int> uniqueElemnts;
	for (int i = 0; i < size; ++i)
	{
		uniqueElemnts.insert(a[i]);
	}
	for (std::unordered_set<int>::iterator i = uniqueElemnts.begin(); i != uniqueElemnts.end(); ++i)
	{
		std::cout << *i;
	}
}
#include <algorithm>
void RemoveDuplicates(std::vector<int> i_a, int size)
{
	int newsize = 0;
	for (int i = 0; i < size; ++i)
	{
		if (i_a[i] != i_a[i + 1])
		{
			i_a[newsize] = i_a[i];
			newsize++;
		}

	}
	for (int i = 0; i < newsize; ++i)
	{
		std::cout << i_a[i];
	}
}

class Integer
{
public:
	Integer() {}
	Integer(const char* i_Data) : m_Data(i_Data) {}
	Integer(const Integer& i_Other) :m_Data(i_Other.m_Data) {}
	Integer(Integer&& i_Other) :m_Data(i_Other.m_Data) {}
	void operator()()
	{
		std::cout << "OPerati";
	}
	Integer& operator=(const Integer& i_Other)
	{
		m_Data = i_Other.m_Data;
	}
	const char* m_Data;
	~Integer()
	{
		std::cout << "Destructor" << std::endl;
	}

};
Integer& CreateInt()
{
	Integer I("hello");
	return I;
}

class TestFunc
{
public:
	void PrintAnyThing(TestFunc& Test);
	friend std::ostream& operator<<(ostream& Test, TestFunc& T)
	{
		std::cout << T.m_A;
		return Test;
	}
private:
	int m_A=1;
};
void TestFunc::PrintAnyThing(TestFunc& Test)
{
	std::cout << Test;
	TestFunc T;
	T.m_A = 1;;
}
//Duplicate Name 
int GloabalInteger=1;
class TestClass
{
public:
	TestClass() :GloabalInteger(GloabalInteger) {}
	inline int Random()
	{
		int GloabalInteger = 7;
		GloabalInteger += 2;
		return this->GloabalInteger;
	}
private:
	int GloabalInteger;

};
class BaseClass
{
public:
	BaseClass() :m_Id(-1) { std::cout << "Base Constructor" << std::endl; }
	BaseClass(int Id) :m_Id(Id){}
	BaseClass(const BaseClass& i_Other)
		:m_Id(i_Other.m_Id) {}
	BaseClass(BaseClass&& i_Other)
		:m_Id(i_Other.m_Id) 
	{
		i_Other.m_Id = INT_MIN;
	}
	BaseClass& operator=(const BaseClass& i_Other)
	{
		m_Id = i_Other.m_Id;
		return *this;
	}
	virtual void Print() const { std::cout << "Base Class" << std::endl; }
	static int s_Int;
	int m_Id;
private:
	
	
};
int BaseClass::s_Int = 0;
class DerivedClass : public BaseClass
{
public:
	DerivedClass() {}
	DerivedClass(float i_Age) :BaseClass(),m_Age(i_Age) { std::cout << "Derived Constructor" << std::endl; }
	void Print() const override { std::cout << "Derived" << std::endl; }
	operator bool()
	{
		return true;
	}
private:
	float m_Age;
	friend ostream& operator<<(ostream& os, const DerivedClass& D);	
};
ostream& operator<<(ostream& os, const DerivedClass& D)
{
	os << D.m_Age << "Derived";
	return os;
}
#include "Templates/TemplateClass.h"
#include <map>
#include "EngineTest/Vector3.h"
template<typename T>
class TemplateTestClass
{
	
public:
	TemplateTestClass(T i_M) :m_T(i_M) {}
	void Print() 
	{
		std::cout << m_T;
	}
private:
	T m_T;
};
void BDTest(const BaseClass& i_base)
{
	i_base.Print();
}

class Point
{
public:
	Point():m_X(0.0f),m_Y(0.0f) {}
	Point(float i_X, float i_Y) :m_X(i_X), m_Y(i_Y) {}
	Point(const Point& i_Other) :m_X(i_Other.m_X), m_Y(i_Other.m_Y) {}
	Point& operator=(const Point& i_Other)
	{
		m_X = i_Other.m_X;
		m_Y = i_Other.m_Y;
		return *this;
	}
	~Point()
	{
		std::cout << "Destructor Called" << std::endl;
		m_X = INT_MIN;
		m_Y = INT_MIN;
	}
private:
	float m_X, m_Y;
};
Point CreatePoint()
{
	return { 12,2 };
}
void TestFunc()
{
	std::cout << "Hello from Main" << std::endl;
}
template<typename T>
T RandomInRange(T i_MinValue, T i_MaxValue)
{
	T randValue;
	if (std::is_same<T, int>::value)
	{
		randValue = rand() % i_MaxValue + i_MinValue;
	}
	return randValue;
}

template<typename T , typename U>
SmartPtr<T> dynamic_pointer_cast(const SmartPtr<U>& i_U)
{
	if (auto p = dynamic_cast<T*>(i_U.Get()))
	{
		return SmartPtr<T>(i_U, p);
	}
	else
	{
		return SmartPtr<T>();
	}
}
inline void PrintName(const char * i_Name);

template<typename T>
class TestTemp
{
	template<typename U>
	friend class TestTemp;
public:
	TestTemp(T i_Data);
	TestTemp(const TestTemp& i_Other);
template<typename U>
TestTemp(const TestTemp<U>& i_Other);/* :m_Data(i_Other.m_Data){
	std::cout << "cons";
}*/
private:
	T m_Data;
};

template<typename T>
TestTemp<T>::TestTemp(T i_Data):m_Data(i_Data) {}

template<typename T>
TestTemp<T>::TestTemp(const TestTemp<T>& i_Data) {}

template<typename T>
template<typename U>
TestTemp<T>::TestTemp(const TestTemp<U>& i_Data){}

int main()
{
	TestTemp<int> T1('d');
	TestTemp<float> TFloat(TestTemp<int>(1));
	std::cout << "as";
	//PrintName("test");
	//int Rand = RandomInRange(1, 22);
	//TestFunc();
	//TestInline();
	//Point p1 = { 1,2 }, p2 = {2,3};
	//(p1 = CreatePoint()) = p2;

	//DerivedClass objDerived(25);
	//BaseClass objBase;
	//objBase = objDerived;
	//BDTest(objBase);

	//DerivedClass* Dr = dynamic_cast<DerivedClass*>(new BaseClass());
	//{
	//	SmartPtr<DerivedClass> D(new DerivedClass(2.5f));
	//	SmartPtr<BaseClass> B = D;
	//	B->Print();
	//}
	//{
	//	/*SmartPtr<BaseClass> D(new DerivedClass(2.5f));
	//	SmartPtr<DerivedClass> B = D;
	//	B->Print();*/
	//}
	//{
	//	Erase TestCase
	//	SmartPtr<BaseClass> B(new BaseClass(25));
	//	std::vector<WeakPtr<BaseClass>> Bases;
	//	Bases.push_back(SmartPtr<BaseClass>(new BaseClass()));
	//	B.~SmartPtr();
	//	for (int i = 0; i < Bases.size(); i++)
	//	{
	//		if (!(Bases[i]))
	//			Bases.erase(Bases.begin() + i);
	//	}
	//}

	//MATH_API::Vector3(1, 2, 3);
	//MATH_API::Vector3 point = { 1,2,3 };
	//point.Normalize();
	//MATH_API::Vector3 Normalized = point.GetNormalized();
	//std::vector<int> a = { 1,2,2,2};
	//RemoveDuplicates(a,4);
	//std::cout << ype();
	//Base * b = new Base;
	//Component* T = new Transform(1.0f);
	//Transform* AT = static_cast<Transform*>(T);
	//std::cout<<"Printing "<<AT->getPosition();

	//SmartPtr<Component> Test(new Transform(1.0));
	//SmartPtr<Transform> t = Test.dynamic_pointer_cast<Transform>();
	//WeakPtr<Component> Temp(Test);
	//WeakPtr<Transform> Testing(Temp);
	//
	//{
	//	GlobalSystem& G = GlobalSystem::Get();
	//	G.AddGameObject("Player");
	//	GlobalSystem::AddComponent<Transform>("Player", 100.0f);
	//	GlobalSystem::Get().AddGameObject("Zombie");
	//	G.AddGameObject("Enemy");
	//	GlobalSystem::AddComponent<Transform>("Enemy", 1.0f);
	//	if (G.Get().m_AllGameObjects["Enemy"] == G.Get().m_AllGameObjects["Enemy"])
	//	{
	//		std::cout << "Smae" << std::endl;
	//	}
	//Physics
	//{
	//	/*std::vector<WeakPtr<GameObject>> PhysicsObjects;
	//	PhysicsObjects.push_back(GlobalSystem::Get().GetObject("Player"));
	//	PhysicsObjects[0].Acquire()->update();
	//	std::cout << (*PhysicsObjects[0].Acquire()->GetGridPosition());*/
	//}

	//	Render
	//	{
	//		/*std::vector<WeakPtr<GameObject>> RenderObjects;
	//		RenderObjects.push_back(GlobalSystem::Get().GetObject("Player"));*/



	//	}
	//}
	//GlobalSystem::ShutDown();
	//_CrtDumpMemoryLeaks();
	SmartPtr<Component> c1(new TestComp());
	SmartPtr<Transform> c2 = dynamic_pointer_cast<Transform>(c1);
	SmartPtr<Transform> c3(new Transform());
	SmartPtr<Transform> c4(c3);
	c4 = c3;
	c1->entity;
	
}


