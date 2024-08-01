#ifndef PATIENT_H
#define PATIENT_H

#include "illness.h"
#include<iostream>
#include<stdexcept>
#include<string>
#include<set>

class Patient {
    std::string name;
    int age;
    std::set<Illness> illnesses;
    unsigned wealth;
    public: 
        Patient(std::string,int,const std::set<Illness>&,unsigned = 200);
        void increase_wealth(unsigned x);
        bool pay_procedure(unsigned x);
        void catch_disease(const Illness& x);
        bool requires_treatment_in(Medical_Specialty x) const;
        bool healthy() const;
        std::string get_name() const;
        unsigned cure(Medical_Specialty x);
        bool operator==(const Patient& obj) const;
        friend std::ostream& operator<<(std::ostream& o, const Patient& p);
};

#endif