#include "illness.h"
#include "patient.h"
#include "hcp.h"
#include<iostream>
#include<string>
#include<memory>
#include<stdexcept>
#include<set>
#include<vector>


Health_Care_Provider::Health_Care_Provider(std::string n, const std::set<Medical_Specialty>& topics,unsigned wealth) :
    name(n), topics(topics), wealth(wealth) {
        if (name.empty())
            throw std::runtime_error("Empty name");
    }

std::string Health_Care_Provider::get_name() const {
    return name;
}

Health_Care_Provider::~Health_Care_Provider() = default;

void Health_Care_Provider::increase_wealth(unsigned x) {
    wealth += x;
}

bool Health_Care_Provider::pay_license(unsigned x) {
    if (wealth < x)
        return false;
    wealth -= x;
    return true;
}

void Health_Care_Provider::receive_license(Medical_Specialty x) {
    topics.insert(x);
}

bool Health_Care_Provider::eligible_for(Medical_Specialty m) {
    return (topics.count(m) > 0);
}

std::ostream& operator<<(std::ostream& o, const Health_Care_Provider& h) {
    o << "[" << h.name << ", {";
    bool first{true};
    for (const auto& topic : h.topics) {
        if (first){
            o << topic;
            first = false;
        }
        else {
            o << ", " << topic;
        }
    }
    o << "}, " << h.wealth << " moneyz, " << h.hcp_type() << "]";
    return o;
}

Teaching_Health_Care_Provider::Teaching_Health_Care_Provider(unsigned fee,std::string n, const std::set<Medical_Specialty>& topics,unsigned wealth) :
    Health_Care_Provider(n, topics, wealth), fee(fee) {}

unsigned Teaching_Health_Care_Provider::perform_procedure(unsigned x,std::shared_ptr<Patient> p, Medical_Specialty m) {
    unsigned count{0};
    if (eligible_for(m) && p->requires_treatment_in(m) && p->pay_procedure(x)) {
        count = p->cure(m);
        increase_wealth(x);
    }
    return count;
}

std::string Teaching_Health_Care_Provider::hcp_type() const {
    return "Teacher";
}

bool Teaching_Health_Care_Provider::teach(Medical_Specialty m, std::shared_ptr<Health_Care_Provider> target) {
    if ((target.get() == this) || target->eligible_for(m) || !eligible_for(m) || !target->pay_license(fee))
        return false;
    increase_wealth(fee);
    target->receive_license(m);
    return true;
}

Smart_Health_Care_Provider::Smart_Health_Care_Provider(unsigned fee,std::string n, const std::set<Medical_Specialty>& topics,unsigned wealth) : 
    Health_Care_Provider(n, topics, wealth), fee(fee) {}

unsigned Smart_Health_Care_Provider::perform_procedure(unsigned , std::shared_ptr<Patient> , Medical_Specialty ) {
    return 0;
}

std::string Smart_Health_Care_Provider::hcp_type() const {
    return "Smart";
}

void Smart_Health_Care_Provider::receive_license(Medical_Specialty m) {
    Health_Care_Provider::receive_license(m);
    increase_wealth(fee);
}
