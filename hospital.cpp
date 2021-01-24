#include<iostream>
using namespace std;

class HospitalInfo{

    public : 
    string hospitalName;
    double chiefID ;
    string hospitalAdress;
    void printHospitalInfo(){
        cout <<"---- Welcome To  "<<hospitalName<<" Hospital"<<"----"<<endl;
    }
    void hospitalOtherInfo(){
        cout <<"|Adress:"<<hospitalAdress<<"|"<<endl;
        cout <<"|Chief's ID:"<<chiefID<<"|"<<endl;
    }
    bool EditOption(){
        char userAns;
        bool flag;
        cout<<"Edit Hospital Info(Y Or N):";
        cin >> userAns;
        if (userAns =='y' || userAns == 'Y'){
            flag = true;
        }
        if (userAns == 'n' || userAns =='N'){
            flag = false;
        }
        return flag;
    }
    string  editHospital(string name , double ID , string add){
        string userName;
        double userID;
        string userAdd;
        cout<<"  ->Name:"<<hospitalName<<endl;
        cout <<" ->Adress:"<<hospitalAdress<<endl;
        cout <<" ->Chief's ID:"<<chiefID<<endl;        
        cout <<"Enter new Name:";
        cin>>userName;
        cout<<"Enter new Adress:";
        cin>>userAdd;
        cout<<"Enter new ID:";
        cin>>userID;
        hospitalName = userName;
        hospitalAdress  = userAdd;
        chiefID = userID;
        printHospitalInfo();
        hospitalOtherInfo();
        return hospitalName;
        return hospitalAdress;
    }
};

class HospitalRoom : public HospitalInfo {
    public:
        string sectionName;
        int roomNumber;
        string supervisorName;

