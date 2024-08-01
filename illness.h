#ifndef ILLNESS_H
#define ILLNESS_H

#include<iostream>
#include<stdexcept>
#include<string>

enum class Medical_Specialty{ Cardiology,Dermatology,Endocrinology,Gynecology,Neurology, Oncology,Pathology,Pediatrics,Pulmonology,Urology};
std::ostream& operator<<(std::ostream& o, Medical_Specialty m);

class Illness {
    Medical_Specialty med;
    std::string name;
    public:
        Illness(Medical_Specialty,const std::string&);
        Medical_Specialty get_specialty() const;
        std::string get_name() const;
        bool operator==(const Illness& obj) const;
        bool operator<(const Illness& obj) const;
};
    
std::ostream& operator<<(std::ostream& o, const Illness& ill);

#endif