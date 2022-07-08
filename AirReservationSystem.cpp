#include <iostream>

using namespace std;
#define INT_MAX 9999999
#define V 5


//Ibrar Ul Haq

//Structure of Passenger
struct passenger
{
    string passengerName;
    int passengerAge;
    string cnic_no;
    string departure_time;
    string landing_time;
    int seat_row_no;
    int seat_coloumn_no;
    string phoneNum;
    string gender;
    passenger *next = NULL;
    passenger *prev = NULL;
};
passenger *last = NULL, *first = NULL;



//Menus
void login();
void costOfTravel();
void admin_menu();
void ticketBookingMenu();
void planAJourney();

//Seating Arrangement 2D array
int Matrix[50][4];
void displayMatrix();
void add_edge(int x,int y);

//Passenger Methods using Doubly Linked List
passenger* searchPassenger();
void displaySpecificPassenger();
void displayPassenger();
void addPassenger();
void cancelPassengerTicket();

//Pilot Methods using Queue and Array
void search(string);
void pilotDelete(string);
void pilotAdd(string);
void avalaiblePilots();
void addPilotToJourney();
void ReturnPilots();

//Graph Data Structure
int visited1[V];
int routes[V][V];
void initialize();
void addRoute(string, string);
void costCalculate(int);
//Dijkstra
int adjMatrix[V][V];
void initialize1(int arr[][V]);
void dijkstra(int graph[V][V],int);
 void addEdges(int arr[][V],int, int,int);
string ShortDistance[V] = {"Islamabad", "Karachi", "Lahore","Rawalpindi","Faislabad"};

int size=6;
int turn=0;
string pilots[6] = {"Aaraiz", "Ibrar", "Ibrahim",  "Ali", "Asma", "Bilal"};
//Implementing Queue Data Structure

class Queue
{
public:
    int size;
    int front;
    int rear;
    string *q;
    Queue(int s)
    {
        front = rear = -1;
        size = s;
        q = new string[size];
    }
//Check if Full
bool isFull()
    {
        if (rear == size - 1)
        {
            return true;
        }
        return false;
    }
//Check if Empty
bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        return false;
    }
//Enqueue
void Enqueue(string x)
    {
        if (isFull())
        {
            cout << "No Space Available" << endl;
            return;
        }
        else
        {
            if (front == -1 && rear == -1)
            {
                rear++;
                front++;
            }
            else
            {
                rear++;
            }
            q[rear] = x;
        }
    }
    
//Dequeue
string Dequeue()
    {   
        string x="";
        if (isEmpty())
        {
            cout << "Already empty" << endl;
        }
        else
        {
            string x = q[rear];
            if (rear == front)
            {
                rear = front = -1;
            }
            else
            {
                rear--;
            }
            return x;
        }
        return x;
    }

//Display Queue
void QueueDisplay()
    {
        if (isEmpty())
        {
            cout << "No record to found..." << endl;
            return;
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                cout << q[i] << endl;
            }
        }
    }
    
};
Queue obj(99);
// Passengers Structure implements doubly linked list 
// Login Menu
void login()
{
    // Admin Log in Details
    string adminName = "Comsats";
    string adminPass = "1122";
    cout << "****************************\n\n";
    cout << "Welcome to Airline Management System \n"<<endl;
    cout << "****************************\n\n";
    cout << "Do you want to login? yes/no: ";
    string opt;
    cin >> opt;
    if (opt == "yes")
    {

        int Option1 = 0;
        int Option2 = 0;

        cout << "Please Enter the log In details\n";

        do
        {

            cout << "Enter admin name: ";

            string guess_admin;

            cin >> guess_admin;

            if (guess_admin == adminName)
            {
                Option1 = 1;
            }

            else
            {

                cout << "Admin name is incorrect" << endl;
            }

        }

        while (Option1 != 1);

        do
        {

            string guess_pass;

            cout << "Enter admin passcode: ";

            cin >> guess_pass;

            if (guess_pass == adminPass)
            {
                Option2 = 1;
            }

            else
            {

                cout << "Incorrect Password. Kindly try again" << endl;
            }

        } while (Option2 != 1);
        admin_menu();
    }
    else if(opt == "no"){
    	exit(0);
	}
	else
    {
        cout<<"Invalid Input......"<<endl;
        login();
    }
}


