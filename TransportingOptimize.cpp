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
				cout << left << setw(10)  <<getName() << setw(15)  <<getSurename() << "вес груза: " 
				<<left << setw(6)  << getWeightOfCargo() << " денюжек: " << getMoney() 
				<< " Подождет не более: " <<getWaitingTime ()<< " дней, " << "хочет доставить груз быстро "<< endl;
			}
			else
				cout << left << setw(10)  <<getName() << setw(15)  <<getSurename() << "вес груза: " 
				<<left << setw(6)  << getWeightOfCargo() << " денюжек: " << getMoney() 
				<< " Подождет не более: " <<getWaitingTime ()<< " дней, " << "хочет доставить груз дешево " << endl;
		}	
		
		~Client () {}
};

class Transport {
	private:
		string name;
		int price; // $/kg
		int timeDelivery;  // days
		int remainingDeliveryTime; // оставшееся время в пути, days
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
			cout << "Тип транспорта: " << left << setw(15)  <<" Название транспорта: "	<< " Прибудет через: " << " Время доставки: " <<  endl;
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
				cout << left << setw(20) <<"Автомобиль   " << left << setw(15)  <<transport->getName() << left << setw(15) << "тут ждет  "	
				<< transport->getTimeDelivery ()<< " дней"  << endl;
			}
			else 
			{
				cout << left << setw(20) <<"Автомобиль   " << left << setw(15)  <<transport->getName() 
				 << transport->getRemainingDeliveryTime() << left << setw(15) << " дней"	
				<< transport->getTimeDelivery ()<< " дней"  << endl;
			}	
		}
		void info() 
		{
			cout << setw(15) << left<< "Автомобиль " << left << setw(15)  <<getName() << "Стоимомть перевозки 1 кг: " 
			<<left << setw(6) << getPrice() 
			<< " Время доставки: "<< getTimeDelivery ()<< " дней, " 
			<< "Время до прибытия: " << getRemainingDeliveryTime() << " дней, " 
			<< " Категория: " << getCategory() << " ,Вероятность аварии: " <<  getProbabilityCrash () << endl;
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
				cout << left << setw(20) << "Поезд" << left << setw(15)  <<transport->getName() << left << setw(15) << "тут ждет  "	
			<< transport->getTimeDelivery ()<< " дней"  << endl;
			}
			else 
			{
				cout << left << setw(20) << "Поезд" << left << setw(15)  <<transport->getName() << 
				 transport->getRemainingDeliveryTime() << left << setw(15)  << " дней"	
			<< transport->getTimeDelivery ()<< " дней"  << endl;
			}	
		}
			void info() 
		{
			cout << setw(15)<< left << "Поезд " << left << setw(15)  <<getName() << "Стоимомть перевозки 1 кг: " 
			<<left << setw(6) << getPrice() 
			<< " Время доставки: "<< getTimeDelivery ()<< " дней, " 
			<< "Время до прибытия: " << getRemainingDeliveryTime() << " дней, " 
			<< " Категория: " << getCategory() << " ,Вероятность аварии: " <<  getProbabilityCrash () << endl;
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
				cout << left << setw(20) << "Самолет" << left << setw(15)  <<transport->getName() << left << setw(15) << "тут ждет  "	
				<< transport->getTimeDelivery ()<< " дней"  << endl;
			}
			else 
			{
				cout << left << setw(20) << "Самолет"<< left << setw(15)  <<transport->getName() 
				<< transport->getRemainingDeliveryTime() << left << setw(15) << " дней"	
				<< transport->getTimeDelivery ()<< " дней"  << endl;
			}	
		}
			void info() 
		{
			cout << setw(15)<< left <<"Самолет"<< left << setw(15)  <<getName() << "Стоимомть перевозки 1 кг: " 
			<<left << setw(6) << getPrice() 
			<< " Время доставки: "<< getTimeDelivery ()<< " дней, " 
			<< "Время до прибытия: " << getRemainingDeliveryTime() << " дней, " 
			<< " Категория: " << getCategory() << " ,Вероятность аварии: " <<  getProbabilityCrash () << endl;
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
			cout << "Клиенты стали в очередь" << endl;
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
					cout << " из филиала  " << getFilialName();
					for(int j=0; j<filial.size(); j++)
					{
						if(filial[j]->getFilialID() == client[i]->getFinishFilialID())
						{
							cout << " в филиал " << filial[j]->getFilialName() << endl<< endl;
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
				
				if(client[j]->getWantFastDelivery () == true) // если в приоритете СКОРОСТЬ доставки, ищем по наименьшему времени доставки
				{
					for(int i=0; i<transport.size(); i++) // идем по массиву трансопорта
					{
						if (transport[i]->getStartFilialID () == getFilialID() and transport[i]->getRemainingDeliveryTime() == 0 ) // выбираем из доступного этому филиалу транспорта ID, из транспорта готового отправиться
						{
							if(transport[i]->getTimeDelivery()  <= client[j]->getWaitingTime() ) // сверяем время доставки транспорта с ожиданием клиента
							{
								if(client[j]->getWeightOfCargo()*transport[i]->getPrice() <= client[j]->getMoney() ) // проверка на то, чтобы хватило денег
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
						else if (transport[i]->getStartFilialID () == getFilialID() and transport[i]->getRemainingDeliveryTime() != 0 ) // транспорт прибудет в филиал
						{
							if(transport[i]->getTimeDelivery() + transport[i]->getRemainingDeliveryTime()  <= client[j]->getWaitingTime() ) // сверяем время доставки транспорта с ожиданием клиента
							{
								if(client[j]->getWeightOfCargo()*transport[i]->getPrice() <= client[j]->getMoney() ) // проверка на то, чтобы хватило денег
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
				
				if(client[j]->getWantFastDelivery () == false) // если в приоритете ЦЕНА доставки, ищем по наименьшей цене доставки
				{
					for(int i=0; i<transport.size(); i++) // идем по массиву трансопорта
					{
						if (transport[i]->getStartFilialID () == getFilialID() and transport[i]->getRemainingDeliveryTime() == 0 ) // выбираем из доступного этому филиалу транспорта ID, из транспорта готового отправиться
						{
							if(client[j]->getWeightOfCargo()*transport[i]->getPrice() <= client[j]->getMoney() ) // проверка на то, чтобы хватило денег
							{
								if(client[j]->getWeightOfCargo()*transport[i]->getPrice() <=bestPrice)
								{
									 bestPrice = client[j]->getWeightOfCargo()*transport[i]->getPrice();
									 numberOfBestTransport = i;
									 client[j]->setStatusWaiting(false);
									 
								}
							}
						}
						else if (transport[i]->getStartFilialID () == getFilialID() and transport[i]->getRemainingDeliveryTime() != 0 ) // транспорт прибудет в филиал
						{
							if(client[j]->getWeightOfCargo()*transport[i]->getPrice() <= client[j]->getMoney() ) // проверка на то, чтобы хватило денег
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
				
				if(numberOfBestTransport < transport.size() and client[j]->getStatusWaiting() == false)	//оформление заявки, взятие денег
				{
					cout << "Заявка принята" << endl
					<< "Клиент " << client[j]->getName() << " " << client[j]->getSurename()<< " оплатит " << bestPrice << "$ , доставка осуществится за " 
					<< transport[numberOfBestTransport]->getTimeDelivery() << " дней, средство доставки - " 
					<< transport[numberOfBestTransport]->getName() << endl<< endl;
					setBalance (getBalance() + bestPrice);
					setFilialsMoney(getFilialsMoney() + bestPrice ) ;
					transport[numberOfBestTransport]->setRemainingDeliveryTime(transport[numberOfBestTransport]->getTimeDelivery()); 	// устанавливаем счетчик дней до прибытия
					transport[numberOfBestTransport]->setFinishFilialID(transport[numberOfBestTransport]->getStartFilialID()); 		// запомнили точку отправления
					transport[numberOfBestTransport]->setStartFilialID(client[j]->getFinishFilialID())	; 			// транспорт становится транспортом другого филиала
					transport[numberOfBestTransport]->setCostOfCargo( bestPrice);
					client.erase(client.begin() + j); 
				}	
				else 
				{
					cout << "Заявка отклонена " << endl
					<< "Невозможно выполнить требования клиента " << client[j]->getName() << " " <<client[j]->getSurename() << endl<< endl;
					client.erase(client.begin() + j); 
				}
			}
		}
		
		void findTransport (vector <Transport*>&transport, vector <Client*>&client, int j)
		{
				int bestTime = client[j]->getWaitingTime()+1;
				int numberOfBestTransport = transport.size()+1;
				
				if(client[j]->getWantFastDelivery () == true) // если в приоритете СКОРОСТЬ доставки, ищем по наименьшему времени доставки
				{
					for(int i=0; i<transport.size(); i++) // идем по массиву трансопорта
					{
						if (transport[i]->getStartFilialID () == getFilialID() and transport[i]->getRemainingDeliveryTime() == 0 ) // выбираем из доступного этому филиалу транспорта ID, из транспорта готового отправиться
						{
							if(transport[i]->getTimeDelivery()  <= client[j]->getWaitingTime() ) // сверяем время доставки транспорта с ожиданием клиента
							{
								if(client[j]->getWeightOfCargo()*transport[i]->getPrice() <= client[j]->getMoney() ) // проверка на то, чтобы хватило денег
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
						else if (transport[i]->getStartFilialID () == getFilialID() and transport[i]->getRemainingDeliveryTime() != 0 ) // транспорт прибудет в филиал
						{
							if(transport[i]->getTimeDelivery() + transport[i]->getRemainingDeliveryTime()  <= client[j]->getWaitingTime() ) // сверяем время доставки транспорта с ожиданием клиента
							{
								if(client[j]->getWeightOfCargo()*transport[i]->getPrice() <= client[j]->getMoney() ) // проверка на то, чтобы хватило денег
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
				
				if(client[j]->getWantFastDelivery () == false) // если в приоритете ЦЕНА доставки, ищем по наименьшей цене доставки
				{
					for(int i=0; i<transport.size(); i++) // идем по массиву трансопорта
					{
						if (transport[i]->getStartFilialID () == getFilialID() and transport[i]->getRemainingDeliveryTime() == 0 ) // выбираем из доступного этому филиалу транспорта ID, из транспорта готового отправиться
						{
							if(client[j]->getWeightOfCargo()*transport[i]->getPrice() <= client[j]->getMoney() ) // проверка на то, чтобы хватило денег
							{
								if(client[j]->getWeightOfCargo()*transport[i]->getPrice() <=bestPrice)
								{
									 bestPrice = client[j]->getWeightOfCargo()*transport[i]->getPrice();
									 numberOfBestTransport = i;
									 client[j]->setStatusWaiting(false);
									 
								}
							}
						}
						else if (transport[i]->getStartFilialID () == getFilialID() and transport[i]->getRemainingDeliveryTime() != 0 ) // транспорт прибудет в филиал
						{
							if(client[j]->getWeightOfCargo()*transport[i]->getPrice() <= client[j]->getMoney() ) // проверка на то, чтобы хватило денег
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
				
				if(numberOfBestTransport < transport.size() and client[j]->getStatusWaiting() == false)	//оформление заявки, взятие денег
				{
					cout << "Заявка принята" << endl
					<< "Клиент " << client[j]->getName() << " " << client[j]->getSurename()<< " оплатит " << bestPrice << "$ , доставка осуществится за " 
					<< transport[numberOfBestTransport]->getTimeDelivery() << " дней, средство доставки - " 
					<< transport[numberOfBestTransport]->getName() << endl<< endl;
					setBalance (getBalance() + bestPrice);
					setFilialsMoney(getFilialsMoney() + bestPrice ) ;
					transport[numberOfBestTransport]->setRemainingDeliveryTime(transport[numberOfBestTransport]->getTimeDelivery()); 	// устанавливаем счетчик дней до прибытия
					transport[numberOfBestTransport]->setFinishFilialID(transport[numberOfBestTransport]->getStartFilialID()); 		// запомнили точку отправления
					transport[numberOfBestTransport]->setStartFilialID(getFilialID())	; 			// транспорт становится транспортом другого филиала
					client.erase(client.begin() + j); 
				}	
				
				else 
				{
					cout << "Заявка отклонена " << endl
					<< "Невозможно выполнить требования клиента " << client[j]->getName() << " " <<client[j]->getSurename() << endl<< endl;
					client.erase(client.begin() + j); 
				}
		}
		friend void endTurn (vector <Transport*>&transport, vector <Filial*>&filial)
		{
			for(int i=0; i<transport.size(); i++) 
			{
				if(transport[i]->getRemainingDeliveryTime() > 0) // на всех кто в пути
				{
					cout << transport[i]->getName() << " едет..." << endl;
					int x = rand()%10000;
					if(x <= transport[i]->getProbabilityCrash()*100) // чекаем аварию
					{
						for (int j=0; j<filial.size(); j++) // проверяем филиалы, откуда был выезд (т.к. оплату принял отправитель)
						{
							if(filial[j]->getFilialID() == transport[i]->getFinishFilialID())
							{
								filial[j]->setBalance(filial[j]->getBalance() - 2*transport[i]->getCostOfCargo() );
								cout << transport[i]->getName() << " попал в аварию с грузом на сумму " 
								<< transport[i]->getCostOfCargo() << "$" << endl;
								cout << "Филиал: " << filial[j]->getFilialName() << " раскошелится на " << transport[i]->getCostOfCargo()*2 << "$" <<endl;
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
					if(filial[i]->getWeather() == true and filial[j]->getWeather() == true) //чекаем погоду на пути
					{
						for(int k=0; k<transport.size(); k++ )
						{
							if(transport[k]->getStartFilialID() == filial[i]->getFilialID() and transport[k]->getFinishFilialID() == filial[j]->getFilialID() )
							{
								if( transport[k]->getRemainingDeliveryTime() > 0) // если вообще едет
								{
									cout << "На пути от " << filial[i]->getFilialName() << " до " << filial[j]->getFilialName() 
									<< " плохая погода, " << transport[k]->getName() <<
									" растерял часть груза, придется вернуть часть денег клиенту" << endl;
									cout << "Филиал: " << filial[j]->getFilialName() << " раскошелится на " <<transport[k]->getCostOfCargo()*15/100 << "$" <<endl;
									filial[j]->setBalance(filial[j]->getBalance() - transport[k]->getCostOfCargo()*15/100 );
								}	
							}
							if (transport[k]->getStartFilialID() == filial[j]->getFilialID() and transport[k]->getFinishFilialID() == filial[i]->getFilialID() )
							{
								if( transport[k]->getRemainingDeliveryTime() > 0) // если вообще едет
								{
									cout << "На пути от " << filial[i]->getFilialName() << " до " << filial[j]->getFilialName() 
									<< " плохая погода, " << transport[k]->getName() <<
									" растерял часть груза, придется вернуть часть денег клиенту" << endl;
									cout << "Филиал: " << filial[j]->getFilialName() << " раскошелится на " <<transport[k]->getCostOfCargo()*15/100 << "$" <<endl;
									filial[i]->setBalance(filial[i]->getBalance() - transport[k]->getCostOfCargo()*15/100 );
								}
							}
						}
					}		
				}
			}
			for(int i=0; i<filial.size(); i++)
			{
				cout << endl << "Налоговая проверяет филиал  " << filial[i]->getFilialName() << endl;
				if(filial[i]->getBalance() < 0) // чекаем отрицательный баланс филиала
				{
					for(int j=0; j<transport.size(); j++)
					{
						if(transport[j]->getStartFilialID() == filial[i]->getFilialID() )
						{
							cout << transport[j]->getName() << " принадлежит филиалу " << filial[i]->getFilialName() << endl;
							if(transport[j]->getRemainingDeliveryTime() == 0) // если траспорт стоит в филиале, который закрывается, отправляем его в рандомный филиал
							{
								int randI;
								do{
									randI = rand()%filial.size();
								}while(transport[j]->getStartFilialID() == filial[randI]->getFilialID() 
										and filial[randI]->getCategory() >= transport[j]->getCategory() ); //ищем другой филиал
								transport[j]->setRemainingDeliveryTime(	transport[j]->getTimeDelivery() ); // отправляем
								transport[j]->setFinishFilialID(transport[j]->getFinishFilialID());
								transport[j]->setStartFilialID(filial[randI]->getFilialID()); 
								
								cout << transport[j]->getName() << "  отправился в филиал " <<  filial[randI]->getFilialName() << endl;
							}
							else
							{
								cout << transport[j]->getName() << " вез груз в филиал "  << filial[i]->getFilialName() ;
								transport[j]->setRemainingDeliveryTime(	transport[j]->getRemainingDeliveryTime() + transport[j]->getTimeDelivery() );
								int tempID = transport[j]->getStartFilialID();
								transport[j]->setStartFilialID(transport[j]->getFinishFilialID());
								transport[j]->setFinishFilialID(tempID);
								cout << " он будет отправлен назад"  << endl;
							}
							
							
						}
					}
					cout<< "Филиал " << filial[i]->getFilialName() << " ЗАКРЫТ из-за долгов" << endl;
					filial.erase(filial.begin() + i);
					i--;
				}
			}
			
			cout << "Вот и прошел еще день" << endl;
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
			cout <<left << setw(20) <<"Маленький филиал: " <<left << setw(25)  << getFilialName() 
			<< "Бух. баланс: " << setw(6)  << getBalance() << endl;
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
			cout << setw(20) <<"Средний филиал: " <<left << setw(25)  << getFilialName() << "Бух. баланс: " << setw(6)  
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
			cout << setw(20) <<"Большой филиал: " <<left << setw(25)  << getFilialName() << "Бух. баланс: " << setw(6)  
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
	string RandomFilialName[] = {"Деловые Линии", "ПовозкаБай", "Кобылка", "Сани от Сани", 
	"Пункт назначения", "Пункт назначения 2", "Пункт назначения 3", "Ковер (со стены) самолет", 
	"Перевёз паровоз", "Почта Раисы", "Мерседес"};
	int sizeRandomFilialName = sizeof(RandomFilialName)/sizeof(string);
	
	filial.push_back(	new SmallFilial("Деловые Линии") );  	
	filial.push_back(	new MiddleFilial("ПовозкаБай") );  	
	filial.push_back(	new BigFilial("Кобылка") );  	
	filial.push_back(	new MiddleFilial("Сани от Сани") );  	
	filial.push_back(	new BigFilial("Ковер (со стены) самолет") );  
	for(i=0; i<filial.size(); i++)
	{
		filial[i]->setFilialID(createRandomFilialID(arrID));
	}	

	
	string CarBrand[] = {"Changan ", "Cizeta ", "Delage ", "Delage ", "Dodge ", "Datsun ", "DeLorean ",
	 "Citroen ", "Foton", "Ford ", "Honda ", "Isuzu ", "Hyundai ", "Jeep ", "Jaguar", "Kia ", "Hummer ", "Infiniti ",
	  "Dacia", "Isdera ", "Lamborghini",  "Lexus", "Land Rover ", "Derways ", "Chery ", "Tesla ", "Toyota ", "Volvo ", "Suzuki "};
//	int sizeCarBrand = sizeof(CarBrand)/sizeof(string);
	string TrainBrand[] = {"БЧ-1233", "БЧ-43242", "БЧ-4324", "БЧ-534", "БЧ-5231", "БЧ-5234", "БЧ-41230",
	 "РЖД-7126", "РЖД-185654", "РЖД-92892", "РЖД-088470", "РЖД-78632", "РЖД-0084004", "РЖД-05690", "РЖД-996633", 
	 "БЧ-001122", "БЧ-002236", "БЧ-998877", "БЧ-88556", "БЧ-0456", "БЧ-9856",  "БЧ-9535", "БЧ-9056" };
	 
	 string AirplaneBrand[] = {"Ту-134", "Ту-154", "Ан-168", "Ан-178", "Ан-218", "Ту-114", "Ту-154",
	 "Ту-414", "Ту-444", "Ту-344", "Ту-204", "Ту-70", "Boeing-747", "Boeing-757", "Airbus A220-100", 
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
	
	string RandomName[] = {"Коля", "Витя", "Паша", "Серёжа", "Игорёк", "Вован", "Тоха", "Жека", "Саня", "Тёма", "Макс", "Евтихий", "Филарет", "Евлампий", "Кондрат", "Митрофан", "Прокопий", "Лукьян", "Поликарп", "Аврелий", "Фабиан", "Агафон", "Феофан", "Капитон", "Лавр", "Эрнест", "Артур", "Симон", "Даниэль", "Роберт", "Ренат"};
	int sizeRandomName = sizeof(RandomName)/sizeof(string);
	string RandomSurename[] = {"Басков", "Киркоров", "Кобзон", "Пушкин", "Лермонтов", "Блок", "Путин", "Жириновский", "Медведев", "Ломоносов", "Франк", "Калашников", "Иванов", "Петров", "Ашанин", "Вревский", "Тяпкин", "Фигин", "Потеряхин", "Брюхов", "Рашидов", "Юсупов", "Саракаев", "Каверин", "Раевский", "Кутузов", "Менделеев", "Нарышкин", "Циммерман", "Вульферт", "Оффенберг", "Вагнер", "Бергер", "Розенберг"};
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

	generateWeather (filial);						//генерация погоды
	
	int mainmenu, podmenu, podmenu2, fExit=0;

do{	
		cout << "1. Показать информацию о филиалах" << endl;
		cout << "2. Показать информацию о транспорте" << endl;
		cout << "3. Показать информацию о клиентах" << endl;
		cout << "4. Приобрести филиал"<< endl;
		cout << "5. Приобрести транспорт"<< endl;
		cout << "6. Начать рабочий день"<< endl;
		cout << "7. Завершить рабочий день"<< endl;
		cout << "8. Выход\n"<< endl;
	
		cout <<  "Выберите пункт меню" << endl;
		cin >> mainmenu;
		
		switch(mainmenu)
		{
			case 1:																				 		
				{
					cout <<"Выберите подходящий вариант" << endl;
					cout <<"1. Показать информацию о балансе филиалов"<< endl;
					cout <<"2. Показать информацию о транспорте филиалов"<< endl;
					cout <<"3. Показать информацию о клиентах филиалов"<< endl;
					cin >> podmenu;
					switch(podmenu) 
					{
						case 1: 
							{
								for(i=0; i<filial.size(); i++)
								{
									filial[i]->infoAboutBalance();
								}
								cout << "---- ---- " << "Общий бухгалтерский баланс = " << Filial::getFilialsMoney() << "   ---- ---- " << endl<< endl;	
							}
						break;	
						case 2:
							{	
								for(i=0; i<filial.size(); i++)
								{
									cout  << "---- ---- ---- ---- " << filial[i]->getFilialName()  << " ---- ---- ---- ----" << endl;
									cout << "Тип транспорта: " << left << setw(15)  <<" Наименование: "	<< " Прибудет через: " << " Время доставки: " <<  endl;
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
								cout << "Некорректный выбор" << endl;
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
					cout <<"1. Купить мальнький филиал (40 000$)"<< endl;
					cout <<"2. Купить средний филиал (60 000$)"<< endl;
					cout <<"3. Купить большой филиал (100 000$)"<< endl;
					cin >> podmenu;
					switch(podmenu) 
					{
						case 1:
							{
								if(Filial::getFilialsMoney() < COST_SMALL_FILIAL )
									cout << "Недостаточно денег, иди работать" << endl;
								else 
								{
									Filial::setFilialsMoney(Filial::getFilialsMoney() - COST_SMALL_FILIAL);
									string nameFilial;
									cout << "Введите название филиала" << endl;
									cin >> nameFilial;
									filial.push_back(	new SmallFilial(nameFilial) ); 
									filial[filial.size()-1]->setFilialID(createRandomFilialID(arrID)); 
									cout <<"Филиал приобретен" <<  endl;									
								}
							}
						break;
						case 2:
							{
								if(Filial::getFilialsMoney() < COST_MIDDLE_FILIAL )
									cout << "Недостаточно денег, иди работать" << endl;
								else 
								{
									Filial::setFilialsMoney(Filial::getFilialsMoney() - COST_MIDDLE_FILIAL);
									string nameFilial;
									cout << "Введите название филиала" << endl;
									cin >> nameFilial;
									filial.push_back(	new MiddleFilial(nameFilial) ); 
									filial[filial.size()-1]->setFilialID(createRandomFilialID(arrID)); 
									cout <<"Филиал приобретен" <<  endl;
								}
							}
						break;
						case 3:
							{
								if(Filial::getFilialsMoney() < COST_BIG_FILIAL )
									cout << "Недостаточно денег, иди работать" << endl;
								else 
								{
									Filial::setFilialsMoney(Filial::getFilialsMoney() - COST_BIG_FILIAL);
									string nameFilial;
									cout << "Введите название филиала" << endl;
									cin >> nameFilial;
									filial.push_back(	new BigFilial(nameFilial) ); 
									filial[filial.size()-1]->setFilialID(createRandomFilialID(arrID)); 
									cout <<"Филиал приобретен" <<  endl;
								}
							}
						break;
						default:
							{
								cout << "Некорректный ввод" << endl;
							}
						
					}
					
				}
			break;	
			case 5:																				 		
				{
					cout <<"1. Купить автомобиль (10 000$)"<< endl;
					cout <<"2. Купить поезд (100 000$)"<< endl;
					cout <<"3. Купить самолет (200 000$)"<< endl;
					cin >> podmenu;
					switch(podmenu) 
					{
						case 1:
							{
								if(Filial::getFilialsMoney() < COST_AUTO )
									cout << "Недостаточно денег, иди работать" << endl;
								else 
								{
									Filial::setFilialsMoney(Filial::getFilialsMoney() - COST_AUTO);
									string nameTransport;
									cout << "Введите название атомобиля" << endl;
									cin >> nameTransport;
									transport.push_back(new Car() );
									transport[i]->setName(nameTransport);							
									transport[i]->setStartFilialID( filial[rand()%filial.size()]->getFilialID() ); // тут можно переделать
									cout <<"Атомобиль приобретен" <<  endl;									
								}
							}
						break;
						case 2:
							{
								if(Filial::getFilialsMoney() < COST_TRAIN )
									cout << "Недостаточно денег, иди работать" << endl;
								else 
								{
									Filial::setFilialsMoney(Filial::getFilialsMoney() - COST_TRAIN);
									string nameTransport;
									cout << "Введите название поезда" << endl;
									cin >> nameTransport;
									transport.push_back(new Car() );
									transport[i]->setName(nameTransport);		
									transport[i]->setStartFilialID( filial[rand()%filial.size()]->getFilialID() ); // transport get ID from Filial
									cout <<"Поезд приобретен" <<  endl;
								}
							}
						break;
						case 3:
							{
								if(Filial::getFilialsMoney() < COST_AIRPLANE )
									cout << "Недостаточно денег, иди работать" << endl;
								else 
								{
									Filial::setFilialsMoney(Filial::getFilialsMoney() - COST_AIRPLANE);
									string nameTransport;
									cout << "Введите название самолета" << endl;
									cin >> nameTransport;
									filial.push_back(	new BigFilial(nameTransport) ); 
									filial[filial.size()-1]->setFilialID(createRandomFilialID(arrID)); 
									cout <<"Самолет приобретен" <<  endl;
								}
							}
						break;
						default:
							{
								cout << "Некорректный ввод" << endl;
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
					cout  << "---- ---- ---- ---- №_" << i+1<< "  " << filial[i]->getFilialName()  << " ---- ---- ---- ----" << endl;
					for(j=0; j<client.size(); j++)					
						if(client[j]->getStartFilialID() ==  filial[i]->getFilialID())						
							clientCount++;
					for(j=0; j<transport.size(); j++)
						if(transport[j]->getStartFilialID() ==  filial[i]->getFilialID() and transport[j]->getRemainingDeliveryTime() == 0)
							transportCount++;
					cout << "Количество заявок: " << clientCount << ", Свободных транспортных единиц: "	<<transportCount << endl;							
				}
				
				cout << "Выберите подходящий вариант" << endl;
				cout << "1. Оказать услуги по выбранному филиалу" << endl;
				cout << "2. Оказать услуги всем филиалам" << endl;
				cin >> podmenu;
				switch(podmenu) 				
					{
						case 1:
							{
								int num;
								do{
									cout << "Введите номер филиала" << endl;
									cin >> 	num;
								}while (num>filial.size());
								cout << "--- --- --- Клиенты: --- --- ---" << endl;
								filial[num-1]->infoAboutClient(client, filial);
								cout << "--- --- --- Техника: --- --- ---" << endl;
								cout << "Тип транспорта: " << left << setw(15)  <<" Наименование: "	<< " Прибудет через: " << " Время доставки: " <<  endl;
								filial[num-1]->infoAboutTransport(transport);
								int numberInLine;
									cout << "Выберите номер клиента" << endl;
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
								cout << "Некорректный ввод" << endl;
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
