#include <iostream>
using namespace std;

class GovEmp;
class PrivEmp;

class Person
{
    public:
        int id, cibil_score, monthly_income, yrs;
        Person()
        {
            cout<<"\nEnter ID:";
            cin>>id;
            cout<<"lol";
            cout<<"Cibil Score (150-900):";
            cin>>cibil_score;
            cout<<"Monthly Income:";
            cin>>monthly_income;
            cout<<"Years of service remaining:";
            cin>>yrs;
        }

};

class GovEmp: private Person
{
    bool Disc_Act;
    public:
        GovEmp()
        {
            char c;
            cout<<"Disciplinary Action (y/n)? ";
            cin>>c;
            if(c == 'y')
                Disc_Act = 1;
            else if(c == 'n')
                Disc_Act = 0;
            else
            {
                cout<<"\nInvalid choice";
                GovEmp();
            }
        }
    friend void LoanGrant(char, GovEmp, GovEmp, PrivEmp, PrivEmp);
};

class PrivEmp: private Person
{
    int rating;
    public:
        PrivEmp()
        {
            cout<<"Rating (0-4):";
            cin>>rating;
        }
    friend void LoanGrant(char, GovEmp, GovEmp, PrivEmp, PrivEmp);
};

void LoanGrant(char ch, GovEmp g1, GovEmp g2, PrivEmp p1, PrivEmp p2)
{
    if(ch == 'I')
    {
        if(g1.Disc_Act)
            cout<<"\nGovernment Employee with ID - "<<g1.id<<" is not eligible for individual loan.";
        else if(g1.monthly_income>=25000 && g1.yrs>=15 && g1.cibil_score>=200)
            cout<<"\nGovernment Employee with ID - "<<g1.id<<" is eligible for an individual loan of INR 5 lakhs";
        else if(g1.monthly_income>=50000 && g1.yrs>=20 && g1.cibil_score>=300)
            cout<<"\nGovernment Employee with ID - "<<g1.id<<" is eligible for an individual loan of INR 10 lakhs";
        else
            cout<<"\nGovernment Employee with ID - "<<g1.id<<" is not eligible for individual loan.";
        
        if(g2.Disc_Act)
            cout<<"\nGovernment Employee with ID - "<<g2.id<<" is not eligible for individual loan.";
        else if(g2.monthly_income>=25000 && g2.yrs>=15 && g2.cibil_score>=200)
            cout<<"\nGovernment Employee with ID - "<<g2.id<<" is eligible for an individual loan of INR 5 lakhs";
        else if(g2.monthly_income>=50000 && g2.yrs>=20 && g2.cibil_score>=300)
            cout<<"\nGovernment Employee with ID - "<<g2.id<<" is eligible for an individual loan of INR 10 lakhs";
        else
            cout<<"\nGovernment Employee with ID - "<<g2.id<<" is not eligible for individual loan.";

        if(p1.rating < 3)
            cout<<"\nPrivate Employee with ID - "<<p1.id<<" is not eligible for individual loan.";
        else if(p1.monthly_income>=35000 && p1.yrs>=15 && p1.cibil_score>=250)
            cout<<"\nPrivate Employee with ID - "<<p1.id<<" is eligible for an individual loan of INR 5 lakhs";
        else if(p1.monthly_income>=70000 && p1.yrs>=20 && p1.cibil_score>=350)
            cout<<"\nPrivate Employee with ID - "<<p1.id<<" is eligible for an individual loan of INR 10 lakhs";
        else
            cout<<"\nGovernment Employee with ID - "<<p1.id<<" is not eligible for individual loan.";

        if(p2.rating < 3)
            cout<<"\nPrivate Employee with ID - "<<p2.id<<" is not eligible for individual loan.";
        else if(p2.monthly_income>=35000 && p2.yrs>=15 && p2.cibil_score>=250)
            cout<<"\nPrivate Employee with ID - "<<p1.id<<" is eligible for an individual loan of INR 5 lakhs";
        else if(p2.monthly_income>=70000 && p2.yrs>=20 && p2.cibil_score>=350)
            cout<<"\nPrivate Employee with ID - "<<p2.id<<" is eligible for an individual loan of INR 10 lakhs";
        else
            cout<<"\nGovernment Employee with ID - "<<p2.id<<" is not eligible for individual loan.";
    }
    else if(ch == 'J')
    {
        GovEmp g = g1;
        PrivEmp p = p1;
        if(g.Disc_Act || p.rating < 3)
            cout<<"\nGovernment Employee 1 and Private Employee 1 are not eligible for a joint loan.";
        else if((g.monthly_income + p.monthly_income >= 50000) && (g.yrs + p.yrs >= 30))
            cout<<"\nGovernment Employee 1 and Private Employee 1 are eligible for a joint loan of INR 5 lakhs";
        else if((g.monthly_income + p.monthly_income >= 100000) && (g.yrs + p.yrs >= 40))
            cout<<"\nGovernment Employee 1 and Private Employee 1 are eligible for a joint loan of INR 10 lakhs";
        else
            cout<<"\nGovernment Employee 1 and Private Employee 1 are not eligible for a joint loan.";

        p = p2;
        if(g.Disc_Act || p.rating < 3)
            cout<<"\nGovernment Employee 1 and Private Employee 2 are not eligible for a joint loan.";
        else if((g.monthly_income + p.monthly_income >= 50000) && (g.yrs + p.yrs >= 30))
            cout<<"\nGovernment Employee 1 and Private Employee 2 are eligible for a joint loan of INR 5 lakhs";
        else if((g.monthly_income + p.monthly_income >= 100000) && (g.yrs + p.yrs >= 40))
            cout<<"\nGovernment Employee 1 and Private Employee 2 are eligible for a joint loan of INR 10 lakhs";
        else
            cout<<"\nGovernment Employee 1 and Private Employee 2 are not eligible for a joint loan.";

        g = g2;
        if(g.Disc_Act || p.rating < 3)
            cout<<"\nGovernment Employee 2 and Private Employee 2 are not eligible for a joint loan.";
        else if((g.monthly_income + p.monthly_income >= 50000) && (g.yrs + p.yrs >= 30))
            cout<<"\nGovernment Employee 2 and Private Employee 2 are eligible for a joint loan of INR 5 lakhs";
        else if((g.monthly_income + p.monthly_income >= 100000) && (g.yrs + p.yrs >= 40))
            cout<<"\nGovernment Employee 2 and Private Employee 2 are eligible for a joint loan of INR 10 lakhs";
        else
            cout<<"\nGovernment Employee 2 and Private Employee 2 are not eligible for a joint loan.";

        p = p1;
        if(g.Disc_Act || p.rating < 3)
            cout<<"\nGovernment Employee 2 and Private Employee 1 are not eligible for a joint loan.";
        else if((g.monthly_income + p.monthly_income >= 50000) && (g.yrs + p.yrs >= 30))
            cout<<"\nGovernment Employee 2 and Private Employee 1 are eligible for a joint loan of INR 5 lakhs";
        else if((g.monthly_income + p.monthly_income >= 100000) && (g.yrs + p.yrs >= 40))
            cout<<"\nGovernment Employee 2 and Private Employee 1 are eligible for a joint loan of INR 10 lakhs";
        else
            cout<<"\nGovernment Employee 2 and Private Employee 1 are not eligible for a joint loan.";
    }
}

int main()
{
    GovEmp g1, g2;
    PrivEmp p1, p2;
    char ch;
    cout<<"\nLoan type - Individual (I) or Joint (J):";
    cin>>ch;
    LoanGrant(ch,g1,g2,p1,p2);
    return 0;
}