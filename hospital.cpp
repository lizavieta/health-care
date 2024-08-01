#include "illness.h"
#include "patient.h"
#include "hcp.h"
#include "hospital.h"
#include<iostream>
#include<string>
#include<memory>
#include<stdexcept>
#include<set>
#include<map>
#include<vector>

Hospital::Hospital(std::string name) : name(name) {
    if (name.empty())
        throw std::runtime_error("Empty name");
}

bool Hospital::sign_hcp(std::shared_ptr<Health_Care_Provider> m) {
    if (hcps.find(m->get_name()) != hcps.end())
        return false;
    hcps[m->get_name()] = m;
    return true;
}

bool Hospital::admit_patient(std::shared_ptr<Patient> m) {
    if (patients.find(m->get_name()) == patients.end() || patients[m->get_name()].expired()) {
        patients[m->get_name()] = m;
        return true;
    }
    return false;
}

bool Hospital::dismiss_hcp(std::string n) {
    if (hcps.erase(n) > 0) {
        return true;
    }
    return false;
}

std::shared_ptr<Health_Care_Provider> Hospital::get_hcp(std::string n) const {
    if (hcps.find(n) == hcps.end())
        throw std::runtime_error("No HCP with such name");
    return hcps.at(n);
}

std::shared_ptr<Patient> Hospital::get_patient(std::string n) const {
    if (patients.find(n) == patients.end() || patients.at(n).expired())
        throw std::runtime_error("No Patient with such name");
    return patients.at(n).lock();
}

bool Hospital::dismiss_patient(std::string n) {
    auto it = patients.find(n);
    bool n_exp{false};
    if (it != patients.end()) {
        if (!it->second.expired())
            n_exp = true;
        patients.erase(it);
        if (n_exp)
            return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& o, const Hospital& p) {
    o << "[" << p.name << ", hcps {";
    bool first{true};
    for (const auto& hcp : p.hcps) {
        if (first){
            o << *(hcp.second);
            first = false;
        }
        else {
            o << ", " << *(hcp.second);
        }
    }
    o << "}, patients {";
    first = true;
    for (const auto& patient : p.patients) {
        if (!patient.second.expired()) {
            if (first){
                o << *(patient.second.lock());
                first = false;
            }
            else {
                o << ", " << *(patient.second.lock());
            }
        }
    }
    o << "}]";
    return o;
}