// Admin Menu
void admin_menu()
{
    string choice;
    while (true)
    {
        cout << "\n------------------------------------------------------------\n";
        cout << "Enter any choice to perform any of the below opertion:" << endl;
        cout << "1 . Ticket Booking" << endl;
        cout << "2 . Plan a journey" << endl;
        cout << "3 . Cost of travel" << endl;
        cout << "4 . If you want to check minum Cost of travel" << endl;
        cout << "0 . To exit" << endl;
        cout << "\n------------------------------------------------------------\n";
        cin >> choice;
        if (choice == "1")
        {
            ticketBookingMenu();
        }
        else if (choice == "2")
        {
            planAJourney();
        }
		else if(choice == "3"){
        	costOfTravel();
		}
			else if(choice == "4"){
			
			
				initialize1(adjMatrix);
				
				
addEdges(adjMatrix,0,1,6);
addEdges(adjMatrix,0,3,12);
addEdges(adjMatrix,0,4,8);
addEdges(adjMatrix,1,2,13);
addEdges(adjMatrix,4,3,2);

	int src = -1;
	string sourceNode;
	cout<<"Enter source node"<<endl;
	cout<<"Islamabad"<<endl;
	cout<<"Karachi"<<endl;
	cout<<"Lahore"<<endl;
	cout<<"Rawalpindi"<<endl;
	cout<<"Faislabad"<<endl;
	cin>>sourceNode;
	
	for(int i = 0; i<6; i++){
		if(sourceNode == ShortDistance[i]){
			src = i;
			dijkstra(adjMatrix, i);
			break;
		
		
	}			
	}
		if(src == -1){
		cout<<"City is not available"<<endl;
	}
	       		
       } else if (choice == "0")
        {
            break;
        }
        else
        {
            continue;
        }
    }
}
// Ticket Booking Menu
void ticketBookingMenu()
{
    string choice;

    while (true)
    {
        cout << "\n------------------------------------------------------------\n";
        cout << "Enter any choice to perform any of the below opertion:" << endl;
        cout << "1 . Add Passenger Records" << endl;
        cout << "2 . Display All Passenger Records" << endl;
        cout << "3 . Display Specific Passenger Record" << endl;
        cout << "4 . Display Booked Seats"<<endl;
        cout << "5 . Cancel Flight" << endl;
        cout << "0 . To exit" << endl;
        cout << "\n------------------------------------------------------------\n";
        cin >> choice;

        if (choice == "1")
        {
            addPassenger();
        }
        else if (choice == "2")
        {
            displayPassenger();
        }
        else if (choice == "3")
        {
            displaySpecificPassenger();
        }
        else if (choice == "4")
        {
            displayMatrix();
        }
        else if (choice == "5")
        {
            cancelPassengerTicket();
        }
        else if (choice == "0")
        {
            break;
        }
        else
        {
            continue;
        }
    }
}


void displayMatrix() {
	
   int i, j;
  
   for(i = 0; i < 50; i++) {
  
      for(j = 0; j < 4; j++) {
  
         cout << Matrix[i][j] << " ";
  
      }
  
      cout << endl;
  
   }
}
void add_edge(int u, int v) {       
  
   Matrix[u][v] = 1;

}

// Add Passenger
void addPassenger()
{

    passenger *curr = new passenger;
    
    string cn;//For CNIC
    
    cout << "Enter the passenger name: ";

    cin >> curr->passengerName;

    cout << "Enter the passenger age: ";

    cin >> curr->passengerAge;
    
    while(true){
    	
    cout << "Enter the cnic of passenger: ";

    cin>>cn;
	
	if(cn.length()==13){
			curr->cnic_no=cn;
		break;
	}
	else continue;
	}
    
    cout << "Enter the departure time: ";

    cin >> curr->departure_time;

    cout << "Enter the landing time: ";

    cin >> curr->landing_time;
    
    while(true){
    	
    while(true){
	
    cout << "Enter the Row seat no: ";

    cin >> curr->seat_row_no;
    
    if(curr->seat_row_no<50&&curr->seat_row_no>0){
    	
    	break;
    	
	}
	else continue;
    }

    while(true){
	
    cout << "Enter the Coloumn seat no: ";

    cin >> curr->seat_coloumn_no;
    
    if(curr->seat_coloumn_no<4&&curr->seat_coloumn_no>0){
    	
    	break;
	}
	else continue;
    }
    
    if(Matrix[curr->seat_row_no][curr->seat_coloumn_no]==1){
    	
    	cout<<"Seat Already Booked Try Again"<<endl;
    	continue;
    	
	}
	else{
	
    add_edge(curr->seat_row_no,curr->seat_coloumn_no);
	break;
	}
	}
    
    cout << "Enter the Gender: ";

    cin >> curr->gender;

    if (first == NULL)
    {
        first = last = curr;
    }
    else
    {
        if (first == last)
        {
            curr->next = NULL;
            first->next = curr;
            last = curr;
        }
        //Insert at End
        else
        {
            curr->next = NULL;
            last->next = curr;
            last = curr;
        }
    }
    cout << "New Passenger added!\n";
}