        void printRoomInfo(){
            cout<<"---- Welcome To "<<sectionName<<"Section"<<" ---- "<<endl;
            cout<<"   <----> "<<"Section:"<<sectionName<<endl;
            cout<<"   <---->"<<"Room Numbers:"<<roomNumber<<endl;
            cout<<"   <---->"<<"Supervisor:"<<supervisorName<<endl;
            cout <<"--------------------------------------------"<<endl;
            }
        string EditRoomOptions(){
            string userSec,userSuper;
            int userRoom;
            cout<<"        >>>>Edit Section:";
            cin>>userSec;
            cout<<"        >>>>Edit Room Number:";
            cin>>userRoom;
            cout<<"        >>>>Edit Supervisor:";
            cin>>userSuper;
            sectionName = userSec;
            supervisorName = userSuper;
            roomNumber = userRoom;
            return sectionName;
        }
};
class HosptitalEmployee : public HospitalRoom{
    public:
    string employeeFName;
    string employeeLName;
    double employeeSSN;
    double employeeCell;
    string employeeAuth;
    void printemployeeInfo(){
        cout<<"  |        Employee List        |"<<endl;
        cout<<"  [*]Employee Firstname ->"<<employeeFName<<endl;
        cout<<"  [*]Employee Lastname ->"<<employeeLName<<endl;
        cout<<"  [*]Employee Social Security Number->"<<employeeSSN<<endl;
        cout<<"  [*]Employee Cell Number->"<<employeeCell<<endl;
        cout<<"  [*]Employee Authority->"<<employeeAuth<<endl;    
    }
    string editEmployeeInfo(){
        string userFname,userLname,auth;        
        double Ssn , number;
        cout<<"Change Firstname:";
        cin>>userFname;
        cout<<"Change Lastname";
        cin>>userLname;
        cout<<"Change Social Security Number:";
        cin>>Ssn;
        cout<<"Change Cell Number:";
        cin>>number;
        cout<<"Change Authority:";
        cin>>auth;
        employeeFName =userFname;
        employeeLName =userLname;
        employeeAuth = auth;
        employeeCell = number;
        employeeSSN = Ssn;
        return userFname;
    }
};
class HospitalPatient : public HosptitalEmployee
{
    public:
    string patientName;
    float patientAge;
    double patientSSN,patientCell;
    string patientDate,patientDr,patientSection;
    void printPatientInfo(){
        cout<<"<<<<<<<< Patient Info >>>>>>>"<<endl;
        cout<<"Name:"<<patientName<<endl;
        cout<<"Age:"<<patientAge<<endl;
        cout<<"Doctor:"<<patientDr<<endl;
        cout<<"Date:"<<endl;
        cout<<"Social Security Number:"<<patientSSN<<endl;
        cout<<"Phone Number:"<<patientCell<<endl;
        cout<<"-------------------"<<endl;
    }
    string editHospitalPatient(){
        string usrName,usrDate,usrDr,usrSection;        
        double usrSsn , usrNumber;
        float usrAge;
        cout<<"Change Name:";
        cin>>usrName;
        cout<<"Change Age:";
        cin>>usrAge;
        cout<<"Change Dr:";
        cin>>usrDr;        
        cout<<"Change Social Security Number:";
        cin>>usrSsn;
        cout<<"Change Cell Number:";
        cin>>usrNumber;
        patientName =usrName;
        patientAge = usrAge;
        patientDr = usrDr;
        patientCell = usrNumber;
        patientSSN = usrSsn;
        return usrName;        
    }
    bool pushButton(){

        cout<<"Enter Emergency Button?(Y OR N):";
        if(EditOption() == true ){
            cout<<"*** Chief Has Paged A Nurse In Your Room"<<endl;

        }
        if(EditOption() == false ){
            cout<<"*** Nurses Are StandBy For Any Emergency Case"<<endl;
        }
        return 1;
    }

};
class HospitalCheckout : public HospitalPatient{
    public:
        string checkOutPatient;
        double daysHospitilized;
        double hospitalRate;
        bool insurance;
        double insuranceDis;
        double hostpitalCost;
    double hospitalBill( double daysHospitilized , double HospitalRate, bool insurance , string checkOutPatient){
        cout<<"***  Patient Has Checked Out On  ***"<<checkOutPatient<<endl;
        hostpitalCost = (daysHospitilized * hospitalRate);
        if( insurance == true){
            insuranceDis = hostpitalCost * 0.04;
            hostpitalCost = hostpitalCost - insuranceDis;
            cout<<"Patient Had Insurance All Cost Reduced By 40% "<<"Final Bill Is:"<<hostpitalCost<<" patient checked out at " <<checkOutPatient<<endl;
        }else{
                cout<<"Patient Did NOT Had Insurance All Cost Are Normal Tariff "<<"Final Bill Is:"<<hostpitalCost<<" patient checked out at " <<checkOutPatient<<endl;

        }
        return hostpitalCost;
    }
};
int main(){

//    Hospital patient1;
//    patient1.patientName ="Uri";
//    patient1.patientAge = 19;
//    patient1.printPatientInfo();
    HospitalCheckout newHospital;
//    HospitalInfo newHospital;

    newHospital.hospitalName = "Beheshti";
    newHospital.chiefID = 5225;
    newHospital.hospitalAdress = "Tehran Modaress";
    newHospital.printHospitalInfo();
    newHospital.hospitalOtherInfo();
    newHospital.EditOption();
    if( newHospital.EditOption() == true ){
        newHospital.editHospital("Hosseini",1323,"Ferdosi Tehran");
    }
    newHospital.HospitalRoom::sectionName = "Emergency";
    newHospital.HospitalRoom::roomNumber = 15;
    newHospital.HospitalRoom::supervisorName="Bozorgi";
    newHospital.HospitalRoom::printRoomInfo();    
    newHospital.employeeFName = "hossein";
    newHospital.employeeLName = "Azizi";
    newHospital.employeeCell = 91110;
    newHospital.employeeSSN = 202000;
    newHospital.employeeAuth ="Azmayeshgah";
    if(newHospital.EditOption() == true){
        newHospital.EditRoomOptions();
        newHospital.printRoomInfo();
    }
    newHospital.printemployeeInfo();
    if(newHospital.EditOption() == true ){
        newHospital.editEmployeeInfo();
        newHospital.printemployeeInfo();
    }
    newHospital.printPatientInfo();
    if(newHospital.EditOption() == true){
        newHospital.editHospitalPatient();
        newHospital.printPatientInfo();
    }
    newHospital.pushButton();
    newHospital.hospitalBill(14,20000,false,"10.2.1399");

}