#include <iostream>

using namespace std;

constexpr float SI = 1000;
constexpr float Stime = 60;

float getconspervial(float x, float cc)
{
	float a = 0;
	cout << "how many mg in the bag/vial " << endl;
	cin >> x;
	cout << "\n how many cc inthe bag??" << endl;
	cin >> cc;
	cout << " " << endl;
	a = x / cc;
	return a;
}

float getWeight(float a)
{
	cout << "what is the weight" << endl;
	cin >> a;
	return a;
}

float getdosage(float x)
{
	cout << "what is the minimum dosage intended?" << endl;
	cin >> x;
	cout << " " << endl;
	return x;
}

float getdosage2(float x)
{
	cout << "what is the maximum dosage intended?" << endl;
	cin >> x;
	cout << " " << endl;
	return x;
}

void get_range_mlsperhour()
{
	float mg = 1;
	float vol = 1;
	float mlsperhour1;
	float mlsperhour2;
	float dose1 =1;
	float dose2 =1;
	float weight= 1;
	float cons;

	dose1 = getdosage(dose1);
	dose2 = getdosage2(dose2);
	weight = getWeight(weight);
	cons = getconspervial(mg, vol);

	mlsperhour1 = weight * dose1 / SI / cons * Stime;
	mlsperhour2 = weight * dose2 / SI / cons * Stime;

	cout << "range of mls is " << mlsperhour1 << " to  " << mlsperhour2 << " mls per hour \n\n";
}

float get_dose()
{
	float dose;
	float cons;
	float weight = 1.0;
	float mg = 1.0;
	float mls = 1.0;
	float mlsperhour;

	cons = getconspervial(mls, mg);
	weight = getWeight(weight);
	cout << "what is the current infusion rate ?\n";
	cin >> mlsperhour;

	dose = mlsperhour * SI * cons / weight / Stime;
	return dose;
}

void display_menu(){
	
	cout << "menu \n"<< endl;
	cout << "  1 : convert mlsperhour to mcg/kg/min \n\n"<< endl;
	cout << "  2 : convert mcg/kg/min to mlserhour \n"<< endl;	
}


int main(int argc, char *argv[])
{	
	cout << "this program convert ionotrope dose from mlsperhour to mcg/kg/min and vice versa\n\n\n" <<endl;
	
	display_menu();
	
	int choice ;
	
	
	char again = ' ';
	
	do{
	cout << "  choice : ";
	cin >>choice ;
	
	switch (choice){
		case 1: cout <<get_dose()<< " mcg/kg/min " << endl;
		break;
		case 2 :  get_range_mlsperhour();
		break;
		default : cout << "you are entering other option pig";
		cin.get();
	}
		
		cout << " do you want to repeat calculate \n\n";
		
		cin >>again;
		
		cout <<">>>>>>>>>>>>>>>> next calculation >>>>>>>>>>>>>>>>>>"<<endl;
		
	} while (again =='y'||again =='Y');
		
		
	return 0;
}
