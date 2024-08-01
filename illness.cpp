#include"illness.h"
#include<iostream>
#include<stdexcept>
#include<string>

std::ostream& operator<<(std::ostream& o, Medical_Specialty m) {
    switch(m) {
        case Medical_Specialty::Cardiology: o<< "Cardiology"; break;
        case Medical_Specialty::Dermatology: o << "Dermatology"; break;
        case Medical_Specialty::Endocrinology: o << "Endocrinology"; break;
        case Medical_Specialty::Gynecology: o << "Gynecology"; break;
        case Medical_Specialty::Neurology: o << "Neurology"; break;
        case Medical_Specialty::Oncology: o << "Oncology"; break;
        case Medical_Specialty::Pathology: o << "Pathology"; break;
        case Medical_Specialty::Pediatrics: o << "Pediatrics"; break;
        case Medical_Specialty::Pulmonology: o << "Pulmonology"; break;
        case Medical_Specialty::Urology: o << "Urology"; break;
    }
    return o;
}

Illness::Illness(Medical_Specialty med,const std::string& name) : med(med), name(name) {
    if (name.empty())
        throw std::runtime_error("Empty name");
}
Medical_Specialty Illness::get_specialty() const {
    return med;
}
std::string Illness::get_name() const {
    return name;
}
bool Illness::operator==(const Illness& obj) const {
    return (med == obj.med && name == obj.name);
}
bool Illness::operator<(const Illness& obj) const {
    if (med == obj.med)
        return (name < obj.name);
    return (med < obj.med);
}
std::ostream& operator<<(std::ostream& o, const Illness& ill) {
    return o << "[" << ill.get_specialty() << ", " << ill.get_name() << "]";
}