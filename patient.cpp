#include "illness.h"
#include "patient.h"
#include<iostream>
#include<stdexcept>
#include<string>
#include<set>

Patient::Patient(std::string name,int age,const std::set<Illness>& illnesses,unsigned wealth) : 
    name(name), age(age), illnesses(illnesses), wealth(wealth) {
        if (name.empty() || age < 0 || illnesses.empty())
            throw std::runtime_error("Invalid parameter: empty name, negative age or no illnesses");
    }
void Patient::increase_wealth(unsigned x) {
    wealth += x;
}
bool Patient::pay_procedure(unsigned x) {
    if (wealth < x)
        return false;
    wealth -= x;
    return true;
}
void Patient::catch_disease(const Illness& x) {
    illnesses.insert(x);
}
bool Patient::requires_treatment_in(Medical_Specialty x) const {
    for (const auto& disease: illnesses) {
        if (disease.get_specialty() == x)
            return true;
    }
    return false;
}
bool Patient::healthy() const {
    return illnesses.empty();
}
std::string Patient::get_name() const {
    return name;
}
unsigned Patient::cure(Medical_Specialty x) {
    unsigned count{0};
    auto it = illnesses.begin();
    while (it != illnesses.end()) {
        if (it->get_specialty() == x) {
            it = illnesses.erase(it);
            ++count;
        }
        else 
            ++it;
    }
    return count;
}
bool Patient::operator==(const Patient& obj) const {
    return (name == obj.name && age == obj.age && illnesses == obj.illnesses && wealth == obj.wealth);
}
std::ostream& operator<<(std::ostream& o, const Patient& p) {
    o << "[" << p.name << ", " << p.age << " years, {";
    bool first{true};
    for (const auto& illness : p.illnesses) {
        if (first){
            o << illness;
            first = false;
        }
        else {
            o << ", " << illness;
        }
    }
    return o << "}, " << p.wealth << " moneyz]";
}