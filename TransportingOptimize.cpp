#include<windows.h>
#include<time.h>
#include<iso646.h> 
#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include <iomanip>

// Variables for filials:
#define SMALL_FILIAL_CATEGORY 0
#define MIDDLE_FILIAL_CATEGORY 1
#define BIG_FILIAL_CATEGORY 2
#define PROBABILITY_BAD_WEATHER 50
#define REDUCED_COST_DUE_TO_WEATHER 0.15
#define START_FILIALS_MONEY 0
#define COST_SMALL_FILIAL 40000
#define COST_MIDDLE_FILIAL 60000
#define COST_BIG_FILIAL 100000

// Variables for data CLIENT randomize:
#define MAX_AMOUNT_MONEY_CLIENT 3300 //+MIN $
#define MIN_AMOUNT_MONEY_CLIENT 200
#define MAX_WEIGHT_OF_CARGO 380 // +MIN $
#define MIN_WEIGHT_OF_CARGO 20
#define START_NUMBER_CLIENT 10
#define MAX_TIME_DELIVERY 9 // +MIN days
#define MIN_TIME_DELIVERY 4
// Variables for TRANSPORT:
#define START_NUMBER_CAR 20
#define START_NUMBER_TRAIN 10
#define START_NUMBER_AIRPLANE 5
#define PRICE_AUTO 5 		//  $/kg
#define	PRICE_TRAIN 3   //  $/kg
#define PRICE_AIRPLANE 20   //  $/kg
#define TIME_DELIVERY_AUTO 6 	//days
#define TIME_DELIVERY_TRAIN 4	//days
#define TIME_DELIVERY_AIRPLANE 1//days
#define PROBABILITY_CRASH_AUTO 90
#define PROBABILITY_CRASH_TRAIN 1
#define PROBABILITY_CRASH_AIRPLANE 0.5
#define COST_AUTO 10000
#define COST_TRAIN 100000
#define COST_AIRPLANE 200000




using namespace std;


class Client {
	private:
		string name;
		string surename;
		int money;
		int weightOfCargo;
		int waitingTime;
		int startFilialID;
		int finishFilialID;
		bool wantFastDelivery;
		int numberInLine;
		bool statusWaiting;
	public:
		Client(string name, string surename, int money, int weightOfCargo, int waitingTime, bool wantFastDelivery)
		{
			this->name = name;
			this->surename = surename;
			this->money = money;
			this->weightOfCargo = weightOfCargo;
			this->waitingTime = waitingTime;
			this->wantFastDelivery = wantFastDelivery;
			this->statusWaiting = false;
		}
		Client()
		{
			this->name = "";
			this->surename = "";
			this->money = 0;
			this->weightOfCargo = 0;
			this->waitingTime = 0;
			this->startFilialID = 0;
			this->finishFilialID = 0;
			this->wantFastDelivery = 0;
			this->statusWaiting = false;
		}
		void setName(string name)
		{
			this->name = name;
		}
		string getName()
		{
			return this->name;
		}
		void setSurename (string surename)
		{
			this->surename = surename;
		}
		string getSurename()
		{
			return this->surename;
		}
		void setMoney (int money)
		{
			this->money = money;
		}
		int getMoney ()
		{
			return this->money;
		}
		void setWeightOfCargo (int weightOfCargo)
		{
			this->weightOfCargo = weightOfCargo;
		}		
		int getWeightOfCargo ()
		{
			return this->weightOfCargo;
		}
		void setWaitingTime(int waitingTime)
		{
			this->waitingTime = waitingTime;
		}
		int getWaitingTime ()
		{
			return this->waitingTime;
		}
		void setStartFilialID (int startFilialID)
		{
			this->startFilialID = startFilialID;
		}
		int getStartFilialID ()
		{
			return this->startFilialID;
		}
		void setFinishFilialID (int finishFilialID)
		{
			this->finishFilialID = finishFilialID;
		}
		int getFinishFilialID ()
		{
			return this->finishFilialID;
		}
		void  setNumberInLine(int numberInLine)
		{
			this->numberInLine = numberInLine;
		}
		int getNumberInLine()
		{
			return this->numberInLine;
		}
		void setWantFastDelivery (bool wantFastDelivery)
		{
			this->wantFastDelivery = wantFastDelivery;
		}
		bool getWantFastDelivery ()
		{
			return this->wantFastDelivery;
		}
		void setStatusWaiting(bool statusWaiting)
		{
			this->statusWaiting = statusWaiting;
		}
		bool getStatusWaiting()
		{
			return this->statusWaiting;
		}
		void info(Client* client)
		{
			if(client->getWantFastDelivery())
			{
				cout << left << setw(10)  <<getName() << setw(15)  <<getSurename() << "��� �����: " 
				<<left << setw(6)  << getWeightOfCargo() << " �������: " << getMoney() 
				<< " �������� �� �����: " <<getWaitingTime ()<< " ����, " << "����� ��������� ���� ������ "<< endl;
			}
			else
				cout << left << setw(10)  <<getName() << setw(15)  <<getSurename() << "��� �����: " 
				<<left << setw(6)  << getWeightOfCargo() << " �������: " << getMoney() 
				<< " �������� �� �����: " <<getWaitingTime ()<< " ����, " << "����� ��������� ���� ������ " << endl;
		}	
		
		~Client () {}
};

class Transport {
	private:
		string name;
		int price; // $/kg
		int timeDelivery;  // days
		int remainingDeliveryTime; // ���������� ����� � ����, days
		int startFilialID;
		int finishFilialID;
		int costOfCargo;
		double probabilityCrash;
	public:
		Transport(string name)
		{
			this->name = name;	
			this->remainingDeliveryTime =0;
			this->costOfCargo =0;
		}
		Transport()
		{
			this->name = "";	
			this->remainingDeliveryTime =0;	
			this->costOfCargo =0;
		}
		void setName(string name)
		{
			this->name = name;	
		}
		string getName() 
		{
			return this->name;
		}
		void setRemainingDeliveryTime(int remainingDeliveryTime)
		{
			this->remainingDeliveryTime = remainingDeliveryTime;
		}
		int getRemainingDeliveryTime()
		{
			return this->remainingDeliveryTime;
		}
		void setStartFilialID (int startFilialID) 
		{
			this->startFilialID = startFilialID;
		}
		int getStartFilialID ()
		{
			return this->startFilialID;
		}
		void setFinishFilialID (int finishFilialID) 
		{
			this->finishFilialID = finishFilialID;
		}
		int getFinishFilialID ()
		{
			return this->finishFilialID;
		}
		void setCostOfCargo (int costOfCargo)
		{
			this->costOfCargo = costOfCargo;
		}
		int getCostOfCargo ()
		{
			return this->costOfCargo;
		}
				