// Search Method
passenger* searchPassenger()
{
    cout << "Enter the cnic of passenger: ";
    string key;
    cin >> key;
    passenger *p = first;
    while ((p->cnic_no != key) && (p != NULL))
    {
        p = p->next;
    }
    if (p == NULL)
    {
        return NULL;
    }
    else
    {
        return p;
    }
}
void displayPassenger()
{
    passenger *p = first;
   
    while (p != NULL)
    {
        cout << "Passenger Details" << endl;

        cout << "Name: " << p->passengerName << endl;

        cout << "Age: " << p->passengerAge << endl;

        cout << "CNIC: " << p->cnic_no << endl;

        cout << "Gender: " << p->gender << endl;

        cout << "Arrival Time: " << p->landing_time << endl;

        cout << "Departure Time: " << p->departure_time << endl;

        cout << "Seat Coloumn Number: "<<p->seat_coloumn_no<<endl;
        
        cout << "Seat Row Number: "<<p->seat_row_no<<endl;
        
        cout << endl;
     
        p = p->next;
    }
    
}


// Display Specific Passenger
void displaySpecificPassenger()
{
    passenger *p = searchPassenger();
    
    if (p == NULL)
    {
        cout << "No record found.........." << endl;
    }
    else
    {
        cout << "Passenger Details" << endl;

        cout << "Name: " << p->passengerName << endl;

        cout << "Age: " << p->passengerAge << endl;

        cout << "CNIC: " << p->cnic_no << endl;

        cout << "Gender: " << p->gender << endl;

        cout << "Arrival Time: " << p->landing_time << endl;

        cout << "Departure Time: " << p->departure_time << endl;

        cout << "Seat Coloumn Number"<<p->seat_coloumn_no<<endl;
        
        cout << "Seat Row Number"<<p->seat_row_no<<endl;
    }
}

//Cancel Flight
void cancelPassengerTicket()
{
    passenger *p = searchPassenger();
    if (p == NULL)
    {
        cout << "No record found.........." << endl;
    }
    else
    {
        if (p == first)
        {
            p = NULL;
            first = last = NULL;
        }
        else if (p == last)
        {
            last->prev->next == NULL;
            last = last->prev;
        }
        else
        {
            p->prev->next = p->next;
        }
        delete p;
        cout << "Passenger's Flight Cancelled!\n";
    }
}

//<<<<<<<<<<<<<<<<<<<<<<< Plan a Journey >>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
void planAJourney(){
    string choice;
    while (true)
    {
        cout << "\n------------------------------------------------------------\n";
        cout << "Enter any choice to perform any of the below operation:" << endl;
        cout << "1 . Display All Available Pilots" << endl;
        cout << "2 . Add Pilot to Journey" << endl;
        cout << "3 . Search Pilot" << endl;
        cout << "4 . Return Pilot" << endl;
        cout << "0 . To exit" << endl;
        cout << "\n------------------------------------------------------------\n";
        cin >> choice;

        if (choice == "1")
        {
            avalaiblePilots();
        }
        else if (choice == "2")
        {
            addPilotToJourney();
        }
        else if (choice == "3")
        {
            string ser;
            cout<<"Enter The Name of the Pilot you want to search: "<<endl;
            cin>>ser;
            search(ser);
        }
        else if (choice == "4")
        {
            ReturnPilots();
        }
        else if (choice == "0")
        {
            break;
        }
        else
        {
            continue;
        }
    }
}

// Search from array
void search(string element)
{
    for (int i = 0; i < 6; i++)
    {
        if (pilots[i] == element)
        {
     
            cout<<"Pilot "<<pilots[i]<<" Found!"<<endl;
        }
    }

}
//Add to Array
void pilotAdd(string n)

{
   pilots[size++]=n;
}
// Delete From Array
void pilotDelete(string element)
{    
    int i,j;
    for(i=0; i<6; i++)
    {
        if(pilots[i]==element)
        {
            for(j=i; j<(6-1); j++)
                pilots[j] = pilots[j+1];
            i--;
            size--;
        }
    }
}
// Display Avaialable Pilots
void avalaiblePilots()
{
    for (int i = 0; i < size; i++)
    {
        cout << (i + 1) << " " << pilots[i] << endl;
    }
    cout << endl;
}
//Add Pilots to Journey
void addPilotToJourney()
{   
    turn++;
    if (turn>1){
    	cout<<"A pilot is already mid-flight"<<endl;

}
	else {
	
	cout<<"<<<<<<<<<<<<<<<<<< Available Pilots >>>>>>>>>>>>>>>"<<endl;
    avalaiblePilots();
    string name;
    cout << "Enter name of Pilot: ";
    cin >> name;
    pilotDelete(name);
    obj.Enqueue(name);
    
}
}

//Add Pilots to Journey
void ReturnPilots()
{   
    turn--;
	string ret= obj.Dequeue();
    pilotAdd(ret);
}


