#include <iostream>
#include <string>
#include <cassert>
using namespace std;
class Person
{
public:
    string _name;
    string _surname;
    int _age;
    int _extensionNumber;
   

    //конструктор за умовчанням
    Person() 
    {
        //cout << "Працює конструктор за умовчанням  базового класу Person " << endl;
    }
//Параметризований конструктор
    Person( string name, string surname, int age, int extensionNumber):
    _name(name), _surname(surname), _age(age),  _extensionNumber(extensionNumber)
    {
        //cout << "Працює параметризований конструктор класу Person " << endl;
    }
virtual void print() {
        cout << "\nДоброго дня мене звати" << _name << " " << _surname << endl;
    }
// Деструктор     
   virtual ~Person() 
    {
        //cout << "Вертульний деструктор класу Person " << endl;
    }
     friend ostream& operator<< (std::ostream &out, Person &person);
    friend bool operator== (const Person &person, const Person &person1);
    // Віртуальна функція для виведення інформації
    
 };
    bool operator== (const Person &person, const Person &person1)
    {
        return (person. _name == person1._name && person._surname == person1._surname &&  person._age==person1._age &&
        person. _extensionNumber == person1. _extensionNumber);   
    }
    
    ostream& operator<< (std::ostream &out, Person &person)
    {
         out << "Ім'я :" << person._name << "\nПрізвище :" << person._surname << " \nВік :" << person._age << "\nНомер телефону :" << person._extensionNumber << endl;
        return out; 
    }
    
 //Клас, учасник в черзі на отримання житла       
class GettingHous: public Person          
{
public:  
    int _day;                                     
    int _month;                                   
    int _year;                                    
    string _benefits;                              // наявність пільг
    int _serialNumber;                            // порядковий  номер в черзі
    
// Конструктор за умовчуванням
    GettingHous()
    {
        //cout << "Конструктор за умовчуванням класу GettingHous" << endl;
    }
// параметризований
    GettingHous(string name, string surname, int age, int extensionNumber,
   int day, int month,int year,string benefits, int serialNumber ):Person ( name, surname, age, extensionNumber), _day(day), _month(month),
    _year(year),_benefits(benefits), _serialNumber(serialNumber)
    {
        //-- _serialNumber; 
        //cout << "Конструктор параметризований класу GettingHous" << endl;
        cout << "Особисті дані людини для постановлення в чергу на отримання житла " << endl;
    }
// Копіювальний
    GettingHous(GettingHous &gettingHous):Person ( _name, _surname, _age, _extensionNumber),
    _day(gettingHous._day),_month(gettingHous._month),_year(gettingHous._year),
    _benefits(gettingHous._benefits),_serialNumber(gettingHous._serialNumber)
    {
       // std::cout << "Конструктор Копіювальний класу GettingHous " << std::endl;
    }
     virtual void print(){
        cout << "Я зареєстрований в черзі на отриманн житла під номером  " << _serialNumber << endl;
    }
// Деструктор     
    virtual ~ GettingHous() 
    {
        //cout << "Вертульний деструктор класу  GettingHous " << endl;
    } 
    
    GettingHous& operator--();
   // Віртуальна функція для виведення інформації
   
};
    GettingHous& GettingHous::operator--()
    {
        --_serialNumber;
        return *this;
    }    
    ostream& operator<<(ostream &out,const GettingHous &gettingHous1)
    {
        out <<" День : " <<gettingHous1._day <<" \n місяць : "<<gettingHous1. _month <<"\n рік :"<< gettingHous1._year 
        <<"\n Наявність пільг :"<< gettingHous1._benefits << "\n Порядковий номер в черзі : " << gettingHous1._serialNumber << endl;
        return out;
    }
    
//Участь в конференції
class ConferenceParticipant       
{
public:
    Person person;
    std::string _settlement;                       // Чи потребує доповідач поселення
    int _reportduration;                           // тривалість доповіді
    string _conferenceОpening;                     // час відкриття конференції
    string _startOfTheReport;                      // час початку виступу
// Конструктор за умовчуванням
    ConferenceParticipant()
    {
         // std::cout << "Конструктор за умовчуванням класу ConferenceParticipant" << std::endl;
    }
// параметризований конструктор
    ConferenceParticipant (string name, string surname, int age, int extensionNumber,string settlement,
    int reportduration,  string conferenceОpening,  string startOfTheReport):
    person ( name, surname, age, extensionNumber),_settlement(settlement),_reportduration(reportduration),
    _conferenceОpening(conferenceОpening),_startOfTheReport(startOfTheReport)
    {
        // cout << "Працює параметризований конструктор класу ConferenceParticipant" <<endl;
        std::cout << "Реєстрація учасника у виїздній конференції " <<person._name << std::endl; 
    }
// Копіюючий конструктор
    ConferenceParticipant (string name, string surname, int age, int extensionNumber, ConferenceParticipant &part):person ( 
    name,surname, age, extensionNumber),_settlement(part._settlement),_reportduration(part._reportduration),
     _conferenceОpening(part._conferenceОpening),_startOfTheReport(part._startOfTheReport)
    {
         //cout << "Копіюючий конструктор класу ConferenceParticipant" << endl;  
    }
     // Віртуальна функція для виведення інформації
    virtual void print()  {
        cout << "Маю друга Антона ми разом приймаємо участь у конференції яка відкривається о: " << _conferenceОpening << " годині ранку" << endl;
    } 
// Деструктор     
   virtual ~ ConferenceParticipant() 
    {
        //cout << "Віртуальна деструктор класу  ConferenceParticipant " << endl;
    }
  