		virtual int getPrice ()	= 0;
		virtual int getTimeDelivery () = 0;	
		virtual double getProbabilityCrash () = 0;
		virtual int getCategory () = 0;	
		virtual int getCost () = 0;		
		virtual void info() = 0;
		friend void headerForInfo()
		{
			cout << "��� ����������: " << left << setw(15)  <<" �������� ����������: "	<< " �������� �����: " << " ����� ��������: " <<  endl;
		}
		virtual void infoForFilial(Transport* transport) = 0;
	
		
		virtual ~Transport() { }
};

class Car : public Transport {
		public:
		Car(string name) : Transport(name)	{	}
		Car() : Transport()		{	}
		
		int getPrice ()	
		{
			return PRICE_AUTO;
		}
		int getTimeDelivery ()
		{
			return TIME_DELIVERY_AUTO;
		}	
		double getProbabilityCrash ()
		{
			return PROBABILITY_CRASH_AUTO;
		}
		int getCategory ()
		{
			return SMALL_FILIAL_CATEGORY;
		} 
		int getCost ()
		{
			return COST_AUTO;
		}
		
		void infoForFilial(Transport* transport)
		{
			if(transport->getRemainingDeliveryTime() == 0)
			{
				cout << left << setw(20) <<"����������   " << left << setw(15)  <<transport->getName() << left << setw(15) << "��� ����  "	
				<< transport->getTimeDelivery ()<< " ����"  << endl;
			}
			else 
			{
				cout << left << setw(20) <<"����������   " << left << setw(15)  <<transport->getName() 
				 << transport->getRemainingDeliveryTime() << left << setw(15) << " ����"	
				<< transport->getTimeDelivery ()<< " ����"  << endl;
			}	
		}
		void info() 
		{
			cout << setw(15) << left<< "���������� " << left << setw(15)  <<getName() << "��������� ��������� 1 ��: " 
			<<left << setw(6) << getPrice() 
			<< " ����� ��������: "<< getTimeDelivery ()<< " ����, " 
			<< "����� �� ��������: " << getRemainingDeliveryTime() << " ����, " 
			<< " ���������: " << getCategory() << " ,����������� ������: " <<  getProbabilityCrash () << endl;
		}
		~Car () { }
};

class Train : public Transport {
		public:
		Train(string name) : Transport(name)	{	}
		Train() : Transport()		{	}
		
		int getPrice ()	
		{
			return PRICE_TRAIN;
		}
		int getTimeDelivery ()
		{
			return TIME_DELIVERY_TRAIN;
		}	
		double getProbabilityCrash ()
		{
			return PROBABILITY_CRASH_TRAIN;
		}
		int getCategory ()
		{
			return MIDDLE_FILIAL_CATEGORY;
		} 
		int getCost ()
		{
			return COST_TRAIN;
		}
		void infoForFilial(Transport* transport)
		{
			if(transport->getRemainingDeliveryTime() == 0)
			{
				cout << left << setw(20) << "�����" << left << setw(15)  <<transport->getName() << left << setw(15) << "��� ����  "	
			<< transport->getTimeDelivery ()<< " ����"  << endl;
			}
			else 
			{
				cout << left << setw(20) << "�����" << left << setw(15)  <<transport->getName() << 
				 transport->getRemainingDeliveryTime() << left << setw(15)  << " ����"	
			<< transport->getTimeDelivery ()<< " ����"  << endl;
			}	
		}
			void info() 
		{
			cout << setw(15)<< left << "����� " << left << setw(15)  <<getName() << "��������� ��������� 1 ��: " 
			<<left << setw(6) << getPrice() 
			<< " ����� ��������: "<< getTimeDelivery ()<< " ����, " 
			<< "����� �� ��������: " << getRemainingDeliveryTime() << " ����, " 
			<< " ���������: " << getCategory() << " ,����������� ������: " <<  getProbabilityCrash () << endl;
		}
		~Train () { }
};

class Airplane : public Transport {
		public:
		Airplane(string name) : Transport(name)	{	}
		Airplane() : Transport()		{	}
		
		int getPrice ()	
		{
			return PRICE_AIRPLANE;
		}
		int getTimeDelivery ()
		{
			return TIME_DELIVERY_AIRPLANE;
		}	
		double getProbabilityCrash ()
		{
			return PROBABILITY_CRASH_AIRPLANE;
		}
		int getCategory ()
		{
			return BIG_FILIAL_CATEGORY;
		} 
		int getCost ()
		{
			return COST_AIRPLANE;
		}
		void infoForFilial(Transport* transport)
		{
			if(transport->getRemainingDeliveryTime() == 0)
			{
				cout << left << setw(20) << "�������" << left << setw(15)  <<transport->getName() << left << setw(15) << "��� ����  "	
				<< transport->getTimeDelivery ()<< " ����"  << endl;
			}
			else 
			{
				cout << left << setw(20) << "�������"<< left << setw(15)  <<transport->getName() 
				<< transport->getRemainingDeliveryTime() << left << setw(15) << " ����"	
				<< transport->getTimeDelivery ()<< " ����"  << endl;
			}	
		}
			void info() 
		{
			cout << setw(15)<< left <<"�������"<< left << setw(15)  <<getName() << "��������� ��������� 1 ��: " 
			<<left << setw(6) << getPrice() 
			<< " ����� ��������: "<< getTimeDelivery ()<< " ����, " 
			<< "����� �� ��������: " << getRemainingDeliveryTime() << " ����, " 
			<< " ���������: " << getCategory() << " ,����������� ������: " <<  getProbabilityCrash () << endl;
		}
		~Airplane () { }
};

