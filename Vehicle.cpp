#include<bits/stdc++.h>
using namespace std;
//This Vehicle class represents the real-world vehicle enity
//with atributes(Type,Maxspeed,Fueltype) and methods(Accelerate,getters,displayinfo)


/*
Bài tập này yêu cầu phân tích các yêu cầu quản lý phương tiện để xác định các thực thể, thuộc tính và hành vi chính. 
Tôi bắt đầu bằng cách xác định thực thể chính (Vehicle) với các thuộc tính cốt lõi (loại, tốc độ tối đa, nhiên liệu) và hành vi (tăng tốc). 
Thách thức chính là xác định thuộc tính nào là thiết yếu so với tùy chọn và cách đóng gói chúng đúng theo nguyên tắc OOP.

Khó khăn chính là quản lý bộ đệm đầu vào khi chuyển đổi giữa cin và getline, đã được giải quyết bằng hàm clearInputBuffer và cùng với sự trợ giúp của DeepSeek
OOP giúp code có tổ chức hơn-đóng gói bảo vệ dữ liệu hơn

Quá trình này củng cố OOP mô hình hóa thực thể thực tế thông qua lớp và đối tượng , giúp code có tổ chức dể bảo trì và mở rộng hơn.

Qua bài này tôi đã học được thêm cho bản thân:
+Phân tích yêu cầu thực tế để thiết kế đối tượng phù hợp
+Áp dụng các nguyên tắc của OOP vào lập trình C++
+Xử lý các vấn đề nhập liệu
+Tổ chức mã nguồn rõ ràng, dễ bảo trì
*/
class Vehicle{
    private:
        string Type;            //Vehicle Type
        int MaxSpeed;           //Maximum Speed(km/h)
        int Year;               //Manufacturing year
        string FuelType;        //Gasoline or Petroline
        double FuelConsumption; //Fuel consumption(liters/100km)
        int Capacity;           //Passenger capacity
        string LicensePlate;    //License plate number
    public:
        Vehicle(string _Type, int _MaxSpeed,int _Year, string _FuelType,double _FuelConsumption,int _Capacity,string _LicensePlate)
            :Type(_Type), MaxSpeed(_MaxSpeed),Year(_Year), FuelType(_FuelType), FuelConsumption(_FuelConsumption), Capacity(_Capacity), LicensePlate(_LicensePlate){}// a constructor to initalize the type, max speed and fueal type of the vehicle
        void accelerate(){
            if(MaxSpeed<0){
                throw invalid_argument("The MaxSpeed must be greater than zero");// Error when enter the max speed lower than zero
            }
            if(MaxSpeed==0){
                cout<<"The "<<Type<<" is stopping"<<endl;// When max speed is 0 its mean the vehicle is stopping
            }else{
            cout<<"The "<<Type<<" is accelerating to "<<to_string(MaxSpeed)<<"km/h"<<endl;
            }
        }
        string getType(){
            return Type;
        }
        int getMaxSpeed(){
            return MaxSpeed;
        }
        int getYear(){
            return Year;
        }
        string getFuelType(){
            return FuelType;
        }
        double getFuelConsumption(){
            return FuelConsumption;
        }
        int getCapacity(){
            return Capacity;
        }
        string getLicensePlate(){
            return LicensePlate;
        }
        void displayInfo(){
            cout<<"===VEHICLE'S INFORMATION===\n";
            cout<<"Type: "<<Type<<endl;
            cout<<"Max speed: "<<MaxSpeed<<"km/h"<<endl;
            cout<<"Manufacturing year: "<<Year<<endl;
            cout<<"Fuel type: "<<FuelType<<endl;
            cout<<"Fuel consumption: "<<fixed<<setprecision(2)<<FuelConsumption<<"litters/100km"<<endl;
            cout<<"Capacity: "<<Capacity<<"persons"<<endl;
            cout<<"License plate: "<<LicensePlate<<endl;
        }
};
void displayMenu(){
    cout<<"===VEHICLE MANAGEMENT SYSTEM===\n";
    cout<<"1. Add a new vehicle\n";
    cout<<"2. Display all vehicles\n";
    cout<<"3. Search for a vehicle by license plate\n";
    cout<<"4. Simulate acceleration for all vehicles\n";
    cout<<"5. Exit program\n";
    cout<<"===============================\n";
    cout<<"Enter your choice: \n";  
}
// Function to clear \n after enter the input
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
int main(){
    vector<Vehicle> vehicles;
    int choice;


    // Add some sample vehicles
    vehicles.push_back(Vehicle("Car", 200,2020, "Gasoline", 7.5, 5, "29A-12345"));
    vehicles.push_back(Vehicle("Truck", 150,2018, "Diesel", 12.3, 3, "29B-54321"));
    vehicles.push_back(Vehicle("Motorcycle", 180,2022, "Gasoline", 2.1, 2, "29C-98765"));


    do{
        displayMenu();
        cin>>choice;
        clearInputBuffer();
        

        switch(choice){
            case 1: {
                string type, fuel, license;
                int speed, cap, year;
                double consumption;
                
                cout << "\n----- ADD A NEW VEHICLE -----" << endl;
                cout << "Enter vehicle type: ";
                getline(cin, type);
                
                cout << "Enter maximum speed (km/h): ";
                cin >> speed;
                
                cout << "Enter fuel type: ";
                clearInputBuffer();
                getline(cin, fuel);
                
                cout << "Enter fuel consumption (liters/100km): ";
                cin >> consumption;
                
                cout << "Enter passenger capacity: ";
                cin >> cap;
                
                cout << "Enter license plate number: ";
                clearInputBuffer();
                getline(cin, license);
                
                cout << "Enter manufacturing year: ";
                cin >> year;
                
                vehicles.push_back(Vehicle(type, speed,year, fuel, consumption, cap, license));
                cout << "Vehicle added successfully!" << endl;
                break;
            }
            case 2:{
                if(vehicles.empty()){
                    cout<<"No vehicles in the system!\n";
                }else{
                    for(int i=0;i<vehicles.size();i++){
                        vehicles[i].displayInfo();
                    }
                }
                break;
            }
            case 3:{
                if(vehicles.empty()){
                    cout<<"No vehicles in the system!\n";
                }else{
                    string licenseplate;
                    cout<<"Enter the License Plate search for: \n";
                    getline(cin,licenseplate);

                    bool found=false;
                    for(int i=0;i<vehicles.size();i++){
                        if(vehicles[i].getLicensePlate()==licenseplate){
                            vehicles[i].displayInfo();
                            found=true;
                            break;
                        }
                    }
                    if(!found){
                        cout<<"No vehicle found with the license plate: "<<licenseplate<<endl;
                    }
                }
                break;
            }
            case 4:{
                if (vehicles.empty()) {
                    cout << "No vehicles in the system!" << endl;
                } else {
                    cout << "\n----- ACCELERATION SIMULATION -----" << endl;
                    for (size_t i = 0; i < vehicles.size(); i++) {
                        vehicles[i].accelerate();
                    }
                }
                break;
            }
            case 5:{
                cout<<"Thank you for using the program! Goodbye\n";
                break;
            }
            default:{
                cout<<"Invalid choice, Please try again\n";
            }
        }
    }while(choice!=5);
    return 0;
}