void costOfTravel(){
	initialize();
    addRoute("Isl", "Kar");
    addRoute("Kar", "Lhr");
    addRoute("Kar", "Fsl");
    addRoute("Fsl", "Rwp");

    costCalculate(0);
}
string cities[] = {"Isl", "Kar", "Lhr", "Rwp", "Fsl"};

class Queue2
{
public:
    int size;
    int front;
    int rear;
    int *q;

    Queue2(int sze)
    {
        front = rear = -1;
        size = sze;
        q = new int[size];
    }

    bool isFull2()
    {
        if (rear == size - 1)
        {
            return true;
       }
        return false;
    }

    bool isEmpty2()
    {
        if (front == -1)
        {
            return true;
        }
        return false;
    }
    void enqueue2(int x)
    {
        if (isFull2())
        {
            cout << "No Space Available" << endl;
            return;
        }
        else
        {
            if (front == -1 && rear == -1)
            {
                rear++;
                front++;
            }
            else
            {
                rear++;
            }
            q[rear] = x;
        }
    }

    int deqeue2()
    {
        if (isEmpty2())
        {
            cout << "Already empty" << endl;
            return -1;
        }
        else
        {
            int x = q[rear];
            if (rear == front)
            {
                rear = front = -1;
            }
            else
            {
                rear--;
            }
            return x;
        }
    }

    void display2()
    {
        if (isEmpty2())
        {
            cout << "No record to found..." << endl;
            return;
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                cout << q[i] << endl;
            }
        }
    }
};
// Initialize the Adjacency Matrix to zero
void initialize()
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            routes[i][j] = 0;
        }
    }
}
// Add Edges in the graph
void connectRoute(int i, int j)
{
    // UnDirected Graph
    int weight;
    cout << cities[i] << " ---> " << cities[j] << " Costs>> ";
    cin >> weight;
    routes[i][j] = weight;
    routes[j][i] = weight;
}
int connectionRoute(string city)
{
    for (int i = 0; i < V; i++)
    {
        if (cities[i] == city)
        {
            return i;
        }
    }
    return -1;
}
int checkConnection(int i, int j)
{
    if (routes[i][j] != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool ValidateCity(string city){
	
	for(int i=0;i<V;i++){
    	if(city==cities[i]){
    		return true;
		}
}
    return false;
}
void addRoute(string departCity, string destination)
{
    int fCity = connectionRoute(departCity);//return index of selected city
    int dCity = connectionRoute(destination);
    bool found1=ValidateCity(departCity);//check city is present int the cities array
    bool found2=ValidateCity(destination);
    if(found1==true && found2==true){
	
	int check = checkConnection(fCity, dCity);
	
    if (check != 0)
    {
        cout << "Flight is already on the way from " << departCity << " ---> " << destination << endl;
        return;
    }
    else
    {
        connectRoute(fCity, dCity);
        cout << "Route Added Successfully" << endl;
    }
    
	}
	else
	{
	cout<<"City not Available"<<endl;	
	}
}
// costCalculate Implememntation
void costCalculate(int i)
{
    Queue2 obj2(100);
    // cout << i << " ";
    for (int k = 0; k < V; k++)
    {
        visited1[k] = 0;
    }
    visited1[i] = 1;
    // Enqueu i for exploration
    obj2.enqueue2(i);
    
    while (!obj2.isEmpty2())
    {
        int node = obj2.deqeue2();
    
        for (int j = 0; j < V; j++)
        {
            if ((routes[node][j] < INT_MAX && routes[node][j] > 0) && visited1[j] == 0)
            {
                cout << cities[node] << " ----> " << cities[j] << " cost:  " << routes[node][j] << endl;
                visited1[j] = 1;
                obj2.enqueue2(j);
            }
        }
    }
}

void addEdges(int arr[][V], int i , int j,int w){
    //Undirected Graph
    arr[i][j] = w;
    arr[j][i] = w;
   
}
void initialize1(int arr[][V]){
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            arr[i][j] = 0;
        }   
    }
}

int minDistance(int dist[], bool sptSet[])
{
   
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}

void printSolution(int dist[],int src)
{
    cout <<"Shortes cost from selected city to other availabel cities " << endl;
    for (int i = 0; i < V; i++)
       	cout<<"Shortest cost from "<<ShortDistance[src]<<" to "<<ShortDistance[i]<<" -> "<<dist[i]<<endl;
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V]; 
    bool sptSet[V]; 
  
    for (int i = 0; i < V; i++){
        dist[i] = INT_MAX, sptSet[i] = false;
    dist[src] = 0;
    }
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)     
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    } 
    printSolution(dist,src);
}
int main()
{
    login(); 
    return 0;
}