class Filial {
		private:
		string name;
		int balance;
		int filialID;
		bool weather;		
		static int filialsMoney;
	public:
		Filial(string name)
		{
			this->name = name;
			this->balance = 0;
			this->weather = false;	
			this->filialID = 0;		
		}
		Filial()
		{
			this->name = "";
			this->balance = 0;
			this->weather = false;
			this->filialID = 0;
		}
		void setFilialName(string name)
		{
			this->name = name;
		}
		string getFilialName()
		{
			return this->name;
		}
		void setBalance (int balance)
		{
			this->balance = balance;
		}
		int getBalance ()
		{
			return this->balance;
		}
		void setFilialID (int FilialID)
		{
			this->filialID = FilialID;
		}
		int getFilialID ()
		{
			return this->filialID;
		}
		void setWeather ()
		{
			if(rand()%100 < PROBABILITY_BAD_WEATHER)
				this->weather = true;
			else 
				this->weather = false;
		}
		bool getWeather()
		{
			return this->weather;
		}
		
		friend void generateWeather (vector <Filial*> &filial)
		{
			for(int i=0; i<filial.size(); i++)
			{
				filial[i]->setWeather();
			}
		}
		friend void organizeClients (vector <Client*> &client, vector <Filial*> &filial)
		{
			for(int i=0; i<filial.size(); i++)
			{
				int num = 1;
				for(int j=0; j<client.size(); j++)
				{
					if(filial[i]->getFilialID() == client[j]->getStartFilialID() )
					{
						client[j]->setNumberInLine(num);
						num++;
					}
				}
			}
			cout << "������� ����� � �������" << endl;
		}
	
		virtual void infoAboutBalance() = 0;
		void infoAboutClient(vector <Client*> &client, vector <Filial*>&filial)
		{
			int count=1;
			for(int i=0; i<client.size(); i++)
			{
				if(client[i]->getStartFilialID() == getFilialID() )
				{
					cout << count << ". " ;
					client[i]->info(client[i]) ;
					cout << " �� �������  " << getFilialName();
					for(int j=0; j<filial.size(); j++)
					{
						if(filial[j]->getFilialID() == client[i]->getFinishFilialID())
						{
							cout << " � ������ " << filial[j]->getFilialName() << endl<< endl;
						}
					}
					count++;
				}
			}
		}
		
		void infoAboutTransport(vector<Transport*>&transport)
		{
			for(int i=0; i<transport.size(); i++)
			{
				if(transport[i]->getStartFilialID() == getFilialID() )
				{
					transport[i]->infoForFilial(transport[i]);
				}
			}
		}
		
		
		 void findTransport (vector <Transport*>&transport, vector <Client*>&client)
		{
			for(int j=0; j<client.size(); j++)
			{	
				int bestTime = client[j]->getWaitingTime()+1;
				int numberOfBestTransport = transport.size()+1;
				
				if(client[j]->getWantFastDelivery () == true) // ���� � ���������� �������� ��������, ���� �� ����������� ������� ��������
				{
					for(int i=0; i<transport.size(); i++) // ���� �� ������� �����������
					{
						if (transport[i]->getStartFilialID () == getFilialID() and transport[i]->getRemainingDeliveryTime() == 0 ) // �������� �� ���������� ����� ������� ���������� ID, �� ���������� �������� �����������
						{
							if(transport[i]->getTimeDelivery()  <= client[j]->getWaitingTime() ) // ������� ����� �������� ���������� � ��������� �������
							{
								if(client[j]->getWeightOfCargo()*transport[i]->getPrice() <= client[j]->getMoney() ) // �������� �� ��, ����� ������� �����
								{
									if(transport[i]->getTimeDelivery() <= bestTime)
									{
										bestTime = transport[i]->getTimeDelivery();
										numberOfBestTransport = i;
										client[j]->setStatusWaiting(false);
										
									}
								}	
							}		
						}
						else if (transport[i]->getStartFilialID () == getFilialID() and transport[i]->getRemainingDeliveryTime() != 0 ) // ��������� �������� � ������
						{
							if(transport[i]->getTimeDelivery() + transport[i]->getRemainingDeliveryTime()  <= client[j]->getWaitingTime() ) // ������� ����� �������� ���������� � ��������� �������
							{
								if(client[j]->getWeightOfCargo()*transport[i]->getPrice() <= client[j]->getMoney() ) // �������� �� ��, ����� ������� �����
								{
									if(transport[i]->getTimeDelivery() <= bestTime)
									{
										bestTime = transport[i]->getTimeDelivery();
										numberOfBestTransport = i;
										client[j]->setStatusWaiting(true);
										
									}
								}	
							}		
						}
					}
				}
				int bestPrice = client[j]->getMoney();
				
				if(client[j]->getWantFastDelivery () == false) // ���� � ���������� ���� ��������, ���� �� ���������� ���� ��������
				{
					for(int i=0; i<transport.size(); i++) // ���� �� ������� �����������
					{
						if (transport[i]->getStartFilialID () == getFilialID() and transport[i]->getRemainingDeliveryTime() == 0 ) // �������� �� ���������� ����� ������� ���������� ID, �� ���������� �������� �����������
						{
							if(client[j]->getWeightOfCargo()*transport[i]->getPrice() <= client[j]->getMoney() ) // �������� �� ��, ����� ������� �����
							{
								if(client[j]->getWeightOfCargo()*transport[i]->getPrice() <=bestPrice)
								{
									 bestPrice = client[j]->getWeightOfCargo()*transport[i]->getPrice();
									 numberOfBestTransport = i;
									 client[j]->setStatusWaiting(false);
									 
								}
							}
						}
						else if (transport[i]->getStartFilialID () == getFilialID() and transport[i]->getRemainingDeliveryTime() != 0 ) // ��������� �������� � ������
						{
							if(client[j]->getWeightOfCargo()*transport[i]->getPrice() <= client[j]->getMoney() ) // �������� �� ��, ����� ������� �����
							{
								if(client[j]->getWeightOfCargo()*transport[i]->getPrice() <=bestPrice)
								{
									 bestPrice = client[j]->getWeightOfCargo()*transport[i]->getPrice();
									 numberOfBestTransport = i;
									 client[j]->setStatusWaiting(true);
									 
								}
							}
						}
					}
				}
				
				if(numberOfBestTransport < transport.size() and client[j]->getStatusWaiting() == false)	//���������� ������, ������ �����
				{
					cout << "������ �������" << endl
					<< "������ " << client[j]->getName() << " " << client[j]->getSurename()<< " ������� " << bestPrice << "$ , �������� ������������ �� " 
					<< transport[numberOfBestTransport]->getTimeDelivery() << " ����, �������� �������� - " 
					<< transport[numberOfBestTransport]->getName() << endl<< endl;
					setBalance (getBalance() + bestPrice);
					setFilialsMoney(getFilialsMoney() + bestPrice ) ;
					transport[numberOfBestTransport]->setRemainingDeliveryTime(transport[numberOfBestTransport]->getTimeDelivery()); 	// ������������� ������� ���� �� ��������
					transport[numberOfBestTransport]->setFinishFilialID(transport[numberOfBestTransport]->getStartFilialID()); 		// ��������� ����� �����������
					transport[numberOfBestTransport]->setStartFilialID(client[j]->getFinishFilialID())	; 			// ��������� ���������� ����������� ������� �������
					transport[numberOfBestTransport]->setCostOfCargo( bestPrice);
					client.erase(client.begin() + j); 
				}	
				else 
				{
					cout << "������ ��������� " << endl
					<< "���������� ��������� ���������� ������� " << client[j]->getName() << " " <<client[j]->getSurename() << endl<< endl;
					client.erase(client.begin() + j); 
				}
			}
		}
		
