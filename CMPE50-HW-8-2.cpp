//DISPLAY 15.9 Definition for the Derived Class Manager
//This is the header file manager.h.
//This is the definition for the class Manager.
//This is primarily intended to be used as a derived class for
//managers who have direct reports.

#ifndef MANAGER_H
#define MANAGER_H

#include "15-05.cpp"

namespace employeessavitch
{
    class Manager : public SalariedEmployee
    {
    public:
        Manager();
        Manager(string the_name, string the_ssn,
                double the_weekly_salary);
        ~Manager();
        Manager(const Manager& source);
        Manager& operator=(const Manager& source);
        void addReport(const SalariedEmployee& report);
        friend ostream& operator<<(ostream& outs, const Manager& manager);

    private:
        SalariedEmployee* reports; // dynamic array of direct reports
        int noReports; // number of direct reports
    };

    Manager::Manager() : SalariedEmployee(), reports(nullptr), noReports(0)
    {
        // deliberately empty
    }

    Manager::Manager(string the_name, string the_ssn, double the_weekly_salary)
        : SalariedEmployee(the_name, the_ssn, the_weekly_salary), reports(nullptr), noReports(0)
    {
        // deliberately empty
    }

    Manager::~Manager()
    {
        delete[] reports;
    }

    Manager::Manager(const Manager& source) : SalariedEmployee(source)
    {
        noReports = source.noReports;
        reports = new SalariedEmployee[noReports];
        for (int i = 0; i < noReports; ++i)
        {
            reports[i] = source.reports[i];
        }
    }

    Manager& Manager::operator=(const Manager& source)
    {
        if (this != &source)
        {
            delete[] reports;

            SalariedEmployee::operator=(source);

            noReports = source.noReports;
            reports = new SalariedEmployee[noReports];
            for (int i = 0; i < noReports; ++i)
            {
                reports[i] = source.reports[i];
            }
        }
        return *this;
    }

    void Manager::addReport(const SalariedEmployee& report)
    {
        SalariedEmployee* newReports = new SalariedEmployee[noReports + 1];

        for (int i = 0; i < noReports; ++i)
        {
            newReports[i] = reports[i];
        }

        newReports[noReports] = report;
        ++noReports;

        delete[] reports;
        reports = newReports;
    }

    ostream& operator<<(ostream& outs, const Manager& manager)
    {
        outs << "Manager: " << manager.get_name() << "\nReports:\n";
        for (int i = 0; i < manager.noReports; ++i)
        {
            outs << "  " << manager.reports[i].get_name() << endl;
        }
        return outs;
    }
} // employeessavitch

#endif // MANAGER_H
