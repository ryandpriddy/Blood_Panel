#include "Test.h"
#include <iostream>
#include <cmath>

BloodTest::BloodTest()= default; //explicit declaration for compiler to treat as default

BloodTest::BloodTest(int percent): level(0), lowerRange(0), upperRange(0){ //constructor used by percent only blood tests
    BloodTest::percent = percent;
}
BloodTest::BloodTest(double level, double lowerRange, double upperRange, const std::string& metric){ //constructor used by all others
    BloodTest::level = level;
    BloodTest::lowerRange = lowerRange;
    BloodTest::upperRange = upperRange;
    BloodTest::percent = calcPercent(level, lowerRange, upperRange); //function call to calculate percentile in normal range
    BloodTest::metric = metric;
}
int BloodTest::calcPercent(double level, double lowerRange, double upperRange){ //Math component
    double number = ((level - lowerRange)/(upperRange - lowerRange))*100; //determines where in the normal range the percentile is
    int roundedNumber = static_cast<int>(std::round(number));
    return roundedNumber; //rounded up to whole number (int) for simplicity in statements
}
//Destructor - explanation in printed statement
BloodTest::~BloodTest(){std::cout << "Parent class destructor: This runs second because it is virtual" << std::endl;}

std::string BloodTest::perName(int number){ //determines how to refer to number based on least significant number
    std::string str;
    int num = number % 10;
    switch (num) {
        case 0: str = "th";
            break;
        case 1: str = "st";
            break;
        case 2: str = "nd";
            break;
        case 3: str = "rd";
            break;
        default: str = "th";
    }
    return std::to_string(number) + str; //passes back number with appropriate tail (1st, 2nd, 3rd, etc)
}

void BloodTest::print(){} //virtual so never called despite test being of type BloodTest

//standard getter setters
double BloodTest::getLevel() const {return level;}
void BloodTest::setLevel(double level) {BloodTest::level = level;}

double BloodTest::getLowerRange() const {return lowerRange;}
void BloodTest::setLowerRange(double lowerRange) {BloodTest::lowerRange = lowerRange;}

double BloodTest::getUpperRange() const {return upperRange;}
void BloodTest::setUpperRange(double upperRange) {BloodTest::upperRange = upperRange;}

int BloodTest::getPercent() const {return percent;}
void BloodTest::setPercent(int percent) {BloodTest::percent = percent;}

std::string BloodTest::getMetric() {return metric;}

/*--------------------------------------------Child Classes below-------------------------------------------------------*/
//constructor collects information and then passes parameters up to parent constructor for storage and processing
Hb::Hb(const std::string& name, double level, double lowerRange, double upperRange, const std::string& metric):BloodTest(level, lowerRange, upperRange, metric){
    Hb::name = name;
}
Hb::~Hb(){std::cout << "Hb Child class destructor: This runs first" << std::endl;} //Destructor
void Hb::print(){ //print statement to explain results
    std::cout << Hb::name << " has a level of " << BloodTest::getLevel() << BloodTest::getMetric() << " with range of " << BloodTest::getLowerRange() << BloodTest::getMetric() << " to " << BloodTest::getUpperRange() << BloodTest::getMetric() << std::endl;
    std::cout << "Therefore, the patient is in the " << BloodTest::perName(BloodTest::getPercent()) << " percentile for normal " << Hb::name << std::endl << std::endl;
}
const std::string &Hb::getName() const {return name;} //standard getter setters
void Hb::setName(const std::string &name) {Hb::name = name;};

/*----------------------------------------------------------------------------------------------------------------------*/

RBC::RBC(const std::string& name, double level, double lowerRange, double upperRange, const std::string& metric):BloodTest(level, lowerRange, upperRange, metric){
    RBC::name = name;
}
RBC::~RBC(){std::cout << "RBC Child class destructor: This runs first" << std::endl;}

void RBC::print(){
    std::cout << RBC::name << " has a level of " << BloodTest::getLevel() << BloodTest::getMetric() << " with range of " << BloodTest::getLowerRange() << BloodTest::getMetric() << " to " << BloodTest::getUpperRange() << BloodTest::getMetric() << std::endl;
    std::cout << "Therefore, the patient is in the " << BloodTest::perName(BloodTest::getPercent()) << " percentile for normal " << RBC::name << std::endl << std::endl;
}
const std::string &RBC::getName() const {return name;}
void RBC::setName(const std::string &name) {RBC::name = name;};