		void findTransport (vector <Transport*>&transport, vector <Client*>&client, int j)
		{
				int bestTime = client[j]->getWaitingTime()+1;
				int numberOfBestTransport = transport.size()+1;
				
				if(client[j]->getWantFastDelivery () == true) // ���� � ���������� �������� ��������, ���� �� ����������� ������� ��������
				{
					for(int i=0; i<transport.size(); i++) // ���� �� ������� �����������
					{
						if (transport[i]->getStartFilialID () == getFilialID() and transport[i]->getRemainingDeliveryTime() == 0 ) // �������� �� ���������� ����� ������� ���������� ID, �� ���������� �������� �����������
						{
							if(transport[i]->getTimeDelivery()  <= client[j]->getWaitingTime() ) // ������� ����� �������� ���������� � ��������� �������
							{
								if(client[j]->getWeightOfCargo()*transport[i]->getPrice() <= client[j]->getMoney() ) // �������� �� ��, ����� ������� �����
								{
									if(transport[i]->getTimeDelivery() <= bestTime)
									{
										bestTime = transport[i]->getTimeDelivery();
										numberOfBestTransport = i;
										client[j]->setStatusWaiting(false);
										
									}
								}	
							}		
						}
						else if (transport[i]->getStartFilialID () == getFilialID() and transport[i]->getRemainingDeliveryTime() != 0 ) // ��������� �������� � ������
						{
							if(transport[i]->getTimeDelivery() + transport[i]->getRemainingDeliveryTime()  <= client[j]->getWaitingTime() ) // ������� ����� �������� ���������� � ��������� �������
							{
								if(client[j]->getWeightOfCargo()*transport[i]->getPrice() <= client[j]->getMoney() ) // �������� �� ��, ����� ������� �����
								{
									if(transport[i]->getTimeDelivery() <= bestTime)
									{
										bestTime = transport[i]->getTimeDelivery();
										numberOfBestTransport = i;
										client[j]->setStatusWaiting(true);
										
									}
								}	
							}		
						}
					}
				}
				int bestPrice = client[j]->getMoney();
				
				if(client[j]->getWantFastDelivery () == false) // ���� � ���������� ���� ��������, ���� �� ���������� ���� ��������
				{
					for(int i=0; i<transport.size(); i++) // ���� �� ������� �����������
					{
						if (transport[i]->getStartFilialID () == getFilialID() and transport[i]->getRemainingDeliveryTime() == 0 ) // �������� �� ���������� ����� ������� ���������� ID, �� ���������� �������� �����������
						{
							if(client[j]->getWeightOfCargo()*transport[i]->getPrice() <= client[j]->getMoney() ) // �������� �� ��, ����� ������� �����
							{
								if(client[j]->getWeightOfCargo()*transport[i]->getPrice() <=bestPrice)
								{
									 bestPrice = client[j]->getWeightOfCargo()*transport[i]->getPrice();
									 numberOfBestTransport = i;
									 client[j]->setStatusWaiting(false);
									 
								}
							}
						}
						else if (transport[i]->getStartFilialID () == getFilialID() and transport[i]->getRemainingDeliveryTime() != 0 ) // ��������� �������� � ������
						{
							if(client[j]->getWeightOfCargo()*transport[i]->getPrice() <= client[j]->getMoney() ) // �������� �� ��, ����� ������� �����
							{
								if(client[j]->getWeightOfCargo()*transport[i]->getPrice() <=bestPrice)
								{
									 bestPrice = client[j]->getWeightOfCargo()*transport[i]->getPrice();
									 numberOfBestTransport = i;
									 client[j]->setStatusWaiting(true);
								}
							}
						}
					}
				}
				
				if(numberOfBestTransport < transport.size() and client[j]->getStatusWaiting() == false)	//���������� ������, ������ �����
				{
					cout << "������ �������" << endl
					<< "������ " << client[j]->getName() << " " << client[j]->getSurename()<< " ������� " << bestPrice << "$ , �������� ������������ �� " 
					<< transport[numberOfBestTransport]->getTimeDelivery() << " ����, �������� �������� - " 
					<< transport[numberOfBestTransport]->getName() << endl<< endl;
					setBalance (getBalance() + bestPrice);
					setFilialsMoney(getFilialsMoney() + bestPrice ) ;
					transport[numberOfBestTransport]->setRemainingDeliveryTime(transport[numberOfBestTransport]->getTimeDelivery()); 	// ������������� ������� ���� �� ��������
					transport[numberOfBestTransport]->setFinishFilialID(transport[numberOfBestTransport]->getStartFilialID()); 		// ��������� ����� �����������
					transport[numberOfBestTransport]->setStartFilialID(getFilialID())	; 			// ��������� ���������� ����������� ������� �������
					client.erase(client.begin() + j); 
				}	
				
				else 
				{
					cout << "������ ��������� " << endl
					<< "���������� ��������� ���������� ������� " << client[j]->getName() << " " <<client[j]->getSurename() << endl<< endl;
					client.erase(client.begin() + j); 
				}
		}
		friend void endTurn (vector <Transport*>&transport, vector <Filial*>&filial)
		{
			for(int i=0; i<transport.size(); i++) 
			{
				if(transport[i]->getRemainingDeliveryTime() > 0) // �� ���� ��� � ����
				{
					cout << transport[i]->getName() << " ����..." << endl;
					int x = rand()%10000;
					if(x <= transport[i]->getProbabilityCrash()*100) // ������ ������
					{
						for (int j=0; j<filial.size(); j++) // ��������� �������, ������ ��� ����� (�.�. ������ ������ �����������)
						{
							if(filial[j]->getFilialID() == transport[i]->getFinishFilialID())
							{
								filial[j]->setBalance(filial[j]->getBalance() - 2*transport[i]->getCostOfCargo() );
								cout << transport[i]->getName() << " ����� � ������ � ������ �� ����� " 
								<< transport[i]->getCostOfCargo() << "$" << endl;
								cout << "������: " << filial[j]->getFilialName() << " ������������ �� " << transport[i]->getCostOfCargo()*2 << "$" <<endl;
								transport.erase(transport.begin() + i);
								i--;
							}
						}	
					}
					else
					{
						transport[i]->setRemainingDeliveryTime( transport[i]->getRemainingDeliveryTime() - 1);
					}	
				}
			}
			cout << endl;
			for(int i=0; i<filial.size(); i++) 
			{
				for(int j=i+1; j<filial.size(); j++)
				{
					if(filial[i]->getWeather() == true and filial[j]->getWeather() == true) //������ ������ �� ����
					{
						for(int k=0; k<transport.size(); k++ )
						{
							if(transport[k]->getStartFilialID() == filial[i]->getFilialID() and transport[k]->getFinishFilialID() == filial[j]->getFilialID() )
							{
								if( transport[k]->getRemainingDeliveryTime() > 0) // ���� ������ ����
								{
									cout << "�� ���� �� " << filial[i]->getFilialName() << " �� " << filial[j]->getFilialName() 
									<< " ������ ������, " << transport[k]->getName() <<
									" �������� ����� �����, �������� ������� ����� ����� �������" << endl;
									cout << "������: " << filial[j]->getFilialName() << " ������������ �� " <<transport[k]->getCostOfCargo()*15/100 << "$" <<endl;
									filial[j]->setBalance(filial[j]->getBalance() - transport[k]->getCostOfCargo()*15/100 );
								}	
							}
							if (transport[k]->getStartFilialID() == filial[j]->getFilialID() and transport[k]->getFinishFilialID() == filial[i]->getFilialID() )
							{
								if( transport[k]->getRemainingDeliveryTime() > 0) // ���� ������ ����
								{
									cout << "�� ���� �� " << filial[i]->getFilialName() << " �� " << filial[j]->getFilialName() 
									<< " ������ ������, " << transport[k]->getName() <<
									" �������� ����� �����, �������� ������� ����� ����� �������" << endl;
									cout << "������: " << filial[j]->getFilialName() << " ������������ �� " <<transport[k]->getCostOfCargo()*15/100 << "$" <<endl;
									filial[i]->setBalance(filial[i]->getBalance() - transport[k]->getCostOfCargo()*15/100 );
								}
							}
						}
					}		
				}
			}
			for(int i=0; i<filial.size(); i++)
			{
				cout << endl << "��������� ��������� ������  " << filial[i]->getFilialName() << endl;
				if(filial[i]->getBalance() < 0) // ������ ������������� ������ �������
				{
					for(int j=0; j<transport.size(); j++)
					{
						if(transport[j]->getStartFilialID() == filial[i]->getFilialID() )
						{
							cout << transport[j]->getName() << " ����������� ������� " << filial[i]->getFilialName() << endl;
							if(transport[j]->getRemainingDeliveryTime() == 0) // ���� �������� ����� � �������, ������� �����������, ���������� ��� � ��������� ������
							{
								int randI;
								do{
									randI = rand()%filial.size();
								}while(transport[j]->getStartFilialID() == filial[randI]->getFilialID() 
										and filial[randI]->getCategory() >= transport[j]->getCategory() ); //���� ������ ������
								transport[j]->setRemainingDeliveryTime(	transport[j]->getTimeDelivery() ); // ����������
								transport[j]->setFinishFilialID(transport[j]->getFinishFilialID());
								transport[j]->setStartFilialID(filial[randI]->getFilialID()); 
								
								cout << transport[j]->getName() << "  ���������� � ������ " <<  filial[randI]->getFilialName() << endl;
							}
							else
							{
								cout << transport[j]->getName() << " ��� ���� � ������ "  << filial[i]->getFilialName() ;
								transport[j]->setRemainingDeliveryTime(	transport[j]->getRemainingDeliveryTime() + transport[j]->getTimeDelivery() );
								int tempID = transport[j]->getStartFilialID();
								transport[j]->setStartFilialID(transport[j]->getFinishFilialID());
								transport[j]->setFinishFilialID(tempID);
								cout << " �� ����� ��������� �����"  << endl;
							}
							
							
						}
					}
					cout<< "������ " << filial[i]->getFilialName() << " ������ ��-�� ������" << endl;
					filial.erase(filial.begin() + i);
					i--;
				}
			}
			
			cout << "��� � ������ ��� ����" << endl;
		}
			
	
		virtual int getCategory() = 0;
		static void setFilialsMoney(int money) 
		{
			filialsMoney = money;
		} 
		static int getFilialsMoney() 
		{
			return filialsMoney;
		} 
		virtual ~Filial () {};
};
int Filial::filialsMoney = START_FILIALS_MONEY;