  ConferenceParticipant( Person& p):person(p)
  {
     
      cout <<"Конструктор перетворення"<<endl;
  }

  operator Person()
  {
    return   Person(person);
       
  }
     ConferenceParticipant& operator += (int value); 
    friend bool operator< (const ConferenceParticipant &part, const ConferenceParticipant &part1);

};


    ConferenceParticipant& ConferenceParticipant::operator+=(int value)
    {
        this->_reportduration += value;
        return *this;
    }
    ostream& operator<<(ostream &out,const ConferenceParticipant &part1)
    {
        out  << "\n Потребує поселення: " <<part1._settlement << "\n Тривалість доповіді: " << part1._reportduration 
         << "\nЧас відкриття конференції: "<< part1._conferenceОpening <<"\n Початок доповіді: "<< part1._startOfTheReport << endl;
        return out;
    }
    bool operator< (const ConferenceParticipant &part, const ConferenceParticipant &part1)
    {
       return part._reportduration < part1._reportduration;
    }
    
    
    
    
    
    class PublicOrganisation
    {
public:
    string _organisationName;
    int _numberOfMembers;
    Person* _array;
     PublicOrganisation(){}
     PublicOrganisation(string org,  int numb ):_organisationName(org),_numberOfMembers(numb)
     {
        _array = new Person[_numberOfMembers];
     }
     ~PublicOrganisation()
     {
         delete [] _array;
     }
//Метод для повернення кількості членів оргнізацї     
     int getNumberOfMembers()
    {
        return _numberOfMembers;
    }
// Перевнтажений оператор індексу    
    Person& operator[](int _numberOfMembers);
   friend ostream& operator<< (std::ostream &out,PublicOrganisation &p );
};
    Person& PublicOrganisation::operator[](int index)
    {
         assert(index >= 0 && index <= _numberOfMembers); // перевірка на коретність значення змінної  index
         cerr << "Не коректне значення" << endl;
         exit(-1);
        return _array[index];
    }
    
    ostream& operator<< (std::ostream &out,PublicOrganisation &p )
    {
        out << "Назва організацї: " << p._organisationName << "\nКільксть працівників: " <<p._numberOfMembers<<"  чолвік"<<endl;
        return out;
    }
  
    
int main()
{

    Person person("Leonid", "Ivanov", 20, 775768 );
    Person person1("Anton", "Antupov", 30, 664657);
    cout << person << " ";
    cout << person1 << " ";
//Перевіримо на рівність   об'єкти  person1 person класу "Людина"
    if(person == person1)
        cout <<"person == person1"<<" ";
    else
        cout <<"person != person1"<<" ";
    cout << "\n------------------------------------------------------\n" << endl;
    GettingHous gettingHou("Leonid", "ivanov", 20, 775768, 05, 10, 2024, "УБД", 4);
    cout <<  person << gettingHou<< " ";
    GettingHous gettingHou1(gettingHou);
    cout<<"Порядковий номер в черзі змінився та становить : "<< --gettingHou._serialNumber;
    
    cout << "\n------------------------------------------------------\n" << endl;
    ConferenceParticipant leonid("Leonid", "Ivanov", 20, 775768, "Так", 20,"9:00", "9:00");
     cout << person << leonid << " ";
     cout << "Реєстрація у конференції закінчена " << endl;
    ConferenceParticipant anton("Anton", "Antupov", 30, 664657, "Ні", 15,"9:20", "10:00");
    cout <<  person1 << anton << " ";
//змінюємо тривалість доповіді Учасника Антона задапомогою перевантажиного оператора +=() на 10хв.збільшили
    cout << "Тривалість доповіді  для учасника Антона змінилася та складає :"  <<endl;
    anton += 10;
    cout <<  anton._reportduration << " ";
    cout << "\nРеєстрація у конференції закінчена " << endl;
//Порівнюємо значення змінної-члена "тривалість доповіді"  обох об'єктів та визначимо найкоротший виступ
    if(leonid < anton)
    cout << "leonid < anton " <<" ";
    else
    cout << "leonid > anton " <<" ";
    cout << "\n------------------------------------------------------\n" << endl;
// оператор індексації для доступу до елементів масиву типу Person які є працівниками громадської організацї
    PublicOrganisation p("ООО Метінвест сервіс", 2);
    
    cout << p << endl;
// Динамічний масив  типу Person
    Person *_array;
    _array=new Person[2];
//ініціалізуємо масив об'єктами      
    _array[0] = Person("Ben","Travolta",58,555555);
    _array[1] = Person("Anastasiia","Korzh",42,444444);
    for( int i = 0; i < 2; ++i)
    {
        cout << _array[i] << endl;
    }

 cout << "\n------------------------------------------------------\n" << endl; 
//перетворення типу  «Учасник виїзної конференції» до об’єкту типа «Людина» і навпаки.

    ConferenceParticipant igor;
    Person person2 = igor; // Перетворення від ConferenceParticipant до Person
    cout << person2;

    Person person3;
    ConferenceParticipant igor1(person3); // Перетворення від Person до ConferenceParticipant
    cout << igor1;
    cout << "\n------------------------------------------------------\n" << endl;
//  вертуальнf функціz print()
    person.print();
    gettingHou.print();
    leonid.print();  
    return 0;
}