/*----------------------------------------------------------------------------------------------------------------------*/

WBC::WBC(const std::string& name, double level, double lowerRange, double upperRange, const std::string& metric):BloodTest(level, lowerRange, upperRange, metric){
    WBC::name = name;
}
WBC::~WBC(){std::cout << "WBC Child class destructor: This runs first" << std::endl;}
void WBC::print(){
    std::cout << WBC::name << " has a level of " << BloodTest::getLevel() << BloodTest::getMetric() << " with range of " << BloodTest::getLowerRange() << BloodTest::getMetric() << " to " << BloodTest::getUpperRange() << BloodTest::getMetric() << std::endl;
    std::cout << "Therefore, the patient is in the " << BloodTest::perName(BloodTest::getPercent()) << " percentile for normal " << WBC::name << std::endl << std::endl;
}
const std::string &WBC::getName() const {return name;}
void WBC::setName(const std::string &name) {WBC::name = name;};

/*----------------------------------------------------------------------------------------------------------------------*/

Platelet::Platelet(const std::string& name, double level, double lowerRange, double upperRange, const std::string& metric):BloodTest(level, lowerRange, upperRange, metric){
    Platelet::name = name;
}
Platelet::~Platelet(){std::cout << "Platelet Child class destructor: This runs first" << std::endl;}

void Platelet::print(){
    std::cout << Platelet::name << " has a level of " << BloodTest::getLevel() << BloodTest::getMetric() << " with range of " << BloodTest::getLowerRange() << BloodTest::getMetric() << " to " << BloodTest::getUpperRange() << BloodTest::getMetric() << std::endl;
    std::cout << "Therefore, the patient is in the " << BloodTest::perName(BloodTest::getPercent()) << " percentile for normal " << Platelet::name << std::endl << std::endl;
}
const std::string &Platelet::getName() const {return name;}
void Platelet::setName(const std::string &name) {Platelet::name = name;};

/*----------------------------------------------------------------------------------------------------------------------*/

Hct::Hct(const std::string& name, double level, double lowerRange, double upperRange, const std::string& metric):BloodTest(level, lowerRange, upperRange, metric){
    Hct::name = name;
}
Hct::~Hct(){std::cout << "Hct Child class destructor: This runs first" << std::endl;}
void Hct::print(){
    std::cout << Hct::name << " has a level of " << BloodTest::getLevel() << BloodTest::getMetric() << " with range of " << BloodTest::getLowerRange() << BloodTest::getMetric() << " to " << BloodTest::getUpperRange() << BloodTest::getMetric() << std::endl;
    std::cout << "Therefore, the patient is in the " << BloodTest::perName(BloodTest::getPercent()) << " percentile for normal " << Hct::name << std::endl << std::endl;
}
const std::string &Hct::getName() const {return name;}
void Hct::setName(const std::string &name) {Hct::name = name;};

/*----------------------------------------------------------------------------------------------------------------------*/

MCV::MCV(const std::string& name, double level, double lowerRange, double upperRange, const std::string& metric):BloodTest(level, lowerRange, upperRange, metric){
    MCV::name = name;
}
MCV::~MCV(){std::cout << "MCV Child class destructor: This runs first" << std::endl;}
void MCV::print(){
    std::cout << MCV::name << " has a level of " << BloodTest::getLevel() << BloodTest::getMetric() << " with range of " << BloodTest::getLowerRange() << BloodTest::getMetric() << " to " << BloodTest::getUpperRange() << BloodTest::getMetric() << std::endl;
    std::cout << "Therefore, the patient is in the " << BloodTest::perName(BloodTest::getPercent()) << " percentile for normal " << MCV::name << std::endl << std::endl;
}
const std::string &MCV::getName() const {return name;}
void MCV::setName(const std::string &name) {MCV::name = name;};

/*----------------------------------------------------------------------------------------------------------------------*/

MCH::MCH(const std::string& name, double level, double lowerRange, double upperRange, const std::string& metric):BloodTest(level, lowerRange, upperRange, metric){
    MCH::name = name;
}
MCH::~MCH(){std::cout << "MCH Child class destructor: This runs first" << std::endl;}
void MCH::print(){
    std::cout << MCH::name << " has a level of " << BloodTest::getLevel() << BloodTest::getMetric() << " with range of " << BloodTest::getLowerRange() << BloodTest::getMetric() << " to " << BloodTest::getUpperRange() << BloodTest::getMetric() << std::endl;
    std::cout << "Therefore, the patient is in the " << BloodTest::perName(BloodTest::getPercent()) << " percentile for normal " << MCH::name << std::endl << std::endl;
}
const std::string &MCH::getName() const {return name;}
void MCH::setName(const std::string &name) {MCH::name = name;};