class SmallFilial : public Filial {
	public:
		SmallFilial (string name) : Filial (name) {	}
		SmallFilial () : Filial () {	}
		
		void infoAboutBalance()
		{
			cout <<left << setw(20) <<"��������� ������: " <<left << setw(25)  << getFilialName() 
			<< "���. ������: " << setw(6)  << getBalance() << endl;
		}
		int getCategory() 
		{
			return 0;
		}
	
		
		
		~SmallFilial() {}
};

class MiddleFilial : public Filial {
	public:
		MiddleFilial (string name) : Filial (name) {	}
		MiddleFilial () : Filial () {	}
		
		void infoAboutBalance()
		{
			cout << setw(20) <<"������� ������: " <<left << setw(25)  << getFilialName() << "���. ������: " << setw(6)  
			<< getBalance() << endl;
		}
		int getCategory() 
		{
			return 1;
		}
	
		
		~MiddleFilial() {}
};

class BigFilial : public Filial {
	public:
		BigFilial (string name) : Filial (name) {	}
		BigFilial () : Filial () {	}
		
		void infoAboutBalance()
		{
			cout << setw(20) <<"������� ������: " <<left << setw(25)  << getFilialName() << "���. ������: " << setw(6)  
			<< getBalance() << endl;
		}

		int getCategory() 
		{
			return 2;
		}
	
