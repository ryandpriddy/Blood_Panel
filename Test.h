
#ifndef BLOOD_PANEL_TEST_H
#define BLOOD_PANEL_TEST_H
#include <iostream>

class BloodTest {
private:
    double level{};
    double lowerRange{};
    double upperRange{};
    int percent{};
    std::string metric;
public:
    BloodTest();
    explicit BloodTest(int percent);
    BloodTest(double level, double lowerRange, double upperRange, const std::string& metric);
    virtual ~BloodTest();

    static int calcPercent(double level, double lowerRange, double upperRange);
    virtual void print()=0; //pure virtual function
    static std::string perName(int num);

    std::string getMetric();

    double getLevel() const;
    void setLevel(double level);

    double getLowerRange() const;
    void setLowerRange(double lowerRange);

    double getUpperRange() const;
    void setUpperRange(double upperRange);

    int getPercent() const;
    void setPercent(int percent);
};

/*----------------------------------------------------------------------------------------------------------------------*/

class Hb: public BloodTest{ //indicates inheritance where BloodTest is base class and Hb is derived class
private:
    std::string name;
public:
    const std::string &getName() const;
    void setName(const std::string &name);
    Hb(const std::string& name, double level, double lowerRange, double upperRange, const std::string& metric);
    ~Hb() override; //explicitly state override for virtual destructor
    void print() override; //explicitly state override for virtual print statement
};

/*----------------------------------------------------------------------------------------------------------------------*/

class RBC: public BloodTest{
private:
    std::string name;
public:
    const std::string &getName() const;
    void setName(const std::string &name);
    RBC(const std::string& name, double level, double lowerRange, double upperRange, const std::string& metric);
    ~RBC() override;
    void print() override;
};

/*----------------------------------------------------------------------------------------------------------------------*/

class WBC: public BloodTest{
private:
    std::string name;
public:
    const std::string &getName() const;
    void setName(const std::string &name);
    WBC(const std::string& name, double level, double lowerRange, double upperRange, const std::string& metric);
    ~WBC() override;
    void print() override;
};

/*----------------------------------------------------------------------------------------------------------------------*/

class Platelet: public BloodTest{
private:
    std::string name;
public:
    const std::string &getName() const;
    void setName(const std::string &name);
    Platelet(const std::string& name, double level, double lowerRange, double upperRange, const std::string& metric);
    ~Platelet() override;
    void print() override;
};

/*----------------------------------------------------------------------------------------------------------------------*/

class Hct: public BloodTest{
private:
    std::string name;
public:
    const std::string &getName() const;
    void setName(const std::string &name);
    Hct(const std::string& name, double level, double lowerRange, double upperRange, const std::string& metric);
    ~Hct() override;
    void print() override;
};

/*----------------------------------------------------------------------------------------------------------------------*/

class MCV: public BloodTest{
private:
    std::string name;
public:
    const std::string &getName() const;
    void setName(const std::string &name);
    MCV(const std::string& name, double level, double lowerRange, double upperRange, const std::string& metric);
    ~MCV() override;
    void print() override;
};

/*----------------------------------------------------------------------------------------------------------------------*/

class MCH: public BloodTest{
private:
    std::string name;
public:
    const std::string &getName() const;
    void setName(const std::string &name);
    MCH(const std::string& name, double level, double lowerRange, double upperRange, const std::string& metric);
    ~MCH() override;
    void print() override;
};

/*----------------------------------------------------------------------------------------------------------------------*/

class MCHC: public BloodTest{
private:
    std::string name;
public:
    const std::string &getName() const;
    void setName(const std::string &name);
    MCHC(const std::string& name, double level, double lowerRange, double upperRange, const std::string& metric);
    ~MCHC() override;
    void print() override;
};

/*----------------------------------------------------------------------------------------------------------------------*/

class Neutrophil: public BloodTest{
private:
    std::string name;
public:
    const std::string &getName() const;
    void setName(const std::string &name);
    Neutrophil(const std::string& name, int percent);
    ~Neutrophil() override;
    void print() override;
};

/*----------------------------------------------------------------------------------------------------------------------*/

class Lymphocyte: public BloodTest{
private:
    std::string name;
public:
    const std::string &getName() const;
    void setName(const std::string &name);
    Lymphocyte(const std::string& name, int percent);
    ~Lymphocyte() override;
    void print() override;
};

/*----------------------------------------------------------------------------------------------------------------------*/

class Monocyte: public BloodTest{
private:
    std::string name;
public:
    const std::string &getName() const;
    void setName(const std::string &name);
    Monocyte(const std::string& name, int percent);
    ~Monocyte() override;
    void print() override;
};

/*----------------------------------------------------------------------------------------------------------------------*/

class Eosinophil: public BloodTest{
private:
    std::string name;
public:
    const std::string &getName() const;
    void setName(const std::string &name);
    Eosinophil(const std::string& name, int percent);
    ~Eosinophil() override;
    void print() override;
};

/*----------------------------------------------------------------------------------------------------------------------*/

class Basophil: public BloodTest{
private:
    std::string name;
public:
    const std::string &getName() const;
    void setName(const std::string &name);
    Basophil(const std::string& name, int percent);
    ~Basophil() override;
    void print() override;
};

/*----------------------------------------------------------------------------------------------------------------------*/

#endif