/*----------------------------------------------------------------------------------------------------------------------*/

MCHC::MCHC(const std::string& name, double level, double lowerRange, double upperRange, const std::string& metric):BloodTest(level, lowerRange, upperRange, metric){
    MCHC::name = name;
}
MCHC::~MCHC(){std::cout << "MCHC Child class destructor: This runs first" << std::endl;}
void MCHC::print(){
    std::cout << MCHC::name << " has a level of " << BloodTest::getLevel() << BloodTest::getMetric() << " with range of " << BloodTest::getLowerRange() << BloodTest::getMetric() << " to " << BloodTest::getUpperRange() << BloodTest::getMetric() << std::endl;
    std::cout << "Therefore, the patient is in the " << BloodTest::perName(BloodTest::getPercent()) << " percentile for normal " << MCHC::name << std::endl << std::endl;
}
const std::string &MCHC::getName() const {return name;}
void MCHC::setName(const std::string &name) {MCHC::name = name;};

/*----------------------------------------------------------------------------------------------------------------------*/
//Constructor collects information and passes info up to BloodTest's secondary constructor
Neutrophil::Neutrophil(const std::string& name, int percent):BloodTest(percent){
    Neutrophil::name = name;
}
Neutrophil::~Neutrophil(){std::cout << "Neutrophil Child class destructor: This runs first" << std::endl;}
void Neutrophil::print(){
    std::cout << Neutrophil::name << " is in the " <<BloodTest::perName(BloodTest::getPercent()) << " percentile" << std::endl;
}
const std::string &Neutrophil::getName() const {return name;}
void Neutrophil::setName(const std::string &name) {Neutrophil::name = name;};

/*----------------------------------------------------------------------------------------------------------------------*/

Lymphocyte::Lymphocyte(const std::string& name, int percent):BloodTest(percent){
    Lymphocyte::name = name;
}
Lymphocyte::~Lymphocyte(){std::cout << "Lymphocyte Child class destructor: This runs first" << std::endl;}
void Lymphocyte::print(){
    std::cout << Lymphocyte::name << " is in the " <<BloodTest::perName(BloodTest::getPercent()) << " percentile" << std::endl;
}
const std::string &Lymphocyte::getName() const {return name;}
void Lymphocyte::setName(const std::string &name) {Lymphocyte::name = name;};

/*----------------------------------------------------------------------------------------------------------------------*/

Monocyte::Monocyte(const std::string& name, int percent):BloodTest(percent){
    Monocyte::name = name;
}
Monocyte::~Monocyte(){std::cout << "Monocyte Child class destructor: This runs first" << std::endl;}
void Monocyte::print(){
    std::cout << Monocyte::name << " is in the " <<BloodTest::perName(BloodTest::getPercent()) << " percentile" << std::endl;
}
const std::string &Monocyte::getName() const {return name;}
void Monocyte::setName(const std::string &name) {Monocyte::name = name;};

/*----------------------------------------------------------------------------------------------------------------------*/

Eosinophil::Eosinophil(const std::string& name, int percent):BloodTest(percent){
    Eosinophil::name = name;
}
Eosinophil::~Eosinophil(){std::cout << "Eosinophil Child class destructor: This runs first" << std::endl;}
void Eosinophil::print(){
    std::cout << Eosinophil::name << " is in the " <<BloodTest::perName(BloodTest::getPercent()) << " percentile" << std::endl;
}
const std::string &Eosinophil::getName() const {return name;}
void Eosinophil::setName(const std::string &name) {Eosinophil::name = name;};

/*----------------------------------------------------------------------------------------------------------------------*/

Basophil::Basophil(const std::string& name, int percent):BloodTest(percent){
    Basophil::name = name;
}
Basophil::~Basophil(){std::cout << "Basophil Child class destructor: This runs first" << std::endl;}
void Basophil::print(){
    std::cout << Basophil::name << " is in the " <<BloodTest::perName(BloodTest::getPercent()) << " percentile" << std::endl;
}
const std::string &Basophil::getName() const { return name;}
void Basophil::setName(const std::string &name) {Basophil::name = name;};