		~BigFilial() {}
};


int createRandomFilialID (vector <int> &arrID)
{
	int ID;
	ID = rand()%100+1;
	for(int i=0; i<arrID.size(); i++)
	{
		while(arrID[i] == ID)
		{
			ID = rand()%100+1;
		}
	}
	arrID.push_back(ID);
	return ID; 
}



int main()
{
	srand(time(NULL));
	system ("MODE CON: COLS=180 LINES=70");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); 
	int i,j;	
	int numberClient = START_NUMBER_CLIENT;
	
	vector <int> arrID;
	vector <Client*> client;
	vector <Filial*> filial;	
	vector <Transport*> transport;
	
{ // create random objekts
// FILIALS
	string RandomFilialName[] = {"������� �����", "����������", "�������", "���� �� ����", 
	"����� ����������", "����� ���������� 2", "����� ���������� 3", "����� (�� �����) �������", 
	"������ �������", "����� �����", "��������"};
	int sizeRandomFilialName = sizeof(RandomFilialName)/sizeof(string);
	
	filial.push_back(	new SmallFilial("������� �����") );  	
	filial.push_back(	new MiddleFilial("����������") );  	
	filial.push_back(	new BigFilial("�������") );  	
	filial.push_back(	new MiddleFilial("���� �� ����") );  	
	filial.push_back(	new BigFilial("����� (�� �����) �������") );  
	for(i=0; i<filial.size(); i++)
	{
		filial[i]->setFilialID(createRandomFilialID(arrID));
	}	

	
	string CarBrand[] = {"Changan ", "Cizeta ", "Delage ", "Delage ", "Dodge ", "Datsun ", "DeLorean ",
	 "Citroen ", "Foton", "Ford ", "Honda ", "Isuzu ", "Hyundai ", "Jeep ", "Jaguar", "Kia ", "Hummer ", "Infiniti ",
	  "Dacia", "Isdera ", "Lamborghini",  "Lexus", "Land Rover ", "Derways ", "Chery ", "Tesla ", "Toyota ", "Volvo ", "Suzuki "};
//	int sizeCarBrand = sizeof(CarBrand)/sizeof(string);
	string TrainBrand[] = {"��-1233", "��-43242", "��-4324", "��-534", "��-5231", "��-5234", "��-41230",
	 "���-7126", "���-185654", "���-92892", "���-088470", "���-78632", "���-0084004", "���-05690", "���-996633", 
	 "��-001122", "��-002236", "��-998877", "��-88556", "��-0456", "��-9856",  "��-9535", "��-9056" };
	 
	 string AirplaneBrand[] = {"��-134", "��-154", "��-168", "��-178", "��-218", "��-114", "��-154",
	 "��-414", "��-444", "��-344", "��-204", "��-70", "Boeing-747", "Boeing-757", "Airbus A220-100", 
	 "Airbus A220-300" };
	
	for(i=0; i<START_NUMBER_CAR; i++) //START_NUMBER_CAR = 20
	{
		transport.push_back(new Car() );
		transport[i]->setName(CarBrand[i]);		
		transport[i]->setStartFilialID( filial[rand()%filial.size()]->getFilialID() ); // transport get ID from Filial
	}	
	
	for(i, j=0; i<START_NUMBER_TRAIN + START_NUMBER_CAR; i++, j++) //START_NUMBER_TRAIN = 10
	{
		transport.push_back(new Train() );
		transport[i]->setName(TrainBrand[j]);	
		int startFilial_I;
		do {
			startFilial_I = rand()%filial.size();		
		}while(filial[startFilial_I]->getCategory() < MIDDLE_FILIAL_CATEGORY );
		transport[i]->setStartFilialID( filial[startFilial_I]->getFilialID() ); // transport get ID from Filial
	}	
		
	for(i, j=0; i<START_NUMBER_AIRPLANE + START_NUMBER_CAR + START_NUMBER_TRAIN; i++, j++) //START_NUMBER_AIRPLANE = 5
	{
		transport.push_back(new Airplane() );
		transport[i]->setName(AirplaneBrand[j]);
		int startFilial_I;
		do {		
			startFilial_I = rand()%filial.size();
		}while(filial[startFilial_I]->getCategory() < BIG_FILIAL_CATEGORY);
		transport[i]->setStartFilialID( filial[startFilial_I]->getFilialID() ); // transport get ID from Filial
	}
}
	
	string RandomName[] = {"����", "����", "����", "�����", "�����", "�����", "����", "����", "����", "Ҹ��", "����", "�������", "�������", "��������", "�������", "��������", "��������", "������", "��������", "�������", "������", "������", "������", "�������", "����", "������", "�����", "�����", "�������", "������", "�����"};
	int sizeRandomName = sizeof(RandomName)/sizeof(string);
	string RandomSurename[] = {"������", "��������", "������", "������", "���������", "����", "�����", "�����������", "��������", "���������", "�����", "����������", "������", "������", "������", "��������", "������", "�����", "���������", "������", "�������", "������", "��������", "�������", "��������", "�������", "���������", "��������", "���������", "��������", "���������", "������", "������", "���������"};
	int sizeRandomSurename = sizeof(RandomSurename)/sizeof(string);

	for(i=0; i<START_NUMBER_CLIENT; i++) //START_NUMBER_CLIENT = 10
	{
		client.push_back(	new Client() );  	
		client[i]->setName(RandomName[rand()%sizeRandomName]);
		client[i]->setSurename(RandomSurename[rand()%sizeRandomSurename]);
		client[i]->setMoney( rand()%MAX_AMOUNT_MONEY_CLIENT + MIN_AMOUNT_MONEY_CLIENT );
		client[i]->setWeightOfCargo( rand()%MAX_WEIGHT_OF_CARGO + MIN_WEIGHT_OF_CARGO );
		client[i]->setWaitingTime( rand()%MAX_TIME_DELIVERY + MIN_TIME_DELIVERY);
		client[i]->setWantFastDelivery(rand()%2);
		client[i]->setStartFilialID(arrID[rand()%arrID.size()]);
		do{
			client[i]->setFinishFilialID(arrID[rand()%arrID.size()]);
		} while(client[i]->getFinishFilialID() == client[i]->getStartFilialID ());		
	}
	
	Filial::getFilialsMoney() ;

	generateWeather (filial);						//��������� ������
	
	int mainmenu, podmenu, podmenu2, fExit=0;

