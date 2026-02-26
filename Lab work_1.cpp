
#include <iostream>
#include <string>
using namespace std;
class Addresses
{
private:
    std::string _city;
    std::string _street;
    int _houseNumber;
    int _apartmentNumber;
public:

//конструктор за замовчуванням
    Addresses() {}
//Параметризований конструктор
     Addresses( std::string city,std::string street,int houseNumber,int apartmentNumber):
      _city(city), _street(street), _houseNumber(houseNumber),_apartmentNumber(apartmentNumber)
    {}
//Копіюючий конструктор
    Addresses(Addresses &copyaddr) : _city(copyaddr._city), _street(copyaddr._street),
    _houseNumber(copyaddr._houseNumber), _apartmentNumber(copyaddr._apartmentNumber)
    {
        cout << "Запрацюва конструктор копіюючий класу Addresses\n"  <<endl;
    }
   
    ~ Addresses(){}
    
// Функції-селектори окремо для кожного з полів
    std::string getCity()
    {
        return  _city;
    }
    std::string getStreet()
    {
        return  _street;
    }
    int getHouseNumber()
    {
        return  _houseNumber;
    }
    int getApartmentNumber()
    {
        return  _apartmentNumber;
    }
    
// 2 функції для виведення на екран інформації про поточний стан об’єкту;
    void informationОutpu1()
     {
         std::cout << _city <<" "<< _street <<" ""буд.:"<< _houseNumber <<" ""кв.:"<< _apartmentNumber << std::endl;
     }
     void informationОutpu2()
     {
         std::cout << "Addresses: " << _houseNumber << std::endl;
     }
 //функції-модифікатори окремо для кожного з полів
     Addresses& setCity(std::string city)
     {
         _city = city;
         return *this;  
     }
     Addresses& setStreet(std::string street)
     {
         _street = street;
         return *this;  
     }
     Addresses& setHouseNumber(int houseNumber)
     {
         _houseNumber = houseNumber;
         return *this;  
     }
     Addresses& setApartmentNumber(int apartmentNumber)
    {
         _apartmentNumber = apartmentNumber;
         return *this;  
     }
};    
 
    
class Person
{
private:
    std::string _name;
    std::string _surname;
    int _cityСode;
    int _extensionNumber;
public:
    //конструктор за замовчуванням
    Person()
    {
        
    }
//Параметризований конструктор
    Person( std::string name, std::string surname, int cityСode, int extensionNumber):
    _name(name), _surname(surname), _cityСode(cityСode), _extensionNumber(extensionNumber)
    {}
    
//Копіюючий конструктор
    Person(Person &person) : _name(person._name), _surname(person._surname),
    _cityСode(person._cityСode), _extensionNumber(person._extensionNumber)
    {
        std::cout << "Запрцював конструктор копіювання класу Person" << std::endl;
    }
    
    ~Person() {}
    
// Функції-селектори окремо для кожного з полів
    std::string getName()
    {
        return  _name;
    }
    std::string getSurname()
    {
        return  _surname;
    }
    int getCityСode()
    {
        return  _cityСode;
    }
    int getExtensionNumber()
    {
        return  _extensionNumber;
    }
    
// 2 функції для виведення на екран інформації про поточний стан об’єкту;
    void informationОutpu1()
     {
         std::cout << _name <<" "<< _surname <<" "<< _cityСode <<" "<< _extensionNumber << std::endl;
     }
     void informationОutpu2()
     {
         std::cout << "Person: " << _name << std::endl;
     }    
//функції-модифікатори окремо для кожного з полів
     Person& setName(std::string name)
     {
         _name = name;
         return *this;  
     }
     Person& setSurname(std::string surname)
     {
         _surname = surname;
         return *this;  
     }
     Person& setCityСode(int cityСode )
     {
         _cityСode = cityСode;
         return *this;  
     }
     Person& setExtensionNumber(int extensionNumber)
    {
         _extensionNumber = extensionNumber;
         return *this;  
     }   
};

Леонід, [27.03.2024 12:08]
int main()
{
// конструктор за замовчуванням
Addresses addr;
//2 конструктор параметризований
std::string city,street;
int houseNumber, apartmentNumber;
cout << "Вкажіть назву міста: ";
    cin >> city;
    cout << "Назву вулиці: " ;
    cin >> street;
    cout << "Номер будинку: ";
    cin >> houseNumber;
    cout << "Номер квартири: ";
    cin >> apartmentNumber;
Addresses addr1(city,street,houseNumber, apartmentNumber);
addr1.informationОutpu1();
addr1.informationОutpu2(); 
//3 конструктор Копіюючий
Addresses copyaddr(addr1);


// Клас людина
//1 Конструктор за замовчуванням
Person person;
// 2 Конструктор параметризований
    std::string name,surname; 
    int cityСode,extensionNumber;
    cout << "Назвіть  своє  ім'я: ";
    cin >> name;
    cout << "Прізвище " ;
    cin >> surname;
    cout << "Код вашого міста: ";
    cin >> cityСode;
    cout << "номер телефону: ";
    cin >> extensionNumber; 
Person person1(name,surname,cityСode,extensionNumber); 
//3 конструктор копіювання
Person copyperson(person1);
    return 0;
}
