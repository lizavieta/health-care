# Overview

The Health Care Management System is a C++ project designed to simulate the interactions between patients, illnesses, health care providers, and hospitals. This system uses a set of classes to model different entities and their behaviors, aiming to provide a comprehensive framework for managing health care operations.

# Components 


1. Medical_Specialty
An enum class representing various medical specialties such as Cardiology, Dermatology, and Neurology.
Includes a function to output the string representation of the medical specialties.
2. Illness
Represents an illness with a specific medical specialty and name.
Provides functions for accessing the specialty and name, comparing illnesses, and outputting illness details.
3. Patient
Represents a patient with a name, age, a set of illnesses, and a certain amount of wealth.
Includes functions for managing wealth, adding illnesses, checking treatment requirements, curing illnesses, and outputting patient details.
4. Hospital
Represents a hospital with a name, a collection of health care providers, and a collection of patients.
Includes functions for signing health care providers, admitting and dismissing patients, retrieving health care providers and patients, and outputting hospital details.
5. - Health_Care_Provider
A base class representing a health care provider with a name, set of specialties, and wealth.
Contains virtual functions for performing procedures and managing licenses.
Provides functionality for checking eligibility for a specialty, paying for licenses, and outputting provider details.
- Teaching_Health_Care_Provider
A derived class from Health_Care_Provider that specializes in teaching.
Provides additional functionality for teaching other health care providers and managing teaching fees.
- Smart_Health_Care_Provider
A derived class from Health_Care_Provider that has unique characteristics and behaviors.
Implements functions related to performing procedures and managing licenses with specific rules.
