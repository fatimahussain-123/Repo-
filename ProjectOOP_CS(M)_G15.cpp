#include<iostream>
using namespace std;
// Base Class / parent class

class Complaint {
	
	// Attributes
	
protected:
	
		int complaintID;
		string userName;
		string complaintDetails;
		string status;
		
    //Methods
    
public:
	
	// Input Function to take input/ complain from user
	
 void inputComplaint() {
 	
 	cout<<" Enter Your ID ";
 	cin>>complaintID;
 	cout<<" Enter Your Name ";
 	cin>>userName;
 	cout<<" Enter Your Complain ";
 	cin>>complaintDetails;
// 	cout<<" Enter Status  ";
// 	cin>>status;
 	
    status = "Pending";
    
 }	
 
 // Display Function to display complain details
 
 void displayComplaint() {
 	
 	cout<<"\n ID : "<<complaintID<<endl;
 	cout<<" User Name : "<<userName<<endl;
 	cout<<" Complain  : "<<complaintDetails<<endl;
 	cout<<" Status : "<<status<<endl;
	 
}	
	 int getID(){
	 	
        return complaintID;
    }

    string getUserName(){
        return userName;
    }

    void updateStatus(string s){
        status = s;
    }
};
/* Derived class 
single Inheritence --> ComplaintManager derived from base class(parent class) complaint
*/
class ComplaintManager : public Complaint {
	
public:
	
	//Array
	
	Complaint c[100];
	int count=0;
	
	// Add Complaint
	
	void addComplaints() {
		
		c[count].inputComplaint();
		count++;
		
		cout<<" Complaint Added\n";
}

   // View Complaint
   
void viewComplaints(){
	
        if(count == 0) {

            cout<<"\n No Complaints Available "<<endl;
        }

        else {

            for(int i=0; i<count; i++) {

                c[i].displayComplaint();
            }
        }

	
	
}

  // Delete Complaint
	
	void deleteComplaints(int id) {
		
        int found = 0;

        for(int i=0; i<count; i++){

            if (c[i].getID() == id){

                for(int j=i; j<count-1; j++){

                    c[j] = c[j+1];
                }

                count--;
                found = 1;

                cout<<"\nComplaint Deleted Successfully\n";
                break;
            }
        }
              if(found == 0){
            cout<<"\nComplaint Not Found\n";
        }
}

  // Update Complaint
	void updateComplaints(int id){
		
     int found = 0;

        string newStatus;

        for(int i=0; i<count; i++) {

            if(c[i].getID() == id) {

                cout<<" Enter New Status : ";
                cin>>newStatus;

                c[i].updateStatus(newStatus);

                found = 1;

                cout<<"\n Complaint Updated Successfully"<<endl;
            }
        }

        if(found == 0){
            cout<<"\nComplaint Not Found "<<endl;
        }
}
	
	void searchComplaints(int id) {
		
		int searchID;
		cout<<"Enter search ID  :";
		cin>>searchID;
		
		 int found = 0;

        for(int i=0; i<count; i++) {

            if(c[i].getID() == id) {

                c[i].displayComplaint();

                found = 1;
            }
        }

        if(found == 0) {

            cout<<"\n Complaint Not Found\n";
        }
    }


   void showALLComplaints(){
   	
   	if(count == 0){

            cout<<"\nNo Complaints Available\n";
        }

        for(int i=0; i<count; i++){

            c[i].displayComplaint();
        }
    }
    
      
}; 

/* Derived class 
 MultiLevel Inheritence --> Admin derived from Complaint Manager and 
                            Complaint Manager derived from base class complaint 
*/
class Admin : public ComplaintManager {
private:
	int adminID;
	string adminName;
	
public:
	
	void manageComplaints() {
	 
	cout<<"\nAdmin Managing Complaints...\n";

}
	
};

/* Derived class 
 MUltiple Inheritence --> staff class derived from complaint class and complaintmanager class
*/

class Staff : public Complaint , public ComplaintManager {
private:
	int staffID;
	string staffName;
public:
	
	void resloveComplaint(int id) {
		
		updateComplaints(id);

        cout<<"\nComplaint Resolved "<<endl;
    }

	void checkStatus(int id) {
		
		 searchComplaints(id);
}
	
};
int main(){
	ComplaintManager CM;
	Admin a;
	Staff s;
	
	int pick;
	int id;
	
	do{
		
	cout<<"\n * Complaint Managment System *"<<endl;
	cout<<"  Menu: "<<endl;
	cout<<" 1. Add Complaints "<<endl;
	cout<<" 2. View Complaints "<<endl;
	cout<<" 3. Search Complaints "<<endl;
	cout<<" 4. Delete  Complaints "<<endl;
	cout<<" 5. Update Complaints "<<endl;
	cout<<" 6. Manage Complaints "<<endl;
	cout<<" 7. Reslove Complaints "<<endl;
	cout<<" 0. Exit "<<endl;
		
	cout<<" Pick a category...";
	cin>>pick;
	   
	   switch(pick){
	   
        case 1:

            CM.addComplaints();
            break;

        case 2:

            CM.viewComplaints();
            break;

        case 3:

            cout<<" Enter Complaint ID : ";
            cin>>id;

            CM.searchComplaints(id);
            break;

        case 4:

            cout<<" Enter Complaint ID : ";
            cin>>id;

            CM.deleteComplaints(id);
            break;

        case 5:

            cout<<" Enter Complaint ID : ";
            cin>>id;

            CM.updateComplaints(id);
            break;

        case 6:

            a.manageComplaints();
            break;

        case 7:

            cout<<" Enter Complaint ID : ";
            cin>>id;

            s.resloveComplaint(id);
            break;

        case 0:

            cout<<"\n Program Ended\n";
            break;

        default:

            cout<<"\n Invalid Choice\n";
        }

	}
	while(pick!=0);
	
}