do{	
		cout << "1. �������� ���������� � ��������" << endl;
		cout << "2. �������� ���������� � ����������" << endl;
		cout << "3. �������� ���������� � ��������" << endl;
		cout << "4. ���������� ������"<< endl;
		cout << "5. ���������� ���������"<< endl;
		cout << "6. ������ ������� ����"<< endl;
		cout << "7. ��������� ������� ����"<< endl;
		cout << "8. �����\n"<< endl;
	
		cout <<  "�������� ����� ����" << endl;
		cin >> mainmenu;
		
		switch(mainmenu)
		{
			case 1:																				 		
				{
					cout <<"�������� ���������� �������" << endl;
					cout <<"1. �������� ���������� � ������� ��������"<< endl;
					cout <<"2. �������� ���������� � ���������� ��������"<< endl;
					cout <<"3. �������� ���������� � �������� ��������"<< endl;
					cin >> podmenu;
					switch(podmenu) 
					{
						case 1: 
							{
								for(i=0; i<filial.size(); i++)
								{
									filial[i]->infoAboutBalance();
								}
								cout << "---- ---- " << "����� ������������� ������ = " << Filial::getFilialsMoney() << "   ---- ---- " << endl<< endl;	
							}
						break;	
						case 2:
							{	
								for(i=0; i<filial.size(); i++)
								{
									cout  << "---- ---- ---- ---- " << filial[i]->getFilialName()  << " ---- ---- ---- ----" << endl;
									cout << "��� ����������: " << left << setw(15)  <<" ������������: "	<< " �������� �����: " << " ����� ��������: " <<  endl;
									filial[i]->infoAboutTransport(transport);
								}
							}
						break;	
						case 3:
							{
								for(i=0; i<filial.size(); i++)
								{
									cout  << "---- ---- ---- ---- " << filial[i]->getFilialName()  << " ---- ---- ---- ----"<< endl;
									
									filial[i]->infoAboutClient(client, filial);
								}
							}
						break;	
						default:
							{
								cout << "������������ �����" << endl;
							}
						break;	
					}
				}
			break;
			case 2:																				 		
				{
					for(i=0; i<transport.size(); i++)
					{
						cout << i+1<< ". " ;
						transport[i]->info();
					}
				}
			break;	
			case 3:																				 		
				{
					for(i=0; i<client.size(); i++)
					{
						cout << i+1<< ". " ;
						client[i]->info(client[i]);
					}
				}
			break;	
			case 4:																				 		
				{
					cout <<"1. ������ ��������� ������ (40 000$)"<< endl;
					cout <<"2. ������ ������� ������ (60 000$)"<< endl;
					cout <<"3. ������ ������� ������ (100 000$)"<< endl;
					cin >> podmenu;
					switch(podmenu) 
					{
						case 1:
							{
								if(Filial::getFilialsMoney() < COST_SMALL_FILIAL )
									cout << "������������ �����, ��� ��������" << endl;
								else 
								{
									Filial::setFilialsMoney(Filial::getFilialsMoney() - COST_SMALL_FILIAL);
									string nameFilial;
									cout << "������� �������� �������" << endl;
									cin >> nameFilial;
									filial.push_back(	new SmallFilial(nameFilial) ); 
									filial[filial.size()-1]->setFilialID(createRandomFilialID(arrID)); 
									cout <<"������ ����������" <<  endl;									
								}
							}
						break;
						case 2:
							{
								if(Filial::getFilialsMoney() < COST_MIDDLE_FILIAL )
									cout << "������������ �����, ��� ��������" << endl;
								else 
								{
									Filial::setFilialsMoney(Filial::getFilialsMoney() - COST_MIDDLE_FILIAL);
									string nameFilial;
									cout << "������� �������� �������" << endl;
									cin >> nameFilial;
									filial.push_back(	new MiddleFilial(nameFilial) ); 
									filial[filial.size()-1]->setFilialID(createRandomFilialID(arrID)); 
									cout <<"������ ����������" <<  endl;
								}
							}
						break;
						case 3:
							{
								if(Filial::getFilialsMoney() < COST_BIG_FILIAL )
									cout << "������������ �����, ��� ��������" << endl;
								else 
								{
									Filial::setFilialsMoney(Filial::getFilialsMoney() - COST_BIG_FILIAL);
									string nameFilial;
									cout << "������� �������� �������" << endl;
									cin >> nameFilial;
									filial.push_back(	new BigFilial(nameFilial) ); 
									filial[filial.size()-1]->setFilialID(createRandomFilialID(arrID)); 
									cout <<"������ ����������" <<  endl;
								}
							}
						break;
						default:
							{
								cout << "������������ ����" << endl;
							}
						
					}
					
				}
			break;	
			case 5:																				 		
				{
					cout <<"1. ������ ���������� (10 000$)"<< endl;
					cout <<"2. ������ ����� (100 000$)"<< endl;
					cout <<"3. ������ ������� (200 000$)"<< endl;
					cin >> podmenu;
					switch(podmenu) 
					{
						case 1:
							{
								if(Filial::getFilialsMoney() < COST_AUTO )
									cout << "������������ �����, ��� ��������" << endl;
								else 
								{
									Filial::setFilialsMoney(Filial::getFilialsMoney() - COST_AUTO);
									string nameTransport;
									cout << "������� �������� ���������" << endl;
									cin >> nameTransport;
									transport.push_back(new Car() );
									transport[i]->setName(nameTransport);							
									transport[i]->setStartFilialID( filial[rand()%filial.size()]->getFilialID() ); // ��� ����� ����������
									cout <<"��������� ����������" <<  endl;									
								}
							}
						break;
						case 2:
							{
								if(Filial::getFilialsMoney() < COST_TRAIN )
									cout << "������������ �����, ��� ��������" << endl;
								else 
								{
									Filial::setFilialsMoney(Filial::getFilialsMoney() - COST_TRAIN);
									string nameTransport;
									cout << "������� �������� ������" << endl;
									cin >> nameTransport;
									transport.push_back(new Car() );
									transport[i]->setName(nameTransport);		
									transport[i]->setStartFilialID( filial[rand()%filial.size()]->getFilialID() ); // transport get ID from Filial
									cout <<"����� ����������" <<  endl;
								}
							}
						break;
						case 3:
							{
								if(Filial::getFilialsMoney() < COST_AIRPLANE )
									cout << "������������ �����, ��� ��������" << endl;
								else 
								{
									Filial::setFilialsMoney(Filial::getFilialsMoney() - COST_AIRPLANE);
									string nameTransport;
									cout << "������� �������� ��������" << endl;
									cin >> nameTransport;
									filial.push_back(	new BigFilial(nameTransport) ); 
									filial[filial.size()-1]->setFilialID(createRandomFilialID(arrID)); 
									cout <<"������� ����������" <<  endl;
								}
							}
						break;
						default:
							{
								cout << "������������ ����" << endl;
							}
						
					}
					
				}
			break;	
			case 6:
			{	
					
				organizeClients (client,filial)	;
				for(i=0; i<filial.size(); i++)
				{
					int clientCount=0;
					int transportCount=0;
					cout  << "---- ---- ---- ---- �_" << i+1<< "  " << filial[i]->getFilialName()  << " ---- ---- ---- ----" << endl;
					for(j=0; j<client.size(); j++)					
						if(client[j]->getStartFilialID() ==  filial[i]->getFilialID())						
							clientCount++;
					for(j=0; j<transport.size(); j++)
						if(transport[j]->getStartFilialID() ==  filial[i]->getFilialID() and transport[j]->getRemainingDeliveryTime() == 0)
							transportCount++;
					cout << "���������� ������: " << clientCount << ", ��������� ������������ ������: "	<<transportCount << endl;							
				}
				
				cout << "�������� ���������� �������" << endl;
				cout << "1. ������� ������ �� ���������� �������" << endl;
				cout << "2. ������� ������ ���� ��������" << endl;
				cin >> podmenu;
				switch(podmenu) 				
					{
						case 1:
							{
								int num;
								do{
									cout << "������� ����� �������" << endl;
									cin >> 	num;
								}while (num>filial.size());
								cout << "--- --- --- �������: --- --- ---" << endl;
								filial[num-1]->infoAboutClient(client, filial);
								cout << "--- --- --- �������: --- --- ---" << endl;
								cout << "��� ����������: " << left << setw(15)  <<" ������������: "	<< " �������� �����: " << " ����� ��������: " <<  endl;
								filial[num-1]->infoAboutTransport(transport);
								int numberInLine;
									cout << "�������� ����� �������" << endl;
									cin >> 	numberInLine;
							
								for(i=0; i<client.size(); i++)
								{
									if(client[i]->getStartFilialID() ==  filial[num-1]->getFilialID())
									{
										if(client[i]->getNumberInLine() == 	numberInLine )
										{
											filial[num-1]->findTransport (transport, client, i);
										}
									}
									
								}
								
							}
						break;	
						case 2:
							{
								for(i=0; i<filial.size(); i++)
								{
									filial[i]->findTransport (transport, client);
								}
								
							}
						break;	
						default:
							{
								cout << "������������ ����" << endl;
							}
						break;	
					}
			}
			break;
			case 7:
			{
				endTurn (transport, filial);
				generateWeather (filial);
			
				int numberRandomClients = rand()%10+3;
				int endClient = client.size();
				for(i=endClient; i< endClient + numberRandomClients; i++)
				{
					client.push_back(	new Client() );  	
					client[i]->setName(RandomName[rand()%sizeRandomName]);
					client[i]->setSurename(RandomSurename[rand()%sizeRandomSurename]);
					client[i]->setMoney( rand()%MAX_AMOUNT_MONEY_CLIENT + MIN_AMOUNT_MONEY_CLIENT );
					client[i]->setWeightOfCargo( rand()%MAX_WEIGHT_OF_CARGO + MIN_WEIGHT_OF_CARGO );
					client[i]->setWaitingTime( rand()%MAX_TIME_DELIVERY + MIN_TIME_DELIVERY);
					client[i]->setWantFastDelivery(rand()%2);
					client[i]->setStartFilialID(arrID[rand()%arrID.size()]);
					do{
						client[i]->setFinishFilialID(arrID[rand()%arrID.size()]);
					} while(client[i]->getFinishFilialID() == client[i]->getStartFilialID ());		
				}
			
			}
			break;
			case 8:
				{
					fExit = 1;
				}
	};
	system("pause");
	system("cls");
}	while(fExit == 0);
	

		


	

	
	
	
	
	system("pause");
	return 0;
}
