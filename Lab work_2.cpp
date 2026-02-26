#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
    std::string _name;
    std::string _surname;
    int _age;
    int _extensionNumber;

    //конструктор за умовчанням
    Person() 
    {
        std::cout << "Працює конструктор за умовчанням  базового класу Person " << std::endl;
    }
//Параметризований конструктор
    Person( std::string name, std::string surname, int age, int extensionNumber):
    _name(name), _surname(surname), _age(age),  _extensionNumber(extensionNumber)
    {
        std::cout << "Працює параметризований конструктор класу Person " << std::endl;
    }
//Копіюючий конструктор
    Person(Person &person) : _name(person._name), _surname(person._surname),
    _age(person._age), _extensionNumber(person._extensionNumber)
    {
        std::cout << "Працює конструктор копіювання класу Person" << std::endl;
    }

// Деструктор     
    ~Person() 
    {
        std::cout << "Деструктор класу Person " << std::endl;
    }

// 2 функції для виведення на екран інформації про поточний стан об’єкту;
    void informationОutpu1()
     {
       std::cout  <<" Ім'я: \n"<<_name << "\n Прізвище: " << _surname <<" \nКод міста: "<< _age <<"\nНомер телефону: "<< _extensionNumber << std::endl; 
     }
      void informationОutpu2();
 };
class GettingHous: public Person     //Клас, учасник в черзі на отримання житла             
{
public:  
    int _day;                                     
    int _month;                                   
    int _year;                                    
    std::string _benefits;                              // наявність пільг
    int _serialNumber;                            // порядковий  номер в черзі
    
// Конструктор за умовчуванням
    GettingHous()
    {
        std::cout << "Конструктор за умовчуванням класу GettingHous" << std::endl;
    }
// параметризований
    GettingHous(std::string name, std::string surname, int age, int extensionNumber,
   int day, int month,int year,string benefits, int serialNumber ):
    Person ( name, surname, age, extensionNumber), _day(day), _month(month),
    _year(year),_benefits(benefits), _serialNumber(serialNumber)
    {
        std::cout << "Конструктор параметризований класу GettingHous" << std::endl;
         std::cout << "Особисті дані людини для постановлення в чергу на отримання житла" << std::endl;
    }
// Копіювальний
    GettingHous(GettingHous &gettingHous):Person ( _name, _surname, _age, _extensionNumber),
    _day(gettingHous._day),_month(gettingHous._month),_year(gettingHous._year),
    _benefits(gettingHous._benefits),_serialNumber(gettingHous._serialNumber)
    {
        std::cout << "Конструктор Копіювальний класу GettingHous " << std::endl;
    }
// Деструктор     
    ~ GettingHous() 
    {
        std::cout << "Деструктор класу  GettingHous " << std::endl;
    }   
//функції для виведення на екран інформації про поточний стан об’єкту;
     void informationОutpu1()
     {
        Person::informationОutpu1();
         std::cout <<" День;\n " <<_day <<" \n місяць: \n"<< _month <<"\n рік:  \n "<< _year <<"\n Наявність пільг:\n "<< _benefits << std::endl;
     }
     void informationОutpu2()
     {
         std::cout << "Ваш порядковий номер в чезі  : " << _serialNumber << std::endl;
     }    
 };
class ConferenceParticipant       //Участь в конференції
{
public:
    Person person;
    std::string _settlement;                       // Чи потребує доповідач поселення
    int _reportduration;                           // тривалість доповіді
     std::string _conferenceОpening;                     // час відкриття конференції
     std::string _startOfTheReport;                      // час початку виступу
   
// Конструктор за умовчуванням
    ConferenceParticipant()
    {
        std::cout << "Конструктор за умовчуванням класу ConferenceParticipant" << std::endl;
    }
// параметризований конструктор
    ConferenceParticipant (std::string name, std::string surname, int age, int extensionNumber,std::string settlement,
    int reportduration,  std::string conferenceОpening,  std::string startOfTheReport):
    person ( name, surname, age, extensionNumber),_settlement(settlement),_reportduration(reportduration),
    _conferenceОpening(conferenceОpening),_startOfTheReport(startOfTheReport)
     {
        std::cout << "Працює параметризований конструктор класу ConferenceParticipant" << std::endl;
        std::cout << "Реєстрація учасників у виїздній конференції " << std::endl; 
     }
// Копіюючий конструктор
     ConferenceParticipant (std::string name, std::string surname, int age, int extensionNumber, ConferenceParticipant &part):person ( name, surname, age, extensionNumber),
     _settlement(part._settlement),_reportduration(part._reportduration),
    _conferenceОpening(part._conferenceОpening),_startOfTheReport(part._startOfTheReport)
     {
        std::cout << "Копіюючий конструктор класу ConferenceParticipant" << std::endl;  
     }
// Деструктор     
    ~ () ConferenceParticipant
    { 
        std::cout << "Деструктор класу  ConferenceParticipant " << std::endl;
    } 
//функції для виведення на екран інформації про поточний стан об’єкту;
     void informationОutpu1()
     {    
        std::cout << "\n Потребує поселення: " <<_settlement << "\n Тривалість доповіді: " << _reportduration 
        << "\nЧас відкриття конференції: "<< _conferenceОpening <<"\n Початок доповіді: "<< _startOfTheReport << std::endl;
        person.informationОutpu1(); 
     }
     void informationОutpu2()
      {
         std::cout << "Реєстрація у конференції закінчена " << std::endl;     
      } 
};
int main()
{

Person person("Leonid", "Ivanov", 056, 775768 );
person.informationОutpu1();
std::cout << "\n----------------------------------------------\n" << std::endl;
GettingHous gettingHou("Leonid","ivanov",7775555,056 , 05,10,2024,"УБД",2);
gettingHou.informationОutpu1();
gettingHou.informationОutpu2();
std::cout << "\n----------------------------------------------\n" << std::endl;
ConferenceParticipant part("Leonid", "Ivanov", 056, 775768, "Так",20,"9:00","9:40");
part.informationОutpu1();
part.informationОutpu2();
std::cout << "\n----------------------------------------------\n" << std::endl;

    return 0;
}




